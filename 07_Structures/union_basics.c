/**
 * union_basics.c
 * Demonstration of unions in C programming
 * Author: Your Name
 * Date: 2026
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// ==================== BASIC UNION EXAMPLES ====================

// Basic union - all members share the same memory location
union Data
{
    int i;
    float f;
    char str[20];
};

// Union with different numeric types
union Number
{
    int intValue;
    float floatValue;
    double doubleValue;
    unsigned int uintValue;
};

// ==================== UNIONS IN STRUCTURES ====================

// Tagged union (discriminated union) - using enum to track type
enum DataType
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
    TYPE_BOOL
};

struct Variant
{
    enum DataType type; // Tag to indicate which member is active
    union
    {
        int intValue;
        float floatValue;
        char stringValue[50];
        int boolValue; // 0 for false, 1 for true
    } data;
};

// ==================== PRACTICAL APPLICATIONS ====================

// 1. IP Address representation (different interpretations of same data)
union IPAddress
{
    uint32_t address;  // 32-bit integer representation
    uint8_t octets[4]; // 4 octets representation
    struct
    {
        uint8_t octet1;
        uint8_t octet2;
        uint8_t octet3;
        uint8_t octet4;
    } octetStruct;
};

// 2. Register representation (embedded systems style)
union Register
{
    uint32_t fullValue; // Full 32-bit register

    // Bit fields for individual bits/groups
    struct
    {
        uint32_t mode : 2;      // Bits 0-1
        uint32_t enable : 1;    // Bit 2
        uint32_t interrupt : 1; // Bit 3
        uint32_t reserved : 4;  // Bits 4-7
        uint32_t data : 8;      // Bits 8-15
        uint32_t address : 16;  // Bits 16-31
    } bits;
};

// 3. Color representation (RGB vs HEX)
union Color
{
    uint32_t hexValue; // 0x00RRGGBB

    struct
    {
        uint8_t blue;
        uint8_t green;
        uint8_t red;
        uint8_t alpha;
    } channels;
};

// 4. Mixed data type storage (like in a spreadsheet cell)
enum CellType
{
    CELL_EMPTY,
    CELL_INT,
    CELL_FLOAT,
    CELL_TEXT
};

struct Cell
{
    enum CellType type;
    union
    {
        int i;
        float f;
        char text[100];
    } value;
};

// ==================== FUNCTION PROTOTYPES ====================

void demonstrateBasicUnion(void);
void demonstrateUnionSize(void);
void demonstrateIPAddress(void);
void demonstrateRegister(void);
void demonstrateColor(void);
void demonstrateVariant(void);
void demonstrateSpreadsheet(void);
void demonstrateTypePunning(void);

// Variant/union helper functions
void setIntValue(struct Variant *v, int val);
void setFloatValue(struct Variant *v, float val);
void setStringValue(struct Variant *v, const char *val);
void printVariant(const struct Variant *v);

// Spreadsheet cell functions
void setCellInt(struct Cell *c, int val);
void setCellFloat(struct Cell *c, float val);
void setCellText(struct Cell *c, const char *val);
void printCell(const struct Cell *c);

// Utility function
void printLine(char c, int length);

// ==================== MAIN FUNCTION ====================

int main()
{
    printf("=== UNIONS IN C - COMPREHENSIVE DEMONSTRATION ===\n\n");

    demonstrateBasicUnion();
    demonstrateUnionSize();
    demonstrateIPAddress();
    demonstrateRegister();
    demonstrateColor();
    demonstrateVariant();
    demonstrateSpreadsheet();
    demonstrateTypePunning();

    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

void demonstrateBasicUnion()
{
    printf("1. BASIC UNION DEMONSTRATION:\n");
    printLine('=', 50);

    union Data data;

    printf("Size of union Data: %lu bytes\n", sizeof(union Data));
    printf("(Compare with size of int: %lu, float: %lu, char[20]: %lu)\n\n",
           sizeof(int), sizeof(float), sizeof(char[20]));

    // Store integer
    data.i = 42;
    printf("After storing int (42):\n");
    printf("  data.i = %d\n", data.i);
    printf("  data.f = %f\n", data.f);       // Garbage value
    printf("  data.str = %s\n\n", data.str); // Garbage

    // Store float
    data.f = 3.14159;
    printf("After storing float (3.14159):\n");
    printf("  data.i = %d (garbage)\n", data.i);
    printf("  data.f = %f\n", data.f);
    printf("  data.str = %s (garbage)\n\n", data.str);

    // Store string
    strcpy(data.str, "Hello Union");
    printf("After storing string (\"Hello Union\"):\n");
    printf("  data.i = %d (garbage)\n", data.i);
    printf("  data.f = %f (garbage)\n", data.f);
    printf("  data.str = %s\n\n", data.str);
}

void demonstrateUnionSize()
{
    printf("2. UNION SIZE DEMONSTRATION:\n");
    printLine('=', 50);

    union Number num;

    printf("Size of union Number: %lu bytes\n", sizeof(union Number));
    printf("  Size of int: %lu bytes\n", sizeof(int));
    printf("  Size of float: %lu bytes\n", sizeof(float));
    printf("  Size of double: %lu bytes\n", sizeof(double));
    printf("  Size of unsigned int: %lu bytes\n\n", sizeof(unsigned int));

    // All members share the same address
    printf("Address of num.intValue: %p\n", (void *)&num.intValue);
    printf("Address of num.floatValue: %p\n", (void *)&num.floatValue);
    printf("Address of num.doubleValue: %p\n\n", (void *)&num.doubleValue);
}

void demonstrateIPAddress()
{
    printf("3. IP ADDRESS REPRESENTATION:\n");
    printLine('=', 50);

    union IPAddress ip;

    // Set IP address 192.168.1.1
    ip.octets[0] = 192;
    ip.octets[1] = 168;
    ip.octets[2] = 1;
    ip.octets[3] = 1;

    printf("IP Address (octets): %d.%d.%d.%d\n",
           ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);
    printf("IP Address (32-bit integer): %u (0x%08X)\n",
           ip.address, ip.address);
    printf("IP Address (struct): %d.%d.%d.%d\n\n",
           ip.octetStruct.octet1, ip.octetStruct.octet2,
           ip.octetStruct.octet3, ip.octetStruct.octet4);

    // Different endianness demonstration
    printf("Note: The 32-bit value may show byte order (endianness) effects\n");
    printf("On little-endian systems: 192.168.1.1 = 0x%08X\n", ip.address);
    printf("On big-endian systems:    192.168.1.1 = 0xC0A80101\n\n");
}

void demonstrateRegister()
{
    printf("4. REGISTER BIT-FIELDS (Embedded Systems Style):\n");
    printLine('=', 50);

    union Register reg;

    // Initialize register
    reg.fullValue = 0;

    printf("Initial register value: 0x%08X\n", reg.fullValue);

    // Set individual bit fields
    reg.bits.mode = 2;         // 10 binary
    reg.bits.enable = 1;       // 1 binary
    reg.bits.interrupt = 0;    // 0 binary
    reg.bits.data = 0xAB;      // 171 decimal
    reg.bits.address = 0x1234; // 4660 decimal

    printf("\nAfter setting bit fields:\n");
    printf("  Mode (2 bits): %u\n", reg.bits.mode);
    printf("  Enable (1 bit): %u\n", reg.bits.enable);
    printf("  Interrupt (1 bit): %u\n", reg.bits.interrupt);
    printf("  Data (8 bits): 0x%02X (%u)\n", reg.bits.data, reg.bits.data);
    printf("  Address (16 bits): 0x%04X (%u)\n", reg.bits.address, reg.bits.address);
    printf("\n  Full register value: 0x%08X\n", reg.fullValue);

    // Show bit layout
    printf("\nBit layout (31-0):\n");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (reg.fullValue >> i) & 1);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n\n");
}

void demonstrateColor()
{
    printf("5. COLOR REPRESENTATION (RGB vs HEX):\n");
    printLine('=', 50);

    union Color color;

    // Set color to purple (RGB: 128, 0, 128)
    color.channels.red = 128;
    color.channels.green = 0;
    color.channels.blue = 128;
    color.channels.alpha = 255; // Fully opaque

    printf("Color channels:\n");
    printf("  Red:   %3d (0x%02X)\n", color.channels.red, color.channels.red);
    printf("  Green: %3d (0x%02X)\n", color.channels.green, color.channels.green);
    printf("  Blue:  %3d (0x%02X)\n", color.channels.blue, color.channels.blue);
    printf("  Alpha: %3d (0x%02X)\n", color.channels.alpha, color.channels.alpha);

    printf("\nAs 32-bit hex value: 0x%08X\n", color.hexValue);
    printf("(Format: 0xAA RR G GB B? Actually depends on endianness)\n\n");

    // Set by hex value
    color.hexValue = 0xFF00FF00; // Green with full alpha? (endianness dependent)
    printf("After setting hex to 0xFF00FF00:\n");
    printf("  Red:   %d\n", color.channels.red);
    printf("  Green: %d\n", color.channels.green);
    printf("  Blue:  %d\n", color.channels.blue);
    printf("  Alpha: %d\n\n", color.channels.alpha);
}

void setIntValue(struct Variant *v, int val)
{
    v->type = TYPE_INT;
    v->data.intValue = val;
}

void setFloatValue(struct Variant *v, float val)
{
    v->type = TYPE_FLOAT;
    v->data.floatValue = val;
}

void setStringValue(struct Variant *v, const char *val)
{
    v->type = TYPE_STRING;
    strcpy(v->data.stringValue, val);
}

void printVariant(const struct Variant *v)
{
    switch (v->type)
    {
    case TYPE_INT:
        printf("Integer: %d\n", v->data.intValue);
        break;
    case TYPE_FLOAT:
        printf("Float: %f\n", v->data.floatValue);
        break;
    case TYPE_STRING:
        printf("String: %s\n", v->data.stringValue);
        break;
    default:
        printf("Unknown type\n");
    }
}

void demonstrateVariant()
{
    printf("6. TAGGED UNION (VARIANT TYPE):\n");
    printLine('=', 50);

    struct Variant v;

    setIntValue(&v, 100);
    printf("After setInt: ");
    printVariant(&v);

    setFloatValue(&v, 3.14159);
    printf("After setFloat: ");
    printVariant(&v);

    setStringValue(&v, "Hello, Union!");
    printf("After setString: ");
    printVariant(&v);

    printf("\nSize of Variant: %lu bytes\n", sizeof(struct Variant));
    printf("(Without union + tag overhead)\n\n");
}

void setCellInt(struct Cell *c, int val)
{
    c->type = CELL_INT;
    c->value.i = val;
}

void setCellFloat(struct Cell *c, float val)
{
    c->type = CELL_FLOAT;
    c->value.f = val;
}

void setCellText(struct Cell *c, const char *val)
{
    c->type = CELL_TEXT;
    strcpy(c->value.text, val);
}

void printCell(const struct Cell *c)
{
    switch (c->type)
    {
    case CELL_EMPTY:
        printf("(empty)");
        break;
    case CELL_INT:
        printf("%d", c->value.i);
        break;
    case CELL_FLOAT:
        printf("%.2f", c->value.f);
        break;
    case CELL_TEXT:
        printf("\"%s\"", c->value.text);
        break;
    }
}

void demonstrateSpreadsheet()
{
    printf("7. SPREADSHEET CELL SIMULATION:\n");
    printLine('=', 50);

    struct Cell spreadsheet[3][3];

    // Initialize all cells to empty
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            spreadsheet[i][j].type = CELL_EMPTY;
        }
    }

    // Fill some cells
    setCellInt(&spreadsheet[0][0], 42);
    setCellFloat(&spreadsheet[0][1], 3.14);
    setCellText(&spreadsheet[0][2], "Hello");
    setCellInt(&spreadsheet[1][0], 100);
    setCellFloat(&spreadsheet[1][1], 2.718);
    setCellText(&spreadsheet[2][2], "World");

    // Display spreadsheet
    printf("3x3 Spreadsheet:\n");
    printf("+------------+------------+------------+\n");
    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < 3; j++)
        {
            printf(" %-10s ", " ");
            printf("|");
        }
        printf("\n|");
        for (int j = 0; j < 3; j++)
        {
            printf(" ");
            printCell(&spreadsheet[i][j]);
            // Pad with spaces
            int len = (spreadsheet[i][j].type == CELL_TEXT) ? strlen(spreadsheet[i][j].value.text) + 2 : 10;
            for (int k = len; k < 10; k++)
                printf(" ");
            printf(" |");
        }
        printf("\n|");
        for (int j = 0; j < 3; j++)
        {
            printf(" %-10s ", " ");
            printf("|");
        }
        printf("\n+------------+------------+------------+\n");
    }
    printf("\nMemory saved by using union: %lu bytes per cell\n",
           sizeof(struct Cell) - sizeof(((struct Cell *)0)->value));
    printf("(Instead of having separate fields for each type)\n\n");
}

void demonstrateTypePunning()
{
    printf("8. TYPE PUNNING (Accessing same data as different types):\n");
    printLine('=', 50);

    // Example 1: Getting float components
    union
    {
        float f;
        uint32_t i;
    } floatPun;

    floatPun.f = 3.14159;
    printf("Float value: %f\n", floatPun.f);
    printf("As 32-bit integer: 0x%08X\n", floatPun.i);
    printf("Binary: ");
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (floatPun.i >> i) & 1);
        if (i == 31 || i == 23)
            printf(" "); // Separate sign, exponent, mantissa
    }
    printf("\n(Sign | Exponent | Mantissa)\n\n");

    // Example 2: Checking endianness
    union
    {
        uint16_t s;
        uint8_t bytes[2];
    } endianTest;

    endianTest.s = 0x1234;
    printf("Endianness test (value 0x1234):\n");
    printf("  Byte 0: 0x%02X\n", endianTest.bytes[0]);
    printf("  Byte 1: 0x%02X\n", endianTest.bytes[1]);

    if (endianTest.bytes[0] == 0x34)
    {
        printf("  System is LITTLE endian\n");
    }
    else
    {
        printf("  System is BIG endian\n");
    }
    printf("\n");

    // Example 3: Extracting bytes from integer
    union
    {
        uint32_t word;
        uint8_t bytes[4];
    } wordTest;

    wordTest.word = 0xDEADBEEF;
    printf("Word: 0x%08X\n", wordTest.word);
    printf("Bytes: ");
    for (int i = 0; i < 4; i++)
    {
        printf("0x%02X ", wordTest.bytes[i]);
    }
    printf("\n\n");
}

void printLine(char c, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}