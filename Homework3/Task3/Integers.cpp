#include "Integers.h"

Integers::Iterator Integers::begin() const
{
    return Integers::Iterator(&values[0]);
}

Integers::Iterator Integers::end() const
{
    return Integers::Iterator(&values[size]);
}

Integers::Integers(int *values, size_t size) : values(values), size(size)
{}

int &Integers::Iterator::operator*()
{
    return *pointer;
}

int *Integers::Iterator::operator->()
{
    return pointer;
}

Integers::Iterator &Integers::Iterator::operator++()
{
    pointer++;

    return *this;
}

Integers::Iterator Integers::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

bool Integers::Iterator::operator==(Iterator iterator)
{
    return iterator.pointer == this->pointer;
}

bool Integers::Iterator::operator!=(Iterator iterator)
{
    return !(iterator == *this);
}