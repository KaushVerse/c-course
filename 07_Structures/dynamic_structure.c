#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[50];
    float gpa;
};

int main()
{
    struct Student *s;

    /* dynamic memory allocation */
    s = (struct Student *)malloc(sizeof(struct Student));

    /* assign values */
    s->id = 101;
    s->gpa = 3.9;

    sprintf(s->name, "Kaushik");

    printf("Student Info\n");
    printf("ID: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("GPA: %.2f\n", s->gpa);

    /* free memory */
    free(s);

    return 0;
}