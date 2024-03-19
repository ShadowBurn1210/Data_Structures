#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <string>
#include <any>

#include "shunting_yard.hpp"
using namespace std;

int main(){
    string input;
    cin >> input;
    queue<char> outputs;
    stack<char> operators;
    bool first = true;
    char prev = ' ';
    bool last = false;
    int count = 0;
    for (int index = 0; index < input.size(); ++index){

        // I needed this line because all the project was build with for (char i : input) this line
        // However, when I added numbers with more than one digit, I had to change it to for (int index = 0; index < input.size(); ++index)
        char i = input[index];
        count++;

        // all the error handeling
        if (is_letter(i)){
            cout << "Invalid input" << endl;
            exit(7);
        }
        if (input.size() == count){
            last = true;
        }
        if (first){
            if (isOperator(i)){
                throw invalid_argument("Invalid input");
            }
            first = false;
            prev = 0;
        }
        if (last){
            if (isOperator(i)){
                throw invalid_argument("Invalid input");
            }
            last = false;
        }
        try {
            // check that character is not a number
            if (i < '0' || i > '9'){

                // is character is a bracket handle it separately
                if (is_bracket(i)){
                    if (i == '(')
                    {
                        operators.push(i);
                        operators.push(' ');
                    }
                    else if (i == ')')
                    {
                        while (!operators.empty() && operators.top() != '(')
                        {
                            outputs.push(operators.top()) ;
                            outputs.push(' ');

                            operators.pop();
                        }
                        operators.pop();
                    }
                }

                // if the character is an operator
                if (isOperator(i)) {
                    // throw an error if the previous character is an operator and the current character is not a bracket
                    if (isOperator(prev) && i != '(' && i != ')'){
                        cout << "Invalid input" << endl;
                        exit(8);
                    }else{
                        prev = i;
                    }

                    // if the stack is empty, push the operator to the stack
                    if (operators.empty()) {
                        operators.push(i);

                        continue;
                    }

                    // if the stack is not empty, check the priority of the operator
                    int top_precident = priotity(operators.top());
                    int current_precident = priotity(i);

                    // if the current operator has a higher priority than the top operator, push the current operator to the stack
                    if (current_precident > top_precident) {
                        operators.push(i);
                        operators.push(' ');
                        continue;
                    }

                    // if the current operator has the same priority as the top operator, pop the top operator and push the current operator to the stack
                    if (current_precident == top_precident) {
                        outputs.push(operators.top());
                        outputs.push(' ');
                        operators.pop();
                        operators.push(i);
                        operators.push(' ');
                        continue;
                    }

                    // if the current operator has a lower priority than the top operator, pop the top operator and push the current operator to the stack
                    if (current_precident < top_precident) {
                        while (!operators.empty()) {
                            outputs.push(operators.top());
                            outputs.push(' ');
                            operators.pop();
                        }
                        operators.push(i);
                        continue;
                    }

                }
                throw invalid_argument("Invalid input");
            }else{
                // check for multiple digit numbers, if the next character is a digit, then continue
                // if the next character is a digit, then continue
                outputs.push(i);

                while (input[count] >= '0' && input[count] <= '9'){
                    outputs.push(input[count]);
                    count++;
                    index++;
                }
                outputs.push(' ');

            }

            prev = i;

        } catch (const invalid_argument& e){
            cout << e.what() << endl;
        }
    }

    // push the remaining operators to the outputs
    while (!operators.empty()){
        outputs.push(operators.top());
        operators.pop();
    }


    cout << "Result: " << calculate_resutl(outputs) << endl;
    return 0;
}

