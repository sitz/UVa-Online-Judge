#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], l[maxn], r[maxn];
bool judge(int p, int n)
{
	int x = a[0], y = p - a[0], i;
	l[0] = x;
	r[0] = 0;
	for (i = 1; i < n; i++)
	{
		if (i % 2 == 0)//ç¬¬å¥æ°ä¸ªï¼å°½éåå³å
		{
			r[i] = min(a[i], y - r[i - 1]);
			l[i] = a[i] - r[i];
		}
		else//ç¬¬å¶æ°ä¸ªï¼å°½éåå·¦å
		{
			l[i] = min(a[i], x - l[i - 1]);
			r[i] = a[i] - l[i];
		}
	}
	return l[n - 1] == 0;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		int i, j, k, ans = -1;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (i != 0)
			{
				ans = max(ans, a[i] + a[i - 1]);
			}
		}
		ans = max(ans, a[0] + a[n - 1]);
		if (n % 2 == 0)
		{
			printf("%d\n", ans);
		}
		else if (n == 1)
		{
			printf("%d\n", a[0]);
		}
		else
		{
			int l = ans, r = ans * 3;
			while (l < r)
			{
				int mid = (l + r) / 2;
				if (judge(mid, n))
				{
					r = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			printf("%d\n", l);
		}
	}
	return 0;
}
