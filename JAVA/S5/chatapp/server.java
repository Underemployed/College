package JAVA.S5.chatapp;

import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class server {
    

    public static void main(String[] args) {
        

        try {
            ServerSocket ss = new ServerSocket(9801);
            Socket client = ss.accept();


            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter out = new PrintWriter(new OutputStreamWriter(client.getOutputStream()),true);
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


            String msgin ="",msgout = "";

            do {
                while(nums[i+1] == nums[i]) i++;
                msgin = in.readLine();
                out.println(msgout);
                msgout = br.readLine();
                out.println(msgout);

            } while (!msgin.equals("bye"));


        } catch (IOException e) {
            e.printStackTrace();
        }

        
    }
}
