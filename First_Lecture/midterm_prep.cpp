#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int max_profit(vector<int> &prices);
int max_total_profit(vector<int> &prices);

int main() {
    //good place for exception here
    ifstream file("path");

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1; // or handle the error appropriately
    }

    string line;
    string delimiter = ",";
    vector<int> prices;


    //so while we get any lines from the file
    while (getline(file, line)) {

        size_t pos = 0;
        string token;
        int num;

        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            cout << "Token: [" << token << "]" << endl; // Print token for debugging

            try {
                num = stoi(token);
            } catch (const std::invalid_argument &e) {
                cerr << "Invalid argument: " << e.what() << endl;
                line.erase(0, pos + delimiter.length());
                continue;
            }
            prices.push_back(num);

            line.erase(0, pos + delimiter.length());
        }
        //we also have to handle whatever is left after last delimiter

        if (!line.empty()) {
            try {
                num = stoi(line);
                prices.push_back(num);
            } catch (const std::invalid_argument &e) {
                cerr << "Invalid argument: " << e.what() << endl;
                continue;
            }
        }
    }
//    for (int i = 0; i < prices.size(); i++) {
//        cout << "Prices in day " << i+1 << " : " << prices[i] << endl;
//    }
    int profit = max_profit(prices);
    int geting_rich = max_total_profit(prices);

    cout << "Max profit: " << profit << endl;
    cout << "Max total profit: " << geting_rich << endl;
}

int max_profit(vector<int> &prices) {
    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }
    }
    return max_profit;
}

int max_total_profit(vector<int> &prices) {
    int max_profit = 0;
    int min_price = prices[0];
    int total_profit = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        } else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
            total_profit += max_profit;
            max_profit = 0;
            min_price = prices[i];
        }
    }
    return total_profit;
}