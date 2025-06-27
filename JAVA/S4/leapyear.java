package JAVA.S4;

public class leapyear {
    public static boolean leapyr(int n) {
        // im happy
        if (n % 400 == 0)
            return true;
        if (n % 100 == 0)
            return false;
        if (n % 4 == 0) 
            return true;
        return false;
    }

    public static void main(String[] args) {
        // Test cases
        System.out.println("Test Case 1: Year 1996");
        System.out.println("Expected: true");
        System.out.println("Result: " + leapyr(1996));

        System.out.println("\nTest Case 2: Year 2000");
        System.out.println("Expected: false");
        System.out.println("Result: " + leapyr(2000));

        System.out.println("\nTest Case 3: Year 2001");
        System.out.println("Expected: false");
        System.out.println("Result: " + leapyr(2001));

        System.out.println("\nTest Case 4: Year 2004");
        System.out.println("Expected: true");
        System.out.println("Result: " + leapyr(2004));
    }
}
