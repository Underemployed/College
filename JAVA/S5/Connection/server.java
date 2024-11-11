package JAVA.S5.Connection;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

class server {
    static Scanner reader = null;
    public static void main(String args[]) throws IOException, InterruptedException {
        int port = 12345;
        System.out.println("Server started");

        ServerSocket ss = new ServerSocket(port);
        Socket client = ss.accept();
        System.out.println("Client connected");
        InputStream in = client.getInputStream();
        OutputStream out = client.getOutputStream();
        reader = new Scanner(in);

        PrintWriter sender = new PrintWriter(out, true);
        Scanner sc = new Scanner(System.in);
        String rec = "", send = "";
        
        Thread receiver =new Thread(new Runnable() {
            String rec = "";
            public void run() {
                while (!(rec = reader.nextLine()).equals("bye")) {
                    System.out.println("Client: " + rec);
                }
                
                
            }
        });

        while (!send.equals("bye")) {
            // System.out.println("Enter message: ");
            send = sc.nextLine();
            sender.println(send);
        }
        
        receiver.join();
        System.out.println("Server Closed");
        ss.close();

    }

}