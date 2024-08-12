package JAVA.S5.chatapp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class client {

    public static void main(String[] args) {
        try {
            System.out.println("client started....");
            Socket server = new Socket("localhost", 9801);
            
            PrintWriter out = new PrintWriter(server.getOutputStream(), false);
            BufferedReader in  = new BufferedReader(new InputStreamReader(server.getInputStream()));
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String msgin = "", msgout = "";

            do {



            } while (!msgin.equals("bye"));







        } catch (UnknownHostException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
}
