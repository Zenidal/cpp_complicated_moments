#include <iostream>
#include <fstream>
#include <string>

#include "Homework1/PhoneBook.h"

int main()
{
    std::ifstream stream;
    stream.open("phones.txt");

    PhoneBook phoneBook(stream);
    std::cout << phoneBook << std::endl;

    phoneBook.sortByName();
    std::cout << phoneBook << std::endl;

    phoneBook.sortByPhone();
    std::cout << phoneBook << std::endl;

    auto[description, phoneNumber] = phoneBook.getPhoneNumber("Miskevich");
    std::cout << "Description: " << description << std::endl;
    if (phoneNumber.has_value()) {
        std::cout << phoneNumber.value() << std::endl;
    }

    std::cout << std::endl;

    auto newPhoneNumber = PhoneNumber(7, 911, "1234567", 12);
    phoneBook.changePhoneNumber(Person("Alexandr", "Miskevich", "Yaroslavovich"), newPhoneNumber);
    std::cout << phoneBook;
}
