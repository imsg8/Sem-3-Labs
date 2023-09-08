import java.util.*;
class Stu{
        String name;
        int marks[]=new int[5];
        Stu(String name,int marks[])
        {
                this.name=name;
                this.marks=marks;
        }
        void display()
        {
                System.out.println("name :"+name+"\n marks :");
                for(int m:marks)
                        System.out.print(m+"\t");
        }
        void compute()
        {
                int total=0;
                for(int m:marks)
                        total+=m;
                System.out.println("Total marks are : "+total+"\nThe average is : "+(total/5.0));
        }
}
class SciStu extends Stu{
        private int PracMarks;
        SciStu(String name,int marks[],int x)
        {
                super(name,marks);
                PracMarks=x;
        }
        int getPrac()
        {
                return PracMarks;
        }
}                 
import java.util.Scanner;
class q1{
	class DemoStu{
        public static void main(String[] args)
        {
                String name="Tejeswar";
                int marks[]={98,98,98,98,98};
                Stu a=new Stu(name,marks);
                SciStu b=new SciStu(name,marks,67);
                ArtStu c=new ArtStu(name,marks,"Machine Learning");
                a.compute();
                b.compute();

        	}
	}
	}
