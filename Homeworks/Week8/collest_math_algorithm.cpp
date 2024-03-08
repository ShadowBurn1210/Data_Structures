// Saulitis_Leo_221RDB477

//The rules are simple,
//
//        f(n) = n/2 if n is even, n*3+1 if n is odd
//
//        We "win" when we reach 1.
//
//Example: we start with 5 then 16 then 8 then 4 then 2 then 1 - total 5 steps
//
//        Example: we start with 1 - 0 steps

#include <iostream>
#include <stdexcept>

using namespace std;
int collatz_conjecture(int n, int &steps);

int main(){
    int n;
    int steps = 0;
    cout << "Write an integer that is greater than 1" << endl;
    cin >> n;
    if (n < 1) {
        throw invalid_argument("n must be greater than 0");
    }
    cout << "It took " << collatz_conjecture(n, steps) << " steps to reach 1" << endl;
    return 0;
}

// used the wikipidea page to understand the problem and the solution
// https://en.wikipedia.org/wiki/Collatz_conjecture
// Got also bit of help to not go forever loop from co-pilot
int collatz_conjecture(int n, int &steps) {

    if (n == 1) {
        return steps;
    }
    if (n % 2 == 0) {
        steps++;
        return collatz_conjecture(n / 2, steps);
    } else {
        steps++;
        return collatz_conjecture(n * 3 + 1, steps);
    }
}

