package JAVA.S5.udp;

import java.net.*;
import java.io.*;


class UDPServer {

    public static final int BUFFER_SIZE = 1024;
    public static final int PORT = 12345;

    
    public static void main(String args[]) throws Exception {
        DatagramSocket ds = new DatagramSocket(PORT);

        System.out.println("Server is running");

        byte[] buffer = new byte[BUFFER_SIZE];
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);
        ds.receive(packet);

        System.out.println(new String(packet.getData()));


    }

}