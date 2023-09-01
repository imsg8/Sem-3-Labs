import java.util.Scanner;

class Employee
{
    String Ename;
    int Eid;

    Employee(String Ename,int Eid)
    {
        this.Ename=Ename;
        this.Eid=Eid;
    }

    void formatEmployeeName()
    { 
        char ch[]=new char[Ename.length()];
        for(int i=0;i<Ename.length();i++)
        {   
            ch[i]=Ename.charAt(i);
        }

        if(ch[0]>=97)
        ch[0]=(char)((int)ch[0]-32);
        
        for(int i=1;i<ch.length;i++ )
        {
           
            if(ch[i]==' ')
             if(ch[i+1]>=97)
              {ch[i+1]=(char)((int)ch[i+1]-32);
              }
        }
        String temp=new String();
        for(char x:ch)
         temp=temp+x;
        Ename=temp;
    }

    String generatemail()
    {
       int count=1,space=0;
       for(int i=0;Ename.charAt(i)!=' ';)
       {
         i++;
         if(Ename.charAt(i)==' ')
           { 
            space=i;
            count+=Ename.length()-(i+1);
           }
       }
       
       
       char ch[]=new char[count];
       if(ch[0]<=90)
       ch[0]=(char)((int)Ename.charAt(0)+32);
       else
       ch[0]=Ename.charAt(0);
       int c=1;
       for(int i=space+1;i<=Ename.length()&c<count;i++)
       {  
         
                    if(Ename.charAt(i)<=90)
                     ch[c]=(char)((int)Ename.charAt(i)+32);
                    
                    else
                      ch[c]=Ename.charAt(i);
                    c++;
                
       }
        String temp="";
        for(char x:ch)
         temp=temp+x;
        temp+="@example.com";
        return temp;
    }

    void display()
    {
        System.out.println("Name: "+Ename+"\n");
        System.out.println("Id: "+Eid+"\n");
    }
}

class EmployeeDemo
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println(("Enter the number of employees: "));
        int N=sc.nextInt();
        Employee E[]=new Employee[N];
        System.out.println("Enter each Employees details: \n");
        for(int i=0;i<N;i++)
        {
            System.out.print("Employee"+(i+1)+":\n");
            System.out.print("Name: ");
            sc.nextLine();
            String name=sc.nextLine();
            System.out.print("Eid: ");
            int Id=sc.nextInt();
            E[i]=new Employee(name,Id);
        }

        System.out.println("The Employee details are: \n");
        for(int i=0;i<N;i++)
        {
            System.out.print("\nEmployee "+(i+1)+":\n");
            E[i].formatEmployeeName();
            E[i].display();
            System.out.println("Email: "+E[i].generatemail());

        }
    }
}
