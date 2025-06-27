package JAVA.S4;

import java.util.Random;

public class summaxmin {
    
    public static void main(String args[]){
        int n = 5;
        int arr[] = new int[n];
        Random r = new Random();

        for(int i = 0; i < n; i++ ){
            arr[i] = r.nextInt(10);
        }
        int min = arr[0];
        int max = arr[0];
        for(int i = 0; i < n; i++){
            System.out.print(arr[i]+" ");
            if(min>arr[i]) min = arr[i];
            if(max<arr[i]) max = arr[i];
        }
        System.out.println();
        System.out.println("min "+min+" \nmax "+max);

    }

}
