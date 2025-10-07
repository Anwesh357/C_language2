#include <stdio.h>
#include <string.h>
#include "student.h"
#include "utils.h"

void addStudent(Student students[], int *count) {
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].roll);

     if (!isValidRoll(students[*count].roll)) {
        printf("Invalid roll number!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    students[*count].grade = calculateGrade(students[*count].marks);
    (*count)++;

    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "Roll No", "Name", "Marks", "Grade");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f %-10c\n",
               students[i].roll,
               students[i].name,
               students[i].marks,
               students[i].grade);
    }
}

void searchStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\nGrade: %c\n",
                   students[i].roll, students[i].name,
                   students[i].marks, students[i].grade);
            return;
        }
    }
    printf("Student with roll %d not found.\n", roll);
}

void updateStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            students[i].grade = calculateGrade(students[i].marks);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Student with roll %d not found.\n", roll);
}

int isValidRoll(int roll) {
    return roll > 0;
}

char calculateGrade(float marks) {
    if (marks >= 80) return 'A';
    else if (marks >= 65) return 'B';
    else if (marks >= 50) return 'C';
    else if (marks >= 35) return 'D';
    else return 'F';

}

