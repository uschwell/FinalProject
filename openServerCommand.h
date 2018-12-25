//
// Created by David Goldberg on 2018-12-23.
//

#ifndef PROJECTUPDATED_OPENSERVERCOMMAND_H
#define PROJECTUPDATED_OPENSERVERCOMMAND_H
using namespace std;

#include "DoCommand.h"

class openServerCommand : public DoCommand {
    // members declarations
    string param1;
    string param2;
public:
    openServerCommand(string param1, string param2);
    int execute();
};


#endif //PROJECTUPDATED_OPENSERVERCOMMAND_H
