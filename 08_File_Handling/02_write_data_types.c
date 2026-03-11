#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[50];
    int age;
    float score;
} Student;

int main()
{
    FILE *file;
    char filename[] = "students.txt";

    // Create some student data
    Student students[] = {
        {"Alice Johnson", 20, 95.5},
        {"Bob Smith", 22, 87.0},
        {"Charlie Brown", 21, 91.3}};
    int num_students = sizeof(students) / sizeof(students[0]);

    // Open file for writing
    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Write header
    fprintf(file, "%-20s %-5s %-6s\n", "Name", "Age", "Score");
    fprintf(file, "%-20s %-5s %-6s\n", "----", "---", "-----");

    // Write student data
    for (int i = 0; i < num_students; i++)
    {
        fprintf(file, "%-20s %-5d %-6.1f\n",
                students[i].name,
                students[i].age,
                students[i].score);
    }

    printf("Student data written to %s\n", filename);

    fclose(file);
    return 0;
}