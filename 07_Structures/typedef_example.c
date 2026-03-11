/**
 * typedef_example.c
 * Comprehensive demonstration of typedef in C
 * Author: Kaushik
 * Date: 2026
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
// ==================== BASIC TYPEDEF EXAMPLES ====================

// 1. Basic type aliases
typedef int Integer;
typedef float Real;
typedef char Character;
typedef unsigned char Byte;
typedef unsigned int UInteger;

// 2. Pointer type aliases
typedef char *String;
typedef int *IntPtr;
typedef void *Pointer;

// 3. Array type aliases
typedef int IntArray10[10];
typedef char String50[50];
typedef float Matrix3x3[3][3];

// 4. Function pointer type aliases
typedef int (*CompareFunction)(const void *, const void *);
typedef void (*CallbackFunction)(int);
typedef int (*Operation)(int, int);

// ==================== TYPEDEF WITH STRUCTURES ====================

// 5. Structure typedef (common pattern)
typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    int day;
    int month;
    int year;
} Date;

// 6. Self-referential structure with typedef
typedef struct Node
{
    int data;
    struct Node *next;
} Node, *NodePtr; // NodePtr is pointer to Node

// 7. Structure with function pointers
typedef struct
{
    char name[50];
    int (*compare)(void *, void *);
    void (*print)(void *);
    void *(*clone)(void *);
} Object;

// 8. Nested structures with typedef
typedef struct
{
    char street[100];
    char city[50];
    char state[30];
    int zip;
} Address;

typedef struct
{
    char name[50];
    int age;
    Address address;
    float salary;
} Employee;

// ==================== TYPEDEF WITH ENUMS ====================

typedef enum
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} WeekDay;

typedef enum
{
    SUCCESS = 0,
    ERROR_FILE_NOT_FOUND = -1,
    ERROR_PERMISSION_DENIED = -2,
    ERROR_INVALID_INPUT = -3,
    ERROR_MEMORY_ALLOCATION = -4
} ErrorCode;

typedef enum
{
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_BLACK,
    COLOR_WHITE
} Color;

// ==================== TYPEDEF WITH UNIONS ====================

typedef union
{
    int intValue;
    float floatValue;
    char stringValue[20];
} Value;

typedef union
{
    uint32_t rgba;
    struct
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    } channels;
} ColorValue;

// ==================== COMPLEX TYPE DEFINITIONS ====================

// 9. Typedef for complex data structures
typedef struct
{
    int id;
    char name[50];
    float prices[4]; // prices for 4 quarters
    float total;
} SalesRecord;

typedef struct
{
    SalesRecord *records;
    int count;
    int capacity;
} SalesDatabase;

// 10. Typedef for callback with context
typedef struct Context Context; // Forward declaration

typedef void (*EventHandler)(Context *ctx, int eventCode);

struct Context
{
    int id;
    char name[50];
    EventHandler handler;
    void *data;
};

// 11. Typedef for generic container
typedef struct
{
    void *data;
    size_t size;
    size_t capacity;
    size_t elementSize;
} Vector;

// ==================== FUNCTION PROTOTYPES ====================

void demonstrateBasicTypedef(void);
void demonstrateStructureTypedef(void);
void demonstrateEnumTypedef(void);
void demonstratePointerTypedef(void);
void demonstrateArrayTypedef(void);
void demonstrateFunctionPointerTypedef(void);
void demonstrateComplexTypedef(void);
void demonstrateTypedefScope(void);

// Helper functions
int compareInts(const void *a, const void *b);
void printInt(void *data);
void callbackExample(int value);
int add(int a, int b);
int multiply(int a, int b);
void processArray(int arr[], int size, Operation op, int initial);

// Vector functions
Vector *createVector(size_t elementSize);
void pushBack(Vector *vec, void *element);
void *get(Vector *vec, size_t index);
void destroyVector(Vector *vec);

// Utility functions
void printLine(char c, int length);
void printPoint(Point p);
void printDate(Date d);
void printEmployee(Employee e);

// ==================== MAIN FUNCTION ====================

int main()
{
    printf("=== TYPEDEF IN C - COMPREHENSIVE DEMONSTRATION ===\n\n");

    demonstrateBasicTypedef();
    demonstrateStructureTypedef();
    demonstrateEnumTypedef();
    demonstratePointerTypedef();
    demonstrateArrayTypedef();
    demonstrateFunctionPointerTypedef();
    demonstrateComplexTypedef();
    demonstrateTypedefScope();

    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

void demonstrateBasicTypedef()
{
    printf("1. BASIC TYPEDEF EXAMPLES:\n");
    printLine('=', 50);

    // Using basic type aliases
    Integer age = 25;
    Real pi = 3.14159;
    Character grade = 'A';
    Byte flag = 0xFF;
    UInteger counter = 1000;

    printf("Integer age: %d\n", age);
    printf("Real pi: %.5f\n", pi);
    printf("Character grade: %c\n", grade);
    printf("Byte flag: 0x%02X\n", flag);
    printf("UInteger counter: %u\n\n", counter);

    // Check sizes
    printf("Size of Integer: %lu bytes\n", sizeof(Integer));
    printf("Size of Real: %lu bytes\n", sizeof(Real));
    printf("Size of Byte: %lu bytes\n\n", sizeof(Byte));
}

void demonstrateStructureTypedef()
{
    printf("2. TYPEDEF WITH STRUCTURES:\n");
    printLine('=', 50);

    // Using Point typedef
    Point p1 = {10, 20};
    Point p2;
    p2.x = 30;
    p2.y = 40;

    printf("Point p1: ");
    printPoint(p1);
    printf("Point p2: ");
    printPoint(p2);

    // Using Date typedef
    Date today = {11, 3, 2024};
    printf("Today's date: ");
    printDate(today);

    // Using Node typedef
    NodePtr head = NULL;
    Node node1 = {10, NULL};
    Node node2 = {20, NULL};
    Node node3 = {30, NULL};

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;

    printf("\nLinked List: ");
    NodePtr current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf("\n");

    // Using Employee typedef
    Employee emp;
    strcpy(emp.name, "John Doe");
    emp.age = 30;
    strcpy(emp.address.street, "123 Main St");
    strcpy(emp.address.city, "New York");
    strcpy(emp.address.state, "NY");
    emp.address.zip = 10001;
    emp.salary = 50000.00;

    printf("\nEmployee details:\n");
    printEmployee(emp);

    printf("\nSize of Employee: %lu bytes\n", sizeof(Employee));
    printf("Size of Address: %lu bytes\n\n", sizeof(Address));
}

void demonstrateEnumTypedef()
{
    printf("3. TYPEDEF WITH ENUMS:\n");
    printLine('=', 50);

    // Using WeekDay enum
    WeekDay today = WEDNESDAY;
    WeekDay tomorrow = THURSDAY;

    printf("Today is day %d of the week\n", today);
    printf("Tomorrow is day %d\n\n", tomorrow);

    // Using ErrorCode enum
    ErrorCode result = SUCCESS;
    printf("Operation result: %d\n", result);

    result = ERROR_FILE_NOT_FOUND;
    if (result != SUCCESS)
    {
        printf("Error occurred: %d\n", result);
    }

    // Using Color enum in a function
    Color favorite = COLOR_BLUE;
    Color background = COLOR_BLACK;

    printf("\nFavorite color code: %d\n", favorite);
    printf("Background color code: %d\n\n", background);

    // Enum values are just integers
    printf("Enum values:\n");
    printf("  MONDAY = %d\n", MONDAY);
    printf("  SUNDAY = %d\n", SUNDAY);
    printf("  ERROR_MEMORY_ALLOCATION = %d\n\n", ERROR_MEMORY_ALLOCATION);
}

void demonstratePointerTypedef()
{
    printf("4. TYPEDEF WITH POINTERS:\n");
    printLine('=', 50);

    // String is alias for char*
    String greeting = "Hello, World!";
    String name = "Alice";

    printf("greeting: %s\n", greeting);
    printf("name: %s\n", name);

    // IntPtr is alias for int*
    int value = 42;
    IntPtr ptr = &value;

    printf("value = %d\n", value);
    printf("*ptr = %d\n", *ptr);

    *ptr = 100;
    printf("After *ptr = 100, value = %d\n\n", value);

    // Pointer is alias for void*
    Pointer p1 = &value;
    Pointer p2 = greeting;

    printf("p1 points to integer: %d\n", *(int *)p1);
    printf("p2 points to string: %s\n", (char *)p2);

    printf("Size of Pointer: %lu bytes\n\n", sizeof(Pointer));
}

void demonstrateArrayTypedef()
{
    printf("5. TYPEDEF WITH ARRAYS:\n");
    printLine('=', 50);

    // IntArray10 is alias for int[10]
    IntArray10 numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("IntArray10: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // String50 is alias for char[50]
    String50 str = "This is a string stored in a String50 array";
    printf("String50: %s\n", str);
    printf("Length: %lu\n", strlen(str));

    // Matrix3x3 is alias for float[3][3]
    Matrix3x3 matrix = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}};

    printf("\nMatrix3x3:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("  [");
        for (int j = 0; j < 3; j++)
        {
            printf("%.1f", matrix[i][j]);
            if (j < 2)
                printf(", ");
        }
        printf("]\n");
    }

    printf("\nSize of IntArray10: %lu bytes\n", sizeof(IntArray10));
    printf("Size of String50: %lu bytes\n", sizeof(String50));
    printf("Size of Matrix3x3: %lu bytes\n\n", sizeof(Matrix3x3));
}

// Helper functions for function pointer demo
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

void callbackExample(int value)
{
    printf("Callback called with value: %d\n", value);
}

void processArray(int arr[], int size, Operation op, int initial)
{
    int result = initial;
    for (int i = 0; i < size; i++)
    {
        result = op(result, arr[i]);
    }
    printf("Result: %d\n", result);
}

int compareInts(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void printInt(void *data)
{
    printf("%d", *(int *)data);
}

void demonstrateFunctionPointerTypedef()
{
    printf("6. TYPEDEF WITH FUNCTION POINTERS:\n");
    printLine('=', 50);

    // Operation is function pointer type
    Operation op1 = add;
    Operation op2 = multiply;

    printf("add(5, 3) = %d\n", op1(5, 3));
    printf("multiply(5, 3) = %d\n", op2(5, 3));

    // Using function pointers in array
    Operation operations[] = {add, multiply};
    const char *opNames[] = {"Addition", "Multiplication"};

    int a = 10, b = 5;
    printf("\nOperations on %d and %d:\n", a, b);
    for (int i = 0; i < 2; i++)
    {
        printf("  %s: %d\n", opNames[i], operations[i](a, b));
    }

    // Callback function example
    CallbackFunction cb = callbackExample;
    printf("\nCallback example: ");
    cb(42);

    // Compare function for qsort
    CompareFunction cmp = compareInts;
    int numbers[] = {5, 2, 8, 1, 9, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("\nBefore sorting: ");
    for (int i = 0; i < size; i++)
        printf("%d ", numbers[i]);

    qsort(numbers, size, sizeof(int), cmp);

    printf("\nAfter sorting:  ");
    for (int i = 0; i < size; i++)
        printf("%d ", numbers[i]);
    printf("\n\n");

    // Using function pointer in structure
    Object obj;
    strcpy(obj.name, "Integer Object");
    obj.compare = (int (*)(void *, void *))compareInts;
    obj.print = (void (*)(void *))printInt;

    int x = 42, y = 100;
    printf("Object name: %s\n", obj.name);
    printf("Comparing %d and %d: %d\n", x, y,
           ((CompareFunction)obj.compare)(&x, &y));
    printf("Printing object: ");
    obj.print(&x);
    printf("\n\n");
}

void demonstrateComplexTypedef()
{
    printf("7. COMPLEX TYPEDEF EXAMPLES:\n");
    printLine('=', 50);

    // SalesDatabase example
    SalesDatabase db;
    db.capacity = 5;
    db.count = 0;
    db.records = (SalesRecord *)malloc(db.capacity * sizeof(SalesRecord));

    if (db.records)
    {
        // Add some records
        SalesRecord r1 = {1, "Product A", {10.5, 12.3, 15.7, 18.2}, 0};
        r1.total = r1.prices[0] + r1.prices[1] + r1.prices[2] + r1.prices[3];
        db.records[db.count++] = r1;

        SalesRecord r2 = {2, "Product B", {5.2, 7.8, 6.4, 9.1}, 0};
        r2.total = r2.prices[0] + r2.prices[1] + r2.prices[2] + r2.prices[3];
        db.records[db.count++] = r2;

        printf("Sales Database (%d records):\n", db.count);
        for (int i = 0; i < db.count; i++)
        {
            printf("  %s (ID: %d) - Total: $%.2f\n",
                   db.records[i].name,
                   db.records[i].id,
                   db.records[i].total);
        }

        free(db.records);
    }

    // Context with event handler example
    Context ctx;
    ctx.id = 1;
    strcpy(ctx.name, "Main Context");
    ctx.handler = NULL; // Would set actual handler
    ctx.data = NULL;

    printf("\nContext created: %s (ID: %d)\n", ctx.name, ctx.id);
    printf("Handler: %s\n", ctx.handler ? "Set" : "Not set");

    // Vector example (generic container)
    Vector *vec = createVector(sizeof(int));
    if (vec)
    {
        int values[] = {10, 20, 30, 40, 50};
        for (int i = 0; i < 5; i++)
        {
            pushBack(vec, &values[i]);
        }

        printf("\nVector contents (%zu elements):\n", vec->size);
        for (size_t i = 0; i < vec->size; i++)
        {
            int *val = (int *)get(vec, i);
            printf("  vec[%zu] = %d\n", i, *val);
        }

        destroyVector(vec);
    }

    printf("\n");
}

void demonstrateTypedefScope()
{
    printf("8. TYPEDEF SCOPE AND BEST PRACTICES:\n");
    printLine('=', 50);

    printf("Typedef Best Practices:\n");
    printf("  1. Use typedef to simplify complex type declarations\n");
    printf("  2. Add _t suffix for type names (common convention)\n");
    printf("  3. Use typedef with structures to avoid 'struct' keyword\n");
    printf("  4. Be careful with typedef and pointers (hides pointer nature)\n");
    printf("  5. Use typedef for platform-independent types\n");

    printf("\nCommon Use Cases:\n");
    printf("  • size_t, time_t, FILE* (standard library)\n");
    printf("  • uint8_t, int32_t (fixed-width integers)\n");
    printf("  • Custom structures and unions\n");
    printf("  • Function pointers for callbacks\n");
    printf("  • Complex nested types\n");

    printf("\nTypedef vs #define:\n");
    printf("  typedef ByteArray[100];  // Creates a type alias\n");
    printf("  #define ByteArray char[100]  // Simple text replacement\n");

    printf("\nScope Example:\n");
    {
        typedef int LocalInt; // Only in this block
        LocalInt x = 42;
        printf("  LocalInt inside block: %d\n", x);
    }
    // LocalInt x;  // Error! LocalInt not in scope

    // But global typedefs are available
    Integer y = 100; // Global typedef
    printf("  Global Integer outside block: %d\n\n", y);
}

// ==================== HELPER FUNCTION DEFINITIONS ====================

void printPoint(Point p)
{
    printf("(%d, %d)\n", p.x, p.y);
}

void printDate(Date d)
{
    printf("%d/%d/%d\n", d.day, d.month, d.year);
}

void printEmployee(Employee e)
{
    printf("  Name: %s\n", e.name);
    printf("  Age: %d\n", e.age);
    printf("  Address: %s, %s, %s %d\n",
           e.address.street, e.address.city,
           e.address.state, e.address.zip);
    printf("  Salary: $%.2f\n", e.salary);
}

Vector *createVector(size_t elementSize)
{
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    if (vec)
    {
        vec->data = malloc(elementSize * 10); // Initial capacity 10
        vec->size = 0;
        vec->capacity = 10;
        vec->elementSize = elementSize;
    }
    return vec;
}

void pushBack(Vector *vec, void *element)
{
    if (vec->size >= vec->capacity)
    {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * vec->elementSize);
    }
    void *dest = (char *)vec->data + (vec->size * vec->elementSize);
    memcpy(dest, element, vec->elementSize);
    vec->size++;
}

void *get(Vector *vec, size_t index)
{
    if (index >= vec->size)
        return NULL;
    return (char *)vec->data + (index * vec->elementSize);
}

void destroyVector(Vector *vec)
{
    if (vec)
    {
        free(vec->data);
        free(vec);
    }
}

void printLine(char c, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}