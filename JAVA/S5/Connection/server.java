package JAVA.S5.Connection;

import java.net.ServerSocket;
import java.net.Socket;

public class server {
    
    public static void main(String[] args) {
        System.out.println("Waiting for connection...");

        try {
            ServerSocket ss = new ServerSocket(9801);
            Socket soc = ss.accept();
            System.out.println("Client Connected");
            ss.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    
}
