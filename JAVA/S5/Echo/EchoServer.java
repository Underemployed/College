package JAVA.S5.Echo;
import java.io.*;
import java.net.*;
import java.util.*;

/**
 * EchoServer
 */
public class EchoServer {


    public static void main(String[] args) {
            try {
                System.out.println("Server Started");
                ServerSocket ss = new ServerSocket(9801);
                Socket client = ss.accept();
                System.out.println("Client connected");
                InputStream input = client.getInputStream();
                OutputStream output = client.getOutputStream();

                Scanner reader = new Scanner(input);
                PrintWriter sender = new PrintWriter(output,true);
                String m = "";

                while(!(m = reader.nextLine()).equals("bye")){
                    sender.println(m);
                    System.out.println(m);
                }
                ss.close();
                
            } catch (IOException e) {
            }        
    }
}