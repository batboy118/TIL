# Exercise 13.01

(a) `printf("%c", '\n');`  
(b) `printf("%c", "\n");`  
(c) `printf("%s", '\n');`  
(d) `printf("%s", "\n");`  
(e) `printf('\n');`  
(f) `printf("\n");`  
(g) `putchar('\n');`  
(h) `putchar("\n");`  
(i) `puts('\n');`  
(j) `puts("\n");`  
(k) `puts("");`

(a) OK

(b) 타입이 맞지 않음 : `%c` : char  , "\n" : string 

(c) 타입이 맞지 않음 : `%s` : string  , '\n' : char  
(e) will not work as `printf` expects a `string`.  
(h) will not work as `putchar` expects a `char`.  
(i) will not work as `puts` expects a `string`.  
(j) will write two newline characters.  

# Exercise 13.02

Suppose that `p` has been declared as follows:

```c
char *p = "abc";
```

Which of the followin function calls are legal? Show the output produced by each
legal call, and explain why the others are illegal.

(a) `putchar(p);`  
(b) `putchar(*p);` 
(c) `puts(p);`  
(d) `puts(*p);`

(a) Illegal: `putchar` expects a `char`, receives a pointer to `char`.  
(b) `a`  
(c) `abc\n`  
(d) Illegal: `puts` expects a `char *` and receives a `char`.

# Exercise 13.03

Suppose that we call `scanf` as follows:

```c
scanf("%d%s%d", %i, s, &j);
```

If the user enters `12abc34 56def78`, what will be the values of `i`, `s` and
`j` after the call? (Assume that `i` and `j` are `int` variables and `s` is an
array of characters.)

### Solution

`i`: `12`  
`s`: `abc34`  
`j`: `56`

# Exercise 13.04

Modify the `read_line` function in each of the following ways:

(a) Have it skip whitespace before beginning to store input characters.  
(b) Have it stop reading at the first whitespace character. *Hint*: To determine
whether or not a character is whitespace, call the `isspace` function.  
(c) Have it stop reading at the first newline character, then store the newline
character in the string.  
(d) Have it leave behind characters that it doesn't have room to store.

### Solution

```c
int read_line(char str[], int n) {
    int ch, i = 0;

    while (isspace(getchar()))                                /* (a) */
        ; 
    while (i < n && (ch = getchar()) != '\n' && !isspace(ch)) /* (b) & (d) */
        str[i++] = ch;
    if (ch == '\n' && i < n - 1)                              /* (c) */
        str[i++] = '\n';
    str[i] = '\0';
    return i;
}
```

# Exercise 13.05

(a) Write a function named `capitalize` that capitalizes all letters in its
argument. The argument will be a null-terminated string containing arbitrary
characters, not just letters. Use arry subscripting to access the characters in
the string. *Hint*: Use the `toupper` function to convert each character to
upper case.

(b) Rewrite the `capitalize` function, this time using pointer arithmetic to
access the characters in the string.

### Solution

#### (a)

```c
void capitalize(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i]))
            toupper(str[i]);
        i++;
    }
}
```

#### (b)

```c
void capitalize(char *str) {
    char *c = str;
    while (c != '\0') {
        if (isalpha(c))
            toupper(c);
        c++;
    }
}
```

# Exercise 13.06

Write a function named `censor` that modifies a string by replacing every
occurrence of `foo` by `xxx`. For example, the string `"food fool"` would become
`"xxxd xxxl"`. Make the function as short as possible without sacrificing
clarity.

### Solution

```c
void censor(char *str) {
    char *c = str;
    while (c+2 != '\0') {
        if (*c == 'f' && *(c+1) == 'o' && *(c+2) == 'o')
            *c = *(c+1) = *(c+2) = 'x';
        c++;
    }
}
```

# Exercise 13.07

Suppose that `str` is an array of characters. Which one of the following
statements is not equivalent to the other three?

(a) `*str = 0;`  
(b) `str[0] = '\0';`  
(c) `strcpy(str, "");`  
(d) `strcat(str, "");`

### Solution

(d) is not equivalent to the other three options, as `strcat` appends the null
character to the end of `str`, while the other three insert the value at the
first character of `str`.

# Exercise 13.08

What will be the value of the string `str` after the following statements have
been executed?

```c
strcpy(str, "tire-bouchon");
strcpy(&str[4], "d-or-wi");
strcat(str, "red?");
```

### Solution

`"tired-or-wired?\0"`

# Exercise 13.09

What will be the value of the string `s1` after the following statements have
been executed?

```c
strcpy(s1, "computer");
strcpy(s2, "science");
if (strcmp(s1, s2) < 0)
    strcat(s1, s2);
else
    strcat(s2, s1);
s1[strlen(s1)-6] = '\0';
```

### Solution

`"computers\0"`

# Exercise 13.10

The following function supposedly creates an identical copy of a string. What's
wrong with the function?

```c
char *duplicate(const char *p)
{
    char *q;

    strcpy(q, p);
    return q;
}
```

### Solution

The string `q` points to will not be accessible outside the scope of the
function.

# Exercise 13.11

The Q&A section at the end of this chapter shows how the `strcmp` function might
be written using array subscripting. Modify the function to use pointer
arithmetic instead.

### Solution

```c
int strcmp(char *s, char *t)
{
    while (*s == *t) {
        if (s[i] == '\0')
            return 0;
        s++; t++;
    }
    return *s - *t;
}
```

# Exercise 13.12

Write the following function:

```c
void get_extension(const char *file_name, char *extension);
```

`file_name` points to a string containing a file name. The function should store
the extension on the file name in the string pointed to by `extension`. For
example, if the file name is `"memo.txt"`, the function will store `"txt"` in
the string pointed to by `extension`. If the file name doesn't have an
extension, the function should store an empty string (a single null character)
in the string pointed to by `extension`. Keep the function as simple as possible
by having it use the `strlen` and `strcpy` functions.

### Solution

```c
void get_extension(const char *file_name, char *extension) {

    while (*file_name) {
        if (*file_name++ == '.') {
            strcpy(extension, file_name);
            return;
        }
    }
    strcpy(extension, "");
}
```

NB: Some problems would arise by using this function: for instance, a filename
with the value `"memo.txt.html"` would incorrectly copy `"txt.html"` to
`extension`.

# Exercise 13.13

Write the following function:

```c
void build_index_url(const char *domain, char *index_url);
```

`domain` points to a string containing an Internet domain, such as
`"knking.com"`. The function should add `"http://www."` to the beginning of this
string and `"/index.html"` to the end of the string, storing the result in the
string pointed to by `index_url`. (In this example, the result will be
`"http://www.knking.com/index.html"`.) You may assume that `index_url` points to
a variable that is long enough to hold the resulting string. Keep the function
as simple as possible by having it use the `strcat` and `strcpy` functions.

### Solution

```c
void build_index_url(const char *domain, char *index_url) {

    strcpy(index_url, "http:////www.");
    strcat(strcat(index_url, domain), "//index.html");
}
```

# Exercise 13.14

What does the following program print?

```c
#include <stdio.h>

int main(void)
{
    char s[] = "Hsjodi", *p;

    for (p = s; *p; p++)
        --*p;
    puts(s);
    return 0;
}
```

### Solution

`Grinch`, followed by a newline.

# Exercise 13.15

Let `f` be the following function:

```c
int f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}
```

(a) What is the value of `f("abcd", "babc")`?  
(b) What is the value of `f("abcd", "bcd")`?  
(c) In general, what value does `f` return when passed two strings `s` and `t`?

### Solution

#### (a)

`f("abcd", "babc")` returns `0`.

#### (b)

`f("abcd", "bcd")` returns `1`.

#### (c)

`f` returns the first character in `s` which has a matching character in `t`.

# Exercise 13.16

Use the techniques of Section 13.6 to condense the `count_spaces` function of
Section 13.4. In particular, replace the `for` statement by a `while` loop.

### Solution

```c
int count_spaces(const char *s)
{
    int count = 0;

    while (*s++)
        if (*s == ' ')
            count++;
    return count;
}
```

# Exercise 13.17

Write the following function:

```c
bool test_extension(const char *file_name, const char *extension);
```

`file_name` points to a string containing a file name. The function should
return `true` if the file's extension matches the string pointed to by
`extension`, ignoring the case of letters. For example, the call
`test_extension("memo.txt", "TXT")` would return `true`. Incorporate the "search
for the end of a string" idiom into your function. *Hint*: Use the `toupper`
function to convert characters to upper-case before comparing them.

### Solution

```c
bool test_extension(const char *file_name, const char *extension) {

    while (*file_name++ != '.')
        ;
    while (*file_name && *extension)
        if (toupper(*file_name++) != toupper(*extension++))
            return false;
    return true;
}
```

# Exercise 13.18

Write the following function:

```c
void remove_filename(char *url);
```

`url` points to a string containing a URL (Uniform Resource Locator) that ends
with a file name (such as `"http://www.knking.com/index.html"`). The function
should modify the string by removing the file name and the preceding slash. (In
this example, the result will be `"http://www.knking.com"`.) Incorporate the
"search for the end of a string" idiom into your function. *Hint*: Have the
function replace the last slash in the string by a null character.

### Solution

```c
void remove_filename(char *url) {

    char *p = url;
    while (*url) {
        if (*url == '/')
            p = url;
        url++;
    }
    *p = '\0';
}
```