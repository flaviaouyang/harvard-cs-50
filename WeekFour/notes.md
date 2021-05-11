# Week Four: Memory

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
