#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX_LEN = 12
};

int to_big_number(char *num)
{
	// reverse
	int len = strlen(num);
	for (int i = 0; i < len / 2; ++i)
	{
		swap(num[i], num[len - i - 1]);
	}
	// sub ascii
	for (int i = 0; i < len; ++i)
	{
		num[i] = num[i] - '0';
	}
	// fill zero
	for (int i = len; i < MAX_LEN; ++i)
	{
		num[i] = 0;
	}
}

int count_carry(char *a, char *b)
{
	to_big_number(a);
	to_big_number(b);
	int carry_counter = 0;
	for (int i = 0; i < MAX_LEN; ++i)
	{
		a[i] = a[i] + b[i];
		if (a[i] > 9)
		{
			a[i] = a[i] - 10;
			a[i + 1]++;
			carry_counter++;
		}
	}
	return carry_counter;
}

int main()
{
	char a[MAX_LEN], b[MAX_LEN];
	while (scanf("%s %s ", a, b) == 2)
	{
		if (a[0] == '0' && b[0] == '0')
		{
			break;
		}
		int result = count_carry(a, b);
		if (result == 0)
		{
			printf("No carry operation.\n");
		}
		else if (result == 1)
		{
			printf("1 carry operation.\n");
		}
		else
		{
			printf("%d carry operations.\n", result);
		}
	}
	return 0;
}
