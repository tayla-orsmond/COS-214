#ifndef CALC_H
#define CALC_H
//Tayla Orsmond u21467456

template <class T>
class Calculator{
    public:
    Calculator(T,T);
    T add();
    T subtract();
    T multiply();
    T divide();

    private:
    T num1, num2;
};
#include "Calculator.cpp"

#endif