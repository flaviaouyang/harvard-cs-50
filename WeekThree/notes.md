# Big O Notation: 
describes running time of an algorithm
1. O(n)
2. O(log n)
3. O(n log n)
4. O(1)
5. O(n^2)
------------------------------------------
# Big Omega Notation: 
describes the lower bound

------------------------------------------
# Linear search: 
search one element by one element

door example:

```
for i from 0 to n - 1
    if number behind ith door
        return true
return false
```

time efficiency: O(n); Ω(1)

------------------------------------------
# Binary search:
search from middle in sorted array

door example:
```
if number behind middle door
    return true
else if number < middle door
    search left half
else if number > middle door
    search right half
```

time efficiency: O(log n); Ω(1)

------------------------------------------
# `strcmp()`:
compare two strings

`strcmp(names[i], "ron") == 0`

------------------------------------------
# struct:
```
typedef struct
{
    string name;
    string number;
}
person;
```
------------------------------------------
# Selection sort:
find the smallest number from the array,
swap the smallest number with index 0,
continue till the end

pseudocode:
```
For i from 0 to n-1
    Find smallest item between i'th item and last item
    Swap smallest item with i'th item
```

time efficiency: O(n^2), Ω(n^2)

-------------------------------------------
# Bubble sort:
swap pairs of numbers repeatedly

pseudocode:
```
Repeat until sorted
    For i from 0 to n-2
        If i'th and i+1'th elements out of order
            Swap them
    If no swaps
        quit
```
time efficiency: O(n^2), Ω(n)

-------------------------------------------
# Recursion:
- the ability for a function to call itself

-------------------------------------------
# Merge sort:

pseudocode:
```
if only one number //base case
    return
else
    sort left half of number
    sort right half of number
    merge sorted halves
```

time efficiency: O(n log n), Ω(n log n)

-------------------------------------------
# Theta Notation:
this notation describes the running time of algorithms if the upper bound and lower bound is the same

θ(n^2): selection sort
θ (n log n): merge sort
