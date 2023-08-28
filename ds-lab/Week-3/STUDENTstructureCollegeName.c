/* Create a structure STUDENT consisting of variables of structures:
i. DOB {day, month (use pointer), year). ii. STU_INFO (reg_no, name(use pointer), address),
i. COLLEGE (college_name (use pointer), university_name )
where structure types from i to in are declared outside the STUDENT independently.
Show how to read and display member variables of DOB type if pointer variable is created for 
DOB inside STUDENT and STUDENT variable is also a pointer variable. The program should read 
and display the values of all members of STUDENT structure. */

#include <stdio.h>
#include <stdlib.h>

// Structure for Date of Birth (DOB)
struct DOB {
    int day;
    int *month; // Using pointer for month
    int year;
};

// Structure for Student Information (STU_INFO)
struct STU_INFO {
    int reg_no;
    char *name; // Using pointer for name
    char *address;
};

// Structure for College
struct COLLEGE {
    char *college_name;
    char *university_name;
};

// Structure for Student (containing nested structures)
struct STUDENT {
    struct DOB dob;
    struct STU_INFO stu_info;
    struct COLLEGE college;
};

int main() {
    // Declare a pointer to STUDENT structure
    struct STUDENT *student;

    // Allocate memory for student structure
    student = (struct STUDENT *)malloc(sizeof(struct STUDENT));
    if (student == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for nested structures
    student->dob.month = (int *)malloc(sizeof(int));
    student->stu_info.name = (char *)malloc(50 * sizeof(char));
    student->stu_info.address = (char *)malloc(100 * sizeof(char));
    student->college.college_name = (char *)malloc(50 * sizeof(char));
    student->college.university_name = (char *)malloc(50 * sizeof(char));

    // Read student details
    printf("Enter student's date of birth (day month year): ");
    scanf("%d %d %d", &student->dob.day, student->dob.month, &student->dob.year);

    printf("Enter student's registration number: ");
    scanf("%d", &student->stu_info.reg_no);

    printf("Enter student's name: ");
    scanf("%s", student->stu_info.name);

    printf("Enter student's address: ");
    scanf(" %s [^\n]", student->stu_info.address);

    printf("Enter college name: ");
    scanf("%s", student->college.college_name);

    printf("Enter university name: ");
    scanf("%s", student->college.university_name);

    printf("\n \n ");
    // Display student details
    printf("\nStudent details:\n");
    printf("Date of Birth: %d/%d/%d\n", student->dob.day, *(student->dob.month), student->dob.year);
    printf("Registration Number: %d\n", student->stu_info.reg_no);
    printf("Name: %s\n", student->stu_info.name);
    printf("Address: %s\n", student->stu_info.address);
    printf("College: %s\n", student->college.college_name);
    printf("University: %s\n", student->college.university_name);

    // Free allocated memory
    free(student->dob.month);
    free(student->stu_info.name);
    free(student->stu_info.address);
    free(student->college.college_name);
    free(student->college.university_name);
    free(student);

    return 0;
}
