//
// Created by schwe on 20/12/2018.
//

#ifndef PROJECTUPDATED_SHUNTYARD_H
#define PROJECTUPDATED_SHUNTYARD_H

#include <string>
#include <stack>
#include <map>
using namespace std;

class MathShuntYard {
    //members
    stack<string> operatorList;
    stack<string> outputList;
public:
    //constructor
    MathShuntYard(string mathEquation);

    //destructor
    virtual ~MathShuntYard();

    const stack<string> &getOperatorList() const;

    const stack<string> &getOutputList() const;
};


#endif //PROJECTUPDATED_SHUNTYARD_H
