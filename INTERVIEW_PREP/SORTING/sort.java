package INTERVIEW_PREP.SORTING;
import java.io.*;
class sort {


    public static void reset(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            
        }

    }

    public void swap(int arra[], int i, int j) {
        int temp = arra[i];
        arra[i] = arra[j];
        arra[j] = temp;
    }




    public void bubble_sort(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr,j,j+1);
                }
            }
        }

    }

    

    public static void main(String args[]) {

        int arr[] = { 2, 5, 3, 4, 5 };
        // new sort().bubble_sort(arr);

        

    }
    
}