#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <iostream>
#include <cmath>

template<class Container>
void printContainer(Container &container)
{
    for (auto element: container) {
        std::cout << element << " ";
    }

    std::cout << std::endl;
}

template<class Container, class Type>
void insertSorted(Container &sortedContainer, Type insertingValue)
{
    auto it = std::upper_bound(sortedContainer.begin(), sortedContainer.end(), insertingValue);

    if (it != sortedContainer.end()) {
        std::inserter(sortedContainer, it) = insertingValue;
    } else {
        std::inserter(sortedContainer, sortedContainer.end()) = insertingValue;
    }
}

void fillAnalog(std::vector<double> &analogVector, double min, double max)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distribution(min, max);

    std::generate(analogVector.begin(), analogVector.end(), [&distribution, &eng]() {
        return distribution(eng);
    });
}

void fillDigit(const std::vector<double> &analogVector, std::vector<int> &digitVector)
{
    std::transform(analogVector.begin(), analogVector.end(), std::back_inserter(digitVector), [](double value) -> int {
        return (int) value;
    });
}

double getDigitError(const std::vector<double> &analogVector, const std::vector<int> &digitVector)
{
    std::cout << std::endl;

    double error = 0.0;

    return std::inner_product(
        analogVector.begin(),
        analogVector.end(),
        digitVector.begin(),
        error,
        [](double value1, double value2) -> double {
            return value1 + value2;
        },
        [](double value1, int value2) -> double {
            return pow(value1 - (double) value2, 2);
        }
    );
}

int main()
{
    { // task 1
        std::vector<int> intVector({10, 20, 20, 30, 40, 50});
        printContainer(intVector);
        insertSorted(intVector, 45);
        printContainer(intVector);


        std::list<double> doubleList({1.5, 20.0, 21.0, 30.4, 40.0, 50});
        printContainer(doubleList);
        insertSorted(doubleList, 45);
        printContainer(doubleList);
    }

    { // task 2
        std::vector<double> analogVector(100);
        fillAnalog(analogVector, 0.0, 10.0);
        printContainer(analogVector);

        std::vector<int> digitVector;
        fillDigit(analogVector, digitVector);
        printContainer(digitVector);

        std::cout << "Calculation error: " << getDigitError(analogVector, digitVector) << std::endl;
    }
}
