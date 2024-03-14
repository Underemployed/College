package JAVA;

import java.util.List;
import java.util.ArrayList;

public class Employeedata {
    static List<Employee> employees = new ArrayList<>();

    public static void main(String[] args) {
        employees.add(new Employee("wow", 1000));
        employees.add(new Employee("nithin", 11000));
        new Employee("how", 1000).sum(employees);
    }
}

class Employee {

    String name;
    int salary;

    public Employee(String name, int salary) {
        this.name = name;
        this.salary = salary;
    }

    void sum(List<Employee> employees) {
        int s = 0;
        for (Employee a : employees) {
            s = s + a.salary;
        }
        System.out.println("The total salary is: " + s);
    }
}