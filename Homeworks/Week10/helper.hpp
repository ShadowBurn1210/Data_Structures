//
// Created by Admin on 22/03/2024.
//

#ifndef DATA_STRUCTURES_HELPER_HPP
#define DATA_STRUCTURES_HELPER_HPP

#include <string>

using namespace std;

int error_checking(char i, bool first, bool last, char prev, string input, int count);
void add_precedence(queue<char> &outputs, stack<char> &operators, char i);


#endif //DATA_STRUCTURES_HELPER_HPP
