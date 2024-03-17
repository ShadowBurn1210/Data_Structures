#include <iostream>
#include <stdexcept>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main(){
    string input;
    cin >> input;
    queue<int> q;
    stack<char> s;

    for (int i = 0; i < input.size(); i++){
        try {
            if (input[i] < '0' || input[i] > '9'){
                if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')'){
                    s.push(input[i]);
                    continue;
                }
                throw invalid_argument("Invalid input");
            }

            int nummber = input[i] - '0';
            q.push(nummber);
        } catch (const invalid_argument& e){
            cout << e.what() << endl;
        }
    }

//    while (!s.empty()){
//
//    }



    cout << "Queue: ";
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << "Stack: ";
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}