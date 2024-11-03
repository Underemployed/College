package JAVA.S5.chatapp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;


public class client {
    static Scanner reader = null;static PrintWriter sender = null;

    public static void main(String[] args) {
        try {
            System.out.println("client started....");
            Socket server = new Socket("localhost", 9801);


            InputStreamReader server_input = new InputStreamReader(server.getInputStream());
            OutputStreamWriter server_output = new OutputStreamWriter(server.getOutputStream());

            sender =  new PrintWriter(server_output,true);
            reader = new Scanner(server_input);
            Scanner sc = new Scanner(System.in);

            
            Thread printer = new Thread(
                new Runnable() {
                    public void run(){
                        String msg = "";
                        while(true){
                            if(!(msg = reader.nextLine()).equals("bye")){
                                    System.out.println("server: "+msg);
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


    
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
}
