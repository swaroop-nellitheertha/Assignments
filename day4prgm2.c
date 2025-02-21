#include <stdio.h>
#include <string.h>
struct Employee {
    int id;
    char name[50];
    float basic, allowances, gross;
};
int main() {
    int n, searchID;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];
    FILE *file = fopen("payroll.txt", "w");
    for (int i = 0; i < n; i++) {
        printf("Enter Employee %d (ID Name Basic Allowances): ", i + 1);
        scanf("%d %s %f %f", &emp[i].id, emp[i].name, &emp[i].basic, &emp[i].allowances);
        emp[i].gross = emp[i].basic + emp[i].allowances;
        fprintf(file, "%d, %s, %.2f\n", emp[i].id, emp[i].name, emp[i].gross);
    }
    fclose(file);
    printf("\nRecord saved in \"payroll.txt\"\n");
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchID);
    for (int i = 0; i < n; i++) {
        if (emp[i].id == searchID) {
            printf("Employee: %s\nGross Salary: %.2f\n", emp[i].name, emp[i].gross);
            return 0;
        }
    }
    printf("Employee not found.\n");
    return 0;
}
