class Employee
{
    String Ename;
    int Eid;
    double Basic;
    
   Employee(String Ename,int Eid,double Basic)
   {
     this.Ename=Ename;
     this.Eid=Eid;
     this.Basic=Basic;
   }
   
   void display()
   {
        
        System.out.println("Name: "+Ename);
        System.out.println("Id: "+Eid);
        System.out.println("Basic Salary: "+Basic);
        System.out.println("Net Salary: "+this.compute_net_sal()+"\n");
        
   }

   double compute_net_sal()
   {
     double DA=Basic*0.52;
     double gross_Sal=Basic + DA;
     double IT= gross_Sal*0.3;
     double net_sal=gross_Sal+DA-IT;
     return net_sal;
   }
   
}

class FullTimeEmp extends Employee
{
    double bonus;
    double deductions;

    FullTimeEmp(String Ename,int Eid,double Basic,double bonus,double deductions)
   {
     super(Ename,Eid,Basic);
     this.bonus=bonus;
     this.deductions=deductions;
   }
    void display()
   {
        System.out.println("Name: "+Ename);
        System.out.println("Id: "+Eid);
        System.out.println("Basic Salary: "+Basic);
        System.out.println("bonus: "+bonus);
        System.out.println("deductions: "+deductions);
        System.out.println("Net Salary: "+this.compute_net_sal()+"\n");
        
   }

    double compute_net_sal()
   {
     Basic+=bonus-deductions;
     double net_sal=super.compute_net_sal();
     return net_sal;
   }

}

class PartTimeEmp extends Employee
{
    int hoursWorked;
    static final double hourlyRate = 200;

    PartTimeEmp(String Ename,int Eid,double Basic,int hoursWorked)
   {
     super(Ename,Eid,Basic);
     this.hoursWorked=hoursWorked;
     
   }

    void display()
   {
        System.out.println("Name: "+Ename);
        System.out.println("Id: "+Eid);
        System.out.println("hours Worked: "+hoursWorked);
        System.out.println("hourlyRate: "+hourlyRate);
        System.out.println("Net Salary: "+this.compute_net_sal()+"\n");
   }

    double compute_net_sal()
   {
     Basic=hoursWorked*hourlyRate;
     double net_sal=super.compute_net_sal();
     return net_sal;
   }

}

class EmployeeDemo
{
   public static void main(String[] args)
   {
     //creating employee object
     Employee E1=new Employee("Vraj",2345,12345);
     E1.display();
     
     //creating FullTimeEmp object
     FullTimeEmp E2=new FullTimeEmp("Aditya",2356,12345,5000,1200);
     E2.display();
     
     //creating PartTimeEmp object
     PartTimeEmp E3=new PartTimeEmp("arko",2489,12345,5);
     E3.display();
     
    }   
}    
