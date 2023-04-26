#pragma once
#include <cstring>
#include <iostream>

template<class T, unsigned int sizeFakt, unsigned int initialSize>
class FlexArray
{
private:
    T* data;
    unsigned int size;
    T defaultValue;
public:
    FlexArray<T, sizeFakt, initialSize>(T deafultV);
    ~FlexArray();
    unsigned int length() {return size;}
    T get(int index);
    void set (unsigned int index, T val);
    void enlarge();
    void exchange(unsigned int i, unsigned int j);
};