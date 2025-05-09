/// Xander Jay C. Cagang
// CMSC 28 (K-3L) Lab Exercise 6 - Java Classes and Objects

public class Circle {
    // Private attribute of the circle class
    private double radius;

    // Default constructor of the circle class
    public Circle() {
        this.radius = 1.0;
    }

    // Parameterized constructor of the circle class - accepts radius as a parameter
    public Circle(double radius) {
        // Sets the received values as the radius
        // Validates the radius as a value greater than 0.
        if(radius <= 0) {
            System.out.println("Radius cannot be less than or equal to 0.");
            this.radius = 1.0;
        } else {
            this.radius = radius;
        }
    }

    // Getter method for the radius
    public double getRadius() {
        return radius;
    }

    // Setter method for the radius
    public void setRadius(double radius) {
        // Sets the value for the radius
        // Validates the radius as a value greater than 0.
        if(radius <= 0) {
            System.out.println("Radius cannot be less than or equal to 0.");
            this.radius = 1.0;
        } else {
            this.radius = radius;
        }
    }

    // Method to calculate the area of the circle
    public double getArea() {
        return Math.PI * radius * radius; // Returns the area from the formula A = πr²
    }

    // Method to calculate the circumference of the circle
    public double getCircumference() {
        return 2 * Math.PI * radius; // Returns the circumference from the formula C = 2πr
    }

    // Method to display the values of the circle object
    public void displayCircle() {
        // Uses the getter methods to display the values of the circle
        System.out.println("Radius: " + getRadius());
        System.out.println("Area: " + getArea());
        System.out.println("Circumference: " + getCircumference());
    }
}