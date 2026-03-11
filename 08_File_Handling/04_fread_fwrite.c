/**
 * fread_fwrite.c
 * Demonstrates fread() and fwrite() with structures
 * Author: Kaushik
 */

#include <stdio.h>
#include <stdlib.h>

/* ==============================
   Structure Definition
   ============================== */

struct Student
{
    int id;
    char name[50];
    float gpa;
};

/* ==============================
   Utility Function
   ============================== */

void printLine(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}

/* ==============================
   Main Function
   ============================== */

int main()
{
    FILE *fp;

    struct Student s1 = {101, "Kaushik", 3.9};
    struct Student s2;

    /* ==============================
       Write structure to file
       ============================== */

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fwrite(&s1, sizeof(struct Student), 1, fp);

    fclose(fp);

    printf("Data written to file successfully.\n");

    /* ==============================
       Read structure from file
       ============================== */

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fread(&s2, sizeof(struct Student), 1, fp);

    fclose(fp);

    /* ==============================
       Display Data
       ============================== */

    printLine('-', 30);

    printf("Student Data From File\n");

    printLine('-', 30);

    printf("ID   : %d\n", s2.id);
    printf("Name : %s\n", s2.name);
    printf("GPA  : %.2f\n", s2.gpa);

    printLine('-', 30);

    return 0;
}