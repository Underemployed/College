package JAVA.S5.Connection;

import java.net.Socket;

public class client {


    public static void main(String[] args) {
        
        try {
            System.out.println("Client Started");
            Socket soc = new Socket("localhost", 9801);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}