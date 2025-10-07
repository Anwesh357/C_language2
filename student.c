#include <stdio.h>
#include <string.h>
#include "student.h"
#include "utils.h"

void addStudent(Student students[], int *count) {
    printf("Enter roll number: ");
    students[*count].roll = getIntInput();

    printf("Enter name: ");
    getStringInput(students[*count].name, 50);

    printf("Enter marks: ");
    students[*count].marks = getFloatInput();

    students[*count].grade = calculateGrade(students[*count].marks);
    (*count)++;

    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nRoll\tName\t\tMarks\tGrade\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%.2f\t%c\n", students[i].roll, students[i].name,
               students[i].marks, students[i].grade);
    }
}

void searchStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Found: %d - %s, Marks: %.2f, Grade: %c\n",
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
            students[i].marks = getFloatInput();
            students[i].grade = calculateGrade(students[i].marks);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Student with roll %d not found.\n", roll);
}

char calculateGrade(float marks) {
    if (marks >= 90) return 'A';
    else if (marks >= 75) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 45) return 'D';
    else return 'F';
}