#include "iostream"

#include "Homework8/Task1/CUnit.h"

template<class Lambda>
void executeTest(const std::string &caseName, CUnit::CUnit &cUnit, Lambda testCase)
{
    bool testCaseFailed = false;

    try {
        testCase(cUnit);
    } catch (CUnit::AssertFailedException &exception) {
        testCaseFailed = true;

        std::cerr << "[" + caseName + "] - " << exception.what() << std::endl;
    } catch (...) {
        testCaseFailed = true;
    }

    if (!testCaseFailed) {
        std::cout << "[" + caseName + "] - OK." << std::endl;
    }
}

int main()
{
    { // task 1
        CUnit::CUnit cUnit;

        executeTest("assert equals passed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertEquals(6, 6);
        });
        executeTest("assert equals failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertEquals(5, 6);
        });

        executeTest("assert equals with string passed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertEquals("string 1", "string 1");
        });
        executeTest("assert equals with string failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertEquals("string 1", "string 2");
        });

        executeTest("assert equals with double passed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertEquals(6.0, 6.0);
        });
        executeTest("assert equals with double failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertEquals(6.1, 6.0);
        });

        executeTest("assert less than passed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertLessThan(5, 6);
        });
        executeTest("assert less than failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertLessThan(6, 6);
        });

        executeTest("assert true passed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertTrue(5 == 5);
        });
        executeTest("assert true failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertTrue(6 == 5);
        });

        executeTest("assert false passed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertFalse(6 == 5);
        });
        executeTest("assert false failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.assertFalse(5 == 5);
        });

        auto e = std::exception();
        executeTest("expect exception passed", cUnit, [e](CUnit::CUnit &cUnit) -> void {
            cUnit.expectException([e]() {
                throw e;
            }, typeid(e).name());
        });
        executeTest("expect exception is invalid", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.expectException([]() {
                throw std::runtime_error("runtime_exception");
            }, typeid(std::exception()).name());
        });
        executeTest("expect exception failed", cUnit, [](CUnit::CUnit &cUnit) -> void {
            cUnit.expectException([]() {
            }, typeid(std::exception()).name());
        });
    }
}
