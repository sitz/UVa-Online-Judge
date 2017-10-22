#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define INF 1000000

struct node
{
	LL st, end;
} seg[1000005];

LL Rp[100005], Gr[100005], Rv[100005], Gv[100005], pos[100005];
vector<int> res;

int main()
{
	bool f;
	int T, r, g, n, id;
	LL st, end, s1, s2, t1, t2, ans;

	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d%d", &r, &g, &n);
		res.clear();
		for (int i = 0; i < r; i++)
		{
			scanf("%lld", &Rp[i]);
		}
		for (int i = 0; i < r; i++)
		{
			scanf("%lld", &Rv[i]);
		}
		for (int i = 0; i < g; i++)
		{
			scanf("%lld", &Gr[i]);
		}
		for (int i = 0; i < g; i++)
		{
			scanf("%lld", &Gv[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &pos[i]);
		}
		sort(pos, pos + n);

		seg[0].st = 0;
		seg[0].end = pos[0];
		for (int i = 1; i < n; i++)
		{
			seg[i].st = seg[i - 1].end;
			seg[i].end = pos[i];
		}
		seg[n].st = seg[n - 1].end;
		seg[n].end = 1000000000LL;

		f = false;
		id = 0;
		ans = 10000000000LL;
		for (int i = 0; i <= n; i++)
		{
			st = 0;
			end = 1000000007LL;
			if (Rv[0] == 0)
			{
				if (Rp[0] >= seg[i].st && Rp[0] <= seg[i].end)
				{
					t1 = 0LL;
					t2 = 10000000000LL;
				}
				else
				{
					continue;
				}
			}
			else
			{
				s1 = seg[i].st - Rp[0];
				if (s1 <= 0)
				{
					t1 = 0;
				}
				else
				{
					t1 = s1 / Rv[0];
					if (s1 % Rv[0] != 0)
					{
						t1++;
					}
				}
				s2 = seg[i].end - Rp[i];
				if (s2 < 0)
				{
					continue;
				}
				t2 = s2 / Rv[0];
			}

			st = max(st, t1);
			end = min(end, t2);

			if (st > end)
			{
				continue;
			}

			if (Gv[0] == 0)
			{
				if (Gr[0] >= seg[i].st && Gr[0] <= seg[i].end)
				{
					t1 = 0LL;
					t2 = 10000000000LL;
				}
				else
				{
					continue;
				}
			}
			else
			{
				s1 = Gr[0] - seg[i].end;
				if (s1 <= 0)
				{
					t1 = 0LL;
				}
				else
				{
					t1 = s1 / Gv[0];
					if (s1 % Gv[0] != 0)
					{
						t1++;
					}
				}
				s2 = Gr[0] - seg[i].st;
				if (s2 < 0)
				{
					continue;
				}
				t2 = s2 / Gv[0];
			}

			st = max(st, t1);
			end = min(end, t2);

			if (end >= st)
			{
				id = i;
				res.push_back(i);
			}
		}

		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			id = res[j];
			f = true;
			st = 0LL;
			end = 1000000007LL;
			for (int i = 0; i < r; i++)
			{
				if (Rv[i] == 0)
				{
					if (Rp[i] >= seg[id].st && Rp[i] <= seg[id].end)
					{
						t1 = 0LL;
						t2 = 10000000000LL;
					}
					else
					{
						f = false;
						break;
					}
				}
				else
				{
					s1 = seg[id].st - Rp[i];
					t1 = s1 / Rv[i];
					if (s1 % Rv[i] != 0)
					{
						t1++;
					}
					if (s1 < 0)
					{
						t1 = 0;
					}
					s2 = seg[id].end - Rp[i];
					if (s2 < 0)
					{
						f = false;
						break;
					}
					t2 = s2 / Rv[i];
				}

				st = max(st, t1);
				end = min(end, t2);
			}

			if (f)
			{
				for (int i = 0; i < g; i++)
				{
					if (Gv[i] == 0)
					{
						if (Gr[i] >= seg[id].st && Gr[i] <= seg[id].end)
						{
							t1 = 0LL;
							t2 = 10000000000LL;
						}
						else
						{
							f = false;
							break;
						}
					}
					else
					{
						s1 = Gr[i] - seg[id].end;
						t1 = s1 / Gv[i];
						if (s1 % Gv[i] != 0)
						{
							t1++;
						}
						if (s1 < 0)
						{
							t1 = 0;
						}
						s2 = Gr[i] - seg[id].st;
						if (s2 < 0)
						{
							f = false;
							break;
						}
						t2 = s2 / Gv[i];
					}

					if (f)
					{
						st = max(st, t1);
						end = min(end, t2);
					}
				}

				if (f && st <= end)
				{
					ans = min(ans, st);
					break;
				}
				else
				{
					ans = 10000000000LL;
				}
			}
		}
		printf("Case %d: ", t);
		if (ans == 10000000000LL)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n", ans);
		}
	}

	return 0;
}
