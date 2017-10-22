#include <bits/stdc++.h>

using namespace std;

char inp[1000005];

int main()
{
	int len, i;
	gets(inp);
	while (inp[0] != '.' || inp[1])
	{
		len = 1;
		for (i = 1; inp[i]; i++)
		{
			while (inp[i] != inp[i % len])
			{
				len++;
			}
		}
		if (i % len == 0)
		{
			printf("%d\n", i / len);
		}
		else
		{
			puts("1");
		}
		gets(inp);
	}
	return 0;
}
