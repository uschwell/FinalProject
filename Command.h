//
// Created by schwe on 18/12/2018.
//

#ifndef AP1EX3_COMMAND_H
#define AP1EX3_COMMAND_H

#include <string>
class Command {
public:
  virtual int execute() =0;
};

#endif //AP1EX3_COMMAND_H
