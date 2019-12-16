# Exercise 12.01
Suppose that the following declarations are in effect:

```c
int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a[1], *q = &a[5];
```

(a) What is the value of `*(p+3)`?  
(b) What is the value of `*(q-3)`?  
(c) What is the value of `q - p`?  
(d) Is the condition `p < q` true or false?  
(e) Is the condition `*p < *q` true or false?

### Solution

(a) `14`  
(b) `34`  
(c) `4`  
(d) `true`  
(e) `false`

# Exercise 12.02
Suppose that `high`, `low` and `middle` are all pointer variables of the same
type, and that `low` and `high` point to elements of an array. What is the following statement illegal, and how could it be fixed?

```c
middle = (low + high) / 2;
```

### Solution
Pointer 끼리 더하는 연산은 할 수 없다.

```c
middle = (high - low) / 2 + low;
```

# Exercise 12.03
What will be the contents of the `a` array after the following statements are
executed?

```c
#define N 10

int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *p = &a[0], *q = &a[N-1], temp;

while (p < q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
}
```

### Solution

10, 9, 8, 7, 6, 5, 4, 3, 2, 1


# Exercise 12.04

Rewrite the `make_empty`, `is_empty` and `is_full` functions of Section 10.2 to
use the pointer variable `top_ptr` instead of the integer variable `top`.

### Solution

```c
void make_empty(void) {
    top_ptr = &contents[0];
}

bool is_empty(void) {
    return top_ptr == &contents[0];
}

bool is_full(void) {
    return top_ptr = &contents[STACK_SIZE];
}
```

# Exercise 12.05

Suppose that `a` is a one-dimensional array and `p` is a pointer variable.
Assuming that the assignment `p = a` has just been performed, which of the
following expressions are illegal because of mismatched types? Of the remaining
expressions, which are true (have a nonzero value)?

(a) `p == a[0]`  
(b) `p == &a[0]`  
(c) `*p == a[0]`  
(d) `p[0] == a[0]`

### Solution

(a) is illegal. (b), (c) and (d) all return true values.

# Exercise 12.06

Rewrite the following function to use pointer arithmetic instead of array
subscripting. (In other words, elimate the variable `i` and all uses of the `[]`
operator.) Make as few changes as possible.

```c
int sum_array(const int a[], int n)
{
    int i, sum;

    sum = 0;
    for (i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
```

### Solution

```c
int sum_array(const int a[], int n) {

    int *p, sum;

    sum = 0;
    for (p = &a[0]; p < &a[n]; p++) { /* variations like (p=a; p<a+n; p++) */
                                      /* are also possible.                */
        sum += *p;
    }
    returm sum;
}

```

# Exercise 12.07

Write the following function:

```c
bool search(const int a[], int n, int key);
```

`a` is an array to be searched, `n` is the number of elements in the array, and
`key` is the search key. `search` should return `true` if `key` matches some
element of `a`, and `false` if it doesn't. Use pointer arithmetic -- not
subscripting -- to visit array elements.

### Solution

```c
bool search(const int a[], int n, int key) {

    int *p;

    for (p = a; p < a + n; p++) {
        if (*p == key)
            return true;
    }
    return false;
}
```
# Exercise 12.08

Rewrite the following function to use pointer arithmetic instead of array
subscripting. (In other words, eliminate the variable `i` and all uses of the
`[]` operator.) Make as few changes as possible.

```c
void store_zeros(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        a[i] = 0;
}
```

### Solution

```c
void store_zeros(int a[], int n) {

    int *p;

    for (p = a; p < a + n; p++)
        *p = 0;
}
```
# Exercise 12.09

Write the following function:

```c
double inner_product(const double *a, const double *b, int n);
```

`a` and `b` both point to arrays of length `n`. The function should return
`a[0] * b[0] + a[1] * b[1] +` ... `+ a[n-1] * b[n-1]`. Use pointer arithmetic --
not subscripting -- to visit array elements.

### Solution

```c
double inner_product(const double *a, const double *b, int n) {

    double sum;
    int i = 0

    while (i++ < n)
        sum += *a++ * *b++;
}
```
# Exercise 12.10

Modify the `find_middle` function of Section 11.5 so that it uses pointer
arithmetic to calculate the return value.

### Solution

```c
int *find_middle(int a[], int n) {

    return a + n / 2;
}
```
# Exercise 12.11

Modify the `find_largest` function so that it uses pointer arithmetic -- not
subscripting -- to visit array elements.

### Solution

```c
int find_largest(int a[], int n) {

    int *p = a;
    int largest = *p++;

    while (p++ < a + n) {
        if (*p > largest) {
            largest = *p;
        }
    }
    return largest;
}
```
# Exercise 12.12

Write the following function:

```c
void find_two_largest(const int *a, int n, int *largest, int *second_largest);
```

`a` points to an array of length `n`. The function searches the array for its
largest and second-largest elements, storing them in the variables pointed to by
`largest` and `second_largest`, respectively. Use pointer arithmetic -- not
subscripting -- to visit array elements.

### Solution

```c
void find_two_largest(const int *a, int n, int *largest, int *second_largest) {

    int *p = a;
    *largest = *second_largest = *a;
    
    while (p++ < a + n) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest)
            *second_largest = *p;
    }
}
```
# Exercise 12.13

Section 8.2 had a program fragment in which two nested `for` loops initialized
the array `ident` for use as an identity matrix. Rewrite this code, using a
single pointer to step through the array one element at a time. *Hint*: Since we
won't be using `row` and `col` index variables, it won't be easy to tell where
to store 1. Instead, we ca use the fact that the first element of the
array should be 1, the next `N` elements should be 0, the next element should be
1 and so forth. Use a variable to kep track of how many consecutive 0s have been
stored; when the count reaches `N`, it's time to store 1.

### Solution

```c
void init_ident(double ident[n][n], int n) {

    double *p = ident;
    int zeros = n;

    while (p++ < ident + n * n) {
        if (zeros = n) {
            *p = 1;
            zeros = 0;
        } else {
            *p = 0;
            zeros++;
        }
    }
}
```
# Exercise 12.14

Assume that the following array contains a week's worth of hourly temperature
readings, with each row containing the readings for one day:

```c
int temperatures[7][24];
```

Write a statement that uses the `search` function (see Exercise 7) to search the
entire `temperatures` array for the value 32.

### Solution

```c
bool has32 = search(temperatures, 7 * 24, 32);
```
# Exercise 12.15

Write a loop that prints all temperature readings stored in row `i` of the
`temperatures` array (see Exercise 14). Use a pointer to visit each element of
the row.

### Solution

```c
int *p = temperatures[i];
while (p < temperatures[i + 1])
    printf("%d ", *p++);
```
# Exercise 12.16

Write a loop that prints the highest temperature in the `temperatures` array
(see Exercise 14) for each day of the week. The loop body should call the
`find_largest` function, passing it one row of the array at a time.

### Solution

```c
int i;
for (i = 0; i < 7; i++)
    printf("Day %d: %d\n", i + 1, find_largest(temperatures[i], 24));
```
# Exercise 12.17

Rewrite the following function to use pointer arithmetic instead of array
subscripting. (In other words, eliminate the variables `i` and `j` and all uses
of the `[]` operator.) Use a single loop instead of nested loops.

```c
int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < LEN; j++)
            sum += a[i][j];
    return sum;
}
```

### Solution

```c
int sum_two_dimensional_array(const int a[][LEN], int n) {

    int *p = *a, sum = 0;

    while (p < *a + n * LEN)
        sum += *p++;
    return sum;
}
```

# Exercise 12.18

Write the `evaluate_position` function described in Exercise 13 of Chapter 9.
Use pointer arithmetic -- not subscripting -- to visit array elements. Use a
single loop instead of nested loops.

### Solution

```c
int evaluate_position(char board[8][8]) {

    char *p;
    int white = 0, black = 0;

    for (p = board; p < board + 64; p++) {

        switch(*p) {
            case 'Q':
                white += 9;
                break;
            case 'q':
                black += 9;
                break;
            case 'R':
                white += 5;
                break;
            case 'r':
                black += 5;
                break;
            case 'B':
                white += 3;
                break;
            case 'b':
                black += 3;
                break;
            case 'N':
                white += 3;
                break;
            case 'n':
                black += 3;
                break;
            case 'P':
                white++;
                break;
            case 'p':
                black++;
                break;
            default:
                break;
        }
    }
    return white - black;
}
```


