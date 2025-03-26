// Xander Jay C. Cagang
// CMSC 28 (K-3L)

#include <iostream>
#include <iomanip> // For setting the decimal point at 2
#include <cmath> // For rounding up decimals
#include <limits> // For error handling
using namespace std;
#define MAX_NUM_OF_SCORES 10 // Set the maximum number of scores as 10


class scoreStack { // Score stack class
    private:
        float scores[MAX_NUM_OF_SCORES];
        int top;

    public:
        scoreStack() { top = -1; }; // Constructor

        bool isEmpty() { return top ==  -1; } // Checks if stack is empty

        bool isFull() { return top == MAX_NUM_OF_SCORES - 1; } // Checks if stack is full

        void addScore(float score) { // Push Method
            if(isFull()) {
                cout << "Maximum number of scores reached! Cannot add new score :(" << endl; // Exits the function when stack is full
            } else { //Prompts the user to enter score if stack is not full
                scores[++top] = score; //Adds the score to the top of the stack
                cout << "Student score added successfully!" << endl;
                displayRecords();
            }
        }
        
        void viewLastScore() { // Peek Method
            if(isEmpty()) {
                cout << "No entered scores. Stack empty. :(" << endl << endl; 
            } else {
                cout << "Last entered score: " << scores[top] << endl; // Displays the last entered score or the score at the top of the stack
                displayRecords();
            }
        }

        void undoLastScore() { // Pop Method
            if (isEmpty()) {
                cout << "No scores available, can't pop." << endl << endl;
            } else {
                top--; // Removes the score on the top of the stack
                cout << "Student score removed successfully!" << endl;
                displayRecords();
            }
        }

        void displayGrade() { // Display method
            if(isEmpty()) {
                cout << "No scores to be displayed." << endl << endl;
            } else {
                displayRecords(); // Prints the current grades
                cout << "Scores Entered: " << endl;
                for (int i = top; i >= 0; i--) { // Prints the inputted scores in Last In, First Out arrangement
                    cout << scores[i] << endl;
                }
                cout << endl;
            }
        }

        float total_calculation() { // Method to GET the total of the scores
            float total = 0;
            for (int i = 0; i <= top; i++) { // Goes through each of the subjects
                total += scores[i]; // Add up the scores of all subjects
            }
            return total; // Returns the total value
        }

        float average_calculation() { // Method to GET the average of the scores
            if(isEmpty()) {
                cout << "No scores to be calculated." << endl << endl;
                return 0;
            }
            return round((total_calculation() / (top + 1)) * 100) / 100; // Returns the average of the total scores rounded up to 2 decimal points
        }

        float grading_scale(float average) { // Method to GET the the final grade
            if(average >= 96 && average <= 100) { return 1.00; } //[96, 100] = 1.00
            else if(average >= 92 && average < 96) { return 1.25; } //[92, 96) = 1.25
            else if(average >= 88 && average < 92) { return 1.50; } //[88, 92) = 1.50 
            else if(average >= 84 && average < 88) { return 1.75; } //[84, 88) = 1.75
            else if(average >= 80 && average < 84) { return 2.00; } //[80, 84) = 2.00
            else if(average >= 75 && average < 80) { return 2.25; } //[75, 80) = 2.25
            else if(average >= 70 && average < 75) { return 2.50; } //[70, 75) = 2.50
            else if(average >= 65 && average < 70) { return 2.75; } //[65, 70) = 2.75
            else if(average >= 60 && average < 65) { return 3.00; } //[60, 65) = 3.00
            else if(average < 60) { return 5.00; } //below 60 = 5.00
            return -1; // For error handling
        }

        void displayRecords() { // Method to display the total, average, and grade
            if(isEmpty()) {
                cout << "No scores entered." << endl; // Exits if stack is empty
            }
            float total = total_calculation(); // Calls total calculation function to store the total
            float average = average_calculation(); // Calls the average calculation function to store the average
            float grade = grading_scale(average); // Calls the grading scale function to store the grade
            cout << fixed << setprecision(2);
            cout << "Total: " << total << ", Average: " << average << ", Grade: " << grade << endl << endl;
        }
};

int main() {
    scoreStack StudentScores; //Object of the scoreStack
    int choice;
    float score;

    // Main menu options
    cout << "1. Add student Score" << endl;
    cout << "2. View Last Entered Score" << endl;
    cout << "3. Undo Last Entered Score" << endl;
    cout << "4. Display Grade and All Entered Score" << endl;
    cout << "5. Exit" << endl << endl;

    do {
        cout << "Enter your choice: ";
        cin >> choice; //User inputted choice to pick what to do

        while (cin.fail()) { // Error handling for inputted characters
            cout << "Invalid input! Choose from 1 to 5 only." << endl;
            cin.clear(); // Resets the error state and allows cin to accept new inputs
            cin.ignore(1000, '\n'); // skips up to 1000 characters or until it reaches a new line
            cout << "Enter your choice: ";
            cin >> choice; // Prompts to choose again
        }

        switch(choice) {
            case 1:
                do {
                    cout << "Enter score: ";
                    cin >> score;
                    while (cin.fail()) { // Error handling for inputted characters
                        cout << "Invalid input! Enter score from 0 - 100 only." << endl;
                        cin.clear(); // Resets the error state and allows cin to accept new inputs
                        cin.ignore(1000, '\n'); // skips up to 1000 characters or until it reaches a new line
                        cout << "Enter score: ";
                        cin >> score; // Prompts to choose again
                    }
                    if (score < 0 || score > 100) {
                        cout << "Please enter a score from 0 to 100 only." << endl; // Error message 
                    }
                } while (score < 0 || score > 100); // Error handling for values less than 0 and greater than 100
                StudentScores.addScore(score); // Passes the inputted score in the function
                break;
            case 2:
                StudentScores.viewLastScore(); // Displays the last inputted score
                break;
            case 3:
                StudentScores.undoLastScore(); // Removes the last inputted score
                break;
            case 4:
                StudentScores.displayGrade(); // Displays all inputted scores, average, and grade
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Choose from 1 to 5 only." << endl;
            }
    } while(choice != 5); // Exits program if user enters 5
    return 0;
}