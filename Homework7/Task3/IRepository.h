#ifndef CPP_COMPLICATED_MOMENTS_IREPOSITORY_H
#define CPP_COMPLICATED_MOMENTS_IREPOSITORY_H

#include <iostream>

class IRepository
{
    public:
        virtual void Open(std::istream* input) = 0;
        virtual void Save(std::ostream* output) = 0;
};

#endif //CPP_COMPLICATED_MOMENTS_IREPOSITORY_H
