import java.util.Scanner;
class Employee
{
        String ename,eid;
        float basic;
        void read()
        {
                Scanner sc = new Scanner(System.in);
                System.out.println("Enter name, id & basic salary");
                ename=sc.next();
                eid=sc.next();
                basic=sc.nextFloat();
        }
        void display()
        {
                System.out.print("Name: "+ename+"\n");
                System.out.print("ID: "+eid+"\n");
                System.out.print("Basic: "+basic+"\n");
        }
        void compute_net_sal()
        {
                double da,gross,net;
                da=0.52*basic;
                gross=basic+da;
                net=0.7*gross;
                System.out.print("Net salary: "+net+"\n");
        }
}
class EmployeeDemo
{
        public static void main(String args[])
        {
                Scanner sc = new Scanner(System.in);
                System.out.println("Enter n.");
                int n = sc.nextInt();
                Employee e[] = new Employee[n];
                for(int i=0;i<n;i++)
                {
                        e[i]= new Employee();//you have to use new for every single object in array of objects
                        e[i].read();
                }
                for(Employee x:e)
                {
                        x.display();
                        x.compute_net_sal();
                }
        }
}