//
// Created by David Goldberg on 2018-12-23.
//

#ifndef PROJECTUPDATED_COMMANDEXPRESSION_H
#define PROJECTUPDATED_COMMANDEXPRESSION_H


#include "MathExpression.h"
#include "Command.h"

class commandExpression : public MathExpression {
    Command command;
public:
    double calculate(){
        command->execute();
    }
};

#endif //PROJECTUPDATED_COMMANDEXPRESSION_H
