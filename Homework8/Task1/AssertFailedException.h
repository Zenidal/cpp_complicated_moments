#ifndef CPP_COMPLICATED_MOMENTS_ASSERTFAILEDEXCEPTION_H
#define CPP_COMPLICATED_MOMENTS_ASSERTFAILEDEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

namespace CUnit
{
    class AssertFailedException : public std::exception
    {
        private:
            std::string message;

        public:
            explicit AssertFailedException(const std::string &message) : message(message)
            {};

            [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
    };
}


#endif //CPP_COMPLICATED_MOMENTS_ASSERTFAILEDEXCEPTION_H
