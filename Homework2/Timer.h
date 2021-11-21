#ifndef CPP_COMPLICATED_MOMENTS_TIMER_H
#define CPP_COMPLICATED_MOMENTS_TIMER_H

#include <chrono>

class Timer
{
    public:
        template<class Function>
        static int calculateExecutionTimeInSeconds(Function f)
        {
            auto start = std::chrono::system_clock::now();

            f();

            auto end = std::chrono::system_clock::now();

            return (end - start).count();
        }
};


#endif //CPP_COMPLICATED_MOMENTS_TIMER_H
