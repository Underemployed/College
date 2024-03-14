package JAVA;

import java.util.List;
import java.util.ArrayList;

public class Employeedata {

    public static void main(String[] args) {
        Employee a = new Employee("wow", 1000);

        new Employee("nithin", 11000);
        Employee.sum();
    }
}

/* using ArrayList */
// class Employee {

// String name;
// int salary;
// static List<Employee> employees = new ArrayList<>();

// public Employee(String name, int salary) {
// this.name = name;
// this.salary = salary;
// employees.add(this);
// }

// static void sum() {
// int s = 0;
// for (Employee a : employees) {
// s = s + a.salary;
// }
// System.out.println("The total salary is: " + s);
// }
// }

/* Using Array Objects */
class Employee {

    String name;
    int salary;
    static Employee[] employees = new Employee[10];
    static int i = 0;

    public Employee(String name, int salary) {
        this.name = name;
        this.salary = salary;
        if (i < employees.length) {
            employees[i++] = this;
        } else {
            System.out.println("No more space in the array");
        }
    }

    static void sum() {
        int s = 0;
        for (Employee a : employees) {
            if (a != null) {

                s = s + a.salary;
            }
        }
        System.out.println("The total salary is: " + s);
    }

    void rrr(Employee a) {

    }
}