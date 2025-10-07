#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int roll;
    char name[100];
    float marks;
    char grade;
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count, int roll);
void updateStudent(Student students[], int count, int roll);
char calculateGrade(float marks);
int isValidRoll(int roll);

#endif
