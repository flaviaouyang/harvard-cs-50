# Memory

---

## Hexadecimal

- convention: 0 through 9 plus 'a' through 'f'
- base-16

```pseudocode
00 01 02 03 ... 09 0A 0B 0C 0D 0E ...
10 11 12 13 ...
...
```

---

## Address

```c
#include<stdio.h>

int main(void)
{
    int n = 50;
    //this is a pointer to integer n
    int *p = &n;

    //print out n
    printf("%i\n", n);

    // & (ampersand): address of..
    //and * (Asterisk ): go to address..

    // print out address of n
    printf("%p\n", &n);
    //or
    printf("%p\n", p);

    // print out n again
    printf("i\n", *&n);
    //or
    printf("%i\n", *p);
}
```

---

## String

```c
#include<stdio.h>

int main()
{
    char *s = "hi!";
    printf("%s\n", s);

    printf("%c\n", s[0]);
    printf("%c\n", s[1]);

    //*: go to address
    //bc s is stored at h
    printf("%c\n", *s);
    //output: h
    printf("%c\n", *(s+1));
    //output: i
    printf("%c\n", *(s+2));
    //output: !
}
```

---

## Compare strings

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char *s, *t;
    printf("input a msg: ");
    scanf("%s", &s);

    printf("input a msg: ");
    scanf("%s", &t);

    if (strcmp(s, t) == 0)
    {
        return true;
    } else {
        return false;
    }
}
```

---

## malloc

```c
#include<stdlib.h>

int i, n;

// malloc: memory allocation
// one more byte for the null character
char *t = malloc(strlen(s) + 1);

for(i = 0, n = strlen(s); i <= n; i++)
{
    t[i] = s[i];
    // *(t+i) = *(s+i); same thing
}

t[0] = toupper(t[0]);

//or use strcpy()
strcpy(t, s);

```

---

## free

```c
// free takes as input whatever the output of malloc is
free(t);
```

---

## valgrind

- commandline tool used to run program and inspect for memory leak

```bash
valgrind ./a.out
```

---

## garbage value

```c
int main(void)
{
    int *x; //declare a pointer to an integer called x
    int *y;

    x = malloc(sizeof(int));

    *x = 42; //go to the address x point to
             //store 42 at that address
   // *y = 13; //never assigned a y value
             //it has a garbage value
    y = x;

    *y = 13;
}
```

---

## swap and memory layout

- machine code: top of memory
- globals: below machine code
- heap: a big chunk of memory used by `malloc()`
- stack: functions use stack space

```c
#include<stdio.h>
#include<stdlib.h>

// void swap(int, int);
void swap(int*, int*);

int main()
{
    // int x = 1;
    // int y = 2;

    // works as well
    // int *x = malloc(sizeof(int));
    // *x = 1;
    // int *y = malloc(sizeof(int));
    // *y = 2;

    //or
    int x = 1;
    int y = 2;

    printf("before swap: x is %i. y is %i.\n",x, y);
    swap(&x, &y);
    printf("after swap: x is %i. y is %i.\n",x, y);
    //output: x is 1. y is 2.
           // x is 1. y is 2.
    // didn't swap. why?
    // bc swap() has their own variables
    // a and b are only copies of x and y
    // changing these variables won't change x and y in the main function
}

// void swap(int a, int b)
// {
//     printf("1: a is %i. b is %i.\n",a, b);
//     int temp = a;
//     a = b;
//     b = temp;
//     printf("2: a is %i. b is %i.\n",a, b);
// }

// take two pointers
void swap(int *a, int *b)
{
    // store whatever is at address a at temp
    int temp = *a;
    // store whatever at address a at address b
    *a = *b;
    *b = temp;
}
//now it works
```

- call `malloc()` for too many memory, it will result in heap overflow
- call too many functions without returning them will result in stackoverflow
  - recursion may cause segmentation fault
- buffer overflow occurs when we go past the end of a buffer, some chunk of memory we’ve allocated like an array, and access memory we shouldn’t be.

---

## `scanf()`

- for scanf to take a string as an input, must use `malloc()` to allocate memory beforehand or declare `char s[512]`.

---

## file I/O

- `FILE *filename` is a new data type.

```c
#include<stdio.h>
#include<string.h>

int main()
{
    //"a" means append
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1; //error handling
    }
 
    char name[1024];
    printf("name: ");
    scanf("%s", name);

    int age;
    printf("age: ");
    scanf("%i", &age);

    char sex[1024];
    printf("sex: ");
    scanf("%s", sex);

    char number[1024];
    printf("phone number: ");
    scanf("%s", number);
    fprintf(file, "%s,%i,%s,%s\n", name, age, sex,number);

    //close the file
    fclose(file);
}
```
