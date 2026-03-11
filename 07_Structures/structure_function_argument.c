/**
 * structure_function_argument.c
 * Demonstrates passing structure to functions
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
   Function Prototypes
   ========================= */

void displayStudent(struct Student s); // pass by value
void updateGPA(struct Student *s);     // pass by pointer

/* =========================
   Main Function
   ========================= */

int main()
{
    struct Student s1 = {101, "Kaushik", 3.8};

    printf("Original Student Data\n");
    displayStudent(s1);

    /* Update GPA using pointer */
    updateGPA(&s1);

    printf("\nAfter GPA Update\n");
    displayStudent(s1);

    return 0;
}

/* =========================
   Function: displayStudent
   Structure passed by value
   ========================= */

void displayStudent(struct Student s)
{
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("GPA: %.2f\n", s.gpa);
}

/* =========================
   Function: updateGPA
   Structure passed by pointer
   ========================= */

void updateGPA(struct Student *s)
{
    s->gpa = 4.0; // modify original structure
}