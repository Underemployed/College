package JAVA.S5.Echo;

import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class EchoClient {
    static  Scanner reader ;
    static  PrintWriter sender;

    public static void main(String[] args) {

        try {
            System.out.println("Client Started");
            Socket server = new Socket("localhost", 9801);

            InputStream input = server.getInputStream();
            OutputStream output = server.getOutputStream();

            Scanner sc = new Scanner(System.in);
            reader = new Scanner(input);
            sender = new PrintWriter(output,true);

            // print all received msg 
            Thread printer = new Thread(
                new Runnable(){
                    public void run(){
                        String m ="";
                        while (true){
                            if(!((m = reader.nextLine()).equals("bye"))) 
                            System.out.println("Server: "+m);
                            else break;
                        }
                    }

                }
            );
            printer.start();

            String m ="";
            while (true) {
                if (!((m = sc.nextLine()).equals("bye"))) sender.println(m);
                else break;
            }
            printer.stop();
            server.close();


        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}