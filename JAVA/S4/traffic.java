package JAVA.LAB;

import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

class traffic extends JFrame implements ActionListener{
    JRadioButton r1,r2,r3;
    Color yel,red,green;
    String text;
    JLabel label;

    public traffic(){
        setSize(1200,1000);

        r1 = new JRadioButton("red");
        r2 = new JRadioButton("yellow");
        r3 = new JRadioButton("blue");

        label = new JLabel(text);
        label.setBounds(500,500,100,50);
        

        ButtonGroup bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        bg.add(r3);

        JPanel panel = new JPanel();
        panel.add(r1);
        panel.add(r2);
        panel.add(r3);

        panel.add(label);

        add(panel);
        setVisible(true);
        
        setLocationRelativeTo(null);
        r1.addActionListener(this);
        r2.addActionListener(this);
        r3.addActionListener(this);

    }


    public void actionPerformed(ActionEvent e){
        if(r1.isSelected()){
            red =  Color.red;
            yel =  Color.black;
            green = Color.black;
            text = "Stop";
            label.setText(text);
        }else if(r2.isSelected()){
            red = Color.black;
            yel =  Color.yellow;
            green = Color.black;
            text = "Get ready";
            label.setText(text);
        }else{
            red = Color.black;
            yel =  Color.black;
            green = Color.green;
            text = "Go";
            label.setText(text);
        }
        repaint();
    }
    public void paint(Graphics g){

        g.setColor(red);
        g.fillOval(100,100,100,100);
        
        g.setColor(yel);
        g.fillOval(100,300,100,100);

        g.setColor(green);
        g.fillOval(100,500,100,100);

    }


    
    public static void main(String[] args) {
        traffic a = new traffic();
    }

// text didnt work so dont bother

}
