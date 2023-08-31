class EMPLOYEE {
    String Ename;
    int Eid;
    double Basic;

    // Default Constructor
    EMPLOYEE() {
        Ename = "Shivang";
        Eid = 22322;
        Basic = 45000.0;
    }

    // Parameterized Constructor
    EMPLOYEE(String name, int id, double basic) {
        Ename = name;
        Eid = id;
        Basic = basic;
    }

    void display() {
        System.out.println("Employee Name: " + Ename);
        System.out.println("Employee ID: " + Eid);
        System.out.println("Basic Salary: " + Basic);
    }
}

public class EmployeeTest {
    public static void main(String[] args) {
        // Using default constructor
        EMPLOYEE employeeDefault = new EMPLOYEE();
        System.out.println("Details using default constructor:");
        employeeDefault.display();

        // Using parameterized constructor
        EMPLOYEE employeeParam = new EMPLOYEE("Kartikeya", 10111, 55000.0);
        System.out.println("\nDetails using parameterized constructor:");
        employeeParam.display();
    }
}