import java.util.Scanner;
class primeinarray {
public static void main(String[] args) {
int n,i;
System.out.println("Input number of integers");
Scanner sc = new Scanner(System.in);
n= sc.nextInt(); // to read size of the array
int a[] = new int[n];
for(i=0;i<n;i++)
        a[i]=sc.nextInt();
System.out.println("The prime numbers are - ");
for(i=0;i<n;i++)
{
boolean f = true;
for(int j=2;j<a[i]/2;j++)
{
        if (a[i]%j==0)
        {f = false;
                break;
        }
}
if (f)
        System.out.println(a[i]+ " ");
}
}
}
