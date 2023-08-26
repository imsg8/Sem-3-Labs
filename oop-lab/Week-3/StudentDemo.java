import java.util.Scanner;
class Student
{

        String sname;
        int marks_array[];
        int n;
        void assign(String sname, int marks_array[])
        {
                this.sname = sname;
                this.marks_array=marks_array;
        }
        void display()
        {
                System.out.println("Name: "+sname);
                System.out.println("Marks:");
                for(int x:marks_array)
                        System.out.print(x+" ");
        }
        void compute()
        {
                float avg,total=0;
                for(int x:marks_array)
                        total+=x;
                avg=total/5;
                System.out.println("Total = "+total);
                System.out.println("Average = "+avg);
        }
}
class StudentDemo
{
        public static void main(String args[])
        {
                Scanner sc = new Scanner(System.in);
                Student s1= new Student();
                String sname;
                int marks_array[]=new int[5];
                System.out.println("Enter the name.");
                sname=sc.next();
                System.out.println("Enter the marks.");
                for(int i=0;i<5;i++)
                        marks_array[i]=sc.nextInt();
                s1.assign(sname,marks_array);
                s1.display();
                s1.compute();
        }
}