//Write a program that finds TWO missing numbers out of 50 numbers.
//
//Numbers are unique, not in any order, and their values are from 1 to 50.
//
//You have 48 numbers you do not know which 2 numbers are missing.

// reference for task https://www.geeksforgeeks.org/insert-elements-c-stl-list/
#include <iostream>
#include <list>

using namespace std;

int main(){
    int index =1;
    int number_value = 1;
    int arr[10] = {1,2,3,4,5,7,8,9,10, 11};

    while(index<=11){

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
