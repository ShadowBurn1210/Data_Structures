#include <iostream>
#include <cmath>
using namespace std;

// Some inspirations https://www.geeksforgeeks.org/c-program-to-check-whether-a-number-is-prime-or-not/

int isPrime(int number){
    int i = 2;

    if (number == 1) {
        printf("1 is neither prime nor composite ");
        return 0;
    }

    while (i <= sqrt(number)){
        if (number % i == 0){
            printf("%d is not a prime number ", number);
            return 0;
        }
        i++;
    }
    printf("%d is a prime number ", number);
    return 1;
}

int main(){


    int first_try = isPrime(1'000'001);
    cout << first_try << endl;

    int second_try = isPrime(1'000'021);
    cout << second_try << endl;

    int third_try = isPrime(1'000'037);
    cout << third_try << endl;

    return 0;
}