#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <string>
#include <any>
#include <fstream>

#include "helper.hpp"
#include "shunting_yard.hpp"
using namespace std;

int main(){
    queue<char> outputs;
    stack<char> operators;
    bool first = true;
    char prev = ' ';
    bool last = false;
    int count = 0;
    int error_num;
    string line;

    ifstream file("file");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1; // or handle the error appropriately
    }




    //so while we get any lines from the file
    while (getline(file, line)) {
        string input = line;

        for (int index = 0; index < input.size(); ++index){

            // I needed this line because all the project was build with for (char i : input) this line
            // However, when I added numbers with more than one digit, I had to change it to for (int index = 0; index < input.size(); ++index)
            char i = input[index];
            count++;

            //https://en.cppreference.com/w/cpp/string/byte/isspace
            if (isspace(i)){
                continue;
            }

            // all the error handeling was moved to helper.hpp file to make the code cleaner
            error_num = error_checking(i, first, last, prev, input, count);

            // different cases for the error numbers
            switch (error_num) {
                case 1:
                    cout << "Invalid input" << endl;
                    exit(8);
                case 2:
                    first = false;
                    break;
                case 3:
                    last = true;
                    break;
                default:
                    break;
            }


            try {
                // check that character is not a number
                if (i < '0' || i > '9'){

                    // is character is a bracket handle it separately
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
                        add_precedence(outputs, operators, i);
                    }

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
    }

    // push the remaining operators to the outputs
    while (!operators.empty()){
        outputs.push(operators.top());
        operators.pop();
    }

//    // print the outputs
//    while (!outputs.empty()){
//        cout << outputs.front();
//        outputs.pop();
//    }

    cout << "Result: " << calculate_resutl(outputs) << endl;
    return 0;
}

