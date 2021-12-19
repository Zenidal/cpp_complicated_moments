#include "StudentsGroup.h"

homework7::Student *StudentsGroup::findStudent(const homework7::FullName &name)
{
    auto student = std::find_if(students, students + studentsCount, [name](homework7::Student &student) {
        const auto &currentName = student.full_name();

        if (currentName.first_name() != name.first_name()) {
            return false;
        }

        if (currentName.second_name() != name.second_name()) {
            return false;
        }

        if ((currentName.has_third_name() && !name.has_third_name()) || (!currentName.has_third_name() && name.has_third_name())) {
            return false;
        }

        if (!currentName.has_third_name() && !name.has_third_name()) {
            return true;
        }

        return currentName.third_name() == name.third_name();
    });

    if (student == students + studentsCount) {
        return nullptr;
    }

    return student;
}

double StudentsGroup::getAverageScore(const homework7::FullName &name)
{
    auto student = findStudent(name);

    if (student == nullptr) {
        return 0.0;
    }

    auto sum = 0;
    for (int i = 0; i < student->marks_size(); i++) {
        sum += student->marks(i);
    }

    return (double) sum / student->marks_size();
}

std::string StudentsGroup::getAllInfo(const homework7::FullName &name)
{
    auto student = findStudent(name);

    if (student == nullptr) {
        return "-";
    }

    std::string result = name.first_name() + " " + name.second_name();

    if (name.has_third_name()) {
        result = result + " " + name.third_name();
    }

    result = result + " (score " + std::to_string(getAverageScore(name)) + ")";

    return result;
}

std::string StudentsGroup::getAllInfo()
{
    std::string result;

    for (int i = 0; i < studentsCount; i++) {
        result = result + getAllInfo(students[i].full_name()) + "\n";
    }

    return result;
}

void StudentsGroup::Save(std::ostream *output)
{
    // Не смог установить протобуф по-человечески, потому сериализацию сделать не смог
}

void StudentsGroup::Open(std::istream *input)
{
    // Не смог установить протобуф по-человечески, потому сериализацию сделать не смог
}
