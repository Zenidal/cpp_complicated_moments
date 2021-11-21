#include <iostream>
#include <vector>

#include "Homework2/Homework2.cpp"
#include "Homework2/VowelsCounter.h"

int main()
{
    { // task 1
        int x = 1;
        int y = 2;

        int *xPtr;
        xPtr = &x;
        int *yPtr;
        yPtr = &y;

        auto printVariablesInfo = [&x, &y, &xPtr, &yPtr]() -> void {
            std::cout << "x ref: " << &x << std::endl << "y ref: " << &y << std::endl << "x ptr: " << xPtr << std::endl << "y ptr: " << yPtr << std::endl;
        };

        printVariablesInfo();

        swap(xPtr, yPtr);

        std::cout << std::endl;

        printVariablesInfo();
    }

    std::cout << std::endl;

    {
        // task 2
        size_t size = 6;
        int values[] = {3, 55, 7, -23, 0, 4};
        auto printVector = [](std::vector<int *> pointers) -> void {
            for (auto pointer: pointers) {
                std::cout << *pointer << " ";
            }

            std::cout << std::endl;
        };

        std::vector<int *> pointers;
        for (size_t i = 0; i < size; i++) {
            pointers.push_back(&values[i]);
        }

        printVector(pointers);

        sortPointers(pointers);

        printVector(pointers);
    }

    std::cout << std::endl;

    { // task 3
        std::string text = "Война и мир";

        VowelsCounter vowelsCounter;
        std::cout << "count if and find: " << VowelsCounter::calculateByCountIfAndFind(text) << std::endl;
        std::cout << "count_if and for: " << VowelsCounter::calculateByCountIfAndFor(text) << std::endl;
        std::cout << "for and find: " << VowelsCounter::calculateForAndFind(text) << std::endl;
        std::cout << "for and for: " << VowelsCounter::calculateForAndFor(text) << std::endl;
    }
}
