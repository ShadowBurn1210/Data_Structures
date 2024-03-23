#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <string>
#include <any>

#include "shunting_yard.hpp"
using namespace std;

int error_checking(char i, bool first, bool last, char prev, string input, int count){

    if (input.size() == count){
        last = true;
    }

    if (is_letter(i)){
        cout << "Cannot have letters in the input" << endl;
        return 1;
    }

    if (first){
        if (isOperator(i)){
            cout << "First cannot be an operator" << endl;
            return 1;
        }
        return 2;
    }
    if (last){
        if (isOperator(i)){
            cout << "Last cannot be an operator" << endl;
            return 1;
        }
        return 3;
    }

    return 0;
}

void add_precedence(queue<char> &outputs, stack<char> &operators, char i){
    // if the stack is empty, push the operator to the stack
    if (operators.empty()) {
        operators.push(i);
        return;
    }
    // if the stack is not empty, check the priority of the operator
    int top_precident = priotity(operators.top());
    int current_precident = priotity(i);

    // if the current operator has a higher priority than the top operator, push the current operator to the stack
    if (current_precident > top_precident) {
        operators.push(i);
        return;
    }

    // if the current operator has the same priority as the top operator, pop the top operator and push the current operator to the stack
    if (current_precident == top_precident) {
        outputs.push(operators.top());
        outputs.push(' ');
        operators.pop();
        operators.push(i);

        return;
    }

    // if the current operator has a lower priority than the top operator, pop the top operator and push the current operator to the stack
    if (current_precident < top_precident) {
        outputs.push(operators.top());
        outputs.push(' ');
        operators.pop();
        add_precedence(outputs, operators, i);

        return;
    }
}