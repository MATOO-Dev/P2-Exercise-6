#pragma once

class BeautilfulFunction
{
public:
    template<class S, class T, int var> static S f(T x, S y);
};




class adjustedInt
{
private:
    int value;
public:
    adjustedInt(double var) : value(var) {}
    int getValue() {return value;}
    int compute(double x) { return value + x; }
    int compute(adjustedInt x, adjustedInt y) {return x.value + y.value;}
};