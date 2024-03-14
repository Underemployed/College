package JAVA;

import java.util.Scanner;

public class fibonnaci2 {
    static int fibonnaci(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonnaci(n - 1) + fibonnaci(n - 2);
    }

    public static void main(String args[]) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n:");

        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print(fibonnaci(i)+" ");
        }

    }
}
