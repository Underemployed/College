package JAVA.S5.udp;

import java.net.*;
import java.io.*;
public class client {
    public static void main(String[] args) throws SocketException, UnknownHostException,IOException {
        DatagramSocket ds = new DatagramSocket();
        String s = "hello from client";
        byte[] b = s.getBytes();

        InetAddress address = InetAddress.getLocalHost();
        DatagramPacket packet = new DatagramPacket(b, b.length, address, 12345);
        ds.send(packet);

        byte[] buffer = new byte[1024];
        DatagramPacket dp1 = new DatagramPacket(buffer, buffer.length);
        ds.receive(dp1);
        String response = new String(dp1.getData());
        System.out.println("Server says: " + response);
    }
}
