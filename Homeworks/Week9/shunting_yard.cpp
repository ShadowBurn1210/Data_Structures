//
// Created by Admin on 17/03/2024.
//
#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <string>

#include "shunting_yard.hpp"


bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_bracket(char c){
    return c == '(' || c == ')';
}
int calculate_resutl(queue<char>& input){
    // calculate the result from Queue: 5 9 8 * 2 / + 9 -
    stack<int> numbers;
    while (!input.empty()){
        char c = input.front();
        input.pop();
        if (c >= '0' && c <= '9'){
            numbers.push(c - '0');
        }
        else{
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
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

int priotity(char c){
    if (c == '+' || c == '-'){
        return 1;
    }
    if (c == '*' || c == '/'){
        return 2;
    }
    return 0;
}

bool is_letter(char c){
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}