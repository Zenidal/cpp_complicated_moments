#ifndef CPP_COMPLICATED_MOMENTS_CUNITEXCEPTIONFORMATTER_H
#define CPP_COMPLICATED_MOMENTS_CUNITEXCEPTIONFORMATTER_H

#include <string>
#include <cstdio>

#include <iostream>

namespace CUnit
{
    class CunitExceptionFormatter
    {
        private:
            std::string equalsMessageFormat = "Expected value should be: '%d', got '%d'.";
            std::string lessMessageFormat = "Expected value '%d' should be less than '%d'.";
            std::string lessOrEqualMessageFormat = "Expected value '%d' should be less or equal to '%d'.";
            std::string greaterMessageFormat = "Expected value '%d' should be greater than '%d'.";
            std::string greaterOrEqualMessageFormat = "Expected value '%d' should be greater or equal to '%d'.";
            std::string trueMessageFormat = "Condition doesn't equal to true.";
            std::string falseMessageFormat = "Condition doesn't equal to false.";
            std::string invalidExceptionTypeMessageFormat = "Expected exception with type: '%s', got '%s'.";
            std::string missingExceptionMessageFormat = "Expected exception with type: '%s'.";
        public:
            template<class T>
            std::string getEqualsMessage(T value1, T value2)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, equalsMessageFormat.c_str(), value1, value2);

                return message;
            }

            template<class T>
            std::string getLessMessage(T value1, T value2)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, lessMessageFormat.c_str(), value1, value2);

                return message;
            }

            template<class T>
            std::string getLessOrEqualMessage(T value1, T value2)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, lessOrEqualMessageFormat.c_str(), value1, value2);

                return message;
            }

            template<class T>
            std::string getGreaterMessage(T value1, T value2)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, greaterMessageFormat.c_str(), value1, value2);

                return message;
            }

            template<class T>
            std::string getGreaterOrEqualMessage(T value1, T value2)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, greaterOrEqualMessageFormat.c_str(), value1, value2);

                return message;
            }

            std::string getTrueMessage()
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, trueMessageFormat.c_str());

                return message;
            }

            std::string getFalseMessage()
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, falseMessageFormat.c_str());

                return message;
            }

            std::string getExceptionMessage(const std::string &expectedType)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, missingExceptionMessageFormat.c_str(), expectedType.c_str());

                return message;
            }

            std::string getExceptionMessage(const std::string &expectedType, const std::string &currentType)
            {
                const int messageLength = 256;
                char message[messageLength];

                snprintf(message, messageLength, invalidExceptionTypeMessageFormat.c_str(), expectedType.c_str(), currentType.c_str());

                return message;
            }
    };
}


#endif //CPP_COMPLICATED_MOMENTS_CUNITEXCEPTIONFORMATTER_H
