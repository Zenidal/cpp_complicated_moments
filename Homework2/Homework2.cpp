#include <vector>

template<class T>
void swap(T *&first, T *&second)
{
    T *temp;

    temp = first;
    first = second;
    second = temp;
}

template<class T>
void sortPointers(std::vector<T *> &pointers)
{
    for (size_t i = 0; i < pointers.size() - 1; ++i) {
        for (size_t j = 0; j < pointers.size() - i - 1; j++) {
            if (*pointers[j] > *pointers[j + 1]) {
                swap(pointers[j], pointers[j + 1]);
            }
        }
    }
}
