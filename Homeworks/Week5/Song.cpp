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
    Song& sing() {
        cout << author << " -- " << title << " -- " << year << endl;
        cout << lyrics << endl;
        return *this;
    }

    Song& yell() {
        cout << author << " -- " << title << " -- " << year << endl;

        //https://stackoverflow.com/questions/23418390/how-to-convert-a-c-string-to-uppercase
        transform(lyrics.begin(), lyrics.end(), lyrics.begin(), ::toupper);
        cout << lyrics << endl;
        return *this;
    }
};


//https://www.w3schools.com/cpp/cpp_inheritance.asp
class Rap: public Song {
public:

    Rap& break_it(int max_lines = -1, string drop = "yeah") {
        string modified_lyrics = lyrics;

        // Applying the drop modification
        if (max_lines == -1)
            max_lines = modified_lyrics.size();
        for (int i = 0; i < max_lines; ++i) {
            if (modified_lyrics[i] == ' ')
                modified_lyrics.insert(i + 1, drop);
        }

        cout << modified_lyrics << endl;
        return *this;
    }
};


int main() {

    auto prayers = Song("Livin On A Prayer", "Bon Jovi","Tommy used to work on the docks\nUnion's been on strike, he's down on his luck\nIt's tough\nSo tough\nGina works the diner all day\n"
                                                        "Workin' for her man, she brings home her pay\n"
                                                        "For love\n"
                                                        "Mm, for love", 1988);

    prayers.sing().yell();

    return 0;
}



