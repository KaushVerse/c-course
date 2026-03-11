#include <stdio.h>

// structure define
struct Student
{
    int id;
    char name[50];
    float marks;
};

int main()
{
    struct Student s1;

    s1.id = 1;
    s1.marks = 89.5;

    printf("Enter name: ");
    scanf("%s", s1.name);

    printf("\nStudent Details:\n");
    printf("ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}