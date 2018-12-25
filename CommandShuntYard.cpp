//
// Created by schwe on 24/12/2018.
//

#include "CommandShuntYard.h"
class CommandShuntYard{
    //constructor
        CommandShuntYard::CommandShuntYard(list<string>newCommand)){
    list<string> operators={"bind","var","="};

};

const stack<string> CommandShuntYard::getOperatorStack()  {
    return operatorStack;
}

void CommandShuntYard::setOperatorStack( stack<string> operatorStack) {
    CommandShuntYard::operatorStack = operatorStack;
}

const stack<string> CommandShuntYard::getOutputStack()  {
    return outputStack;
}

void CommandShuntYard::setOutputStack( stack<string> outputStack) {
    CommandShuntYard::outputStack = outputStack;
}

};