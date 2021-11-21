#include <list>
#include <iostream>

#include "Homework3/Task2/Matrix.h"
#include "Homework3/Task2/Matrix.cpp"
#include "Homework3/Task3/Integers.h"

void appendAverage(std::list<float> &floatValues)
{
    float sum = 0;

    for (auto element: floatValues) {
        sum += element;
    }

    float average = sum / (float) floatValues.size();

    floatValues.push_back(average);
}

void showList(const std::list<float> &floatValues)
{
    for (auto element: floatValues) {
        std::cout << element << " ";
    }

    std::cout << std::endl;
}

int main()
{
    { // task 1
        std::list<float> floatValues;
        floatValues.push_back(4.35f);
        floatValues.push_back(3.84f);
        floatValues.push_back(-3.5f);

        showList(floatValues);

        appendAverage(floatValues);
        appendAverage(floatValues);

        showList(floatValues);
    }

    std::cout << std::endl;

    { // task 2
        std::vector<size_t> data = {
            3, 4, 3, 5, 23,
            6, 23, 1, 0, 62,
            7, 8, 0, 35, 21,
            2, 32, 35, 1, 53
        };
        Matrix<size_t> matrix(5, data);
        matrix.print();

        std::cout << "Discriminant: " << matrix.discriminant() << std::endl;
    }

    std::cout << std::endl;

    { // task 3
        int values[] = {1, 4, 5, 8};
        Integers integers(values, 4);

        for (auto integer: integers) {
            std::cout << integer << " ";
        }

        std::cout << std::endl;

        int sum = 0;
        integers.iterate([&sum](int value) -> void const {
            sum += value;
        });

        std::cout << "Sum of elements: " << sum << std::endl;
    }
}
