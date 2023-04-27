#include "../include/FlexArray.h"

template<class T, unsigned int sizeFakt, unsigned int initialSize>
FlexArray<T, sizeFakt, initialSize>::FlexArray(T defaultV)
{
    size = initialSize;
    data = new T[size];
    defaultValue = defaultV;

    for(int i = 0; i < size; i++)
        set(i, defaultValue);
}

template<class T, unsigned int sizeFakt, unsigned int initialSize>
FlexArray<T, sizeFakt, initialSize>::~FlexArray()
{
    delete[] data;
}

template<class T, unsigned int sizeFakt, unsigned int initialSize>
T FlexArray<T, sizeFakt, initialSize>::get(int index)
{
    while(index > size - 1)
    {
        enlarge();
    }
    return data[index];
}

template<class T, unsigned int sizeFakt, unsigned int initialSize>
void FlexArray<T, sizeFakt, initialSize>::set (unsigned int index, T val)
{
    while(index > size -1)
    {
        enlarge();
    }
    data[index] = val;
}

template<class T, unsigned int sizeFakt, unsigned int initialSize>
void FlexArray<T, sizeFakt, initialSize>::enlarge()
{
    T* enlargedArray = new T[size * sizeFakt];


    for(int i = 0; i < size * sizeFakt; i++)
        enlargedArray[i] = defaultValue;
    
    for(int i = 0; i < size; i++)
        enlargedArray[i] = data[i];

    //switch arrays and free unused memory
    delete data;
    data = enlargedArray;
    enlargedArray = nullptr;
    delete[] enlargedArray;

    size = size * sizeFakt;
}

template<class T, unsigned int sizeFakt, unsigned int initialSize>
void FlexArray<T, sizeFakt, initialSize>::exchange(unsigned int i, unsigned int j)
{
    T tempValue = data[i];
    data[i] = data[j];
    data[j] = tempValue;
}