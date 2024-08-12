package JAVA.S5.Echo;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.Buffer;

public class EchoClient {


    public static void main(String[] args) {
        
        try {
            System.out.println("Client Started");
            Socket soc = new Socket("localhost", 9801);
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter a string:");
            String str = userInput.readLine();
            PrintWriter out = new PrintWriter(soc.getOutputStream(), true); //auto flush true getting data from keyboard
            out.println(str); // sending to server
            out.flush();// not needed if auto flush true

            BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream())); // getting data from server
            System.out.println(in.readLine()); // printing data
 
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}