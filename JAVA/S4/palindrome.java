package JAVA.S4;
import java.util.regex.*;

public class palindrome {
    public static boolean isPalindrome(String s) {
        s = s.toLowerCase().replaceAll("[^a-z0-9]","");


        int left = 0;
        int right = s.length() - 1;
        
        while (left <= right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false; 
            }
            left++;
            right--;
        }
        
        return true; 
    }
    public static void main(String[] args) {
    System.out.println("Malayalam:"+ isPalindrome("Mayalayam--"));
    }
}
