#include <regex>
#include <fstream>

#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream &stream)
{
    std::string line;

    size_t delimiterPosition;
    std::string name;
    std::string phoneNumber;
    while (std::getline(stream, line)) {
        delimiterPosition = line.find(',');

        if (delimiterPosition > 0) {
            name = line.substr(0, delimiterPosition);
            phoneNumber = line.substr(delimiterPosition, line.size());

            auto subscriber = std::make_pair(PhoneBook::parseName(name), PhoneBook::parsePhone(phoneNumber));

            subscribers.push_back(subscriber);
        }
    }
}

Person PhoneBook::parseName(std::string &name)
{
    size_t firstDelimiterPosition, secondDelimiterPosition;
    std::string firstName;
    std::string secondName;
    std::optional<std::string> thirdName;
    Person person;

    firstDelimiterPosition = name.find(' ', 0);
    secondDelimiterPosition = name.find(' ', firstDelimiterPosition + 1);

    firstName = name.substr(0, firstDelimiterPosition);
    if (secondDelimiterPosition != std::string::npos) {
        secondName = name.substr(firstDelimiterPosition + 1, secondDelimiterPosition - firstDelimiterPosition - 1);
        thirdName = name.substr(secondDelimiterPosition + 1, name.size());

        person = Person(firstName, secondName, thirdName);
    } else {
        secondName = name.substr(firstDelimiterPosition + 1, name.size());

        person = Person(firstName, secondName);
    }

    return person;
}

PhoneNumber PhoneBook::parsePhone(std::string &phone)
{
    std::regex regex("\\+(\\d+)\\((\\d+)\\)(\\d+)\\s?(\\d+)?");
    std::smatch matches;
    std::regex_search(phone, matches, regex);

    int countryCode = std::stoi(matches[1]);
    int cityCode = std::stoi(matches[2]);
    std::string number = matches[3];

    if (matches[4].length() > 0) {
        int additionNumber = std::stoi(matches[4]);

        return {countryCode, cityCode, number, additionNumber};
    } else {
        return {countryCode, cityCode, number};
    }
}

std::ostream &operator<<(std::ostream &os, PhoneBook &phoneBook)
{
    for (auto subscriber: phoneBook.subscribers) {
        os << subscriber.first << ": " << subscriber.second << std::endl;
    }

    return os;
}

void PhoneBook::sortByName()
{
    std::sort(subscribers.begin(), subscribers.end(), [](const std::pair<Person, PhoneNumber> &s1, const std::pair<Person, PhoneNumber> &s2) -> bool {
        if (s1.first.getSecondName() != s2.first.getSecondName()) {
            return s1.first.getSecondName() < s2.first.getSecondName();
        }

        if (s1.first.getFirstName() != s2.first.getFirstName()) {
            return s1.first.getFirstName() < s2.first.getFirstName();
        }

        if (s1.first.getThirdName().has_value() && s2.first.getThirdName().has_value()) {
            return s1.first.getThirdName().value() < s2.first.getThirdName().value();
        }

        return !s1.first.getThirdName().has_value();
    });
}

void PhoneBook::sortByPhone()
{
    std::sort(subscribers.begin(), subscribers.end(), [](const std::pair<Person, PhoneNumber> &s1, const std::pair<Person, PhoneNumber> &s2) -> bool {
        if (s1.second.getCountryCode() != s2.second.getCountryCode()) {
            return s1.second.getCountryCode() < s2.second.getCountryCode();
        }

        if (s1.second.getCityCode() != s2.second.getCityCode()) {
            return s1.second.getCityCode() < s2.second.getCityCode();
        }

        if (s1.second.getNumber() != s2.second.getNumber()) {
            return s1.second.getNumber() < s2.second.getNumber();
        }

        if (s1.second.getAdditionalNumber().has_value() && s2.second.getAdditionalNumber().has_value()) {
            return s1.second.getAdditionalNumber().value() < s2.second.getAdditionalNumber().value();

        }

        return !s1.second.getAdditionalNumber().has_value();
    });
}

std::tuple<std::string, std::optional<PhoneNumber>> PhoneBook::getPhoneNumber(const std::string &secondName) const
{
    int counter = 0;
    PhoneNumber phoneNumber;

    std::for_each(subscribers.begin(), subscribers.end(), [&counter, &phoneNumber, secondName](std::pair<Person, PhoneNumber> s) -> void {
        if (s.first.getSecondName() == secondName) {
            counter++;
            phoneNumber = s.second;
        }
    });

    if (counter == 0) {
        return std::tuple<std::string, std::optional<PhoneNumber>>("not found", phoneNumber);
    }

    if (counter == 1) {
        return std::tuple<std::string, std::optional<PhoneNumber>>("", phoneNumber);
    }

    return std::tuple<std::string, std::optional<PhoneNumber>>("found more than 1", phoneNumber);
}

void PhoneBook::changePhoneNumber(const Person &person, PhoneNumber &phoneNumber)
{
    auto subscriber = std::find_if(subscribers.begin(), subscribers.end(), [person](const std::pair<Person, PhoneNumber> &subscriber) -> bool {
        return subscriber.first == person;
    });

    if (subscriber != subscribers.end()) {
        subscriber->second = phoneNumber;
    }
}