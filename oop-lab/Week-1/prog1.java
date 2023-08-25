import java.util.Scanner;
public class prog1 {
        public static void main(String []args) {
                Scanner sc = new Scanner (System.in);
                System.out.println("Enter three numbers: ");
                int a = sc.nextInt();
                int b = sc.nextInt();
                int c = sc.nextInt();
                System.out.println("Largest of "+a+", "+b+", and "+c+" is "+largest(a, b, c)+".");
                System.out.println("Largest of "+a+", "+b+", and "+c+" is "+largest2(a, b, c)+".");
        }
        static int largest(int a, int b, int c){
                if (a>b){
                        if (a>c)
                                return a;
                        else return c;

                }
                else {
                        if (b>c)
                                return b;

                        else return c;
                }

        }
        static int largest2(int a, int b, int c){
                if (a>=b && a>=c)
                        return a;
                if (b>=a && b>=c)
                        return b;
                else return c;
        }
}