#include <bits/stdc++.h>

using namespace std;

char dig[10000];

int main()
{
	int odd, even;
	while (gets(dig))
	{
		if (!strcmp(dig, "0"))
		{
			break;
		}
		odd = even = 0;
		for (int i = 0; dig[i]; i++)
		{
			if (i % 2)
			{
				odd += dig[i] - '0';
			}
			else
			{
				even += dig[i] - '0';
			}
		}
		if ((odd - even) % 11)
		{
			printf("%s is not a multiple of 11.\n", dig);
		}
		else
		{
			printf("%s is a multiple of 11.\n", dig);
		}
	}
	return 0;
}
