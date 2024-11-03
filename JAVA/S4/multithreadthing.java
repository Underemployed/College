package JAVA.S4;

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

class myRunnable implements Runnable{

    public void run() {        
        for(int i =1 ;i<100;i++){
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {}
        }
    }
        
}




public class multithreadthing {

     public static void main(String[] args) {
        // extend thread
        myThread extthreadobj = new myThread();
        System.out.println("main");

        // without class direct
        Thread threadwithoutclas= new Thread(
            new Runnable() {
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
        );// new thread closing bracket

        
        // using runnable interface
        myRunnable runableobj = new myRunnable();
        Thread runablethread = new Thread(runableobj);
    }
}