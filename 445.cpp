#include <bits/stdc++.h>

using namespace std;

int main()
{
	char ch;
	int sum = 0;
	int i;
	while ((ch = getc(stdin)) != EOF)
	{
		if (isdigit(ch))
		{
			sum += ch - 48;
		}
		else
		{
			if (ch == '!')
			{
				printf("\n");
			}
			else if (ch == '\n')
			{
				printf("\n");
			}
			else if (ch == 'b')
				for (i = 0; i < sum; i++)
				{
					printf(" ");
				}
			else
				for (i = 0; i < sum; i++)
				{
					printf("%c", ch);
				}
			sum = 0;
		}
	}
	return 0;
}
