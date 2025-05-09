// This file is the main program
// The purpose of this file is to get user input, create an object of the HeartRates class, and display the results

#include "HeartRates.h" // Header file for the HeartRates class
#include <iostream> // For input and output
#include <limits> // For input validation
using namespace std;

int main() {
    string firstName, lastName; // Stores first and last name
    string birthMonth, currentMonth; // Stores birth and current month
    int birthDay, birthYear; // Stores birth day and year
    int currentDay, currentYear; // Stores current day and year
    int tempYear = 2000; // Temporary year to check for leap year
    int entry = 3; // Three entries for person heart rate calculation allowed

    // Main loop: allows the user to enter information for a maximum of 3 people
    while(entry > 0) {
        cout << "TARGET-HEART-RATE CALCULATOR" << endl;
        cout << "(You can run this program up to " << entry << " more times.)" << endl << endl;

        // Prompts to enter person's first name
        cout << "Enter first name: ";
        getline(cin, firstName); // Allows for spaces to be included

        // Prompts to enter person's last name
        cout << "Enter last name: ";
        getline(cin, lastName); // Allows for spaces to be included

        // Prompts to enter person's birth month
        cout << "Enter birth month: ";
        cin >> birthMonth;
            // Validate the inputted month - if it is not in the months array, it prompts to enter again
            while(HeartRates::getMonthIndex(birthMonth) == -1) {
                cout << "!!! Invalid month entered. Please enter a proper month. !!!" << endl;
                cout << "Enter birth month: ";
                cin >> birthMonth;
            }

        // Prompts to enter person's birth day
        cout << "Enter birth day (1-" << HeartRates::daysInMonth(birthMonth, tempYear) << "): ";
        cin >> birthDay;
            // Validate the inputted day - if it is not in the range of 1 to the number of days in the month, then it prompts to enter again
            while (cin.fail() || birthDay < 1 || birthDay > HeartRates::daysInMonth(birthMonth, tempYear)) { // Error handling for inputted characters
                cout << "!!! Invalid \"birth day\" entered. Please enter valid day, 1-" << HeartRates::daysInMonth(birthMonth, birthYear) << " only. !!!" << endl;
                cin.clear(); // Resets the error state and allows cin to accept new inputs
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skips up to 1000 characters or until it reaches a new line
                cout << "Enter birth day (1-" << HeartRates::daysInMonth(birthMonth, birthYear) << "): ";
                cin >> birthDay; // Prompts to choose again
            }

        // Prompts to enter person's birth year
        cout << "Enter birth year: ";
        cin >> birthYear;
            // Validate the inputted year - if it is not a valid year, it prompts to enter again
            while (cin.fail() || birthYear < 0) {
                cout << "!!! Invalid \"birth year\" entered. Please enter a valid year." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter birth year: ";
                cin >> birthYear;
            }

        // Special case for February: if the birth day is greater than the number of days in February of the given year, it prompts to enter again
        if (HeartRates::getMonthIndex(birthMonth) == 2 && birthDay > HeartRates::daysInMonth(birthMonth, birthYear)) {
            cout << "!!! Invalid \"birth day\" for February in the year " << birthYear << ". Please re-enter the day. !!!" << endl;
            do {
                cout << "Enter birth day (1-" << HeartRates::daysInMonth(birthMonth, birthYear) << "): ";
                cin >> birthDay;
                if (cin.fail() || birthDay < 1 || birthDay > HeartRates::daysInMonth(birthMonth, birthYear)) {
                    cout << "!!! Invalid \"birth day\" entered. Please enter a valid day (1-" << HeartRates::daysInMonth(birthMonth, birthYear) << "). !!!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail() || birthDay < 1 || birthDay > HeartRates::daysInMonth(birthMonth, birthYear));
        }

        // Prompts to enter current month
        cout << "Enter current month: ";
        cin >> currentMonth;
            // Validate the inputted month - if it is not in the months array, it prompts to enter again
            while(HeartRates::getMonthIndex(currentMonth) == -1) {
                cout << "!!! Invalid month entered. Please enter a proper month. !!!" << endl;
                cout << "Enter current month: ";
                cin >> currentMonth;
            }

        // Prompts to enter current day
        cout << "Enter current day (1-" << HeartRates::daysInMonth(currentMonth, tempYear) << "): ";
        cin >> currentDay;
            // Validate the inputted day - if it is not in the range of 1 to the number of days in the month, it prompts to enter again
            while (cin.fail() || currentDay < 1 || currentDay > HeartRates::daysInMonth(currentMonth, tempYear)) { // Error handling for inputted characters
                cout << "!!! Invalid \"current day\" entered. Please enter valid day, 1-" << HeartRates::daysInMonth(currentMonth, currentYear) << " only. !!!" << endl;
                cin.clear(); // Resets the error state and allows cin to accept new inputs
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skips up to 1000 characters or until it reaches a new line
                cout << "Enter current day (1-" << HeartRates::daysInMonth(currentMonth, currentYear) << "): ";
                cin >> currentDay; // Prompts to choose again
            }

        // Prompts to enter current year
        cout << "Enter current year: ";
        cin >> currentYear;
            // Validate the inputted year - if it is not a valid year, it prompts to enter again
            while (cin.fail() || currentYear < 0 || currentYear < birthYear) {
                cout << "!!! Invalid \"current year\" entered. Please enter a valid year." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter current year: ";
                cin >> currentYear;
            }

        // Special case for February: if the current day is greater than the number of days in February of the given year, it prompts to enter again
        if (HeartRates::getMonthIndex(currentMonth) == 2 && currentDay > HeartRates::daysInMonth(currentMonth, currentYear)) {
            cout << "!!! Invalid \"current day\" for February in the year " << currentYear << ". Please re-enter the day. !!!" << endl;
            cout << "Enter current day (1-" << HeartRates::daysInMonth(currentMonth, currentYear) << "): ";
            cin >> currentDay;
            // Validate the inputted day if it is in the range of the month
            while (cin.fail() || currentDay < 1 || currentDay > HeartRates::daysInMonth(currentMonth, currentYear)) {
                cout << "!!! Invalid \"current day\" entered. Please enter a valid day (1-" << HeartRates::daysInMonth(currentMonth, currentYear) << "). !!!" << endl;
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Enter current day (1-" << HeartRates::daysInMonth(currentMonth, currentYear) << "): ";
                cin >> currentDay;
            }
        }
        
        // Create a HeartRates object
        HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);

        // Calculates the age of the person
        int age = person.getAge(currentMonth, currentDay, currentYear);
        // Calculates the maximum heart rate of the person
        int maxHR = person.getMaximumHeartRate(currentMonth, currentDay, currentYear);
        // Calculates the target heart rate range of the person
        int lower, upper;
        person.getTargetHeartRate(lower, upper, currentMonth, currentDay, currentYear); 

        // Displays the heart rate information of the person
        cout << endl << "--- Heart Rate Information ---" << endl;
        cout << "Name: " << person.getfirstName() << " " << person.getlastName() << endl;
        cout << "Date of Birth: " << person.getbirthMonth() << " " << person.getbirthDay() << ", " << person.getbirthYear() << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Maximum Heart Rate: " << maxHR << " bpm" << endl;
        cout << "Target Heart Rate Range: " << lower << " - " << upper << " bpm" << endl << endl;

        // Decrements entry counts 
        entry--;
        // Asks if the user wants to calculate for another person if there are still entries left
        if(entry > 0) {
            cout << "Would you like to calculate for another person? (y/n): ";
            char choice;
            cin >> choice;
            choice = tolower(choice);
            while (choice != 'y' && choice != 'n') {
                cout << "!!! Invalid input. Please enter 'y' or 'n' only. !!!" << endl;
                cout << "Would you like to calculate for another person? (y/n): ";
                cin >> choice;
                choice = tolower(choice);
            }
            // Breaks out of the loop and ends program if user enters 'n
            if (choice == 'n') {
                break;
            }  
        }
        cout << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer for the next iteration
    }

    cout << "Thank you for using this program. - Xander";
    return 0;
}