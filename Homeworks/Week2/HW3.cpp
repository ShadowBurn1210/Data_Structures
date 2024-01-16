// Saulitis_Leo_221RDB477

#include <iostream>
using namespace std;


int main() {
    int num1, num2, num3;

    cout << "Please enter three numbers: " << endl;
    cin >> num1 >> num2 >> num3;


    // Created with the help of Co-pilot auto complete
    if (num1 < num2 && num1 < num3) {
        cout << num1 << " ";
        if (num2 < num3) {
            cout << num2 << " " << num3 << endl;
        } else {
            cout << num3 << " " << num2 << endl;
        }
    } else if (num2 < num1 && num2 < num3) {
        cout << num2 << " ";
        if (num1 < num3) {
            cout << num1 << " " << num3 << endl;
        } else {
            cout << num3 << " " << num1 << endl;
        }
    } else {
        cout << num3 << " ";
        if (num1 < num2) {
            cout << num1 << " " << num2 << endl;
        } else {
            cout << num2 << " " << num1 << endl;
        }
    }

    return 0;
}