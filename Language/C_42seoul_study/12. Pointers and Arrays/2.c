#include <stdio.h>

#define N 100

int read_message(char a[], int n);
void print_palindrome(char a[], int a_size);

int main(void)
{
	char message[N];
	int message_length = read_message(message, N);

	print_palindrome(message, message_length);

	return 0;
}

int read_message(char a[], int n)
{
	char ch;
	int i;
	int gap;

	gap = 'a' - 'A';
	printf("Enter a message: ");
	for (i = 0; i < 50 && (ch = getchar()) != EOF && ch != '\n'; i++)
	{
		if (ch >= 'a' && ch <= 'z') {
			a[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			a[i] = ch + gap;
		}
	}
	return i;
}

void print_palindrome(char a[], int a_size)
{
	char *p = a + a_size - 1;
	char *s = a;
	int i = 0;
	
	while (i < a_size / 2)
	{
		if (*p-- != *s++)
		{
			printf("Not a palindrome");
			return;
		}
		i++;
	}
	printf("Palindrome");
}

