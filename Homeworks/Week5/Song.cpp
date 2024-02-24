// Saulitis_Leo_221RDB477

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Song {

protected:
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

        transform(lyrics.begin(), lyrics.end(), lyrics.begin(), ::tolower);

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
class Rap: public Song {

public:
    Rap(string title = "", string author = "", string lyrics = "", int year = 0) :  Song(title, author, lyrics, year) {}

    Rap& break_it(int max_lines = -1, string drop = "yeah") {
        string modified_lyrics = lyrics;
        transform(drop.begin(), drop.end(), drop.begin(), ::toupper);
        int lines_printed = 0;


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
                }else if (c == ' ') {
                    cout << drop << " ";
                }
            }
    };

        return *this;
    }
};

int main() {

//    auto prayers = Song("Livin On A Prayer",
//                        "Bon Jovi",
//                        "Tommy used to work on the docks\nUnion's been on strike, he's down on his luck\n", 1988);
//    auto always = Song("Always",
//                       "Bon Jovi",
//                       "This Romeo is bleeding, but you can't see his blood\nIt's nothing but some feelings\n"
//                       "This old dog kicked up", 1994);
//    prayers.sing(1).yell();
//    always.sing(1).yell(2).sing(3);



    auto zrap = Rap("Always",
                       "Bon Jovi",
                       "This Romeo is bleeding, but you can't see his blood\nIt's nothing but some feelings\n"
                       "This old dog kicked up", 1994);
    zrap.break_it(2, "yeah");


    return 0;
}



