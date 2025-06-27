package JAVA.S4;

import java.util.*;

class GFG {
	// Function to check whether two strings
	// are anagram of each other
	static boolean areAnagram(char[] str1, char[] str2)
	{
        int n = str1.length;
        int m  = str2.length;

        if(n != m) return false;

        Arrays.sort(str1);
        Arrays.sort(str2);

        for(int i = 0; i < n;i++){
            if(str1[i] != (str2[i]))
            return false;
        }
        return true;


	}

	// Driver Code
	public static void main(String args[])
	{
		char str1[] = { 't', 'e', 's', 't' };
		char str2[] = { 't', 't', 'e', 's' };

		if (areAnagram(str1, str2))
			System.out.println("The two strings are"
							+ " anagram of each other");
		else
			System.out.println("The two strings are not"
							+ " anagram of each other");
	
    String myStr = "Hello, World!"; 
System.out.println(myStr.substring(7, 12));


String str = "Hello World!";
String newStr = "";
int startFrom = 2, endBefore = 5;// test startFrom and endBefore indices
char[] strArray = str.toCharArray();
for (int i = startFrom; i < endBefore; i++)
	newStr += strArray[i];
System.out.println(newStr);



    }
}
