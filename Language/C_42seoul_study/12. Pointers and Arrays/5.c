#include <stdio.h>

#define MAX 100

int main(void) {
    char c, *p, *q, term, words[MAX] = {0, };

    printf("Enter a sentence: ");

    for (p = words; (c = getchar()) != '\n' && p < words + MAX; p++) {
        if (c == '.' || c == '!' || c == '?') {
            term = c;
            break;
        }
        *p = c;
    }

    printf("Reversal of sentence: ");
    while (p >= words) {
        while (*--p != ' ' && p != words)
            ;
        q = p == words ? words : p + 1;
        while (*q != ' ' && *q != '\0')
            putchar(*q++);
        if (p >= words)
            putchar(' ');
    }

    printf("\b%c\n", term);
    return 0;
}