#ifndef CPP_COMPLICATED_MOMENTS_MATRIX_H
#define CPP_COMPLICATED_MOMENTS_MATRIX_H

#include <iostream>
#include <vector>

template<class T>
class Matrix
{
    private:
        T *data;
        size_t size;

    public:
        Matrix() : size(0)
        {
            data = {};
        }

        Matrix(size_t size, std::vector<T> data);

        ~Matrix();

        Matrix(const Matrix &matrix) = delete;

        Matrix(Matrix &&matrix) noexcept;

        Matrix &operator=(const Matrix &matrix) = delete;

        Matrix &operator=(Matrix &&matrix) noexcept;

        void setValue(size_t row, size_t column, T value);

        void print();

        T discriminant();
};


#endif //CPP_COMPLICATED_MOMENTS_MATRIX_H
