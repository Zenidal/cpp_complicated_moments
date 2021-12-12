#ifndef CPP_COMPLICATED_MOMENTS_CUNIT_H
#define CPP_COMPLICATED_MOMENTS_CUNIT_H

#include <functional>
#include <string>
#include <cmath>

#include "CunitExceptionFormatter.h"
#include "AssertFailedException.h"

/**
 * Не смог почему-то реализовать специализацию для вещественных чисел, что не пробовал.
 * Также не вышло отображать корректно сообщения для нецелых чисел и строк, по сути всё из-за той же специализации.
 */
namespace CUnit
{
    class CUnit
    {
        private:
            CunitExceptionFormatter exceptionFormatter;

        public:
            CUnit();

            void assertTrue(bool condition);

            void assertFalse(bool condition);

            template<class T>
            void assertEquals(T value1, T value2)
            {
                if (value1 != value2) {
                    throw AssertFailedException(exceptionFormatter.getEqualsMessage(value1, value2));
                }
            }

            template<class T>
            void assertLessThan(T value1, T value2)
            {
                if (value1 >= value2) {
                    throw AssertFailedException(exceptionFormatter.getLessMessage(value1, value2));
                }
            }

            template<class T>
            void assertLessThanOrEqual(T value1, T value2)
            {
                if (value1 > value2) {
                    throw AssertFailedException(exceptionFormatter.getLessOrEqualMessage(value1, value2));
                }
            }

            template<class T>
            void assertGreaterThan(T value1, T value2)
            {
                if (value1 <= value2) {
                    throw AssertFailedException(exceptionFormatter.getGreaterMessage(value1, value2));
                }
            }

            template<class T>
            void assertGreaterThanOrEqual(T value1, T value2)
            {
                if (value1 < value2) {
                    throw AssertFailedException(exceptionFormatter.getGreaterOrEqualMessage(value1, value2));
                }
            }

            // попытался хоть как-то сравнить исключения, но по факту это жуткий велосипед, который непонятно как и когда работает
            template<class Function>
            void expectException(Function testCase, const std::string &exceptionType)
            {
                try {
                    testCase();
                } catch (...) {
                    std::exception_ptr p = std::current_exception();
                    std::string currentExceptionType = p ? p.__cxa_exception_type()->name() : "";

                    if (exceptionType == currentExceptionType) {
                        return;
                    }

                    throw AssertFailedException(exceptionFormatter.getExceptionMessage(exceptionType, currentExceptionType));
                }

                throw AssertFailedException(exceptionFormatter.getExceptionMessage(exceptionType));
            }
    };
}


#endif //CPP_COMPLICATED_MOMENTS_CUNIT_H
