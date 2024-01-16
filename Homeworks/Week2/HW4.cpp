//
// Created by 37129 on 1/16/2024.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    char letter;

    // I was too lazy to create this dictionary, so I asked AI to do it for me https://chat.openai.com/share/eea0b835-a100-4df1-a44b-fac1ef3e59f6
    map<char, string> NATO = {
            {'A', "Alfa"},
            {'B', "Bravo"},
            {'C', "Charlie"},
            {'D', "Delta"},
            {'E', "Echo"},
            {'F', "Foxtrot"},
            {'G', "Golf"},
            {'H', "Hotel"},
            {'I', "India"},
            {'J', "Juliett"},
            {'K', "Kilo"},
            {'L', "Lima"},
            {'M', "Mike"},
            {'N', "November"},
            {'O', "Oscar"},
            {'P', "Papa"},
            {'Q', "Quebec"},
            {'R', "Romeo"},
            {'S', "Sierra"},
            {'T', "Tango"},
            {'U', "Uniform"},
            {'V', "Victor"},
            {'W', "Whiskey"},
            {'X', "X-ray"},
            {'Y', "Yankee"},
            {'Z', "Zulu"},
            {'0', "Zero"},
            {'1', "One"},
            {'2', "Two"},
            {'3', "Three"},
            {'4', "Four"},
            {'5', "Five"},
            {'6', "Six"},
            {'7', "Seven"},
            {'8', "Eight"},
            {'9', "Nine"}
    };


    cout << "Please enter a letter or a digit: " << endl;
    cin >> letter;


    // Created with the help of Co-pilot auto complete
    for (auto & i : NATO) {
        if (i.first == toupper(letter)) {
            cout << i.second << endl;
        }
    }

}