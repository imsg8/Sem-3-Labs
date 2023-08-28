/* Samuel wants to store the data of his employees, which includes the following fields:
(1) Name of the emplovee (11) Date of birth which is a collection of dav. month. vear!
(in) Address which is a collection of house number. zip code and state!. Write a 'C
program to read and display the data of N emplovees using pointers to array of structures */

#include <stdio.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Address {
    char houseNumber[20];
    char zipCode[20];
    char state[30];
};

struct Employee {
    char name[50];
    struct Date dob;
    struct Address address;
};

void readEmployee(struct Employee *employee) {
    printf("Enter employee name: ");
    scanf("%s", employee->name);

    printf("Enter date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &employee->dob.day, &employee->dob.month, &employee->dob.year);

    printf("Enter house number: ");
    scanf("%s", employee->address.houseNumber);

    printf("Enter zip code: ");
    scanf("%s", employee->address.zipCode);

    printf("Enter state: ");
    scanf("%s", employee->address.state);
}

void displayEmployee(const struct Employee *employee) {
    printf("Name: %s\n", employee->name);
    printf("Date of Birth: %d/%d/%d\n", employee->dob.day, employee->dob.month, employee->dob.year);
    printf("Address: %s, %s, %s\n", employee->address.houseNumber, employee->address.zipCode, employee->address.state);
}

int main() {
    int numEmployees;

    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    struct Employee *employees = (struct Employee *)malloc(numEmployees * sizeof(struct Employee));
    if (employees == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < numEmployees; ++i) {
        printf("Enter details for employee %d:\n", i + 1);
        readEmployee(&employees[i]);
    }

    printf("\nEmployee details:\n");
    for (int i = 0; i < numEmployees; ++i) {
        printf("\nEmployee %d:\n", i + 1);
        displayEmployee(&employees[i]);
    }

    free(employees);

    return 0;
}
