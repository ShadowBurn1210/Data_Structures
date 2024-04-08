//This is the infamous two sum problem.
//
//Create a program that can read an arbitrary text file
//
//Format is first row contains target integer
//
//2nd row is empty
//
//3rd row to the rest makes up array of integers (we can call it nums)
//
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//You can return the answer in any order.
//
//
//
//Text field should contain the answer in form of 0 based indexes for the file given for example 342,468
//
//Submit code
//
//Grading:
//
//40% for brute force O(n*n) code - you could do this in week 1 right ?
//
//70% for O(n log n)
//
//100% for O(n) solution - hint it involves data structure that utilizes hashing



#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;


pair<int, int> find_target(int target, vector<int> nums) {
    unordered_map<int, int> m;

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
    int target = 9;
    vector<int> nums = {2, 7, 11, 15};

    pair<int, int> result = find_target(target, nums);
    cout << result.first << "," << result.second << endl;

    int target3 = 10;
    vector<int> nums3 = {1, 2, 3, 4};
    pair<int, int> result3 = find_target(target3, nums3);
    cout << result3.first << "," << result3.second << endl;

    int target2 = 6;
    // create a vector with 20 integers
    vector<int> nums2 = {9, 7, 18, 53, 14, 3, 3};
    pair<int, int> result2 = find_target(target2, nums2);
    cout << result2.first << "," << result2.second << endl;
    return 0;
}