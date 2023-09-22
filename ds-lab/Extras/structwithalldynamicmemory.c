#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct STUDENT{
    char* name;
    char* hometown;
    char* address;
};
struct DOJ{
    int day;
    char *month;
    int year;
};
struct STU{
    struct STUDENT stu;
    struct DOJ doj;
};
int main(){
    int n;
    printf("Enter number of students - ");
    scanf("%d",&n);
    struct STU *student = (struct STU *) malloc (n * sizeof(struct STU));
    for (int i = 0; i < n ; i++){
        student->stu.name = (char * ) malloc (sizeof(char));
        student->stu.hometown = (char * ) malloc (sizeof(char));
        student->stu.address = (char * ) malloc (sizeof(char));
        student->doj.day = (int *) malloc (sizeof(int));
        student->doj.month = (char *) malloc (sizeof(char));
        student->doj.year = (int *) malloc (sizeof(int));

        printf("Enter name - ");
        scanf("%s",student->stu.name);
        printf("\nEnter hometown - ");
        scanf("%s",student->stu.hometown);
        printf("\nEnter address - ");
        scanf("%s",student->stu.address);
        printf("\n \n");
        printf("Enter date of joining - ");
        scanf("%d",&student->doj.day);
        printf("Enter month of joining - ");
        scanf("%d",student->doj.month);
        printf("Enter year of joining - ");
        scanf("%d",&student->doj.year);
    }
    for (int i = 0; i < n ; i++){
        printf("Name - %s",student->stu.name);
        printf("Hometown - %s",student->stu.hometown);
        printf("Address - %s",student->stu.address);
        printf("Date of joining - %d / %d / %d",student->doj.day, student->doj.month, student->doj.year);
    }
}