package JAVA.S5.chatapp_server_client;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class server {
    
    public static void main(String[] args) {
        System.out.println("Waiting for connection...");

        try {
            ServerSocket ss = new ServerSocket(1234);
            Socket client = ss.accept();
            System.out.println("Client Connected");
            // for getting input
            InputStream clientIn = client.getInputStream();
            Scanner input = new Scanner(clientIn); 
            // for sending data
            OutputStream clientOut = client.getOutputStream();
            PrintWriter writer = new PrintWriter(clientOut, true);

            String message = input.nextLine(); // recive message from client
            System.out.println(message);


            writer.println("Hello from server"); // send message to client



            ss.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    
}
