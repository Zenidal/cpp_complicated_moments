#ifndef CPP_COMPLICATED_MOMENTS_INTEGERS_H
#define CPP_COMPLICATED_MOMENTS_INTEGERS_H

#include <iostream>

class Integers
{
    public:
        Integers(int *values, size_t size);

        class Iterator
        {
            public:
                explicit Iterator(int *pointer) : pointer(pointer)
                {}

                int &operator*();

                int *operator->();

                Iterator &operator++();

                Iterator operator++(int);

                bool operator==(Iterator iterator);

                bool operator!=(Iterator iterator);

            private:
                int *pointer;
        };

        Iterator begin() const;

        Iterator end() const;


        // для преподавателя. По возможности напишите, как бы выглядел этот код в cpp файле (не нашёл, как должна выглядеть сигнатура при переносе этого кода в cpp)
        template<class Function>
        void iterate(Function f) const
        {
            for (auto element: *this) {
                f(element);
            }
        }
    private:
        int *values;
        size_t size;
};


#endif //CPP_COMPLICATED_MOMENTS_INTEGERS_H
