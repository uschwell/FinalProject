//
// Created by schwe on 23/12/2018.
//

#ifndef PROJECTUPDATED_MULTICOMMANC_H
#define PROJECTUPDATED_MULTICOMMANC_H

#include "Command.h"
#include <list>

/**
 * MultiCommand:
 * This function receives (or adds to/removes from) a list of several Commands
 * upon 'execute' it will execute the entire list of given commands
 * @param list<Command> *toDo
 * @return
 */
class MultiCommand : Command {
protected:
    std::list<Command> *commandsToDo;
public:
    //constructor
    MultiCommand(std::list<Command> &commandsToDo) : commandsToDo(commandsToDo) {}

    //constructor
    MultiCommand() {
        this->commandsToDo = new std::list<Command>;
    }

    //getter
    std::list<Command> *getCommandsToDo() {
        return commandsToDo;
    }

    //setter
    void setCommandsToDo(std::list<Command> &commandsToDo) {
        MultiCommand::commandsToDo = commandsToDo;
    }

    /**
 * execute:
 * Function iterates over entire list and 'executes' each Command
 * @param
 * @return
 */
    int execute() {
        for (Command index=commandsToDo->begin();index!=commandsToDo->end();++index){
                Command *commandBuffer= *index;
                commandBuffer.execute();
        }
            //as always we return the AMOUNT of arguements we have just executed
            return commandsToDo->size();
    }

public:
/**
 * addCommand:
 * This function adds a new command to the 'toDo' list
 * @param doCommand;
 * @return
 */
    void addCommand(Command newCommand) {
        commandsToDo.push_back(newCommand);
    };

/**
 * removeCommand:
 * This function removes a command from the 'toDo' list
 * @param toRemove
 * @return
 */
    void removeCommand(Command toRemove) {
        commandsToDo.remove(toRemove);
    };


};


#endif //PROJECTUPDATED_MULTICOMMANC_H
