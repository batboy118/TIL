# Exercise 12.01

(a) `14`  
(b) `34`  
(c) `4`  
(d) `true`  
(e) `false`

# Exercise 12.02

Pointer끼리 더하는 연산은 할 수 없다.

```c
middle = (high - low) / 2 + low;
```

# Exercise 12.03

10, 9, 8, 7, 6, 5, 4, 3, 2, 1


# Exercise 12.04

```c
void make_empty(void) {
    top_ptr = contents;
}

bool is_empty(void) {
    return top_ptr == contents;
}

bool is_full(void) {
    return top_ptr == &contents[STACK_SIZE];
}
```

# Exercise 12.05

(a) `p == a[0]`  : 0

(b) `p == &a[0]`  : 1

(c) `*p == a[0]`  : 1

(d) `p[0] == a[0]` : 1



# Exercise 12.06

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

=>

```c
int sum_array(const int a[], int n) {

    int *p;
    int sum;

    sum = 0;
    for (p = &a[0]; p < &a[n]; p++) { 
        sum += *p;
    }
    returm sum;
}

```

# Exercise 12.07

```c
bool search(const int a[], int n, int key) {
    int *p;
    bool ok;

    ok = false;
    for (p = a; p < a + n; p++) {
        if (*p == key)
        {
            ok = true;
            break;
        }
    }
    return ok;
}
```
# Exercise 12.08

```c
void store_zeros(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        a[i] = 0;
}
```
=>

```c
void store_zeros(int a[], int n) {

    int *p;

    for (p = a; p < a + n; p++)
        *p = 0;
}
```
# Exercise 12.09

```c
double inner_product(const double *a, const double *b, int n) {

    double total;
    int i = 0

    while (i++ < n)
    {
        total += (*a) * (*b);
        a++; 
        b++;
    }
    return total;
}
```
# Exercise 12.10

```c
int *find_middle(int a[], int n) {

    return a + (n / 2);
}
```
# Exercise 12.11

```c
int find_largest(int a[], int n) {

    int *p;
    int Largest; 

    p = a;
    Largest = *p++;
    while (p < a + n) {
        if (*p > Largest) {
            Largest = *p;
        }
        p++;
    }
    return Largest;
}
```
# Exercise 12.12

```c
void find_two_largest(const int *a, int n, int *largest, int *second_largest) {

    int *p = a;
    *largest = *second_largest = *a;
    
    while (++p < a + n) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } 
        else if (*p > *second_largest)
            *second_largest = *p;
    }
}
```
# Exercise 12.13
```c
void init_ident(double ident[][n], int n) {

    double *p = ident[];
    int z;
    
    z = n;
    while (p++ < ident[] + n * n) {
        if (z == n) {
            *p = 1;
            z = 0;
        } 
        else {
            *p = 0;
            z++;
        }
    }
}
```
# Exercise 12.14

```c
bool has32 = search(temperatures, 7 * 24, 32);
```
# Exercise 12.15

```c
int *p = temperatures[i];

while (p < temperatures[i] + 1)
    printf("%d ", *p++);
```
# Exercise 12.16
```c
int i;
for (i = 0; i < 7; i++)
    printf("%d: %d\n", i + 1, find_largest(temperatures[i], 24));
```
# Exercise 12.17
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

    int *p = a, sum = 0;

    while (p < *a + n * LEN)
        sum += *p++;
    return sum;
}
```

# Exercise 12.18
```c
int evaluate_position(char board[][8]) {

    char *p;
    int white, black;
    
    white= 0, black = 0;
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


