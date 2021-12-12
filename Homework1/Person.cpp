#include "Person.h"

Person::Person(const std::string &firstName, const std::string &secondName) : firstName(firstName), secondName(secondName)
{}

Person::Person(const std::string &firstName, const std::string &secondName, const std::optional<std::string> &thirdName) : firstName(firstName), secondName(secondName),
                                                                                                                           thirdName(thirdName)
{}

std::ostream &operator<<(std::ostream &os, Person &person)
{
    os << person.firstName << " " << person.secondName;

    if (person.thirdName.has_value()) {
        os << " " << person.thirdName.value();
    }

    return os;
}

bool operator==(const Person& p1, const Person& p2)
{
    bool isEqual = p1.getSecondName() == p2.getSecondName() && p1.getFirstName() == p2.getFirstName();

    if (p1.getThirdName().has_value() && p2.getThirdName().has_value()) {
        return isEqual && p1.getThirdName().value() == p2.getThirdName().value();
    } else if (!p1.getThirdName().has_value() && !p2.getThirdName().has_value()) {
        return isEqual;
    } else {
        return false;
    }
}

const std::string &Person::getFirstName() const
{
    return firstName;
}

const std::string &Person::getSecondName() const
{
    return secondName;
}

const std::optional<std::string> &Person::getThirdName() const
{
    return thirdName;
}
