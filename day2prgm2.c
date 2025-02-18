#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int marks;
} Student;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student *students = (Student *)malloc(n * sizeof(Student));
    for (int i = 0; i < n; i++) {
        char temp[50];
        printf("Enter Student %d Name: ", i + 1);
        scanf(" %s", temp);
        students[i].name = (char *)malloc(strlen(temp) + 1);
        strcpy(students[i].name, temp);
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
        free(students[i].name);
    }
    free(students);
    return 0;
}
