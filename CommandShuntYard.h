//
// Created by schwe on 24/12/2018.
//

#ifndef PROJECTUPDATED_COMMANDSHUNTYARD_H
#define PROJECTUPDATED_COMMANDSHUNTYARD_H

#include <string>
#include <stack>
using namespace std;
class CommandShuntYard {
protected:
    stack<string> operatorStack;
    stack <string> outputStack
public:
    CommandShuntYard(stack<string> operatorStack, stack<string> outputStack){};

    const stack<string> getOperatorStack();

    void setOperatorStack( stack<string> operatorStack);

    const stack<string> getOutputStack();

    void setOutputStack( stack<string> outputStack);
};


#endif //PROJECTUPDATED_COMMANDSHUNTYARD_H
