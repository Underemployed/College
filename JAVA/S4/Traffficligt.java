package JAVA;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.event.*;
import javax.swing.*;


class Traffficligt extends JFrame implements ActionListener{

    Font myFont = new Font("Arial",Font.PLAIN,24);

    JRadioButton r1 = new JRadioButton("RED");
    JRadioButton r2 = new JRadioButton("GREEn");
    JRadioButton r3 = new JRadioButton("YELlow");

    JLabel label2 = new JLabel("Get ready");

    Color red = Color.red;
    Color yel = Color.yellow;
    Color green = Color.green;

    public Traffficligt() {

    
        ButtonGroup b = new ButtonGroup();
        r1.setSelected(true);
        r1.setFocusable(false);
        r1.addActionListener(this);
        r2.setFocusable(false);

        r2.addActionListener(this);
        r3.setFocusable(false);

        r3.addActionListener(this);
        b.add(r1);
        b.add(r2);
        b.add(r3);
        label2.setBounds(300, 300, 100, 100); // x, y, width, height
    
        JPanel panel = new JPanel();
        panel.setLayout(null); // Use null layout
        panel.add(r1);
        panel.add(r2);
        panel.add(r3);
        panel.add(label2);
        panel.setPreferredSize(getPreferredSize());

        add(panel);
        
        setVisible(true);
        setTitle("TRaffic");
        setLocationRelativeTo(null);
        setSize(800,800);
    }
    @Override
    public void paint(Graphics g){
        g.setColor(Color.black);
        g.drawOval(100, 100, 100, 100);

        g.setColor(red);
        g.fillOval(100, 100, 100, 100);

        g.setColor(Color.black);
        g.drawOval(100, 300, 100, 100);
        
        g.setColor(yel);
        g.fillOval(100, 300, 100, 100);

        g.setColor(Color.black);
        g.drawOval(100, 500, 100, 100);
        g.setColor(green);
        g.fillOval(100, 500, 100, 100);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
    
        if (r1.isSelected() == true) {
            label2.setText("Stop!?");
            red = Color.red;
            yel = getBackground();
            green = getBackground();
        } else if (r2.isSelected() == true) {
            label2.setText("Get Ready!");
            red = getBackground();
            yel = Color.yellow;
            green = getBackground();
        } else if (r3.isSelected() == true) {
            label2.setText("GOOOO!");

            red = getBackground();
            yel = getBackground();
            green = Color.green;
        }
        repaint();
    }


    
}

class Main{
    public static void main(String[] args) {
        Traffficligt a = new Traffficligt();
    }
}
