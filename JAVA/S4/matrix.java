package JAVA.S4;
import java.util.*; 

public class matrix {
    static Scanner sc = new Scanner(System.in);

    static void print(String s){
        System.out.println(s);
    }


    public static void main(String[] args) {
        print("hiii");
        int m1,n1,m2,n2;
        print("Enter the no. of rows and columns of first Matrix: ");
        m1= sc.nextInt();
        n1= sc.nextInt();
        int[][] a = new int[m1][n1];

        print("Enter the first matrix:");
        for( int i=0;i<m1;i++){
            for(int j=0;j<n1;j++){
                a[i][j]=sc.nextInt();
            }
        }
        print("Enter the no. of rows and columns of 2nd Matrix: ");
        m2= sc.nextInt();
        n2= sc.nextInt();
        int[][] b = new int[m2][n2];

        print("Enter the first matrix:");
        for( int i=0;i<m2;i++){
            for(int j=0;j<n2;j++){
                b[i][j]=sc.nextInt();
            }
        }
        int c[][] =new int [m1][n2];

        for(int i=0;i<m1;i++)
            for(int j=0;i<n2;j++)
                for(int k=0;k<n1;k++)
                    c[i][j] += a[i][k]* b[k][j];
        for(int i=0;i<m1;i++){
            for(int j=0;i<n2;j++){
                System.out.print(c[i][j]+ " ");
            }
            print("");
        }


    }

}
