#ifndef CPP_COMPLICATED_MOMENTS_PHONENUMBER_H
#define CPP_COMPLICATED_MOMENTS_PHONENUMBER_H

#include <string>
#include <optional>
#include <ostream>

struct PhoneNumber
{
    private:
        int countryCode;
        int cityCode;
        std::string number;
        std::optional<int> additionalNumber;

    public:
        PhoneNumber() = default;

        PhoneNumber(int countryCode, int cityCode, std::string number);

        PhoneNumber(int countryCode, int cityCode, std::string number, int additionalNumber);

        friend std::ostream &operator<<(std::ostream &os, PhoneNumber &phoneNumber);

        int getCountryCode() const;

        int getCityCode() const;

        const std::string &getNumber() const;

        const std::optional<int> &getAdditionalNumber() const;

        friend bool operator==(PhoneNumber phoneNumber1, PhoneNumber phoneNumber2);
};


#endif //CPP_COMPLICATED_MOMENTS_PHONENUMBER_H
