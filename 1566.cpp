#include <bits/stdc++.h>

using namespace std;

int t, n;

bool solve()
{
	scanf("%d", &n);
	int x, sum = 0, flag = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x > 1)
		{
			flag = 0;
		}
		sum ^= x;
	}
	if (flag)
	{
		return n % 2 == 0;
	}
	else
	{
		return sum != 0;
	}
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		if (solve())
		{
			printf("John\n");
		}
		else
		{
			printf("Brother\n");
		}
	}
	return 0;
}
