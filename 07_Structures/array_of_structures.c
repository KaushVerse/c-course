/**
 * array_of_structures.c
 * Demonstration of arrays of structures in C
 * Author: Kaushik
 * Date: 2026
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

// ==================== BASIC STRUCTURE DEFINITIONS ====================

// Student structure
struct Student
{
    int id;
    char name[50];
    int age;
    float gpa;
    char grade;
};

// Book structure
struct Book
{
    int id;
    char title[100];
    char author[50];
    float price;
    int quantity;
};

// ==================== MORE COMPLEX STRUCTURE ====================

struct Product
{
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
    float rating;
};

// ==================== FUNCTION PROTOTYPES ====================

// Student functions
void initializeStudents(struct Student students[], int size);
void displayStudent(struct Student s);
void displayAllStudents(struct Student students[], int size);
struct Student findTopStudent(struct Student students[], int size);
float calculateAverageGPA(struct Student students[], int size);
void sortStudentsByGPA(struct Student students[], int size);
void addStudent(struct Student students[], int *size, int maxSize);
void deleteStudent(struct Student students[], int *size, int id);
struct Student *searchStudentById(struct Student students[], int size, int id);

// Book functions
void initializeBooks(struct Book books[], int size);
void displayBook(struct Book b);
void displayAllBooks(struct Book books[], int size);
float calculateInventoryValue(struct Book books[], int size);
void sellBook(struct Book books[], int size, int id, int quantity);

// Product functions
void displayProductsByCategory(struct Product products[], int size, const char *category);
void applyDiscount(struct Product products[], int size, float discountPercent);

// Utility functions
void printLine(char c, int length);

// ==================== MAIN FUNCTION ====================

int main()
{
    printf("=== ARRAYS OF STRUCTURES DEMONSTRATION ===\n\n");

    // ==================== EXAMPLE 1: STUDENT DATABASE ====================
    printf("1. STUDENT DATABASE USING ARRAY OF STRUCTURES:\n");
    printLine('=', 50);

    struct Student students[MAX_STUDENTS];
    int studentCount = 5; // Start with 5 students

    // Initialize with sample data
    initializeStudents(students, studentCount);

    // Display all students
    printf("\nAll Students:\n");
    displayAllStudents(students, studentCount);

    // Find top student
    struct Student topStudent = findTopStudent(students, studentCount);
    printf("\nTop Student: ");
    displayStudent(topStudent);

    // Calculate average GPA
    float avgGPA = calculateAverageGPA(students, studentCount);
    printf("\nAverage GPA: %.2f\n", avgGPA);

    // Sort students by GPA
    printf("\nStudents Sorted by GPA (Highest to Lowest):\n");
    sortStudentsByGPA(students, studentCount);
    displayAllStudents(students, studentCount);

    // Search for a student
    printf("\nSearching for Student ID 103:\n");
    struct Student *found = searchStudentById(students, studentCount, 103);
    if (found != NULL)
    {
        printf("Found: ");
        displayStudent(*found);
    }
    else
    {
        printf("Student not found!\n");
    }

    // Add a new student
    printf("\nAdding a new student:\n");
    addStudent(students, &studentCount, MAX_STUDENTS);
    printf("Updated student list (%d students):\n", studentCount);
    displayAllStudents(students, studentCount);

    // Delete a student
    printf("\nDeleting student with ID 102:\n");
    deleteStudent(students, &studentCount, 102);
    printf("Updated student list (%d students):\n", studentCount);
    displayAllStudents(students, studentCount);

    printf("\n\n");

    // ==================== EXAMPLE 2: BOOK INVENTORY ====================
    printf("2. BOOK INVENTORY SYSTEM:\n");
    printLine('=', 50);

    struct Book books[5];
    initializeBooks(books, 5);

    printf("\nCurrent Inventory:\n");
    displayAllBooks(books, 5);

    // Calculate total inventory value
    float totalValue = calculateInventoryValue(books, 5);
    printf("\nTotal Inventory Value: $%.2f\n", totalValue);

    // Sell some books
    printf("\nSelling 2 copies of 'C Programming' (ID 1):\n");
    sellBook(books, 5, 1, 2);

    printf("\nUpdated Inventory:\n");
    displayAllBooks(books, 5);

    printf("\n\n");

    // ==================== EXAMPLE 3: PRODUCT CATALOG ====================
    printf("3. PRODUCT CATALOG:\n");
    printLine('=', 50);

    struct Product products[6] = {
        {101, "Laptop", "Electronics", 999.99, 10, 4.5},
        {102, "Smartphone", "Electronics", 699.99, 15, 4.3},
        {103, "Desk Chair", "Furniture", 199.99, 5, 4.0},
        {104, "Notebook", "Stationery", 4.99, 100, 4.8},
        {105, "Pen Set", "Stationery", 12.99, 50, 4.2},
        {106, "Monitor", "Electronics", 299.99, 8, 4.6}};

    printf("\nElectronics Products:\n");
    displayProductsByCategory(products, 6, "Electronics");

    printf("\nApplying 10%% discount to all products:\n");
    applyDiscount(products, 6, 10.0);

    printf("\nUpdated Electronics Products:\n");
    displayProductsByCategory(products, 6, "Electronics");

    printf("\n\n");

    // ==================== EXAMPLE 4: 2D ARRAY OF STRUCTURES ====================
    printf("4. 2D ARRAY OF STRUCTURES (Grade Matrix):\n");
    printLine('=', 50);

    // Create a grade matrix: 3 students x 4 subjects
    struct Student gradeMatrix[3][4];

    // Initialize with sample grades (each cell is a student-grade combination)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gradeMatrix[i][j].id = i * 100 + j;
            sprintf(gradeMatrix[i][j].name, "Student_%d_Subj_%d", i + 1, j + 1);
            gradeMatrix[i][j].gpa = 2.0 + (i * 0.5) + (j * 0.3);
            if (gradeMatrix[i][j].gpa > 4.0)
                gradeMatrix[i][j].gpa = 4.0;
        }
    }

    // Display grade matrix
    printf("Grade Matrix (Students vs Subjects):\n");
    printf("         ");
    for (int j = 0; j < 4; j++)
    {
        printf("  Subject %d  ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < 4; j++)
        {
            printf("   %.2f    ", gradeMatrix[i][j].gpa);
        }
        printf("\n");
    }

    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

// Initialize students with sample data
void initializeStudents(struct Student students[], int size)
{
    // Sample data
    struct Student sample[] = {
        {101, "Alice Johnson", 20, 3.8, 'A'},
        {102, "Bob Smith", 21, 3.2, 'B'},
        {103, "Charlie Brown", 19, 3.9, 'A'},
        {104, "Diana Prince", 22, 3.5, 'B'},
        {105, "Evan Wright", 20, 2.8, 'C'}};

    for (int i = 0; i < size && i < 5; i++)
    {
        students[i] = sample[i];
    }
}

// Display a single student
void displayStudent(struct Student s)
{
    printf("ID: %d, Name: %s, Age: %d, GPA: %.2f, Grade: %c\n",
           s.id, s.name, s.age, s.gpa, s.grade);
}

// Display all students
void displayAllStudents(struct Student students[], int size)
{
    printLine('-', 60);
    for (int i = 0; i < size; i++)
    {
        printf("%d. ", i + 1);
        displayStudent(students[i]);
    }
    printLine('-', 60);
}

// Find student with highest GPA
struct Student findTopStudent(struct Student students[], int size)
{
    struct Student top = students[0];
    for (int i = 1; i < size; i++)
    {
        if (students[i].gpa > top.gpa)
        {
            top = students[i];
        }
    }
    return top;
}

// Calculate average GPA
float calculateAverageGPA(struct Student students[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += students[i].gpa;
    }
    return sum / size;
}

// Sort students by GPA (descending) using bubble sort
void sortStudentsByGPA(struct Student students[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (students[j].gpa < students[j + 1].gpa)
            {
                // Swap students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Add a new student
void addStudent(struct Student students[], int *size, int maxSize)
{
    if (*size >= maxSize)
    {
        printf("Cannot add more students. Array is full!\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);

    // Calculate grade based on GPA
    if (newStudent.gpa >= 3.5)
        newStudent.grade = 'A';
    else if (newStudent.gpa >= 2.5)
        newStudent.grade = 'B';
    else if (newStudent.gpa >= 1.5)
        newStudent.grade = 'C';
    else
        newStudent.grade = 'D';

    students[*size] = newStudent;
    (*size)++;
    printf("Student added successfully!\n");
}

// Delete a student by ID
void deleteStudent(struct Student students[], int *size, int id)
{
    int found = -1;

    // Find the student
    for (int i = 0; i < *size; i++)
    {
        if (students[i].id == id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Student with ID %d not found!\n", id);
        return;
    }

    // Shift elements left
    for (int i = found; i < *size - 1; i++)
    {
        students[i] = students[i + 1];
    }

    (*size)--;
    printf("Student with ID %d deleted successfully!\n", id);
}

// Search student by ID
struct Student *searchStudentById(struct Student students[], int size, int id)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].id == id)
        {
            return &students[i]; // Return pointer to the student
        }
    }
    return NULL;
}

// Initialize books
void initializeBooks(struct Book books[], int size)
{
    struct Book sample[] = {
        {1, "C Programming", "Dennis Ritchie", 45.99, 10},
        {2, "Python Basics", "Guido van Rossum", 39.99, 8},
        {3, "Java Complete", "James Gosling", 55.50, 5},
        {4, "Data Structures", "Robert Sedgewick", 65.00, 3},
        {5, "Algorithms", "Thomas Cormen", 75.25, 4}};

    for (int i = 0; i < size; i++)
    {
        books[i] = sample[i];
    }
}

// Display a book
void displayBook(struct Book b)
{
    printf("ID: %d, Title: %s, Author: %s, Price: $%.2f, Qty: %d\n",
           b.id, b.title, b.author, b.price, b.quantity);
}

// Display all books
void displayAllBooks(struct Book books[], int size)
{
    printLine('-', 80);
    for (int i = 0; i < size; i++)
    {
        printf("%d. ", i + 1);
        displayBook(books[i]);
    }
    printLine('-', 80);
}

// Calculate total inventory value
float calculateInventoryValue(struct Book books[], int size)
{
    float total = 0;
    for (int i = 0; i < size; i++)
    {
        total += books[i].price * books[i].quantity;
    }
    return total;
}

// Sell a book
void sellBook(struct Book books[], int size, int id, int quantity)
{
    for (int i = 0; i < size; i++)
    {
        if (books[i].id == id)
        {
            if (books[i].quantity >= quantity)
            {
                books[i].quantity -= quantity;
                printf("Sold %d copies of '%s'. Remaining: %d\n",
                       quantity, books[i].title, books[i].quantity);
            }
            else
            {
                printf("Insufficient stock! Available: %d\n", books[i].quantity);
            }
            return;
        }
    }
    printf("Book with ID %d not found!\n", id);
}

// Display products by category
void displayProductsByCategory(struct Product products[], int size, const char *category)
{
    int found = 0;
    printf("%-10s %-20s %-10s %-10s %-10s\n",
           "ID", "Name", "Price", "Stock", "Rating");
    printLine('-', 60);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(products[i].category, category) == 0)
        {
            printf("%-10d %-20s $%-9.2f %-10d %.1f\n",
                   products[i].id, products[i].name,
                   products[i].price, products[i].stock,
                   products[i].rating);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No products found in category: %s\n", category);
    }
}

// Apply discount to all products
void applyDiscount(struct Product products[], int size, float discountPercent)
{
    for (int i = 0; i < size; i++)
    {
        float discount = products[i].price * (discountPercent / 100);
        products[i].price -= discount;
    }
}

// Utility function to print a line
void printLine(char c, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}