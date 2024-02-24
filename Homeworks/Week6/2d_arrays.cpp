#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int smallest_value(vector<int> &vec);
int average_value(vector<int> &vec);
double standard_deviation(vector<int> &vec);

int main() {
    string line;
    string delimiter = ",";

    vector<int> first_collum;
    vector<int> second_collum;
    vector<int> third_collum;

    ifstream file("C:\\Users\\Admin\\CLionProjects\\Data_Structures\\Homeworks\\Week6\\2d.csv");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }


    // to skip the first line
    getline(file, line);

    // Used code provided in lectures to open file and read from it line by line with delimiter

    //so while we get any lines from the file
    while (getline(file, line)) {

        size_t pos = 0;
        string token;
        int num;
        int rows_position_index = 0;

        // Read each lines number and get inty to which I add to my vectors
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);

            num = stoi(token);

            if (rows_position_index == 0) {
                first_collum.push_back(num);
            } else if (rows_position_index == 1) {
                second_collum.push_back(num);
            }
            rows_position_index++;
            line.erase(0, pos + delimiter.length());

        }

        // handle whatever is left after last delimiter
        num = stoi(line);
        third_collum.push_back(num);
        rows_position_index = 0;
    }


    int min_value = smallest_value(first_collum);
    auto second_average = average_value(second_collum);
    auto third_deviation = standard_deviation(third_collum);

    cout << "Population standard deviation of third collum: " << third_deviation << endl;
    cout << "Average value of second collum: " << second_average << endl;
    cout << "Min value of first collum: " << min_value << endl;
}


int smallest_value(vector<int> &vec) {
    int min_value = 99999999;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < min_value) {
            min_value = vec[i];
        }
    }
    return min_value;
}


// Used this for understanding the math behind it https://chat.openai.com/share/63846eec-5549-4f7c-b17d-a4d0b71c3c91
int average_value(vector<int> &vec) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        count++;
    }
    return sum / count;
}

// Used this for understanding the math behind it https://chat.openai.com/share/63846eec-5549-4f7c-b17d-a4d0b71c3c91
double standard_deviation(vector<int> &vec) {
    int count = 0;
    int square_sum = 0;

    // Get average value
    int average = average_value(vec);

    for (int i = 0; i < vec.size(); i++) {
        int square = (vec[i]-average) * (vec[i]-average);
        square_sum += square;
        count++;
    }
    auto bam = square_sum / count;
    auto square_root = sqrt(bam);

    return square_root;
}