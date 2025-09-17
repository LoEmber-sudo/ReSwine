#pragma once
#include <Windows.h> // for tagRECT
#include <cstdlib>

struct SDarray {
    int size = 0;
    int maxsize = 0;
    tagRECT* array = nullptr;

    SDarray() = default;

    ~SDarray() {
        delete[] array;
    }

    void reserve(int capacity) {
        if (capacity > maxsize) {
            tagRECT* newArray = new tagRECT[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            maxsize = capacity;
        }
    }

    void push_back(const tagRECT& rect) {
        if (size >= maxsize) {
            reserve(maxsize == 0 ? 4 : maxsize * 2);
        }
        array[size++] = rect;
    }

    tagRECT& operator[](int index) {
        return array[index];
    }

    const tagRECT& operator[](int index) const {
        return array[index];
    }
};
