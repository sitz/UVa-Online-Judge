#include <bits/stdc++.h>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define INF 0x3f3f3f3f
const int N = 5005;
int t, n, k, i, start[N];

bool check(int s, int e)
{
	return e - s <= k;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int ans = 0;
		scanf("%d%d", &n, &k);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &start[i]);
		}
		sort(start, start + n);
		i = 0;
		while (i < n)
		{
			int sum = 1;
			while (i < n - 1 && ((sum == 1 && check(start[i], start[i + 1])) ||
													 (check(start[i], start[i + 1]) && check(start[i - 1], start[i + 1]))))
			{
				sum++, i++;
			}
			if (!check(start[i], start[i + 1]) || i == n - 1)
			{
				i++;
			}
			ans = max(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}
