#include <bits/stdc++.h>

using namespace std;

const int maxn = 200200;

struct Data
{
	int x, y;
	bool operator<(const Data &rhs) const
	{
		return (x > rhs.x) || (x == rhs.x && y < rhs.y);
	}
} F[maxn];

int n, P, ans;
char s1[maxn], s2[maxn];

int main()
{
	while (scanf("%d %d", &n, &P) != EOF && n + P > 0)
	{
		scanf("%s %s", s1 + 1, s2 + 1);
		int sum = 0;
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s1[i] != s2[i])
				sum++;
			F[i].x = 100 * sum - i * P;
			F[i].y = i;
		}
		F[0].x = F[0].y = 0;
		sort(F, F + n + 1);
		for (int i = 1, j = F[0].y; i <= n; i++)
			if (j < F[i].y)
				ans = max(ans, F[i].y - j);
			else
				j = F[i].y;
		if (ans > 0)
			printf("%d\n", ans);
		else
			printf("No solution.\n");
	}
	return 0;
}
