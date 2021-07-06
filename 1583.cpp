#include <bits/stdc++.h>

using namespace std;

int proc(int n)
{
	int sum = n;
	while (n != 0)
	{
		sum = sum + (n % 10);
		n = n / 10;
	}
	return sum;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		bool flag = 0;
		int s, n;
		scanf("%d", &n);
		if (n > 100)
		{
			for (int i = n - 100; i < n; i++)
			{
				if (proc(i) == n)
				{
					flag = true;
					s = i;
					break;
				}
			}
		}
		else
		{
			for (int i = n / 2; i < n; i++)
			{
				if (proc(i) == n)
				{
					flag = true;
					s = i;
					break;
				}
			}
		}
		printf("%d\n", flag ? s : 0);
	}
	return 0;
}
