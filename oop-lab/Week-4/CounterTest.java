class Counter {
    static int counter = 0;

    Counter() {
        counter++;
    }

    static void showCount() {
        System.out.println("Number of objects created: " + counter);
    }
}

public class CounterTest {
    public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();

        Counter.showCount(); // Display count after creating three objects
    }
}