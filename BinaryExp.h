//
// Created by schwe on 18/12/2018.
//

#ifndef AP1EX3_BINARYEXP_H
#define AP1EX3_BINARYEXP_H

#include "UnaryExp.h"
class BinaryExp :MathExpression{
protected:
    MathExpression *left;
    MathExpression *right;
public:
    virtual double calculate()=0;
    BinaryExp(MathExpression *a, MathExpression *b) : left(a), right(b){};
};
#endif //AP1EX3_BINARYEXP_H
