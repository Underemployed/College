package JAVA.S4;

import java.util.Scanner;

public class fibonacci {
    
    public static int fib(int n){
        if(n == 1 ) return 0;
        if(n == 2) return 1;
        return fib(n-1)+fib(n-2);
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter num: ");
        int n =sc.nextInt();
        System.out.println(fib(n));

    }
}
