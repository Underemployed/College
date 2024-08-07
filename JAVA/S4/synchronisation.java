package JAVA;

/**
 * synchronisation
 */
class Method {
    public static int a = 0;
    public static boolean inStock = false;// becomes true after seller puts
    
    public synchronized int get() throws InterruptedException{
        while(inStock == false) wait();
        inStock = false;
        notify();
        return a;
    }

    public synchronized int put(int newValue) throws InterruptedException{
        while (inStock == true) 
            wait();
        inStock =true;
        this.a  = newValue;
        notify();
        return a;//for printing
    }
}


class client {
    public static void main(String[] args)throws InterruptedException{
    
        Method method = new Method();
        Thread client = new Thread(new Runnable() {
            public void run(){
                for(int i = 0;i<100;i++){
                    try {
                        System.out.println("get :"+method.get());
                        Thread.sleep(1000);

                    } catch (InterruptedException e) {
                    }
                }
            }
        });
        Thread seller = new Thread(new Runnable() {
            public void run(){
                for(int i = 0;i<100;i++){
                    try {
                        System.out.println("put :"+method.put(i));
                        Thread.sleep(1000);

                    } catch (InterruptedException e) {
                    }
                }
            }
        });

        client.start();
        seller.start();
        // client.join();
        // seller.join();


    }
    // get :0
    // put :0
    // put :1
    // get :1
    // put :2
    // get :2
}
/*
no synchronisation
class Method {
    public static int a = 0;
    public static boolean put = false;
    
    public synchronized int get(){

        return a;
    }

    public synchronized int put(int a){
        this.a  = a;
        return a;
    }
}


class client {
    public static void main(String[] args) {
    
        Method method = new Method();
        Thread client = new Thread(new Runnable() {
            public void run(){
                for(int i = 0;i<100;i++){
                    System.out.println("get :"+method.get());
                }
            }
        });
        Thread seller = new Thread(new Runnable() {
            public void run(){
                for(int i = 0;i<100;i++){
                    System.out.println("put :"+method.put(i));
                }
            }
        });

        client.start();
        seller.start();


    }
}
get :0
get :0
put :0
put :1
get :0
get :2
*/