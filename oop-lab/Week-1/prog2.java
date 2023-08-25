import java.util.Scanner;
class prog2{
        static int reverse(int x){
                int rev = 0;
                while(x>0){
                        rev = rev*10 + (x%10);
                        x = x/10;
                }
                return rev;
        }
public static void main(String[] args){
        System.out.println("Enter a number - ");
        Scanner sc = new Scanner (System.in);
        int x;
        x = sc.nextInt();
        int rev = reverse(x);
        System.out.println("Reverse of number is - "+rev);
        if (rev == x){
                System.out.println("Palindrome");
        }
                else System.out.println("Not a palindrome");

}
}
