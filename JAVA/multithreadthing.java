package JAVA;

import java.util.Scanner;

class multithreadthing extends Thread {
    private int threadnumber;
    public multithreadthing(int i){
        threadnumber = i;
    }
    @Override
    public void run() {
        for (int i = 0; i <= 3; i++) {
            System.out.println(i + " from thread number "+threadnumber);

            // if(threadnumber == 3 ) throw new RuntimeException();

            try {
                Thread.sleep(1000);

            } catch (InterruptedException e) {
                System.out.println(e);

            }
        }
    }
}

class multithread {
    public static void main(String[] args) {

        for (int i = 0; i < 5; i++) {
            // 1
            multithreadthing mything = new multithreadthing(i);
            mything.start();
        }
        throw new RuntimeException();


        // // 1
        // multithreadthing mything = new multithreadthing();
        // mything.run();

        // //2
        // multithreadthing mything2 = new multithreadthing();
        // mything2.run();
    }

}