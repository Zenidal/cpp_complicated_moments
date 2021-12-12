#ifndef CPP_COMPLICATED_MOMENTS_PHONEBOOK_H
#define CPP_COMPLICATED_MOMENTS_PHONEBOOK_H

#include <vector>
#include <iostream>
#include <tuple>

#include "PhoneNumber.h"
#include "Person.h"

class PhoneBook
{
    private:
        std::vector<std::pair<Person, PhoneNumber>> subscribers;

        static Person parseName(std::string &name);

        static PhoneNumber parsePhone(std::string &phone);

    public:
        explicit PhoneBook(std::ifstream &stream);

        friend std::ostream &operator<<(std::ostream &os, PhoneBook &phoneBook);

        void sortByName();

        void sortByPhone();

        std::tuple<std::string, std::optional<PhoneNumber>> getPhoneNumber(const std::string &secondName) const;

        void changePhoneNumber(const Person &person, PhoneNumber &phoneNumber);
};


#endif //CPP_COMPLICATED_MOMENTS_PHONEBOOK_H
