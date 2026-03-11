/**
 * structure_return_function.c
 * Demonstrates returning a structure from a function
 * Author: Kaushik
 */

#include <stdio.h>

/* =========================
   Structure Definition
   ========================= */

struct Student
{
    int id;
    char name[50];
    float gpa;
};

/* =========================
   Function Prototype
   ========================= */

struct Student createStudent(int id, char name[], float gpa);

/* =========================
   Main Function
   ========================= */

int main()
{
    struct Student s1;

    /* Receive structure returned from function */

    s1 = createStudent(101, "Kaushik", 3.9);

    printf("Student Details\n");
    printf("-----------------\n");
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("GPA: %.2f\n", s1.gpa);

    return 0;
}

/* =========================
   Function returning structure
   ========================= */

struct Student createStudent(int id, char name[], float gpa)
{
    struct Student s;

    s.id = id;
    s.gpa = gpa;

    /* copy name */
    sprintf(s.name, "%s", name);

    return s; // return full structure
}