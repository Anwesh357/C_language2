#include <stdio.h>
#include "student.h"
#include "utils.h"

int main() {
    Student students[100];
    int count = 0;
    int choice, roll;

    while (1) {
        printf("\n=== Student Grade Manager ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = getIntInput();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter roll number to search: ");
                roll = getIntInput();
                searchStudent(students, count, roll);
                break;
            case 4:
                printf("Enter roll number to update: ");
                roll = getIntInput();
                updateStudent(students, count, roll);
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}