package JAVA;

import java.util.Scanner;

public class palindrome1 {
    public static void main(String[] args) {
        int a;
        Scanner sc = new Scanner(System.in);
        String result = "not a palindrome";
        System.out.println("Enter a number: ");
        a = sc.nextInt();
        int x = a;
        int rev = 0;
        while (x > 0) {
            rev = x % 10 + rev * 10;
            x = x / 10;
        }
        if (a == rev) {
            result = "is a palindrome";
        }
        System.out.println(a + " " + result);

    }
}
