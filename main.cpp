#include <iostream>

#include "Homework2/Task1/Task1.cpp"

int main()
{
    { // task 1
        int x = 1;
        int y = 2;

        int *xPtr;
        xPtr = &x;
        int *yPtr;
        yPtr = &y;

        auto printVariablesInfo = [&x, &y, &xPtr, &yPtr]() -> void {
            std::cout << "x ref: " << &x << std::endl << "y ref: " << &y << std::endl << "x ptr: " << xPtr << std::endl << "y ptr: " << yPtr << std::endl;
        };

        printVariablesInfo();

        swap(xPtr, yPtr);

        std::cout << std::endl;

        printVariablesInfo();
    }
}
