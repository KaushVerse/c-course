/**
 * nested_structures.c
 * Demonstration of nested structures in C
 * Author: Kaushik
 * Date: 2026
 */

#include <stdio.h>
#include <string.h>

// ==================== BASIC NESTED STRUCTURES ====================

// Inner structure: Address
struct Address
{
    char street[50];
    char city[30];
    char state[20];
    int zipCode;
};

// Outer structure: Person (contains Address)
struct Person
{
    char name[50];
    int age;
    struct Address homeAddress; // Nested structure
    struct Address workAddress; // Another nested structure
};

// ==================== ANOTHER EXAMPLE ====================

// Structure for date
struct Date
{
    int day;
    int month;
    int year;
};

// Structure for education details
struct Education
{
    char degree[50];
    char university[100];
    int graduationYear;
    float gpa;
};

// Structure for employee (contains multiple nested structures)
struct Employee
{
    int id;
    char name[50];
    struct Date birthDate;
    struct Date joiningDate;
    struct Address empAddress;
    struct Education qualification;
    float salary;
};

// ==================== NESTED STRUCTURES WITH POINTERS ====================

struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    struct Point topLeft;
    struct Point bottomRight;
    char color[20];
};

// ==================== STRUCTURES CONTAINING ARRAYS OF STRUCTURES ====================

struct Department
{
    char name[30];
    struct Employee employees[10]; // Array of structures
    int employeeCount;
};

// ==================== FUNCTION PROTOTYPES ====================

void displayPerson(struct Person p);
void displayEmployee(struct Employee e);
void displayRectangle(struct Rectangle r);
float calculateRectangleArea(struct Rectangle r);
void initializeDepartment(struct Department *dept, const char *name);

// ==================== MAIN FUNCTION ====================

int main()
{
    printf("=== NESTED STRUCTURES DEMONSTRATION ===\n\n");

    // 1. Basic nested structure example
    printf("1. BASIC NESTED STRUCTURE:\n");
    struct Person person1;

    // Assign values to Person
    strcpy(person1.name, "John Doe");
    person1.age = 30;

    // Assign values to nested Address structures
    strcpy(person1.homeAddress.street, "123 Main St");
    strcpy(person1.homeAddress.city, "New York");
    strcpy(person1.homeAddress.state, "NY");
    person1.homeAddress.zipCode = 10001;

    strcpy(person1.workAddress.street, "456 Business Ave");
    strcpy(person1.workAddress.city, "New York");
    strcpy(person1.workAddress.state, "NY");
    person1.workAddress.zipCode = 10002;

    displayPerson(person1);
    printf("\n");

    // 2. More complex nested structure
    printf("2. COMPLEX NESTED STRUCTURE (EMPLOYEE):\n");
    struct Employee emp1;

    emp1.id = 1001;
    strcpy(emp1.name, "Jane Smith");

    // Birth date
    emp1.birthDate.day = 15;
    emp1.birthDate.month = 6;
    emp1.birthDate.year = 1990;

    // Joining date
    emp1.joiningDate.day = 1;
    emp1.joiningDate.month = 1;
    emp1.joiningDate.year = 2020;

    // Address
    strcpy(emp1.empAddress.street, "789 Oak Rd");
    strcpy(emp1.empAddress.city, "Boston");
    strcpy(emp1.empAddress.state, "MA");
    emp1.empAddress.zipCode = 700152;

    // Education
    strcpy(emp1.qualification.degree, "Computer Science");
    strcpy(emp1.qualification.university, "MIT");
    emp1.qualification.graduationYear = 2012;
    emp1.qualification.gpa = 3.8;

    emp1.salary = 75000.50;

    displayEmployee(emp1);
    printf("\n");

    // 3. Nested structures with pointers
    printf("3. NESTED STRUCTURES WITH POINTERS (RECTANGLE):\n");
    struct Rectangle rect;

    rect.topLeft.x = 0;
    rect.topLeft.y = 10;
    rect.bottomRight.x = 20;
    rect.bottomRight.y = 0;
    strcpy(rect.color, "Blue");

    displayRectangle(rect);
    printf("Rectangle Area: %.2f square units\n\n",
           calculateRectangleArea(rect));

    // 4. Structure initialization at declaration
    printf("4. INITIALIZATION AT DECLARATION:\n");
    struct Person person2 = {
        "Alice Johnson",
        25,
        {// homeAddress
         "321 Pine St",
         "Chicago",
         "IL",
         60601},
        {// workAddress
         "654 Lake Shore Dr",
         "Chicago",
         "IL",
         60602}};

    displayPerson(person2);
    printf("\n");

    // 5. Array of structures with nested structures
    printf("5. DEPARTMENT WITH EMPLOYEE ARRAY:\n");
    struct Department dept;
    initializeDepartment(&dept, "Engineering");

    // Add some employees
    dept.employees[0] = emp1; // Copy first employee

    struct Employee emp2 = emp1; // Copy and modify
    emp2.id = 1002;
    strcpy(emp2.name, "Bob Wilson");
    emp2.birthDate.year = 1988;
    emp2.salary = 82000.00;

    dept.employees[1] = emp2;
    dept.employeeCount = 2;

    printf("Department: %s\n", dept.name);
    printf("Number of employees: %d\n", dept.employeeCount);
    for (int i = 0; i < dept.employeeCount; i++)
    {
        printf("  Employee %d: %s (ID: %d)\n",
               i + 1, dept.employees[i].name, dept.employees[i].id);
    }
    printf("\n");

    // 6. Accessing nested members with pointers
    printf("6. POINTER ACCESS TO NESTED STRUCTURES:\n");
    struct Employee *empPtr = &emp1;

    printf("Employee (via pointer): %s\n", empPtr->name);
    printf("  Birth Year: %d\n", empPtr->birthDate.year);
    printf("  University: %s\n", empPtr->qualification.university);
    printf("  City: %s\n\n", empPtr->empAddress.city);

    // 7. Size of nested structures
    printf("7. STRUCTURE SIZES:\n");
    printf("Size of Address: %lu bytes\n", sizeof(struct Address));
    printf("Size of Person: %lu bytes\n", sizeof(struct Person));
    printf("Size of Employee: %lu bytes\n", sizeof(struct Employee));
    printf("Size of Rectangle: %lu bytes\n", sizeof(struct Rectangle));

    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

void displayPerson(struct Person p)
{
    printf("Person: %s, Age: %d\n", p.name, p.age);
    printf("  Home Address: %s, %s, %s %d\n",
           p.homeAddress.street,
           p.homeAddress.city,
           p.homeAddress.state,
           p.homeAddress.zipCode);
    printf("  Work Address: %s, %s, %s %d\n",
           p.workAddress.street,
           p.workAddress.city,
           p.workAddress.state,
           p.workAddress.zipCode);
}

void displayEmployee(struct Employee e)
{
    printf("Employee ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Birth Date: %d/%d/%d\n", e.birthDate.day,
           e.birthDate.month, e.birthDate.year);
    printf("Joining Date: %d/%d/%d\n", e.joiningDate.day,
           e.joiningDate.month, e.joiningDate.year);
    printf("Address: %s, %s, %s %d\n",
           e.empAddress.street, e.empAddress.city,
           e.empAddress.state, e.empAddress.zipCode);
    printf("Education: %s from %s (%d), GPA: %.2f\n",
           e.qualification.degree, e.qualification.university,
           e.qualification.graduationYear, e.qualification.gpa);
    printf("Salary: $%.2f\n", e.salary);
}

void displayRectangle(struct Rectangle r)
{
    printf("Rectangle [%s]\n", r.color);
    printf("  Top Left: (%d, %d)\n", r.topLeft.x, r.topLeft.y);
    printf("  Bottom Right: (%d, %d)\n", r.bottomRight.x, r.bottomRight.y);
}

float calculateRectangleArea(struct Rectangle r)
{
    int width = r.bottomRight.x - r.topLeft.x;
    int height = r.topLeft.y - r.bottomRight.y;
    return (float)(width * height);
}

void initializeDepartment(struct Department *dept, const char *name)
{
    strcpy(dept->name, name);
    dept->employeeCount = 0;
}