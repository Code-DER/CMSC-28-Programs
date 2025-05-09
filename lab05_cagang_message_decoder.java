// Xander Jay C. Cagang
// CMSC 28 (K-3L) Laboratory Activity 5 - Message Decoder

import java.util.Scanner; // Imports the Scanner class for user input

public class lab05_cagang_message_decoder {
    public static void main(String[] args) {
        // Declares the scanner object
        Scanner input = new Scanner(System.in);

        System.out.println("Welcome to the Message Decoder Program in Java!");
        System.out.println("This program will decode your message from your number (1-26) inputs to letters (A-Z).");

        //Variable Declarations
        String message;
        String[] numbers;
        boolean isWithinRange;

        // Loop for error handling to check if inputted value is within range of 1-26 or if it is a number
        do {
            // Initializes the boolean variable to true for the loop
            isWithinRange = true; 

            // Asks the user to input numbers as the message or word
            System.out.print("Enter a line of numbers (1-26) separated by spaces: ");
            message = input.nextLine();

            // Split the message into individual numbers
            numbers = message.split(" ");

            // Error handling for loop to check if the inputted value has an "83" in it
            for (String numStr : numbers) {
                // Special case for the number 83
                // Prints message if an input of 83 is detected anywhere. Statement is set first so that it won't be handled as invalid
                if(numStr.equals("83")) { // Checks if the inputted string is equal to "83"
                    System.out.println("Legen...wait for it.......DARY!");
                    input.close(); // Closes the scanner
                    return; // Exits the program
                }
            }

            // Error handling for loop to check if the inputted value is a character or within range
            for (String numStr : numbers) {
                // Calls isNumeric() method to check if the input is a number or character
                if (!isNumeric(numStr)) {
                    System.out.println("Invalid input: " + numStr + " (Enter numbers only!)");
                    isWithinRange = false;
                    break;
                }

                // Converts the string num to an integer number
                int number = Integer.parseInt(numStr);
                
                // Checks if the number is within the range of 1 to 26
                if (number < 1 || number > 26) {
                    System.out.println("Invalid number: " + numStr + " (Enter numbers from 1 to 26 only!)");
                    isWithinRange = false;
                    break;
                }
            }
        } while (!isWithinRange);
        
        // Decodes the message
        StringBuilder decoded = new StringBuilder(); // StringBuilder is used to build the decoded message, it allows to append letters to the "decoded" variable

        // Loops through each number and assigns it to string num
        for(String numStr : numbers) {
            // Converts the string num to an integer number
            int number = Integer.parseInt(numStr);
            
            // Converts the number to its corresponding character through the ASCII code
            char letter = (char)(number + 64);

            // Appends the letter to the decoded message for printing
            decoded.append(letter);
        }

        // Prints the final decoded message
        System.out.println("Decoded Message: " + decoded);

        //Closes the scanner
        input.close();
    }
    
    // Method to check if the input is a number or character
    public static boolean isNumeric(String str) {
        // Loops through the string and assigns it to char c
        for (char c : str.toCharArray()) {
            // If the input is not a digit, return false
            if (!Character.isDigit(c)) {
                return false;
            }
        }
        // If all the characters are digits, return true
        return true;
    }
}