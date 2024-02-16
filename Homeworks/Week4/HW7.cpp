// reference for task https://www.geeksforgeeks.org/insert-elements-c-stl-list/
// Saulitis_Leo_221RDB477


#include <iostream>
#include <vector>
#include<algorithm>
#include <fstream>
using namespace std;

int main(){
    int index =1;
    int number_value = 1;
    ifstream myfile;
    myfile.open("C:\\Users\\37129\\Programming\\Programming Languages\\Data_Structures\\Homeworks\\Week4\\missing_numbers.txt");
    vector<int> arr;

    if (myfile.is_open()) {
        int number;
        while (myfile >> number) {
            arr.push_back(number);
        }
    }
    sort(arr.begin(), arr.end());

    while(index<=arr.size()){

        if(arr[index-1] != number_value){
            cout << "Missing number: " << number_value << endl;
            number_value=number_value+2;
            index++;
        }else{
            cout << "Number: " << index << endl;
            index++;
            number_value++;
        }
    }

    return 0;
}
