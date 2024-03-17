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
    for (char i : input){
        count++;

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
            if (i < '0' || i > '9'){

                if (is_bracket(i)){
                    if (i == '(')
                    {
                        operators.push(i);
                    }
                    else if (i == ')')
                    {
                        while (!operators.empty() && operators.top() != '(')
                        {
                            outputs.push(operators.top()) ;
                            operators.pop();
                        }
                        operators.pop();
                    }
                }

                if (isOperator(i)) {
                    if (isOperator(prev) && i != '(' && i != ')'){
                        cout << "Invalid input" << endl;
                        exit(8);
                    }else{
                        prev = i;
                    }


                    if (operators.empty()) {
                        operators.push(i);
                        continue;
                    }
                    int top_precident = priotity(operators.top());
                    int current_precident = priotity(i);
                    if (current_precident > top_precident) {
                        operators.push(i);
                        continue;
                    }
                    if (current_precident == top_precident) {
                        outputs.push(operators.top());
                        operators.pop();
                        operators.push(i);
                        continue;
                    }
                    if (current_precident < top_precident) {
                        while (!operators.empty()) {
                            outputs.push(operators.top());
                            operators.pop();
                        }
                        operators.push(i);
                        continue;
                    }

                }
                throw invalid_argument("Invalid input");
            }
            // TODO: check for multiple digit numbers
            else{
                // check for multiple digit numbers, if the next character is a digit, then continue
                // if the next character is a digit, then continue
                cout << "count: " << count << " its corresponding value is " << input[count] << endl;
                char new_i =input[count-1];
                cout << "i: " << i << " new_i "<< new_i<< endl;
                int num = i - '0';
                cout << "num: " << num << endl;
            }

            prev = i;
            outputs.push(i);
        } catch (const invalid_argument& e){
            cout << e.what() << endl;
        }
    }

//    while (!ope.empty()){
//
//    }
    while (!operators.empty()){
        outputs.push(operators.top());
        operators.pop();
    }

    cout << "Result: " << calculate_resutl(outputs) << endl;
    return 0;
}

