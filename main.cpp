#include "iostream"

#include "Homework8/Task1/CUnit.h"
#include "Homework1/Person.h"
#include "Homework1/PhoneNumber.h"

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
    CUnit::CUnit cUnit;

    { // task 1
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

    { // task 2
        executeTest("persons with and without third name are not equal", cUnit, [](CUnit::CUnit &cUnit) -> void {
            Person person1("First name", "Second name", "Last name");
            Person person2("First name", "Second name");

            cUnit.assertFalse(person1 == person2);
        });

        executeTest("persons are equals", cUnit, [](CUnit::CUnit &cUnit) -> void {
            Person person1("First name", "Second name", "Last name");
            Person person2("First name", "Second name", "Last name");
            cUnit.assertTrue(person1 == person2);
        });

        executeTest("first name return correct result", cUnit, [](CUnit::CUnit &cUnit) -> void {
            Person person1("First name", "Second name", "Last name");
            cUnit.assertEquals(person1.getFirstName(), std::string("First name"));
        });

        executeTest("second name return correct result", cUnit, [](CUnit::CUnit &cUnit) -> void {
            Person person1("First name", "Second name", "Last name");
            cUnit.assertEquals(person1.getSecondName(), std::string("Second name"));
        });

        executeTest("third name return correct result", cUnit, [](CUnit::CUnit &cUnit) -> void {
            Person person1("First name", "Second name", "Last name");
            cUnit.assertEquals(person1.getThirdName().value(), std::string("Last name"));
        });

        executeTest("third name doesn't exist", cUnit, [](CUnit::CUnit &cUnit) -> void {
            Person person1("First name", "Second name");
            cUnit.assertFalse(person1.getThirdName().has_value());
        });

        executeTest("phone numbers are equals", cUnit, [](CUnit::CUnit &cUnit) -> void {
            PhoneNumber phoneNumber1(375, 29, "1234567");
            PhoneNumber phoneNumber2(375, 29, "1234567");
            cUnit.assertEquals(phoneNumber1, phoneNumber2);
        });

        executeTest("phone numbers with and without optional number are not equals", cUnit, [](CUnit::CUnit &cUnit) -> void {
            PhoneNumber phoneNumber1(375, 29, "1234567");
            PhoneNumber phoneNumber2(375, 29, "1234567", 23);
            cUnit.assertNotEquals(phoneNumber1, phoneNumber2);
        });
    }
}
