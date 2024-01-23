#include <iostream>
using namespace std;

int getCityYear(double starting_population, double increse_precentage, int delta, double end_population) {
//    double population = starting_population;
    double percantage = increse_precentage * 0.01;
    int year=0;
    double difference;



    while(starting_population < end_population){
        difference = (starting_population * percantage) + delta;
        if (difference < 0){
            year = -1;
            return year;
        }
        starting_population += starting_population * percantage + delta;
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
