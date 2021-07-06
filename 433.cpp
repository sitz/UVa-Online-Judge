#include <bits/stdc++.h>

using namespace std;

char *good_digit[10] =
		{
				" _ | ||_|",
				"     |  |",
				" _  _||_ ",
				" _  _| _|",
				"   |_|  |",
				" _ |_  _|",
				" _ |_ |_|",
				" _   |  |",
				" _ |_||_|",
				" _ |_| _|"};

char full_digit[] =
		" _ |_||_|";

int isOK(int c[9])
{
	int result = 0;
	for (int i = 0; i < 9; i++)
	{
		result += (9 - i) * c[i];
	}
	return (result % 11) == 0;
}

int scanDigit(char d[9][9], int c[9])
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 10; j++)
			if (memcmp(d[i], good_digit[j], 9) == 0)
			{
				break;
			}
		if (j == 10)
		{
			return -1;
		}
		c[i] = j;
	}
	return 0;
}

char digit[9][9];

int set_digit;
int ok_code[9];
int n_ok_code;

void PrintDigit(void)
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			putchar(digit[i][j]);
		}
		putchar('\n');
	}
}

void TestSeg(int n)
{
	//printf("(%d)\n",n);
	if (n == 9)
	{
		int test_code[9];
		if (scanDigit(digit, test_code) == 0 && isOK(test_code))
		{
			memcpy(ok_code, test_code, 9 * sizeof(int));
			n_ok_code++;
			/*
			        printf("==");
			        for (int k=0; k<9; k++)
			            printf("%d",ok_code[k]);
			        printf("\n");
			*/
		}
		return;
	}
	TestSeg(n + 1);
	if (digit[set_digit][n] != full_digit[n])
	{
		digit[set_digit][n] = full_digit[n];
		TestSeg(n + 1);
		digit[set_digit][n] = ' ';
	}
}

int main()
{
	char line[80];
	gets(line);
	int n_case = atoi(line);
	while (--n_case >= 0)
	{
		memset(digit, ' ', 9 * 9);
		int i, j;
		for (i = 0; i < 3; i++)
		{
			gets(line);
			int len = strlen(line);
			for (j = 0; j < len; j++)
			{
				if (line[j] == '_' || line[j] == '|')
				{
					digit[j / 3][i * 3 + j % 3] = line[j];
				}
				else if (line[j] != ' ')
					while (1)
						;// other char...
			}
		}
		//    PrintDigit();
		int code[9];
		if (scanDigit(digit, code) == 0 && isOK(code))
		{
			for (i = 0; i < 9; i++)
			{
				printf("%d", code[i]);
			}
			printf("\n");
			continue;
		}
		n_ok_code = 0;
		for (i = 0; i < 9 && n_ok_code < 2; i++)
		{
			set_digit = i;
			TestSeg(0);
		}
		if (n_ok_code == 0)
		{
			printf("failure\n");
		}
		else if (n_ok_code != 1)
		{
			printf("ambiguous\n");
		}
		else
		{
			for (i = 0; i < 9; i++)
			{
				printf("%d", ok_code[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
