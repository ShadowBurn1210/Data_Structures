#ifndef SHUNTING_YARD_HPP
#define SHUNTING_YARD_HPP

#include <string>

using namespace std;

bool isOperator(char);
double calculate_resutl(queue<char>&);
int priotity(char);
bool is_bracket(char);
bool is_letter(char);

#endif