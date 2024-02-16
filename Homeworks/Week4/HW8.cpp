// Saulitis_Leo_221RDB477

#include <iostream>
#include <vector>
#include<algorithm>
#include <fstream>

using namespace std;
int main(){

    ifstream myfile;
    myfile.open("C:\\Users\\37129\\Programming\\Programming Languages\\Data_Structures\\Homeworks\\Week4\\numbers.txt");
    vector<int> arr;

    if (myfile.is_open()) {
        int number;
        while (myfile >> number) {
            arr.push_back(number);
            cout << number << " ";
        }
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    sort(arr.begin(), arr.end());

    // initialize all the values used in the program

    // get to 2 biggest value product in the array
    int max1 = arr[arr.size()-1];
    int max2 = arr[arr.size()-2];
    int sum1 = max1 * max2;

    // get to 2 smales value product in the array
    int min1 = arr[0];
    int min2 = arr[1];
    int sum2 = min1 * min2;


    int sum;

    // compare the two products and get the biggest one
    if (sum1 > sum2){
        sum=sum1;
    }else{
        sum=sum2;
    }

    cout << "Max product of two elements: " << sum << endl;
    return 0;
}