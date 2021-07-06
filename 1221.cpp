#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

int s[505][505], pre[505], dis[255][255], human[255], alien[255], hp[255], ap[255], st = 0, ed;
bool stop;

void dfs(int v)
{
	for (int i = st; i <= ed && stop; i++)
		if (s[v][i] && pre[i] == -1)
		{
			pre[i] = v;
			if (i == ed)
			{
				stop = false;
			}
			else
			{
				dfs(i);
			}
		}
}

int flow()
{
	int i, j, k, ans = 0;
	while (1)
	{
		memset(pre, -1, sizeof(pre));
		stop = true;
		dfs(0);
		if (stop)
		{
			return ans;
		}
		ans += 1;
		for (i = ed; i != st; i = pre[i])
		{
			s[pre[i]][i] -= 1;
			s[i][pre[i]] += 1;
		}
	}
}

int main()
{
	int H, A, h, a, i, j;
	long long t1, t2, tmp;
	while (~scanf(" %d %d", &H, &A) && (H + A))
	{
		for (h = 0; h < H; h++)
		{
			scanf(" %d %d", &human[h], &hp[h]);
		}
		for (a = 0; a < A; a++)
		{
			scanf(" %d %d", &alien[a], &ap[a]);
		}
		for (h = 0; h < H; h++)
			for (a = 0; a < A; a++)
			{
				scanf(" %d", &dis[h][a]);
			}
		if (H < A)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		int low = 0, up = 10000000, mid, ans = -1;
		ed = H + A + 1;
		while (up > low + 1)
		{
			mid = (up + low) >> 1;
			memset(s, 0, sizeof(s));
			int can = 1;
			for (h = 0; h < H; h++)
			{
				s[st][h + 1] = 1;
				for (a = 0; a < A; a++)
				{
					s[H + a + 1][ed] = 1;
					tmp = (long long)alien[a];
					int gap = mid - dis[h][a];
					t1 = (long long)human[h] + (long long)gap * (long long)hp[h];
					t2 = tmp + (long long)mid * (long long)ap[a];
					if (t1 >= t2)
					{
						s[h + 1][H + a + 1] = 1;
					}
					else
					{
						can = 0;
					}
				}
			}
			int num = flow();
			if (num == A)
			{
				up = mid;
				ans = up;
			}
			else
			{
				low = mid;
			}
		}
		if (ans != -1)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
