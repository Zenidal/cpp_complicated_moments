#ifndef CPP_COMPLICATED_MOMENTS_IMETHODS_H
#define CPP_COMPLICATED_MOMENTS_IMETHODS_H

#include "../Task2/gen/Students.pb.h"

class IMethods
{
    public:
        virtual double getAverageScore(const homework7::FullName &name) = 0;

        virtual std::string getAllInfo(const homework7::FullName &name) = 0;

        virtual std::string getAllInfo() = 0;
};

#endif //CPP_COMPLICATED_MOMENTS_IMETHODS_H
