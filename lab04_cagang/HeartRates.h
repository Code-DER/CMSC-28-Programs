// This file is the header file.
// The purpose of this file is to define the HeartRates class and its member functions

#ifndef HEARTRATES_H
#define HEARTRATES_H

#include <iostream>
using namespace std;

// Class for HeartRates
class HeartRates {
    private:
        string firstName;
        string lastName;
        string birthMonth;
        int birthDay;
        int birthYear;
    public:
        //Constructor
        HeartRates(string firstName, string lastName, string birthMonth, int birthDay, int birthYear);
        
        //Getters
        string getfirstName();
        string getlastName();
        string getbirthMonth();
        int getbirthDay();
        int getbirthYear();
        int getAge(string currentMonth, int currentDay, int currentYear);
        int getMaximumHeartRate(string currentMonth, int currentDay, int currentYear);
        void getTargetHeartRate(int &lower, int &upper, string currentMonth, int currentDay, int currentYear);

        //Setters
        void setfirstName(string fName);
        void setlastName(string lname);
        void setbirthMonth(string bMonth);
        void setbirthDay(int bDay);
        void setbirthYear(int bYear);

        //Methods for error handling of the dates
        static string formatMonth(string month);
        static int getMonthIndex(string month);
        static bool isLeapYear(int year);
        static int daysInMonth(string month, int year);
};

#endif