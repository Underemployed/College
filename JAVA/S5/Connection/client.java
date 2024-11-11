package JAVA.S5.Connection;

import java.io.*;

import java.net.*;
import java.util.Scanner;

class client {
    static Scanner reader;
    public static void main(String[] args) throws IOException,InterruptedException{
        System.err.println("Client started");
        Socket server = new Socket("localhost", 12345);
        System.err.println("Client connected");

        InputStream in = server.getInputStream();
        OutputStream out = server.getOutputStream();

         reader = new Scanner(in);
        PrintWriter sender = new PrintWriter(out, true);
        Scanner sc = new Scanner(System.in);
        String rec = "", send = "";

        Thread receiver = new Thread(new Runnable() {
            public void run() {
                String rec = "";
                while(
                    !(
                        (rec = reader.nextLine()).equals("bye"))
                    ){
                        System.out.println("Server: "+rec);
                    }
    

            }
        });
        receiver.start();
        while (!send.equals("bye")) {
            // System.out.println("Enter message: ");
            send = sc.nextLine();
            sender.println(send);
        }
        receiver.join();
     
        server.close();
    }
}