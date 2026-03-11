/**
 * structure_inside_structure.c
 * Demonstration of nested structures in C
 * Author: Kaushik
 */

#include <stdio.h>

/* ==========================
   Address Structure
   ========================== */

struct Address
{
    char city[50];
    char state[50];
    int pin;
};

/* ==========================
   Student Structure
   (Address inside Student)
   ========================== */

struct Student
{
    int id;
    char name[50];
    float gpa;

    struct Address addr; // Nested structure
};

/* ==========================
   Main Function
   ========================== */

int main()
{
    struct Student s1;

    /* Assign Student Data */

    s1.id = 101;
    s1.gpa = 3.9;

    sprintf(s1.name, "Kaushik");

    /* Assign Address Data */

    sprintf(s1.addr.city, "Kolkata");
    sprintf(s1.addr.state, "West Bengal");
    s1.addr.pin = 700001;

    /* Display Data */

    printf("Student Information\n");
    printf("----------------------\n");

    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("GPA: %.2f\n", s1.gpa);

    printf("\nAddress Details\n");
    printf("City: %s\n", s1.addr.city);
    printf("State: %s\n", s1.addr.state);
    printf("PIN: %d\n", s1.addr.pin);

    return 0;
}