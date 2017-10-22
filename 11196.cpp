#include <bits/stdc++.h>

using namespace std;

int n, m;
int S;
bool prune(int depth, int s, int hope, int r, int h)
{
	if (depth == n)
	{
		return false;
	}
	int nn = m - depth;
	int sum = (nn * (nn + 1)) / 2;
	int sum2 = sum * sum;
	int s1 = s + sum2;
	if (s1 > n)
	{
		return true;
	}
	int s2 = s + nn * r * r * h - r * (r + h + h) * sum + (r + r + h) * nn * (nn + 1) * (nn + nn + 1) / 6 - sum2;
	if (s2 < n)
	{
		return true;
	}
	int s3 = hope + 2 * nn * nn;
	if (s3 >= S)
	{
		return true;
	}
	return false;
}
void DFS(int depth, int strict, int hope, int prevh, int prevr)
{
	if (strict > n || hope > S)
	{
		return;
	}
	if (depth == m)
	{
		if (strict != n)
		{
			return;
		}
		if (hope < S)
		{
			S = hope;
		}
	}
	else
	{
		if (depth)
		{
			int P = (n - strict) * 2 / prevr;
			if (P >= S - hope)
			{
				return;
			}
		}
		int x = (int)sqrt((double)(n - strict));
		if (x > prevr - 1)
		{
			x = prevr - 1;
		}
		int bound = m - depth;
		for (int r = x; r >= bound; r--)
		{
			int r2 = r * r;
			int y = (n - strict) / r2;
			if (y > prevh - 1)
			{
				y = prevh - 1;
			}
			for (int h = y; h >= bound; h--)
			{
				int temp = 2 * r * h, r2h = r2 * h;
				if (depth == 0)
				{
					temp += r2;
				}
				if (prune(depth + 1, strict + r2h, hope, r, h))
				{
					continue;
				}
				int P = (n - strict - r2h) * 2 / r;
				if (P >= S - hope)
				{
					break;
				}
				DFS(depth + 1, strict + r2h, hope + temp, h, r);
			}
		}
	}
}
int main()
{
	int caseno = 1;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		scanf("%d", &m);
		S = 7000;
		DFS(0, 0, 0, 7000, 7000);
		if (S == 7000)
		{
			S = 0;
		}
		printf("Case %d: %d\n", caseno++, S);
	}
}
