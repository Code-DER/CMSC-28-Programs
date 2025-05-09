// Xander Jay C. Cagang
// CMSC 28 (K-3L) Lab Exercise 6 - Java Classes and Objects

public class Rectangle {
    // Private attributes of the rectangle class
    private double length;
    private double width;

    // Default constructor of the rectangle class
    public Rectangle() {
        this.length = 1.0;
        this.width = 1.0;
    }

    // Parameterized constructor of the rectangle class - accepts length and width as parameters
    public Rectangle(double length, double width) {
        // Sets the received values as the length and width
        // Validates the length and width as values greater than 0.
        if(length <= 0) {
            System.out.println("Length cannot be less than or equal to 0.");
            this.length = 1.0;
        } else {
            this.length = length;
        }
        if(width <= 0) {
            System.out.println("Width cannot be less than or equal to 0.");
            this.width = 1.0;
        } else {
            this.width = width;
        }
    }

    // Getter method for the length
    public double getLength() {
        return length;
    }

    // Getter method for the width
    public double getWidth() {
        return width;
    }

    // Setter method for the length
    public void setLength(double length) {
        // Sets the value for the length
        // Validates the length as a value greater than 0.
        if(length <= 0) {
            System.out.println("Length cannot be less than or equal to 0.");
            this.length = 1.0;
        } else {
            this.length = length;
        }
    }

    // Setter method for the width
    public void setWidth(double width) {
        // Sets the value for the width
        // Validates the length as a value greater than 0.
        if(width <= 0) {
            System.out.println("Width cannot be less than or equal to 0.");
            this.width = 1.0;
        } else {
            this.width = width;
        }
    }

    // Method to calculate the area of the rectangle
    public double getArea() {
        return length * width; // Returns the area from the formula: A = l * w
    }

    // Method to calculate the perimeter of the rectangle
    public double getPerimeter() {
        return (2 * length) + (2 * width); // Returns the perimeter from the formula: P = 2l + 2w
    }

    // Method to display the values of the rectangle
    public void displayRectangle() {
        // Uses the getter methods to get the values of the rectangle
        System.out.println("Length: " + getLength());
        System.out.println("Width: " + getWidth());
        System.out.println("Area: " + getArea());
        System.out.println("Perimeter: " + getPerimeter());
    }
}