package JAVA.S5.chatapp_server_client;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class client {
    static int port = 1234;
    static String host = "localhost";

    public static void main(String[] args) {
        

        try {
            Socket server = new Socket(host, port);
            // for getting input
            InputStream serverin = server.getInputStream();
            Scanner input = new Scanner(serverin); 
            // for sending data
            OutputStream serverout = server.getOutputStream();
            PrintWriter writer = new PrintWriter(serverout, true);

            writer.println("hello from client"); // send message to server
            String message = input.nextLine(); // receive message from server 

            System.out.println(message); 

        } catch (Exception e) {
        }
    }
    
}