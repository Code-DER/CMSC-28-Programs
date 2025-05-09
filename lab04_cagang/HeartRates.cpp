// This file is the implementation file.
// The purpose of this file is to define the member functions of the HeartRates class

#include "HeartRates.h" // Header file for the HeartRates class
#include <iostream> // For input and output
#include <cctype> // For character manipulation
#include <algorithm> // For transform function
using namespace std;

// "HeartRates::" is used to specify the the function belongs to the HeartRates class in the other file

// Constructor to initialize the HeartRates object
HeartRates::HeartRates(string fName, string lName, string bMonth, int bDay, int bYear)
: firstName(fName), lastName(lName), birthMonth(bMonth), birthDay(bDay), birthYear(bYear) {};

// Array of months for validating and formatting the month input
string months[12] = { "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December" };

//Getter functions for the person's information
string HeartRates::getfirstName() { return firstName; }
string HeartRates::getlastName() { return lastName; }
string HeartRates::getbirthMonth() { return formatMonth(birthMonth); }
int HeartRates::getbirthDay() { return birthDay; }
int HeartRates::getbirthYear() { return birthYear; }

//Setter functions for the person's information
void HeartRates::setfirstName(string fName) { firstName = fName; }
void HeartRates::setlastName(string lName) { lastName = lName; }
void HeartRates::setbirthMonth(string bMonth) { birthMonth = bMonth; }
void HeartRates::setbirthDay(int bDay) { birthDay = bDay; }
void HeartRates::setbirthYear(int bYear) { birthYear = bYear; }

//Function to convert string month to its index in the array
int HeartRates::getMonthIndex(string month) {
    transform(month.begin(), month.end(), month.begin(), ::tolower);

    for(int i = 0; i < 12; i++) {
        string lowercaseMonth = months[i];
        // converts month to lowercase for comparison
        transform(lowercaseMonth.begin(), lowercaseMonth.end(), lowercaseMonth.begin(), ::tolower);
        if (month == lowercaseMonth) {
            return i + 1;
        }
    }
    return -1; // Invalid month
}

// Function to format a string month to have its first letter capitalized for printing
string HeartRates::formatMonth(string month) {
    if(month.empty()) return "";
    month[0] = toupper(month[0]);
    return month;
}

// Function to check if an inputted year is a leap year
bool HeartRates::isLeapYear(int year) {
    // If divisible by 4, it is generally a leap year
    if (year % 4 == 0) {
        // If a century year (ends in '00'), is divisible by both 100 and 400, then it is a leap year
        if (year % 100 == 0) {
            return (year % 400 == 0);
        }
        return true;
    }
    return false;
}

// Function to check the number of days in an inputted month and year
// It also accounts for leap years in February
int HeartRates::daysInMonth(string month, int year) {
    transform(month.begin(), month.end(), month.begin(), ::tolower);
    if (month == "january" || month == "march" || month == "may" || month == "july" || month == "august" || month == "october" || month == "december") {
        return 31;
    } else if (month == "april" || month == "june" || month == "september" || month == "november") {
        return 30;
    } else if (month == "february") {
        return isLeapYear(year) ? 29 : 28;
    }
    return -1; // Invalid month
}

// Function to calculate the age of the person based on the inputted data
int HeartRates::getAge(string currentMonth, int currentDay, int currentYear) {
    int birthMonthIndex = getMonthIndex(birthMonth); // Gets the index of the birth month
    int currentMonthIndex = getMonthIndex(currentMonth); // Gets the index of the current month

    if (birthMonthIndex == -1 || currentMonthIndex == -1) {
        cout << "Invalid month entered." << endl;
        return -1;
    }

    // Calculates the age based on the birth and current years
    int age = currentYear - birthYear;

    // Adjusts the age if the birthday has not occured yet in the current year
    if (currentMonthIndex < birthMonthIndex || (currentMonthIndex == birthMonthIndex && currentDay < birthDay)) {
        age--;
    }

    return age;
}

//Function that calculates the maximum heart rate of the person based on their age
// Maximum Heart Rate = 220 - Age
int HeartRates::getMaximumHeartRate(string currentMonth, int currentDay, int currentYear) {
    return 220 - getAge(currentMonth, currentDay, currentYear);
}

// Function that calculates the target heart rate rage of the person
// Target Heart Rate = 50% (lower limit) to 85% (upper limit) of the person's maximum heart rate
void HeartRates::getTargetHeartRate(int &lower, int &upper, string currentMonth, int currentDay, int currentYear) {
    double maxHeartRate = getMaximumHeartRate(currentMonth, currentDay, currentYear);
    // Add 0.5 to round the values to the nearest integer
    lower = maxHeartRate * 0.5 + 0.5; 
    upper = maxHeartRate * 0.85 + 0.5;
}