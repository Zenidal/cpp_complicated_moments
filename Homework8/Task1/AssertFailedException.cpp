#include "AssertFailedException.h"

namespace CUnit
{
    const char *AssertFailedException::what() const noexcept
    {
        return message.c_str();
    }
}