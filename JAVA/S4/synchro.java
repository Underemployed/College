


package JAVA.S4;
import java.lang.*;
class synchro {
    public static void main(String[] args) throws Exception {
        Counter c  = new Counter();
        c.increment();
        Thread t1 = new Thread(new Runnable(){
            public void run(){
                for(int i =1;i<10000;i++){
                    c.increment();
                }
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                for(int i =1;i<10000;i++){
                    c.increment();
                }
            }
        });
        t2.start();
        t1.start();

 
            t1.join();
            t2.join();

        System.out.println("Count "+ c.count);

    }
   
}
class Counter {
    int count;
    public  void increment(){
        count++;
    }
    
}