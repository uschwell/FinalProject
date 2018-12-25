//
// Created by David Goldberg on 2018-12-17.
//

using namespace std;

#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
#include <fstream>
#include "Command.h"
#include "Translator.h"

#define ENDOFSTRING '\0'
#define SPACE ' '


/**
 * This is a constructor
 * @param symbolTable
 */
Translator::Translator(map<string, Command> symbolTable) {
    this->symbolTable = symbolTable;
}


///**
/**
 * This function breaks the text into words (expressions) in a list of strings
 * @param file
 * @return list of expression
 */

list<string> Translator::lexer(string str) {
    string strTmp; // temporary string for holding the chars
    list<string> strLst; // the return value
    int i = 0; // index
    string newStr = str;
    string strStart, strEnd;

    // first iteration for fixing the spaces issues
    while (newStr[i] != ENDOFSTRING) {
        // pad with spaces around '='
        if (newStr[i] == '=') {
            int opIndex = i; // index of operator char in string
            string strStart, strEnd;
            if (newStr[opIndex - 1] != SPACE) { // if there is no space before operator
                strStart = newStr.substr(0, opIndex); // start of string
                strStart.push_back(SPACE); // push space char
                strEnd = newStr.substr(opIndex, newStr.length() - opIndex); // end of string
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                opIndex++;
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
            if (newStr[opIndex + 1] != SPACE) { // if there is no space after operator
                strStart = newStr.substr(0, opIndex + 1); // start of string
                strStart.push_back(SPACE); // push space char
                strEnd = newStr.substr(opIndex + 1, newStr.length() - opIndex); // end of string
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
            // a special case for '=' and '-' next to each other
            if (newStr[opIndex + 1] == '-' || newStr[opIndex + 2] == '-') {
                strStart = newStr.substr(0, opIndex + 1); // start of string
                strStart.push_back(SPACE); // push space char
                strEnd = newStr.substr(opIndex + 1, newStr.length() - opIndex); // end of string
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
        }

        // delete spaces around these operators: +, /, *, <, >
        if ((newStr[i] == '+') || (newStr[i] == '/') ||
            (newStr[i] == '*') || (newStr[i] == '<') || (newStr[i] == '>')) {
            int opIndex = i; // index of operator char in string
            if (newStr[opIndex - 1] == SPACE) { // if there is a space before operator
                strStart = newStr.substr(0, opIndex - 1); // start of string (skip the space char)
                strEnd = newStr.substr(opIndex, newStr.length() - opIndex); // end of string
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                opIndex--;
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
            if (newStr[opIndex + 1] == SPACE) { // if there is a space after operator
                strStart = newStr.substr(0, opIndex + 1); // start of string
                strEnd = newStr.substr(opIndex + 2,
                                       newStr.length() - (opIndex + 1)); // end of string (skip the space char)
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
        }

        // a special case for '(' and ')'
        if(newStr[i] == '(') {
            int leftBracketInd = i;
            if (newStr[leftBracketInd + 1] == SPACE) { // if there is a space after '('
                strStart = newStr.substr(0, leftBracketInd + 1); // start of string
                strEnd = newStr.substr(leftBracketInd + 2,
                                       newStr.length() - (leftBracketInd + 1)); // end of string (skip the space char)
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
        }
        if(newStr[i] == ')'){
            int rightBracketInd = i;
            if (newStr[rightBracketInd - 1] == SPACE) { // if there is a space before ')'
                strStart = newStr.substr(0, rightBracketInd - 1); // start of string (skip the space char)
                strEnd = newStr.substr(rightBracketInd, newStr.length() - rightBracketInd); // end of string
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                rightBracketInd--;
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
        }

        // a special case for minus operator
        if (newStr[i] == '-' && ((newStr[i - 1] != ',') || (newStr[i - 2] != ','))) {
            int minusInd = i; // index of operator char in string
            if (newStr[minusInd - 1] == SPACE) { // if there is a space before operator
                strStart = newStr.substr(0, minusInd - 1); // start of string (skip the space char)
                strEnd = newStr.substr(minusInd, newStr.length() - minusInd); // end of string
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                minusInd--;
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
            if (newStr[minusInd + 1] == SPACE) { // if there is a space after operator
                strStart = newStr.substr(0, minusInd + 1); // start of string
                strEnd = newStr.substr(minusInd + 2,
                                       newStr.length() - (minusInd + 1)); // end of string (skip the space char)
                newStr = strStart.append(strEnd); // new string = start of string + space + end of string
                // delete content from temporary strings
                strStart = "";
                strEnd = "";
            }
        }

        if (newStr[i] == ',') // replace ',' with space char for splitting afterwards
            newStr[i] = SPACE;

        i++;
    }
    i = 0; // initializing the index

    // second iteration for splitting by whitespaces
    while (newStr[i] != ENDOFSTRING) {
        // as long as the current char is not whitespace or end of string
        while (isspace(newStr[i]) == 0 && newStr[i] != ENDOFSTRING) {
            strTmp.push_back(newStr[i]); // push the char to the word
            i++;
        }
        strLst.push_back(strTmp); // push the word to the list
        strTmp = "";
        if (isspace(newStr[i]) != 0)  // if the current char is a whitespace
            i++;
    }
    return strLst;
}


//
//void Translator::parser(list<string> strLst) {
//        map<string, Command> symbolTable;
//        // updating command map
//        symbolTable = {{"openDataServer", openServerCommand()},
//                       {"connect",        connectCommand()},
//                       {"var",            varCommand()}};
//
//        // for every string in list
//        iterator<string> iter;
//        for (int i = 0; i < strLst.size(); i++) {
//            // search for the command in the map
//            auto search = symbolTable.find(strLst.get(i));
//            // if the command is not found
//}
//}