#ifndef CPP_COMPLICATED_MOMENTS_PCOUT_H
#define CPP_COMPLICATED_MOMENTS_PCOUT_H

#include <iostream>
#include <mutex>
#include <ostream>

static std::mutex pcoutMutex;

class pcout
{
    private:
        std::unique_lock<std::mutex> lock;
    public:
        pcout() : lock(std::unique_lock<std::mutex>(pcoutMutex))
        {}

        template<typename T>
        pcout &operator<<(const T &printableValue)
        {
            std::cout << printableValue;

            return *this;
        }

        pcout &operator<<(std::ostream &(*fp)(std::ostream &))
        {
            std::cout << fp;

            return *this;
        }
};


#endif //CPP_COMPLICATED_MOMENTS_PCOUT_H
