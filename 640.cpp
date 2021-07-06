#include <bits/stdc++.h>

using namespace std;

char x[1000001];

int main()
{
	memset(x, 0, sizeof(x));

	int j, tmp;
	for (int i = 1; i <= 999999; i++)
	{
		j = i, tmp = 0;
		while (j)
		{
			tmp += j % 10;
			j /= 10;
		}
		if (tmp + i <= 1000000)
		{
			x[tmp + i] = 1;
		}
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (!x[i])
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
