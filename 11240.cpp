#include <bits/stdc++.h>

using namespace std;

int main()
{
	int count, n, i, in, max, type, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &max);
		for (i = 1, ans = 1, type = 0; i < n; i++)
		{
			scanf("%d", &in);
			if (type && in > max)
			{
				type = 1 - type;
				ans++;
			}
			else if (!type && in < max)
			{
				type = 1 - type;
				ans++;
			}
			max = in;
		}
		printf("%d\n", ans);
	}
	return 0;
}
