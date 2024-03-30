#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstring>
#include <locale>
#include <codecvt>
using namespace std;

int main(int argc, char* argv[]) {

    map<wchar_t, int> frequency;
    string input_file;
    string output_file;
    wstring line;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            input_file = argv[i + 1];
        } else if (strcmp(argv[i], "-o") == 0) {
            output_file = argv[i + 1];
        }
    }
    wifstream file(input_file);

    if (!file.is_open()) {
        // cerr is used to print errors to the standard error stream
        cerr << "Error opening file!" << endl;
         return 1;
    }

    // Output using UTF-8 encoding
    locale::global(locale("C.UTF-8"));

    while (getline(file, line)) {
        cout << "Input file: " << endl;
        for (wchar_t i : line) {
            if (isspace(i)) {
                continue;
            }
            if (frequency.find(i) == frequency.end()) {
                frequency[i] = 1;
            } else {
                frequency[i]++;
            }
        }
    }
    // add to frequency map test element
    frequency[L'Ģ'] = 1;
    // write to output file with extension tsv
    wofstream output(output_file);
    for (auto const& [key, val] : frequency) {
        output << key << "\t" << val << endl;
    }
    cout << "Output file: " << output_file<< endl;
    return 0;
}

