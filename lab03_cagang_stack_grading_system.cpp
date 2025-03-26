// Xander Jay C. Cagang
// CMSC 28 (K-3L)

#include <iostream>
#include <iomanip> // For setting the decimal point at 2
#include <cmath> // For rounding up decimals
using namespace std;
#define MAX_NUM_OF_SCORES 10 // Set the maximum number of scores as 10

// Struct for the stack
struct Stack { 
    float scores[MAX_NUM_OF_SCORES];
    int top;
};

// Function Prototypes
bool isEmpty(Stack &stack);
bool isFull(Stack &stack);
void addScore(Stack &stack);
void viewLastScore(Stack &stack);
void undoLastScore(Stack &stack);
void displayGrade(Stack &stack);
float total_calculation(Stack &stack);
float average_calculation(Stack &stack);
float grading_scale(float average);
void displayRecords(Stack &stack);

// Global Variables
float grade;
float score;

int main() {
    Stack StudentScores; //Object of the stack
    StudentScores.top = -1; //Sets top -1
    int choice;

    // Main menu options
    cout << "1. Add student Score" << endl;
    cout << "2. View Last Entered Score" << endl;
    cout << "3. Undo Last Entered Score" << endl;
    cout << "4. Display Grade and All Entered Score" << endl;
    cout << "5. Exit" << endl << endl;
    do {
        cout << "Enter your choice: ";
        cin >> choice; //User inputted choice to pick what to do
        switch(choice) {
            case 1:
                addScore(StudentScores); // Prompts the user to add score
                break;
            case 2:
                viewLastScore(StudentScores); // Displays the inputted last score
                break;
            case 3:
                undoLastScore(StudentScores); // Removes the last inputted score
                break;
            case 4:
                displayGrade(StudentScores); // Displays all inputted scores, average, and grade
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

bool isEmpty(Stack &stack) {
    return stack.top == -1; //Returns true if stack is empty, or set as -1
}

bool isFull(Stack &stack) {
    return stack.top == MAX_NUM_OF_SCORES - 1; //Returns true if stack is full of scores
}

void addScore(Stack &stack) { //Function to add new student score to the stack
    if(isFull(stack)) {
        cout << "Maximum number of scores reached! Cannot add new score :(" << endl; // Exits the function when stack is full
    } else { //Prompts the user to enter score if stack is not full
        cout << "Enter score: ";
        cin >> score;
        stack.scores[++stack.top] = score; //Adds the score to the top of the stack
        cout << "Student score added successfully!" << endl;
        displayRecords(stack);
    }
}

void viewLastScore(Stack &stack) { // Function to display the score added without removing it
    if(isEmpty(stack)) {
        cout << "No entered scores. :(" << endl << endl; 
    } else {
        cout << "Last entered score: " << stack.scores[stack.top] << endl; // Displays the last entered score or the score at the top of the stack
        displayRecords(stack);
    }
}

void undoLastScore(Stack &stack) { // Function to remove the most recent score
    if (isEmpty(stack)) {
        cout << "No scores available, can't pop." << endl << endl;
    } else {
        stack.top--; // Removes the score on the top of the stack
        cout << "Student score removed successfully!" << endl;
        displayRecords(stack);
    }
}

void displayGrade(Stack &stack) { // Function to display all student scores
    if(isEmpty(stack)) {
        cout << "No scores to be displayed" << endl << endl;
    } else {
        displayRecords(stack); // Prints the current grades
        cout << "Scores Entered: " << endl;
        for (int i = stack.top; i >= 0; i--) { // Prints the inputted scores in Last In, First Out arrangement
            cout << stack.scores[i] << endl;
        }
        cout << endl;
    }
}

float total_calculation(Stack &stack) { // Function to calculate the total of the scores
    float total = 0;
    for (int i = 0; i <= stack.top; i++) { // Goes through each of the subjects
        total += stack.scores[i]; // Add up the scores of all subjects
    }
    return total; // Returns the total value
}

float average_calculation(Stack &stack) { // Function to calculate the average of the scores
    if(isEmpty(stack)) {
        cout << "No scores to be calculated." << endl << endl;
    }
    return round((total_calculation(stack) / (stack.top + 1)) * 100) / 100; // Returns the average of the total scores rounded up to 2 decimal points
}

float grading_scale(float average) { // Function to convert the average into the final grade
    if(average >= 96 && average <= 100) { //[96, 100] = 1.00
        grade = 1.00; 
    }else if(average >= 92 && average < 96) { //[92, 96) = 1.25
        grade = 1.25; 
    }else if(average >= 88 && average < 92) { //[88, 92) = 1.50
        grade = 1.50;
    }else if(average >= 84 && average < 88) { //[84, 88) = 1.75
        grade = 1.75;
    }else if(average >= 80 && average < 84) { //[80, 84) = 2.00
        grade = 2.00;
    }else if(average >= 75 && average < 80) { //[75, 80) = 2.25
        grade = 2.25; 
    }else if(average >= 70 && average < 75) { //[70, 75) = 2.50
        grade = 2.50; 
    }else if(average >= 65 && average < 70) { //[65, 70) = 2.75
        grade = 2.75; 
    }else if(average >= 60 && average < 65) { //[60, 65) = 3.00
        grade = 3.00; 
    }else if(average < 60) { //below 60 = 5.00
        grade = 5.00; 
    }
    return grade; //returns the grade based on the student's average
}

void displayRecords(Stack &stack) { // Function to display the total, average, and grade
    if(isEmpty(stack)) {
        cout << "No scores entered." << endl; // Exits if stack is empty
    }

    float total = total_calculation(stack); // Calls total calculation function to store the total
    float average = average_calculation(stack); // Calls the average calculation function to store the average
    float grade = grading_scale(average); // Calls the grading scale function to store the grade

    cout << fixed << setprecision(2);
    cout << "Total: " << total << ", Average: " << average << ", Grade: " << grade << endl << endl;
}