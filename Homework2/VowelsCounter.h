#ifndef CPP_COMPLICATED_MOMENTS_VOWELSCOUNTER_H
#define CPP_COMPLICATED_MOMENTS_VOWELSCOUNTER_H

#include <string>

class VowelsCounter
{
    public:
        static int calculateByCountIfAndFind(std::string &text);

        static int calculateByCountIfAndFor(std::string &text);

        static int calculateForAndFind(std::string &text);

        static int calculateForAndFor(std::string &text);
};


#endif //CPP_COMPLICATED_MOMENTS_VOWELSCOUNTER_H
