package JAVA;

import java.util.Scanner;

class myThread extends Thread{
    @Override
    public void run(){
        for(int i =1 ;i<100;i++){
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
            }
        }
    }
}

public class multithreadthing {

     public static void main(String[] args) {
        
        System.out.println("main");
     }
}