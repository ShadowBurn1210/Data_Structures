// Saulitis_Leo_221RDB477

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Song {

private:
    string title;
    string author;
    string lyrics;
    int year;

public:
    Song(string title = "", string author = "", string lyrics = "", int year = 0) {

        this->title = title;
        this->author = author;
        this->lyrics = lyrics;
        this->year = year;

        cout << "New Song made\n";
    }
// https://chat.openai.com/share/5763403c-d865-4c81-8696-93bb0f0c9a42 my chat with openAI to make member functions chainable
    Song& sing(int max_lines = -1) {
        int lines_printed = 0;

        cout << author << " -- " << title << " -- " << year << endl;
        if (max_lines == -1) {
            cout << lyrics << endl;

        // Got the help from co-pilot to split on \n
        } else {
            for (char c : lyrics) {
                cout << c;
                if (c == '\n') {
                    lines_printed++;
                    if (lines_printed == max_lines)
                        break;
                }
            }
        }
        return *this;
    }

    Song& yell(int max_lines = -1) {
        cout << author << " -- " << title << " -- " << year << endl;
        int lines_printed = 0;

        //https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase
        transform(lyrics.begin(), lyrics.end(), lyrics.begin(), ::toupper);

        if (max_lines == -1) {
            cout << lyrics << endl;
        } else {
            for (char c : lyrics) {
                cout << c;
                if (c == '\n') {
                    lines_printed++;
                    if (lines_printed == max_lines)
                        break;
                }
            }
        }
        return *this;
    }
};


////https://www.w3schools.com/cpp/cpp_inheritance.asp
//class Rap: public Song {
//public:
//    Rap& break_it(int max_lines = -1, string drop = "yeah") {
//        string modified_lyrics = lyrics;
//
//        // Applying the drop modification
//        if (max_lines == -1)
//            max_lines = modified_lyrics.size();
//        for (int i = 0; i < max_lines; ++i) {
//            if (modified_lyrics[i] == ' ')
//                modified_lyrics.insert(i + 1, drop);
//        }
//
//        cout << modified_lyrics << endl;
//        return *this;
//    }
//};


int main() {

    auto prayers = Song("Livin On A Prayer",
                        "Bon Jovi",
                        "Tommy used to work on the docks\nUnion's been on strike, he's down on his luck\n", 1988);

    prayers.sing(1).yell();

    return 0;
}



