#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char name[50];
    int roll;
    int cgpa;
};
void read(struct student *stu){
    printf("Enter student name: ");
    scanf("%s", &(stu->name));
    printf("Enter roll number: ");
    scanf("%d", &(stu->roll));
    printf("Enter CGPA: ");
    scanf("%d", &(stu->cgpa));
}
void displayStudent(const struct student *stu) {
    printf("Name: %s\n", stu->name);
    printf("Roll Number: %d\n", stu->roll);
    printf("CGPA: %d\n", stu->cgpa);
}
void bubsort(struct student *stu, int n){
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++){
            if( stu[j].roll > stu[j+1].roll){
                struct student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}
int main(){
    struct student *stu;
    int n;
    printf("Enter number of students - ");
    scanf("%d",&n);
    stu = (struct student * )malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        read(&stu[i]);
    }

    // Sort the array of Student structures based on roll number using bubble sort
    bubsort(stu, n);

    // Display student data
    printf("\nStudent List (Sorted by Roll Number):\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(&stu[i]);
    }

    // Free dynamically allocated memory
    free(stu);

    return 0;
}