// Saulitis_Leo_221RDB477

#include <iostream>
#include <string>
using namespace std;


int main() {
    string name;
    int age;
    int dustAge;
    int currentYear = 2024;

    cout << "Hello, how should I address you good sir or lady?" << endl;
    getline(cin, name);

    cout << "Greetings and salutations, " << name << "!" << endl;
    cout << "May I ask how many Earth circles have you witnessed, my friend?" << endl;
    cin >> age;

    dustAge = (currentYear - age) + 100;

    cout << "Wow you, "<< name << " will become as old as sand in year: " << dustAge <<endl;

    return 0;
}