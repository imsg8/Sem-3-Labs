import java.util.Scanner;
class arraytilln {
public static void main(String[] args) {
int n,i;
System.out.println("Input number of integers");
Scanner sc = new Scanner(System.in);
n= sc.nextInt();
// to read size of the array
int a[] = new int[n];

        // to display array elements 
System.out.println("The array is");
        for (i = 0; i<n; i++){
            a[i]=i+1;
        }
        for(int c:a)
                System.out.print(c+" ");
}
}
