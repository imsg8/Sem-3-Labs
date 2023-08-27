import java.util.Scanner;
class revarray {
public static void main(String[] args) {

int n,c,j,i;
Scanner in = new Scanner(System.in);
System.out.println("Input number of integers");

n= in.nextInt(); // to read size of the array
j = n;
int array[] = new int[n]; // allocate memory for the array dynamically

System.out.println("Enter "+n + " integers"); // to read array for n elements 
        for (c = 0; c < n; c++){
        array[c] = in.nextInt();
        }
int temp;
for (i=0;i<j/2;i++){
        temp = array[i];
        array[i]=array[j-1-i];
        array[j-1-i]=temp;
}
        // to display array elements 
System.out.println("The array is");
        for (c = 0; c<n ; c++){
        System.out.println(array[c]);
        }
}
}
