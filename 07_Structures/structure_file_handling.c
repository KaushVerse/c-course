/**
 * structure_file_handling.c
 * Demonstrates structure with file handling
 * Author: Kaushik
 */

#include <stdio.h>
#include <stdlib.h>

/* =========================
   Structure Definition
   ========================= */

struct Student
{
    int id;
    char name[50];
    float gpa;
};

int main()
{
    FILE *fp;

    struct Student s1 = {101, "Kaushik", 3.9};
    struct Student s2;

    /* =========================
       Writing structure to file
       ========================= */

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    fwrite(&s1, sizeof(struct Student), 1, fp);

    fclose(fp);

    /* =========================
       Reading structure from file
       ========================= */

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    fread(&s2, sizeof(struct Student), 1, fp);

    fclose(fp);

    /* =========================
       Display data
       ========================= */

    printf("Student Data Read From File\n");
    printf("-----------------------------\n");
    printf("ID: %d\n", s2.id);
    printf("Name: %s\n", s2.name);
    printf("GPA: %.2f\n", s2.gpa);

    return 0;
}