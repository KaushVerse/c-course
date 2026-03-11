#include <stdio.h>

struct Student
{
    int id;
    char name[50];
    float gpa;
};

int main()
{
    struct Student s1 = {101, "Kaushik", 3.9};

    struct Student s2;

    s2 = s1; // structure copy

    printf("Student 1\n");
    printf("ID: %d Name: %s GPA: %.2f\n", s1.id, s1.name, s1.gpa);

    printf("\nStudent 2\n");
    printf("ID: %d Name: %s GPA: %.2f\n", s2.id, s2.name, s2.gpa);

    return 0;
}