#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <set>

std::mutex mutex;
std::condition_variable semaphore;

int main()
{
    { // task 3
        std::set<unsigned int> values;
        unsigned int mostValuableValue = 1;
        int numberOfIterations = 10;

        std::thread host([&values, &mostValuableValue, numberOfIterations]() {
            std::lock_guard<std::mutex> lock(mutex);

            for (int i = 0; i < numberOfIterations; i++) {
                values.insert(mostValuableValue);

                std::cout << "Host has bought: " << mostValuableValue << std::endl;
                mostValuableValue++;

                semaphore.notify_one();
            }
        });

        std::thread thief([&values, numberOfIterations]() {
            std::unique_lock<std::mutex> lock(mutex);

            for (int i = 0; i < numberOfIterations; i++) {
                semaphore.wait(lock, [&values] { return !values.empty(); });

                auto stolenValueIt = std::prev(values.end());
                auto stolenValue = *stolenValueIt;
                values.erase(stolenValueIt);

                std::cout << "Thief has stolen: " << stolenValue << std::endl;
            }
        });

        host.join();
        thief.join();
    }

    return EXIT_SUCCESS;
}
