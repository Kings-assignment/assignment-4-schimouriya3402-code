// Write a C program that defines a structure Employee with members: name, employee ID, and salary. 
// Take input for 5 employees and display the details of the employee with the highest salary.

#include <stdio.h>
#include <string.h>
struct Employee {
    char name[50];
    int employee_id;
    float salary;
};
int main() {
    struct Employee employees[5];
    int i, highest_salary_index = 0;


    for (i = 0; i < 5; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        
        printf("Name: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Employee ID: ");
        scanf("%d", &employees[i].employee_id);

        printf("Salary: ");
        scanf("%f", &employees[i].salary);

        getchar(); 
    }
    for (i = 1; i < 5; i++) {
        if (employees[i].salary > employees[highest_salary_index].salary) {
            highest_salary_index = i;
        }
    }
    printf("\nEmployee with the highest salary:\n");
    printf("Name: %s\n", employees[highest_salary_index].name);
    printf("Employee ID: %d\n", employees[highest_salary_index].employee_id);
    printf("Salary: %.2f\n", employees[highest_salary_index].salary);   
    return 0;
}   