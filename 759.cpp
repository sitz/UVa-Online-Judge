#include <bits/stdc++.h>

using namespace std;

char R[10000];
int main()
{
	int i, j, n;
	while (gets(R))
	{
		n = 0;
		for (i = j = 0; R[i] == 'M' && j < 3; i++)
		{
			n += 1000;
		}
		if (R[i] == 'C')
		{
			i++;
			if (R[i] == 'D')
			{
				n += 400, i++;
			}
			else if (R[i] == 'M')
			{
				n += 900, i++;
			}
			else
			{
				for (i--, j = 0; R[i] == 'C' && j < 3; i++, j++)
				{
					n += 100;
				}
			}
		}
		else if (R[i] == 'D')
		{
			n += 500;
			for (i++, j = 0; R[i] == 'C' && j < 3; i++, j++)
			{
				n += 100;
			}
		}
		if (R[i] == 'X')
		{
			i++;
			if (R[i] == 'L')
			{
				n += 40, i++;
			}
			else if (R[i] == 'C')
			{
				n += 90, i++;
			}
			else
			{
				for (i--, j = 0; R[i] == 'X' && j < 3; i++, j++)
				{
					n += 10;
				}
			}
		}
		else if (R[i] == 'L')
		{
			n += 50;
			for (i++, j = 0; R[i] == 'X' && j < 3; i++, j++)
			{
				n += 10;
			}
		}
		if (R[i] == 'I')
		{
			i++;
			if (R[i] == 'V')
			{
				n += 4, i++;
			}
			else if (R[i] == 'X')
			{
				n += 9, i++;
			}
			else
			{
				for (i--, j = 0; R[i] == 'I' && j < 3; i++, j++)
				{
					n += 1;
				}
			}
		}
		else if (R[i] == 'V')
		{
			n += 5;
			for (i++, j = 0; R[i] == 'I' && j < 3; i++, j++)
			{
				n += 1;
			}
		}
		if (R[i] != '\0' || n >= 4000)
		{
			printf("This is not a valid number\n");
		}
		else
		{
			printf("%d\n", n);
		}
	}
	return 0;
}
