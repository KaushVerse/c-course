/**
 * Demonstrates structures, typedef, and pointer to structure in C
 */

#include <stdio.h>

/* =========================
   Student Structure
   =========================
   Represents a student with roll number,
   CGPA and name.
*/
struct Student
{
    int roll;       // Student roll number
    float cgpa;     // Student CGPA
    char name[100]; // Student name
};

/* =========================
   Teacher Structure (typedef)
   =========================
   typedef allows us to use 'Teacher'
   instead of 'struct Teacher'
*/
typedef struct Teacher
{
    int id;         // Teacher ID
    char name[100]; // Teacher name
} Teacher;

/* =========================
   Main Function
   =========================
*/
int main()
{
    /* Create and initialize a Student structure */
    struct Student s1 = {101, 9.2, "Kaushik"};

    /* Create and initialize a Teacher structure
       Notice we don't need to write 'struct Teacher'
       because of typedef
    */
    Teacher t1 = {102, "Apna College"};

    /* =========================
       Pointer to Structure
       =========================
       Store address of structure
    */
    struct Student *ptr = &s1;

    /* =========================
       Accessing structure using pointer
       =========================
    */

    printf("\nStudent Details\n");
    /* Method 1: Using dereference operator */
    printf("Roll: %d\n", (*ptr).roll);

    /* Method 2: Using arrow operator (recommended) */
    printf("CGPA: %.2f\n", ptr->cgpa);
    printf("Name: %s\n", ptr->name);

    /* =========================
       Printing Teacher Details
       =========================
    */
    printf("\nTeacher Details\n");
    printf("ID: %d\n", t1.id);
    printf("Name: %s\n", t1.name);

    return 0;
}