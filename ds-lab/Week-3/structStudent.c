/* Write a C program to implement the following functions. Use pointers and dynamic memory management functions.
i. To read one Student object where Student is a structure with name, roll number and CGPA as the data members.
ii. To display one Student object.
iii. To sort an array of Student structures according to the roll number. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    float cgpa;
};

void readStudent(struct Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);
    
    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);
    
    printf("Enter CGPA: ");
    scanf("%f", &student->cgpa);
}

void displayStudent(const struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("CGPA: %.2f\n", student->cgpa);
}

int compareStudents(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    
    return studentA->rollNumber - studentB->rollNumber;
}

int main() {
    int numStudents;
    
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < numStudents; ++i) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }
    
    printf("\nStudent details:\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(&students[i]);
    }
    
    qsort(students, numStudents, sizeof(struct Student), compareStudents);
    
    printf("\nSorted by roll number:\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(&students[i]);
    }
    
    free(students);
    
    return 0;
}
