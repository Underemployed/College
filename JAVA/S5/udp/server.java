package JAVA.S5.udp;

import java.net.*;
import java.io.*;
public class server {
    public static void main(String[] args) throws IOException, UnknownHostException, SocketException {
        DatagramSocket s = new DatagramSocket(12345);
        byte[] b = new byte[1024];
        DatagramPacket dp = new DatagramPacket(b, b.length);
        s.receive(dp);
        System.out.println(new String(dp.getData()));
        String a = "hello from server";
        byte w[] = a.getBytes();

        DatagramPacket dp1 = new DatagramPacket(b, b.length, InetAddress.getLocalHost(),12345);
        s.send(dp1);
        

        
        
    }
}
