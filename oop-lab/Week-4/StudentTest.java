class STUDENT
{
    String sname;
    int[] marks_array = new int[5]; // Assuming 5 subjects

    // Default Constructor
    STUDENT() {
        sname = "Shivang";
        for (int i = 0; i < marks_array.length; i++) {
            marks_array[i] = 0;
        }
    }

    // Parameterized Constructor
    STUDENT(String name, int[] marks) {
        sname = name;
        System.arraycopy(marks, 0, marks_array, 0, marks.length);
    }

    void display() {
        System.out.println("Student Name: " + sname);
        System.out.print("Marks: ");
        for (int mark : marks_array) {
            System.out.print(mark + " ");
        }
        System.out.println();
    }
}

      class StudentTest {
    public static void main(String[] args) {
        // Using default constructor
        STUDENT studentDefault = new STUDENT();
        System.out.println("Details using default constructor:");
        studentDefault.display();

        // Using parameterized constructor
        int[] marks = { 85, 92, 78, 88, 95 };
        STUDENT studentParam = new STUDENT("Alice", marks);
        System.out.println("\nDetails using parameterized constructor:");
        studentParam.display();
    }
}