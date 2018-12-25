//
// Created by schwe on 20/12/2018.
//

#include "MathShuntYard.h"
#include <string>
#include <sstream>

#define ENDOFSTRING '\0'
using namespace std;


/**
*our constructor receives a lexer component (a string) and builds 2 lists
* @param string
* @return void
*/
MathShuntYard::MathShuntYard(string equation) {
    //generate new members
    stack<string> operatorList;
    stack<string> outputList;
    string buffer;
    //index
    int i = 0;
    //we iterate through the entire string
    while (equation[i] != ENDOFSTRING) {
        //first, we skip over all blank spaces
        if (equation[i] != ' ') {
            //we check for operators (+,-,/,*)
            if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/') {
                //we determine if we need to rearrange the 'operator' stack
                if ((equation[i] == '+' || equation[i] == '-')) {
                    //if the stack isn't empty, and the topmost element is lower priority)
                    //using a counter to stop our while loop as needed
                    int end = 1;
                    while (!operatorList.empty() && end) {
                        string temp = operatorList.top();
                        //if the top operator ISNT a '('
                        if (temp != "(") {
                            //if the top operators are a HIGHer priority
                            if (temp == "/" || temp == "*") {
                                outputList.push(temp);
                                operatorList.pop();
                            } else {
                                //we end this loop
                                end = 0;
                            }
                        }
                        //to prevent infinite loops
                        if (temp == "(") {
                            end = 0;
                        }
                    }
                }
                //we add our new operator into the 'operator stack' (AFTER rearranging)
                buffer = equation.substr(i);
                operatorList.push(buffer);
            } else {
                //we check for 'named variables' (numbers OR named variables)
                if (((int) equation[i] >= 65 && (int) equation[i] <= 122) ||
                    ((int) equation[i] >= 48 && (int) equation[i] <= 57)) {
                    //we determine the length of the variable's name
                    int j = i;
                    while ((int) equation[j] != ' ') {
                        j++;
                    }
                    //we add the variable to the output stack
                    buffer = equation.substr(i, j);
                    outputList.push(buffer);
                }

                //we check for  parentheses variables (different rules than other operators)
                //we have a '(' parentheses
                if (equation[i] == '(') {
                    //we add the parentheses to the operators stack
                    buffer = equation.substr(i);
                    operatorList.push(buffer);
                }
                //we have a ')' parentheses
                if (equation[i] == ')') {
                    if (!operatorList.empty()) {
                        string temp = operatorList.top();
                        this->operatorList.pop;
                        //until we find a '(' we pop our operators into our output stack
                        while (temp != "(" && (!operatorList.empty())) {
                            outputList.push(temp);
                            temp=operatorList.top();
                            operatorList.pop();
                        }
                    }
                }
            }

        }
        //we move to the next word, symbol, or number
        i++;
    }
}

/*
 *returns the stack of operators
 */
const stack<string> &MathShuntYard::getOperatorList() const {
    return operatorList;
}

/*
 *returns the stack of variables
 */
const stack<string> &MathShuntYard::getOutputList() const {
    return outputList;
};


//destructor
MathShuntYard::~MathShuntYard() = default;
