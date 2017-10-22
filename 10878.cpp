#include <bits/stdc++.h>

using namespace std;

char str[20];

int main()
{
	gets(str);
	while (gets(str) && str[0] == '|')
	{
		int i, val = 0;
		for (i = 1; str[i] != '|'; i++)
		{
			if (str[i] == 'o')
			{
				val = val * 2 + 1;
			}
			if (str[i] == ' ')
			{
				val = val * 2;
			}
		}
		printf("%c", val);
	}
	return 0;
}
