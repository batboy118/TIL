#include <stdio.h>

#define N 100

int read_message(char a[], int n);
void print_message_reverse(char a[], char *a_last);

int main(void)
{
	char message[N];
	int message_length = read_message(message, N);

	print_message_reverse(message, &message[message_length - 1]);

	return 0;
}

int read_message(char a[], int n)
{
	char ch;
	int i;

	printf("Enter a message: ");
	for (i = 0; i<50 && (ch = getchar()) != EOF && ch != '\n'; i++)
		a[i] = ch;
	return i;
}

void print_message_reverse(char a[], char *a_last)
{
	char *p = a_last;

	printf("Reversal is: ");
	while (p >= a)
		printf("%c", *p--);
	printf("\n");
}

