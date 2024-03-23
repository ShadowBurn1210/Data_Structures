//
// Created by Admin on 17/03/2024.
//
#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <string>

#include "shunting_yard.hpp"



double calculate_resutl(queue<char>& input){
    // calculate the result from Queue: 5 9 8 * 2 / + 9 -
    stack<double> numbers;

    while (!input.empty()){
        char c = input.front();

        // if the character is a space, pop it and continue
        if (c == ' '){
            input.pop();
            continue;
        }

        // if the character is a number, pop it and continue
        if (c >= '0' && c <= '9'){
            input.pop();
            // read input till you get the number before the space
            // so that you can push the whole number not just the char to the stacks
            int number = 0;
            while (c >= '0' && c <= '9'){
                number = number * 10 + c - '0';
                c = input.front();
                input.pop();
            }

            numbers.push(number);
        }
        else{
            // if the character is an operator, pop it and apply the operation
            input.pop();
            double a = numbers.top();
            numbers.pop();
            double b = numbers.top();
            numbers.pop();
            switch (c){
                case '+':
                    numbers.push(a + b);
                    break;
                case '-':
                    numbers.push(b - a);
                    break;
                case '*':
                    numbers.push(a * b);
                    break;
                case '/':
                    numbers.push(b / a);
                    break;
            }
        }
    }
    return numbers.top();
}

// check the priority of the operator and return the priority
int priotity(char c){
    if (c == '+' || c == '-'){
        return 1;
    }
    if (c == '*' || c == '/'){
        return 2;
    }
    return 0;
}

// check if the character is a letter
bool is_letter(char c){
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

// check if the character is an operator
bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// check if the character is a bracket
bool is_bracket(char c){
    return c == '(' || c == ')';
}