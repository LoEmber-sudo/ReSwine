#pragma once
#include <cstddef> // for size_t ig
#include <vector>

template<typename T>
struct SStack
{
    T* array = nullptr;  
    int size = 0;           
    int maxsize = 0;        
    float userdata = 0.0f;  

    SStack() = default;
    ~SStack() { delete[] array; }
    void push(const T& value)
    {
        if (size >= maxsize)
        {
            int newMax = (maxsize == 0) ? 4 : maxsize * 2;
            T* newArray = new T[newMax];
            if (array)
            {
                for (int i = 0; i < size; ++i)
                    newArray[i] = array[i];
                delete[] array;
            }
            array = newArray;
            maxsize = newMax;
        }
        array[size++] = value;
    }
    void pop() { if (size > 0) --size; }

    T& top() { return array[size - 1]; }
};
