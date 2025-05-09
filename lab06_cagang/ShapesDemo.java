// Xander Jay C. Cagang
// CMSC 28 (K-3L) Lab Exercise 6 - Java Classes and Objects

public class ShapesDemo {

    public static void main(String[] args) {
        //Objects of the Rectangle and Circle class
        Rectangle rectangle_1 = new Rectangle(); // Rectangle 1 object - default constructor
        Rectangle rectangle_2 = new Rectangle(5.0, 10.0); // Rectangle 2 object - Passes values 5.0 and 10.0 through the parameterized constructor
        Circle circle_1 = new Circle(); // Circle 1 object - Default constructor
        Circle circle_2 = new Circle(3.0); // Circle 2 object - Passes the value 3.0 through the parameterized constructor
        
        // Display values
        System.out.println("\nRectangle 1:");
        rectangle_1.displayRectangle(); // Displays the default values of the rectangle object

        System.out.println("\nRectangle 2: ");
        rectangle_2.displayRectangle(); // Displays the values of the rectangle object with parameters

        System.out.println("\nCircle 1: ");
        circle_1.displayCircle(); // Displays the default values of the circle object

        System.out.println("\nCircle 2: ");
        circle_2.displayCircle(); // Displays the values of the circle object with parameters

        System.out.println("\nRectangle 1: ");
        rectangle_1.setLength(15.0); // Sets the lenghth of the rectangle object to 15.0 using the setLenghth() method
        rectangle_1.setWidth(-2.0); // Sets the width of the rectangle object to -2.0 using the setWidth() method
        rectangle_1.displayRectangle(); // Displays the values of rectangle 1 after setting its length and width

        System.out.println("\nCircle 1: ");
        circle_1.setRadius(4.5); // Sets the radius of circle 1 to 4.5 using the setRadius() method
        circle_1.displayCircle();
    }
}
