package JAVA.S5.chatapp;

import java.io.*;
import java.net.*;
import java.util.Scanner;
// cd JAVA/S5/chatapp
public class server {
    static Scanner reader = null;static PrintWriter sender = null;

    public static void main(String[] args) {


        try {
            ServerSocket ss = new ServerSocket(9801);
            Socket client = ss.accept();
            System.out.println("Client connected");

            InputStreamReader client_input = new InputStreamReader(client.getInputStream());
            OutputStreamWriter client_output = new OutputStreamWriter(client.getOutputStream());
            Scanner sc = new Scanner(System.in);

            sender =  new PrintWriter(client_output,true);
            reader = new Scanner(client_input);
            

            Thread printer = new Thread(
                new Runnable() {
                    public void run(){
                        String msg = "";
                        while(true){
                            if(!(msg = reader.nextLine()).equals("bye")){
                                System.out.println("client: "+msg);
                            }else{
                                break;
                            }

                        }
                    }
                }
            );
            printer.start();


            String send =null;
            while ((send =sc.nextLine())!= "bye") {
                sender.println(send);
            }


            ss.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

        
    }
}
