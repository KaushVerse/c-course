# C Pointers – Hinglish Explanation

Is document me hum C language ke important pointer concepts ko simple Hinglish me samjhenge.

Topics:

1. Pointer Basics
2. Pointer Arithmetic
3. Pointer to Pointer
4. Pointer with Arrays
5. Pointer with Functions
6. Void Pointer

---

# 1. Pointer Basics

Pointer ek special variable hota hai jo kisi dusre variable ka **address store karta hai**.

Example:

```c
#include <stdio.h>

int main(){

    int a = 10;
    int *ptr;

    ptr = &a;

    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", &a);

    printf("Pointer value: %p\n", ptr);
    printf("Value using pointer: %d\n", *ptr);

}
```

### Important Symbols

`&` → address operator

`*` → dereference operator

Example:

```
ptr = &a
```

Pointer me variable ka address store hota hai.

```
*ptr
```

Pointer ke address par jo value stored hai wo milti hai.

---

# 2. Pointer Arithmetic

Pointer ko increment ya decrement bhi kar sakte hain.

Example:

```c
#include <stdio.h>

int main(){

    int arr[3] = {10,20,30};

    int *ptr = arr;

    printf("%d\n", *ptr);

    ptr++;

    printf("%d\n", *ptr);

}
```

### Important Rule

Pointer increment hone par **next memory location par move karta hai**.

Agar int pointer hai to usually **4 bytes jump karta hai**.

Example:

```
ptr -> arr[0]
ptr++ -> arr[1]
ptr++ -> arr[2]
```

---

# 3. Pointer to Pointer

Jab ek pointer dusre pointer ka address store kare to use **double pointer** kehte hain.

Example:

```c
#include <stdio.h>

int main(){

    int a = 50;

    int *ptr = &a;

    int **pptr = &ptr;

    printf("%d\n", **pptr);

}
```

### Memory Flow

```
pptr -> ptr -> a
```

`*ptr` → value of a

`**pptr` → value of a

---

# 4. Pointer with Arrays

C language me **array ka naam first element ka address hota hai**.

Example:

```c
#include <stdio.h>

int main(){

    int arr[3] = {5,10,15};

    int *ptr = arr;

    for(int i=0;i<3;i++){
        printf("%d\n", *(ptr+i));
    }

}
```

Equivalent expressions:

```
arr[i]
*(arr+i)
ptr[i]
*(ptr+i)
```

Sab same result dete hain.

---

# 5. Pointer with Functions

Pointer use karke hum function me original variable ki value change kar sakte hain.

Isko **pass by reference** bolte hain.

Example:

```c
#include <stdio.h>

void update(int *x){

    *x = *x + 10;

}

int main(){

    int num = 20;

    update(&num);

    printf("%d", num);

}
```

Output:

```
30
```

Kyuki function ko variable ka **address** diya gaya hai.

---

# 6. Void Pointer

Void pointer ek **generic pointer** hota hai jo kisi bhi type ka address store kar sakta hai.

Example:

```c
#include <stdio.h>

int main(){

    int a = 10;

    void *ptr;

    ptr = &a;

    printf("%d", *(int*)ptr);

}
```

Important:

Void pointer ko dereference karne se pehle **type cast karna padta hai**.

Example:

```
*(int*)ptr
```

---

# Quick Summary

| Concept            | Meaning                           |
| ------------------ | --------------------------------- |
| Pointer            | Address store karne wala variable |
| &                  | Address operator                  |
| *                  | Dereference operator              |
| Pointer Arithmetic | Pointer ka memory move karna      |
| Double Pointer     | Pointer ka pointer                |
| Void Pointer       | Generic pointer                   |

---

# Why Pointers Important

Pointers ka use hota hai:

* Dynamic Memory Allocation
* Data Structures
* Operating Systems
* Embedded Systems
* High Performance Programming

Isliye C language me pointers **sabse powerful concept** mana jata hai.
