package JAVA;


class Method{
    int num;
    boolean put = true;
    synchronized void get(){
        while(!put){
            try {
                wait();
            } catch (InterruptedException e) {}
        }
        System.out.println("Get: "+ num);
        put = false;
        notify();
    }
    synchronized void put(int n){
        while (put) {
            try {
                wait();
            } catch (InterruptedException e) {}            
        }
        num = n;
        System.out.println("Put: "+ num);
        put = true;
        notify();
    }
}


class Manufacturer implements Runnable{
    Method A ;
    Manufacturer(Method A){
        this.A  = A;
        Thread t  = new Thread(this,"Manufacturer");
        t.start();
    }

    public void run(){
        int i = 0;
        while(true){
            A.put(i++);
            try {
                Thread.sleep(1000);
            } catch (Exception e) {}
        }
    }
}
class Buyer implements Runnable{
    Method A ;
    Buyer(Method A){
        this.A  = A;
        Thread t  = new Thread(this,"Buyer");
        t.start();
    }

    public void run(){
        int i = 0;
        while(true){
            A.get();
            try {
                Thread.sleep(1000);
            } catch (Exception e) {}
        }
    }
}
class InterThread {
    public static void main(String[] args) {
        Method A = new Method();
        new Manufacturer(A);
        new Buyer(A);

    }
}
