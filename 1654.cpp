#include <bits/stdc++.h>

using namespace std;

int get_len(int x)
{
	static char buf[16];
	sprintf(buf, "%d", x);
	return (int)strlen(buf);
}

int main()
{
	int T, n, t10[10] = {1};
	for (int i = 1; i < 10; i++)
	{
		t10[i] = t10[i - 1] * 10;
	}
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		vector<pair<int, int> > ret;
		for (int i = 0; i < 10 && t10[i] <= n; i++)
		{
			int front = n / t10[i], back = n % t10[i];
			int u = front / 11;
			int p = front - u * 11;
			if (p < 10)
			{
				int x = u * 10 * t10[i] + p * t10[i] + back / 2;
				int y = u * t10[i] + back / 2;
				if (x + y == n && get_len(x) > get_len(y))
				{
					ret.push_back(make_pair(x, y));
				}
			}
			if (p > 0)
			{
				int x = u * 10 * t10[i] + (p - 1) * t10[i] + (back + t10[i]) / 2;
				int y = u * t10[i] + (back + t10[i]) / 2;
				if (x + y == n && get_len(x) > get_len(y))
				{
					ret.push_back(make_pair(x, y));
				}
			}
		}
		sort(ret.begin(), ret.end());
		ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
		printf("%d\n", (int)ret.size());
		for (int i = 0; i < ret.size(); i++)
		{
			int lx = get_len(ret[i].first);
			char format[] = "%d + %0?d = %d\n";
			format[7] = lx - 1 + '0';
			printf(format, ret[i].first, ret[i].second, n);
		}
		if (T)
		{
			printf("\n");
		}
	}
	return 0;
}
