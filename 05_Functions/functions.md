# C Functions – Hinglish Explanation

Is document me hum 4 important C function concepts ko simple Hinglish me samjhenge:

1. Function Basics
2. Recursion
3. Scope & Storage Classes
4. Inline vs Normal Functions

---

# 1. Function Basics

Function ka matlab hota hai ek reusable block of code jo ek specific kaam karta hai.

Example:

```c
#include <stdio.h>

void greet(){
    printf("Hello Bro! Welcome to C Functions\n");
}

int main(){
    greet();
    return 0;
}
```

### Kaise kaam karta hai

1. `void greet()` → function declare + define hua
2. `greet();` → function call hua
3. Jab call hota hai to program us function ke andar ka code run karta hai

### Structure

```
return_type function_name(parameters)
{
   code
}
```

Example:

```
int add(int a, int b)
```

---

# 2. Recursion

Recursion ka matlab hai **jab ek function khud ko hi call karta hai**.

Example: Factorial

```c
#include <stdio.h>

int factorial(int n){
    if(n==0 || n==1)
        return 1;

    return n * factorial(n-1);
}

int main(){
    printf("%d", factorial(5));
}
```

### Flow

```
factorial(5)
5 * factorial(4)
5 * 4 * factorial(3)
5 * 4 * 3 * factorial(2)
5 * 4 * 3 * 2 * factorial(1)
```

Final Answer = 120

### Recursion ke 2 rules

1. Base Condition hona chahiye
2. Function khud ko call karega

Agar base condition nahi hoga to program infinite recursion me chala jayega.

---

# 3. Scope & Storage Classes

Scope matlab variable kaha tak accessible hai.

Storage class decide karta hai:

* variable kaha store hoga
* kitna time tak zinda rahega

## auto

Default local variable.

```
auto int a = 10;
```

Lifetime → function ke end tak.

---

## static

Static variable apni value **function calls ke beech retain karta hai**.

```c
void counter(){
    static int count = 0;
    count++;
    printf("%d", count);
}
```

Agar function 3 baar call hoga:

```
1
2
3
```

---

## extern

Extern ka use hota hai **dusri file ka global variable access karne ke liye**.

File1.c

```
int num = 50;
```

File2.c

```
extern int num;
```

---

## register

Register variable CPU register me store hone ka request karta hai taaki access fast ho.

```
register int x = 5;
```

---

# 4. Inline vs Normal Functions

## Normal Function

Normal function call hone par:

1. stack me memory allocate hoti hai
2. control function ke paas jata hai
3. return hota hai

Example:

```c
int add(int a, int b){
   return a+b;
}
```

---

## Inline Function

Inline function me compiler function call nahi karta.

Compiler function ke code ko **direct replace kar deta hai**.

Example:

```c
inline int square(int x){
   return x*x;
}
```

Agar call hua:

```
square(5)
```

Compiler internally bana dega:

```
5*5
```

### Benefit

Fast execution because function call overhead nahi hota.

### Drawback

Code size bada ho sakta hai.

---

# Quick Summary

| Concept         | Simple Meaning                         |
| --------------- | -------------------------------------- |
| Function        | Reusable block of code                 |
| Recursion       | Function calling itself                |
| Scope           | Variable kaha accessible hai           |
| Storage Class   | Variable ka lifetime aur memory type   |
| Inline Function | Function call ko code se replace karna |

---

Agar tum C programming deeply seekh rahe ho to next topics important hote hain:

* Function Pointers
* Dynamic Memory
* Structures
* File Handling
* Data Structures in C
