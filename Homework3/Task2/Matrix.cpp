#include <exception>
#include <iostream>
#include <cmath>

#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(size_t size, std::vector<T> data)
{
    this->size = size;
    this->data = new T[size * size];

    for (size_t i = 0; i < size * size; i++) {
        this->data[i] = data[i];
    }
}

template<class T>
Matrix<T>::~Matrix<T>()
{
    delete[] data;
}

template<class T>
Matrix<T>::Matrix(Matrix<T> &&matrix) noexcept
{
    size = matrix.size;
    data = new T[size * size];

    for (size_t i = 0; i < size * size; i++) {
        data[i] = matrix.data[i];
    }

    delete[] matrix.data;
}

template<class T>
Matrix<T> &Matrix<T>::operator=(Matrix<T> &&matrix) noexcept
{
    size = matrix.size;
    data = new T[size * size];

    for (size_t i = 0; i < size * size; i++) {
        data[i] = matrix.data[i];
    }

    delete[] matrix.data;
}

template<class T>
void Matrix<T>::setValue(size_t row, size_t column, T value)
{
    if (row < 0 || row >= size || column < 0 || column >= size) {
        throw std::exception();
    }

    data[row * size + column] = value;
}

template<class T>
void Matrix<T>::print()
{
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (j > 0) {
                std::cout << " ";
            }

            std::cout << data[i * size + j];
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

template<class T>
T Matrix<T>::discriminant()
{
    if (size == 2) {
        return data[0] * data[3] - data[1] * data[2];
    }

    if (size == 3) {
        std::vector<T> data11 = {data[4], data[5], data[7], data[8]};
        Matrix<T> matrix11(2, data11);

        std::vector<T> data12 = {data[3], data[5], data[6], data[8]};
        Matrix<T> matrix12(2, data12);

        std::vector<T> data13 = {data[3], data[4], data[6], data[7]};
        Matrix<T> matrix13(2, data13);

        T part11 = data[0] * matrix11.discriminant();
        T part12 = data[1] * matrix12.discriminant();
        T part13 = data[2] * matrix13.discriminant();

        return part11 - part12 + part13;
    }


    T count = 0;
    std::vector<T> partData;
    for (size_t partNumber = 0; partNumber < size; partNumber++) {
        partData.clear();
        for (size_t row = 1; row < size; row++) {
            for (size_t column = 0; column < size; column++) {
                if (column != partNumber) {
                    partData.push_back(data[row * size + column]);
                }
            }
        }

        Matrix<T> partMatrix(size - 1, partData);
        count = count + pow(-1, 1 + (1 + partNumber)) * data[partNumber] * partMatrix.discriminant();
    }

    return count;
}