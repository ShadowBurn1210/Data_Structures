#include <iostream>
using namespace std;

int getCityYear(int p0, double perc, int delta, double p) {
//    double population = p0;
    double percantage = perc * 0.01;
    int year=0;
    double difference;


    while(p0 < p){
        difference = (p0 * percantage) + delta;
        if (difference < 0){
            year = -1;
            return year;
        }
        p0 += p0 * percantage + delta;
        year++;
    }

    return year;
}

int main(){
    int first_try = getCityYear(1500000, 2.5, 10000, 2'000'000);
    int second_try = getCityYear(1000, 2, -50, 5000);
    int third_try = getCityYear(1500, 5, 100, 5000);
    int forth_try = getCityYear (1000,2,50,1200) ;
//    int fifth_try = getCityYear(1000, -3, 50, 2000);
    cout << first_try << '\n' << second_try << '\n' << third_try << '\n' << forth_try << '\n' << endl;
//    cout << third_try << endl;

    return 0;
}
