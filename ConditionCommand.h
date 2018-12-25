//
// Created by schwe on 18/12/2018.
//

#ifndef AP1EX3_CONDITIONCOMMAND_H
#define AP1EX3_CONDITIONCOMMAND_H

#include "Command.h"
#include "MathExpression.h"
#include <string>
/**
 * ConditionCommand::
 * This function receives two Expressions, and a Condition between them, it checks
 * if the given condition 'exists' (i.e is true of false) between the 2 given Expressions
 * @param MathExpression left,right; Command ConditionOperator
 * @return
 */
class ConditionCommand : Command {
protected:
    MathExpression *left;
    MathExpression *right;
    bool condition;
public:
    ConditionCommand(MathExpression *left, MathExpression *right){};
     int execute(){};

    //getter
    bool isCondition() const {
        return condition;
    }

    //setter
    void setCondition(bool condition) {
        ConditionCommand::condition = condition;
    }

    //getter
    MathExpression *getLeft() const {
        return left;
    }
//setter
    void setLeft(MathExpression *left) {
        ConditionCommand::left = left;
    }
//getter
    MathExpression *getRight() const {
        return right;
    }
//setter
    void setRight(MathExpression *right) {
        ConditionCommand::right = right;
    }
};
#endif //AP1EX3_CONDITIONCOMMAND_H
