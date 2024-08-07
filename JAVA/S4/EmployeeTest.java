package JAVA.LAB;


import java.util.*;


class Employee{

    String name;
    int s ;
    static List<Employee> full = new ArrayList<>();
    Employee(){

    }
    Employee(String a, int sal){
        name = a;
        s =sal;
        full.add(this);
    }

    void total(){
        System.out.println(full.size());
    }

    void find(String n){
        for(Employee a : full){
            if(a.name.equals(n)){
                System.out.println(n+ " " +a.s );
                return;                
            }
        }
        System.out.println("not found");

    }






    

}

public class EmployeeTest {

    public static void main(String[] args) {
        // Creating Employee objects
        new Employee("John Doe", 50000);
        new Employee("Jane Doe", 60000);
        new Employee("Jim Beam", 55000);

        // Testing total method
        new Employee().total(); // Using an empty Employee object to call total

        // Testing find method
        new Employee().find("Jane Doe"); // Should find Jane Doe
        new Employee().find("Jack Daniels"); // Should not find Jack Daniels
    }
}