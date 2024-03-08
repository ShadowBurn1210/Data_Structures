// Saulitis_Leo_221RDB477

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// These function were written with help from co-pilot, as it severly reduced boiler plate code
void parseDate(string date, int &day, int &month, int &year);
string determen_mounth(int month);
bool isLeapYear(int year);
void validateDay(int day, int month, int year);
void validateYear(int year);

int main() {
    string birthday;
    cout << "Please enter your birthday (format dd-mm-year):" << endl;
    cin >> birthday;

    int day, month, year;
    try {
        parseDate(birthday, day, month, year);
    } catch (const invalid_argument &e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return 1;
    }

    try {
        determen_mounth(month);
    } catch (const invalid_argument &e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return 1;
    }

    try {
        validateDay(day, month, year);
    } catch (const invalid_argument &e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return 1;
    }
    try {
        validateYear(year);
    } catch (const invalid_argument &e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return 1;
    }
    string mounth = determen_mounth(month);
    cout << "Your birthday is: " << mounth << ", " << day << "th, " << year << endl;
    return 0;
}

//Divide each part of the date into separate variables
void parseDate(string date, int &day, int &month, int &year) {
    string delimiter = "-";
    size_t pos = 0;
    string token;
    int i = 0;
    while ((pos = date.find(delimiter)) != string::npos) {
        token = date.substr(0, pos);
        if (i == 0) {
            day = stoi(token);
        } else if (i == 1) {
            month = stoi(token);
        }
        date.erase(0, pos + delimiter.length());
        i++;
    }
    year = stoi(date);
}

// custom exception for invalid month
class InvalidMonthException_custom : public invalid_argument {
public:
    InvalidMonthException_custom() : invalid_argument("You should enter a day that exists!!! I am very smart programme that knows the truht") {}
};

// determen which month the birthday is in, and if not valid throw exception
string determen_mounth(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            throw InvalidMonthException_custom();
    }
}

// custom exception for invalid day
class InvalidDayException_custom : public invalid_argument {
public:
    InvalidDayException_custom() : invalid_argument("You should enter a day that exists!!! I am very smart programme that knows the truht") {}
};

// determen if day is valid
void validateDay(int day, int month, int year) {
    if (day < 1 || day > 31) {
        throw InvalidDayException_custom();
    }
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day > 29) {
                throw InvalidDayException_custom();
            }
        } else {
            if (day > 28) {
                throw InvalidDayException_custom();
            }
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            throw InvalidDayException_custom();
        }
    }
}

// custom exception for invalid year
class InvalidYearException_custom : public invalid_argument {
public:
    InvalidYearException_custom() : invalid_argument("You should enter a year that your are actually born!!!") {}
};

// determen if the year is a leap year
bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

// determen if the year is valid
// used this to determen oldes possible year https://en.wikipedia.org/wiki/List_of_oldest_living_people
void validateYear(int year) {
    if (year < 1900 || year > 2050) {
        throw InvalidYearException_custom();
    }
    if (year < 1907) {
        cout << "Wow you must be oldest person still alive" << endl;
    }
    if (year > 2024) {
        cout << "You are not born yet" << endl;
    }
}


