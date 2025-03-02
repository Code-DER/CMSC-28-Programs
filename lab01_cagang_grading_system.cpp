// Xander Jay C. Cagang
// CMSC 28 (K-3L) - Lab 01

#include <iostream> // For input and output
#include <cstdlib> // For system("cls") - To clear the console, for system("pause") - to pause and wait for user to enter any key to continue
#include <iomanip> // For setting decimal places when printing float values, uses "fixed" and "setprecision()"
#include <limits> // For cin.ignore for error handling 

using namespace std;

// Function prototypes
void introduction();
void exit();
void enter_student_details();
float total_calculation(float subjects_container[], int num_of_subs);
float average_calculation(float total_score, int num_of_subs);
void display_student_records();
float grading_scale(float average);

// Variable declarations
string student_Lastname; 
float total_score = 0;
float grade = 0;
float average = 0;
int menu_choice = 0;
int num_of_subs = 0;
bool student_has_data = false; // Sets as false when there is no data inputted for the students yet

// Main Function
int main() {
    string student_list[10] = {"Cagang", "Buhayan", "Lorejo", "Gonzales", "Lambayao", "Cantero", "Perez", "Mangaron", "Medina", "Moran"}; // Populated list/array of students
    int number_of_students = sizeof(student_list) / sizeof(student_list[0]); // To get the size of the student list array
    introduction(); // Prints introductory text of the program

    do { // do-while loop for the main program
        bool on_the_list = false; // Check for the student on the list set to false for the while loop

        while (!on_the_list) { // To check inputted student surname if it is in the student_list
            cout << "Enter student surname: ";
            cin >> student_Lastname;

            for (int i = 0; i < number_of_students; ++i) { // Goes through student_list to match the inputted surname from the user
                if (student_list[i] == student_Lastname) {
                    on_the_list = true; // Turns to true once student is found on the list
                    break;
                }
            }
            if (!on_the_list) { // If student not found, enter again
                cout << "Student not found. Try again" << endl;
            }
        } 

        do { // do-while loop for the main menu
            cout << "Student Grading System" << endl;
            cout << "\t[1] Enter Student Details" << endl;
            cout << "\t[2] Display Student Results" << endl;
            cout << "\t[3] Compute for another student" << endl;
            cout << "\t[4] Exit" << endl;
            cout << "Enter your choice: ";
            cin >> menu_choice; // User input for the main menu

            while (cin.fail()) { // Error handling for inputted characters
                cout << "Invalid input! Choose from 1 to 4 only." << endl;
                cin.clear(); // Resets the error state and allows cin to accept new inputs
                cin.ignore(1000, '\n'); // skips up to 1000 characters or until it reaches a new line
                cout << "Enter your choice: ";
                cin >> menu_choice; // Prompts to choose again
            }

            switch(menu_choice) {
                case 1:
                    system("cls");  
                    enter_student_details(); // Calls the function for user to enter student details
                    break;
                case 2:
                    system("cls"); 
                    display_student_records(); // Calls the function to display the student records recorded by the user
                    break;
                case 3:
                    total_score = 0; // Resets to 0 when choosing another student to clear previous records
                    average = 0;
                    grade = 0;
                    student_has_data = false;
                    system("cls"); 
                    cout << endl << "Enter another student surname..." << endl << endl;
                    break;
                case 4:
                    system("cls"); 
                    break; // Exits/Ends the program
                default:
                    system("cls");
                    cout << "Invalid input! Choose from 1 to 4 only." << endl; // Error handling for the switch statement, it won't accept other values
            }
        } while (menu_choice != 4 && menu_choice != 3); // Main menu do-while loop - loops until 3 or 4 is chosen
    } while (menu_choice != 4); // Main function do-while loop - loops until 4 is chosen
    exit(); // Prints exit statements right before the program ends
    return 0;
}

// Introduction Function
void introduction() {
    cout << "====================================================" << endl;
    cout << "Welcome to Xander's Student Grading System using C++" << endl;
    cout << "                   CMSC 28 (K-3L)                   " << endl;
    cout << "====================================================" << endl;
}

// Exit Function
void exit() {
    cout << "====================================================" << endl;
    cout << "Thank you for using Xander's Student Grading System!" << endl;
    cout << "                   Program Ended.                   " << endl;
    cout << "====================================================" << endl;
}

// Function for entering details of students
void enter_student_details() {
    total_score = 0; // Resets to 0 when the user wants to enter new subject counts and scores
    average = 0;
    grade = 0;

    cout << "=================================================" << endl;
    cout << "How many subjects do you want to enter scores in?" << endl;
    cout << "Number of subjects: ";
    cin >> num_of_subs; // User input on the number of subjects

    while (cin.fail()) { // Error handling on inputting characters
        cout << "Invalid input! Enter number > 0 only" << endl;
        cin.clear(); // Resets the error state and allows cin to accept new inputs
        cin.ignore(1000, '\n'); // skips up to 1000 characters or until it reaches a new line
        cout << "Number of subjects: ";
        cin >> num_of_subs; // Prompts to input again
    }
    while (num_of_subs <= 0) { // Handles error when user inputs values <= 0
        cout << "Enter a valid number of subjects." << endl;
        cin >> num_of_subs; // Prompts to input again
    }

    float subjects_container[num_of_subs] = {}; // Declaration for the array of the container of the subjects with its size based on the inputted number of subjects

    for (int i = 0; i < num_of_subs; i++) { // Goes through the subject_container to input scores per subject
        float subj_score; // Declaration for subject score
        cout << "Enter score of Subject " << i + 1 << ": ";
        cin >> subj_score; // User inputs subject score
        
        while (subj_score < 0 || subj_score > 100) { // Score input must only from 0 to 100
            cout << "Enter score from 0 to 100 only." << endl;
            cout << "Enter score of Subject " << i + 1 << ": ";
            cin >> subj_score; // Prompts to enter score again
        }

        subjects_container[i] = subj_score; // Stores the score into the subject in the container
    }

    total_score = total_calculation(subjects_container, num_of_subs); // Calls total_calculation function to get the total scores from the subjects and assigns it to total_score
    average = average_calculation(total_score, num_of_subs); // Calls average_calculation function to get the average of the scores and assigns it to average
    grade = grading_scale(average); // Calls grading_scale to convert the average to its equivalent grade
    student_has_data = true; // Set as true when data is inputted for students
    cout << endl << "Recorded successfully!" << endl;
    cout << "=================================================" << endl;
    system("pause"); 
    system("cls"); 
}

// Function for calculating the total score
float total_calculation(float subjects_container[], int num_of_subs) {
    float total = 0;
    for (int i = 0; i < num_of_subs; i++) { // Goes through each of the subjects
        total += subjects_container[i]; // Add up the scores of all subjects
    }
    return total; // Returns the total value
}

// Function for calculating the average of the scores
float average_calculation(float total_score, int num_of_subs) {
    return total_score / num_of_subs; // Returns the average of the total scores
}

// Function for displaying the student information
void display_student_records() {
    cout << "==============================" << endl;
    cout << "Last Name: " << student_Lastname << endl; // Prints the student's last name

    if (!student_has_data) { // Prints when there is no available data yet
        cout << "Total Score: N/A" << endl;
        cout << "Average: N/A" << endl;
        cout << "Grade: N/A" << endl;
    } else { // Prints when data has already been inputted
        cout << "Total Score: " << fixed << setprecision(2) << total_score << endl;
        cout << "Average: " << fixed << setprecision(2) << average << endl;
        cout << "Grade: " << fixed << setprecision(2) << grade << endl;
    }

    cout << "==============================" << endl;
    system("pause");
    system("cls");
}

// Function converting the range of averages to its equivalent grades
float grading_scale(float average) {
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