#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		unsigned long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans *= 2;
			if (i % 3)
			{
				ans++;
			}
		}
		printf("%llu\n", ans);
	}
}
