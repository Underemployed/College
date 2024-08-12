package JAVA.S5.Echo;

import java.net.ServerSocket;
import java.net.Socket;

import java.io.*;

public class EchoServer {
    
    public static void main(String[] args) {
        System.out.println("Waiting for connection...");

        try {
            ServerSocket ss = new ServerSocket(9801);
            Socket soc = ss.accept();
            System.out.println("Client Connected");
            BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream())); // getting send data
            String str = in.readLine();
            PrintWriter out = new PrintWriter(soc.getOutputStream(), true);
            out.println("Server says: " +str); // sending data back to user

            ss.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    
}
