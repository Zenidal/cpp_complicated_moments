#include "CUnit.h"

namespace CUnit
{
    CUnit::CUnit()
    {
        exceptionFormatter = CunitExceptionFormatter();
    }

    void CUnit::assertTrue(bool condition)
    {
        if (!condition) {
            throw AssertFailedException(exceptionFormatter.getTrueMessage());
        }
    }

    void CUnit::assertFalse(bool condition)
    {
        if (condition) {
            throw AssertFailedException(exceptionFormatter.getFalseMessage());
        }
    }
}