#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16384 + 5;
const int INF = 0x3f3f3f3f;

struct node
{
	int score[3], id, ran;
	int sum()
	{
		return score[0] + score[1] + score[2];
	}
	bool operator<(const node &p) const
	{
		return ran < p.ran;
	}
};
node a[MAXN];

bool solve(int n, int val, bool ok)
{
	int num[10];
	vector<int> v[10];
	for (int i = 0; i < 8; ++i)
	{
		num[i] = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (i & (1 << j))
			{
				num[i] += a[n].score[j];
				v[i].push_back(j);
			}
		}
	}
	int m = INF, t = -1;
	for (int i = 0; i < 8; ++i)
	{
		if ((ok && num[i] >= val) || (num[i] > val))
		{
			if (num[i] < m)
			{
				m = num[i];
				t = i;
			}
		}
	}
	if (t == -1)
	{
		return false;
	}
	for (int i = 0; i < v[t].size(); ++i)
	{
		a[n].score[v[t][i]] = 0;
	}
	return true;
}

int main()
{

	int n, t = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				double x;
				scanf("%lf", &x);
				a[i].score[j] = (int)round(x * 100.0f);
			}
		}
		int x;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			a[x - 1].ran = i;
			a[x - 1].id = x;
		}
		sort(a, a + n);
		bool ok = true;
		for (int i = 1; i < n; ++i)
		{
			int s = a[i].sum(), t = a[i - 1].sum();
			if (s < t || (s == t && a[i].id > a[i - 1].id))
			{
				continue;
			}
			if (!solve(i, s - t, a[i].id > a[i - 1].id))
			{
				ok = false;
				break;
			}
		}
		printf("Case %d: ", ++t);
		ok ? printf("%.2lf\n", (double)a[n - 1].sum() / 100.0f) : printf("No solution\n");
	}
	return 0;
}
