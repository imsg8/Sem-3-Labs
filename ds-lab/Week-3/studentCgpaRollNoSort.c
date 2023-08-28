/* Write a C program to implement the following functions. Use pointers and
dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll number and CGPA as the data members
ii. To display one Student object
iii. To sort an array of Student structures according to the roll number. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student {
    char name[50];
    int rollNumber;
    float cgpa;
};

// Function to read a Student object
void readStudent(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &(student->rollNumber));
    printf("Enter CGPA: ");
    scanf("%f", &(student->cgpa));
}

// Function to display a Student object
void displayStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("CGPA: %.2f\n", student->cgpa);
}

// Function to sort an array of Student structures using bubble sort
void bubbleSort(struct Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare roll numbers and swap if necessary
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for an array of Student objects
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read student data
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    // Sort the array of Student structures based on roll number using bubble sort
    bubbleSort(students, n);

    // Display student data
    printf("\nStudent List (Sorted by Roll Number):\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(&students[i]);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student {
    char name[50];
    int rollNumber;
    float cgpa;
};

// Function to read a Student object
void readStudent(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    printf("Enter roll number: ");
    scanf("%d", &(student->rollNumber));
    printf("Enter CGPA: ");
    scanf("%f", &(student->cgpa));
}

// Function to display a Student object
void displayStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("CGPA: %.2f\n", student->cgpa);
}

// Function to sort an array of Student structures using bubble sort
void bubbleSort(struct Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare roll numbers and swap if necessary
            if (students[j].rollNumber > students[j + 1].rollNumber) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for an array of Student objects
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read student data
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    // Sort the array of Student structures based on roll number using bubble sort
    bubbleSort(students, n);

    // Display student data
    printf("\nStudent List (Sorted by Roll Number):\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(&students[i]);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}
