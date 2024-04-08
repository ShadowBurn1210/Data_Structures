#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <fstream>

using namespace std;


pair<int, int> find_target(int target, vector<int> nums) {
    unordered_map<int, int> m;

    // this was written with help of co-pilot
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (m.find(complement) != m.end()) {
            return {m.find(complement)->second, i};
        }
        m[nums[i]] = i;
    }
    return {}; // Return an empty pair if no match is found
}



int main(){
    int target = 0;
    vector<int> nums;
    string filename = "C:\\Users\\37129\\Programming\\Programming Languages\\Data_Structures\\Homeworks\\Week12\\two_sum_target_n_data.txt";
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        getline(file, line);

        target = stoi(line);

        while (getline(file, line)) {
            try {
                stoi(line);
                nums.push_back(stoi(line));
            } catch (invalid_argument e) {
                cout << "Invalid argument" << endl;
                continue;
            }
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    pair<int, int> result = find_target(target, nums);
    cout << result.first << " " << result.second << endl;
    return 0;
}