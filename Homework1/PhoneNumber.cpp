#include "PhoneNumber.h"

std::ostream &operator<<(std::ostream &os, PhoneNumber &phoneNumber)
{
    os << "+" << phoneNumber.countryCode << "(" << phoneNumber.cityCode << ")" << phoneNumber.number;

    if (phoneNumber.additionalNumber.has_value()) {
        os << " " << phoneNumber.additionalNumber.value();
    }

    return os;
}

PhoneNumber::PhoneNumber(int countryCode, int cityCode, std::string number) : countryCode(countryCode), cityCode(cityCode), number(number)
{}

PhoneNumber::PhoneNumber(int countryCode, int cityCode, std::string number, int additionalNumber) : countryCode(countryCode), cityCode(cityCode), number(number),
                                                                                                           additionalNumber(additionalNumber)
{}

int PhoneNumber::getCountryCode() const
{
    return countryCode;
}

int PhoneNumber::getCityCode() const
{
    return cityCode;
}

const std::string &PhoneNumber::getNumber() const
{
    return number;
}

const std::optional<int> &PhoneNumber::getAdditionalNumber() const
{
    return additionalNumber;
}

bool operator==(PhoneNumber phoneNumber1, PhoneNumber phoneNumber2)
{
    bool isEqual = phoneNumber1.countryCode == phoneNumber2.countryCode && phoneNumber1.cityCode == phoneNumber2.cityCode && phoneNumber1.number == phoneNumber2.number;

    if (phoneNumber1.additionalNumber.has_value() && phoneNumber2.additionalNumber.has_value()) {
        return isEqual && phoneNumber1.additionalNumber.value() == phoneNumber2.additionalNumber.value();
    } else if (!phoneNumber1.additionalNumber.has_value() && !phoneNumber2.additionalNumber.has_value()) {
        return isEqual;
    } else {
        return false;
    }
}