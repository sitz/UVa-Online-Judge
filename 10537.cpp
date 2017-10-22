#include <bits/stdc++.h>

using namespace std;

#define N 52

int target, from[52], map_[52][52], num[52], used[52];
long long inf, dis[52];

int comp(int p, int q)
{
	if (p < 26 && q >= 26)
	{
		return 1;
	}
	if (p >= 26 && q < 26)
	{
		return -1;
	}
	return p - q;
}

int letter(char ch)
{
	return (ch > 64 && ch < 91) || (ch > 96 && ch < 123);
}

int decode(int now)
{
	if (now < 26)
	{
		return now + 97;
	}
	return now + 39;
}

int trans(char ch)
{
	if (ch > 90)
	{
		return ch - 97;
	}
	return ch - 39;
}

void backtracking(int now)
{
	if (now == target)
	{
		printf("%c", decode(now));
	}
	else
	{
		printf("-%c", decode(now));
	}
	if (from[now] != -1)
	{
		backtracking(from[now]);
	}
}

int main()
{
	int cas, m, i, t, temp;
	long long min, j, p, q, c;
	char c1, c2;
	cas = 0;
	inf = (1ll << 62);
	while (scanf("%d", &m) == 1)
	{
		if (m == -1)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		while (m--)
		{
			for (; scanf("%c", &c1) == 1 && !letter(c1);)
				;
			for (; scanf("%c", &c2) == 1 && !letter(c2);)
				;
			c1 = trans(c1);
			c2 = trans(c2);
			map_[c1][num[c1]++] = c2;
			map_[c2][num[c2]++] = c1;
		}
		for (i = 0; i < N; i++)
		{
			dis[i] = inf;
			used[i] = 0;
		}
		scanf("%d", &temp);
		for (; scanf("%c", &c1) == 1 && !letter(c1);)
			;
		for (; scanf("%c", &c2) == 1 && !letter(c2);)
			;
		c1 = trans(c1);
		c2 = trans(c2);
		target = c1;
		dis[c2] = temp;
		used[c2] = 0;
		from[c2] = -1;
		for (;;)
		{
			for (i = 0, min = inf; i < N; i++)
			{
				if (!used[i] && dis[i] < min)
				{
					min = dis[i];
					temp = i;
				}
			}
			if (min == inf)
			{
				break;
			}
			used[temp] = 1;
			if (temp == target)
			{
				break;
			}
			for (i = 0; i < num[temp]; i++)
			{
				t = map_[temp][i];
				if (!used[t])
				{
					if (temp >= 26)
					{
						for (j = 20 * dis[temp] / 19; j - (j + 19) / 20 < dis[temp]; j++)
							;
					}
					else
					{
						j = dis[temp] + 1;
					}
					if (j < dis[t])
					{
						dis[t] = j;
						from[t] = temp;
					}
					else if (j == dis[t])
					{
						if (comp(from[t], temp) > 0)
						{
							from[t] = temp;
						}
					}
				}
			}
		}
		printf("Case %d:\n", ++cas);
		printf("%lld\n", dis[target]);
		backtracking(target);
		printf("\n");
	}
	return 0;
}
