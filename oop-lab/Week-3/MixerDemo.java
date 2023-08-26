import java.util.Scanner;
class Mixer
{
        int arr[];
        void accept()
        {
                Scanner sc = new Scanner(System.in);
                System.out.println("Enter n.");
                int n= sc.nextInt();
                arr=new int[n];
                System.out.println("Enter the elements.");
                for(int i=0;i<n;i++)
                        arr[i]=sc.nextInt();
        }
        Mixer mix(Mixer m)
        {
                Mixer c=new Mixer();
                c.arr=new int[arr.length+m.arr.length];
                for(int i=0,j=0,k=0; k<(arr.length+m.arr.length);)
                {
                        if(i>arr.length-1)
                        {
                                c.arr[k]=m.arr[j];
                                k++; j++;
                        }
                        else if(j>m.arr.length-1)
                        {
                                c.arr[k]=arr[i];
                                k++; i++;
                        }
                        else if(arr[i]<m.arr[j])
                        {
                                c.arr[k]=arr[i];
                                k++; i++;
                        }
                        else
                        {
                                c.arr[k]=m.arr[j];
                                k++; j++;
                        }
                }
                return c;
        }
        void display()
        {
                for(int x:arr)
                        System.out.print(x+" ");
                System.out.println();
        }
}
class MixerDemo
{
        public static void main(String args[])
        {
                Mixer m1=new Mixer();
                m1.accept();
                Mixer m2=new Mixer();
                m2.accept();
                Mixer m3=new Mixer();
                m3=m1.mix(m2);
                m3.display();
        }
}