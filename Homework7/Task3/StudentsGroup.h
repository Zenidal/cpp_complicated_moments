#ifndef CPP_COMPLICATED_MOMENTS_STUDENTSGROUP_H
#define CPP_COMPLICATED_MOMENTS_STUDENTSGROUP_H

#include <numeric>
#include <algorithm>

#include "IRepository.h"
#include "IMethods.h"
#include "../Task2/gen/Students.pb.h"

class StudentsGroup : public IRepository, IMethods
{
    private:
        int studentsCount;
        homework7::Student *students;

        homework7::Student *findStudent(const homework7::FullName &name);

    public:
        StudentsGroup() : studentsCount(0), students(nullptr)
        {}

        StudentsGroup(int studentsCount, homework7::Student *students) : studentsCount(studentsCount), students(students)
        {}

        double getAverageScore(const homework7::FullName &name) override;

        std::string getAllInfo(const homework7::FullName &name) override;

        std::string getAllInfo() override;

        void Open(std::istream *input) override;

        void Save(std::ostream* output) override;
};


#endif //CPP_COMPLICATED_MOMENTS_STUDENTSGROUP_H
