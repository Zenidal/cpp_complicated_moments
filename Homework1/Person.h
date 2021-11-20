#ifndef CPP_COMPLICATED_MOMENTS_PERSON_H
#define CPP_COMPLICATED_MOMENTS_PERSON_H

#include <string>
#include <optional>
#include <ostream>

struct Person
{
    private:
        std::string firstName;
        std::string secondName;
        std::optional<std::string> thirdName;
    public:
        const std::string &getFirstName() const;

        const std::string &getSecondName() const;

        const std::optional<std::string> &getThirdName() const;

        Person() = default;

        Person(const std::string &firstName, const std::string &secondName);

        Person(const std::string &firstName, const std::string &secondName, const std::optional<std::string> &thirdName);

        friend std::ostream &operator<<(std::ostream &os, Person &person);

        friend bool operator==(const Person& p1, const Person& p2);
};


#endif //CPP_COMPLICATED_MOMENTS_PERSON_H
