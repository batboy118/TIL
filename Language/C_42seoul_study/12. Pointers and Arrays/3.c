#include <stdio.h>

#define N 100

int read_message(char a[], int n);
void print_message_reverse(char a[], int point);

int main(void)
{
	char message[N];
	int message_length = read_message(message, N);

	print_message_reverse(message, message_length - 1);

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

void print_message_reverse(char a[], int point)
{
	printf("Reversal is: ");
	while (point >= 0)
		printf("%c", *(a + point--));
	printf("\n");
}

