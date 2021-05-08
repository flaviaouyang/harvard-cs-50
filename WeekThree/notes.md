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

-------------------------------------------
# Recursion
- the ability for a function to call itself


## Question 1: Write a recursive function that given an input n sums all nonnegative integers up to n?

### 5 steps:
1. what is the simplest possible output?
    - Base case
    - when n is 0, sum is 0
2. try with more examples and visualize
    - when n is 1, sum is 1
    - when n is 2, sum is 1 plus 2
    - when n is 3, sum is 1+2+3
    ...
3. Relate hard cases to simpler cases
    - if given sum(3), how to solve sum(4)
4. Generalize the patter
    - let n be k, sum(k) = sum(k-1) + k

```python
def sum(n):
    if n == 0:
        return 0;
    else:
        return n + sum(n-1)
```

- Recursive leap of faith: assume simpler cases work out

## Question 2: Write a recursive function that takes input n and m and outputs the number of unique paths from the top left corner to the bottom right corner of a n*m grid? Note you can only move down or right 1 unit at a time.

1. base case: grid_path(1, 1) -> 1 path
    - grid_path(n, 1) -> 1 path
2. more examples
3. relation: the number of path of 3 * 3 is the sum of 2 * 3 and 3 * 2
4. Gneralization: to find grid_path(n, m) find the sum of grid_path(n,m-1) and grid_path(n-1,m)

```python
def grid_paths(n, m):
    if n == 1 or m == 1:
        return 1
    else:
        return grid_paths(n, m - 1) + grid_paths(n - 1, m)
```

## Question 3: Write a recursive function that counts the number of ways you can partition n objects using parts up to m (assuming m >= 0)

1. base case: n and m both are 0 -> 1 partition
    - (0, 1) -> 1
    - (n, m) if n = 0 -> 1 (base case one)
    - (n, m) if m = 0 -> 0 (base case two)
2. write out examples
...

```python
def count_partition(n, m):
    if n == 0:
        return 1
    elif m == 0:
        return 0
    else:
        return count_partition(n-m,m) + count_partition(n,m-1)
```
