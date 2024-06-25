package JAVA;

import java.util.Scanner;

<<<<<<< HEAD
class multithreadthing implements Runnable {
    private int threadnumber;
    public multithreadthing(int i){
        threadnumber = i;
    }
    @Override
    public void run() {
        for (int i = 0; i <= 5; i++) {
            System.out.println(i + " from thread number "+threadnumber);

            // if(threadnumber == 3 ) throw new RuntimeException();

=======
class myThread extends Thread{
    @Override
    public void run(){
        for(int i =1 ;i<100;i++){
            System.out.println(i);
>>>>>>> 30e68615f6b76fbda43bcda064d4d2df0af060d6
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
            }
        }
    }
}

class myRunnable implements Runnable{

<<<<<<< HEAD
        for (int i = 0; i < 5; i++) {
            // 1
            multithreadthing mything = new multithreadthing(i);
            Thread mythread = new Thread(mything);
            mythread.start();
            mythread.isAlive();
           
        }


        // // 1
        // multithreadthing mything = new multithreadthing();
        // mything.run();

        // //2
        // multithreadthing mything2 = new multithreadthing();
        // mything2.run();
=======
    public void run() {        
        for(int i =1 ;i<100;i++){
            System.out.println(i);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {}
        }
>>>>>>> 30e68615f6b76fbda43bcda064d4d2df0af060d6
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