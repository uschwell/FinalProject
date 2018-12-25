//
// Created by David Goldberg on 2018-12-17.
//
#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
#include "Command.h"

#ifndef PROJECT_TRANSLATOR_H
#define PROJECT_TRANSLATOR_H

using namespace std;

class Translator {
    // members declarations
    map<string, Command> symbolTable;

public:
    // constructor and functions declarations
    Translator(map<string, Command> symbolTable);
    void parser(list<string> strLst);
    list<string> lexer(string str);
};

#endif //PROJECT_TRANSLATOR_H
