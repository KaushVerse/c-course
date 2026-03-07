/****************************************************
 * 🧠 C PREPROCESSOR – FULL DEEP DIVE (SINGLE FILE)
 * Author: Kaushik 😎
 ****************************************************/

/* ================================================
 * LEVEL 1️⃣ : INCLUDE FILES
 * ================================================ */
#include <stdio.h>
#include <stdlib.h>

/* ================================================
 * LEVEL 2️⃣ : INCLUDE GUARDS (Normally for .h files)
 * ================================================ */
#ifndef PREPROCESSOR_DEMO
#define PREPROCESSOR_DEMO

/* ================================================
 * LEVEL 3️⃣ : OBJECT-LIKE MACROS
 * ================================================ */
#define PI 3.1415926
#define MAX_USERS 100

/* ================================================
 * LEVEL 4️⃣ : FUNCTION-LIKE MACROS
 * ================================================ */
#define SQUARE(x) ((x) * (x))
#define ADD(a, b) ((a) + (b))

/* ❌ BAD MACRO (for demo) */
#define BAD_SQUARE(x) x *x

/* ================================================
 * LEVEL 5️⃣ : CONDITIONAL COMPILATION
 * ================================================ */
#define DEBUG 1

#if DEBUG
#define DEBUG_LOG(msg) \
    printf("🐞 DEBUG [%s:%d]: %s\n", __FILE__, __LINE__, msg)
#else
#define DEBUG_LOG(msg)
#endif

/* ================================================
 * LEVEL 6️⃣ : PREDEFINED MACROS
 * ================================================ */
#define SHOW_BUILD_INFO()                                                  \
    printf("📄 File  : %s\n📅 Date  : %s\n⏰ Time  : %s\n📍 Line  : %d\n", \
           __FILE__, __DATE__, __TIME__, __LINE__)

/* ================================================
 * LEVEL 7️⃣ : STRINGIFY (#) OPERATOR
 * ================================================ */
#define TO_STRING(x) #x

/* ================================================
 * LEVEL 8️⃣ : TOKEN PASTING (##)
 * ================================================ */
#define CREATE_VAR(name) int var_##name = 0

/* ================================================
 * LEVEL 9️⃣ : PLATFORM CHECK
 * ================================================ */
#ifdef _WIN32
#define PLATFORM "Windows"
#elif __linux__
#define PLATFORM "Linux"
#elif __APPLE__
#define PLATFORM "MacOS"
#else
#define PLATFORM "Unknown"
#endif

/* ================================================
 * LEVEL 🔟 : ERROR / WARNING
 * ================================================ */
#ifndef PI
#error "PI is not defined!"
#endif

/* ================================================
 * LEVEL 1️⃣1️⃣ : INLINE FUNCTION (BETTER THAN MACRO)
 * ================================================ */
static inline int safe_square(int x)
{
    return x * x;
}

/* ================================================
 * MAIN FUNCTION
 * ================================================ */
int main(void)
{
    printf("🚀 C PREPROCESSOR FULL DEMO STARTED\n\n");

    /* --- Object-like macros --- */
    printf("PI = %.6f\n", PI);
    printf("MAX_USERS = %d\n\n", MAX_USERS);

    /* --- Function-like macros --- */
    int a = 3;
    int b = 4;

    printf("SQUARE(%d) = %d\n", a, SQUARE(a));
    printf("ADD(%d, %d) = %d\n", a, b, ADD(a, b));

    /* ❌ Macro bug demo */
    printf("BAD_SQUARE(1+2) = %d  ❌\n", BAD_SQUARE(1 + 2));
    printf("SQUARE(1+2) = %d      ✅\n\n", SQUARE(1 + 2));

    /* --- Debug macro --- */
    DEBUG_LOG("This is a debug message");

    /* --- Predefined macros --- */
    SHOW_BUILD_INFO();
    printf("\n");

    /* --- Stringify operator --- */
    printf("TO_STRING(Hello_Bro) = %s\n\n", TO_STRING(Hello_Bro));

    /* --- Token pasting --- */
    CREATE_VAR(age);
    var_age = 25;
    printf("Token pasted variable var_age = %d\n\n", var_age);

    /* --- Platform info --- */
    printf("🖥️ Platform detected: %s\n\n", PLATFORM);

    /* --- Inline function vs macro --- */
    int x = 5;
    printf("safe_square(%d) = %d\n", x, safe_square(x));

    printf("\n✅ DEMO COMPLETED SUCCESSFULLY\n");
    return 0;
}

#endif /* PREPROCESSOR_DEMO */
