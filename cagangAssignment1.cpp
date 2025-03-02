#include <iostream>
using namespace std;

//Function Prototypes
void cagangProgramDescription();
void cagangInputIntegers(int cagangNum[], int size);
void cagangSort(int cagangNum[], int size);
void cagangSwap(int *x, int *y);
void cagangPosNeg(int cagangNum[], char cagangClassification[][2], int size);
void cagangEvenOdd(int cagangNum[], char cagangClassification[][2], int size);
void cagangShowElem(int cagangNum[], char cagangClassification[][2], int size, string title); 
//The string is used to store and print the title of the table for each changed data

// Main Function
int main() {
    //Variable Declarations
    int cagangNum[10] = {}; //Array to store the user-inputted values with size 10
    char cagangClassification[10][2] = {}; //Array to store the classification of each value of the cagangNum array
    int size = sizeof(cagangNum) / sizeof(cagangNum[0]); //Size of the cagangNum[10] array

    //Prints Introduction
    cagangProgramDescription();

    //Promtps for user inputted values and prints values
    cagangInputIntegers(cagangNum, size); 
    cagangShowElem(cagangNum, cagangClassification, size, "USER-INPUTTED NUMBERS");

    //Sorts the inputted values in descending order and prints the sorted values
    cagangSort(cagangNum, size);
    cagangShowElem(cagangNum, cagangClassification, size, "SORTED NUMBERS IN DESCENDING ORDER");

    //Checks each value if they are either positive or negative and prints out the result
    cagangPosNeg(cagangNum, cagangClassification, size);
    cagangShowElem(cagangNum, cagangClassification, size, "POSITIVE(P) OR NEGATIVE(N) CLASSIFICATION OF NUMBERS");

    //Checks each value if they are either even or odd and prints out the result
    cagangEvenOdd(cagangNum, cagangClassification, size);
    cagangShowElem(cagangNum, cagangClassification, size, "EVEN(E) OR ODD(O) CLASSIFICATION OF NUMBERS");
    
    cout << endl << "Program ended. Thank you for using this program.";
    return 0;
}

//Function for printing introduction and program description
void cagangProgramDescription() {
    cout << "====================================================" << endl;
    cout << "                Xander Jay C. Cagang                " << endl;
    cout << "                   CMSC 28 (K-3L)                   " << endl;
    cout << "          Due Date: March 2, 2025, 11:59 PM         " << endl << endl;
    cout << "This program will show how to handle arrays, loops, " << endl;
    cout << "and conditional statements in C++. This program will" << endl;
    cout << "classify and manipulate numbers in an array.        " << endl;
    cout << "====================================================" << endl;
}

//Function for user-inputted values of the array
void cagangInputIntegers(int cagangNum[], int size) {
    cout << "Please enter 10 integers." << endl;
    for(int i = 0; i < size; i++) {
        cout << "[" << i + 1 << "]: ";
        cin >> cagangNum[i];
    }
}

//Function for sorting the values in the array in descending order
void cagangSort(int cagangNum[], int size) {
    for(int i = 0; i < size - 1; i++) { //Outer loop passing through the array
        for(int j = 0; j < size - i - 1; j++) { //Inner loop iterates through the unsorted portion for each value of i
            if (cagangNum[j] < cagangNum[j + 1]) { //Condition for sorting in descending order if the current element is less than the next
                cagangSwap(&cagangNum[j], &cagangNum[j + 1]); //Function call for swapping the values by passing their addresses
            }
        }
    }
}

//Function for swapping values inside the array
void cagangSwap(int *x, int *y) { //Accepts the address of the array and swaps out its values
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//Function for classifying values in the array either as positive or negative
void cagangPosNeg(int cagangNum[], char cagangClassification[][2], int size) {
    //'P' for positive if value is greater than 0, 'N' for negative if value is less than 0, and a special case 'Z' for zero as 0 is neither positive or negative
    for(int i = 0; i < size; i++) { //Iterates through each value the cagangNum array
        if(cagangNum[i] > 0) {
            cagangClassification[i][0] = 'P'; //Stores 'P' in the first column of the cagangClassification array 
        } else if(cagangNum[i] < 0) {
            cagangClassification[i][0] = 'N'; //Stores 'N' in the first column of the cagangClassification array
        } else {
            cagangClassification[i][0] = 'Z'; //Stores 'Z' in the first column of the cagangClassification array
        }
    }
}

//Function for classifying values in the array either as even or odd
void cagangEvenOdd(int cagangNum[], char cagangClassification[][2], int size) {
    //'E' for even if the value has a remainder of 0 after divided by 2 and 'O' for odd if the value has a remainder of 1 after divided by 2
    for(int i = 0; i < size; i++) { //Iterates through each value the cagangNum array
        if(cagangNum[i] % 2 == 0) {
            cagangClassification[i][1] = 'E'; //Store 'E' in the second column of the cagangClassification array 
        } else {
            cagangClassification[i][1] = 'O'; //Store 'O' in the second column of the cagangClassification array 
        }
    }
}

//Function for showing the elements of the array after each function call
void cagangShowElem(int cagangNum[], char cagangClassification[][2], int size, string title) {
    //String title receives a string of message for the title on top of the table for each step of sorting and classification
    //This prints the elements of the array in a table format
    cout << endl << "----------------------------------------------------" << endl;
    cout << title << endl;
    cout << "     Numbers    Positive/Negative    Even/Odd       " << endl;
    cout << "----------------------------------------------------" << endl;
    for(int i = 0; i < size; i++) {
        cout << "\t" << cagangNum[i] << "\t\t" << cagangClassification[i][0] << "\t\t" << cagangClassification [i][1]<< endl;
    } //In a row, it first prints the values, then the positive or negative classification, lastly the even or odd classification per value/element
    cout << "----------------------------------------------------" << endl;
}