#include <bits/stdc++.h>

using namespace std;

struct point {int x, y;};
point land_lst[110], queue_[110];

const int mod = 100007;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool vis[11][11];
char api[13][13][10], ld[77][100];
int n, r, c, pos[2][222], value[13][13], cnt[222], vv, st[222], lst[44], qt[222], ans[44], at[2][222], mat[13][13], cnt_lst, ep[222], num[mod];
long long hash_[mod][107], big_mod = (long long)100000009 * (long long)100000009, ex[111];

bool judge(int x, int y, int state)
{
	int i, j, s, p, q, vv, temp1, temp2, temp;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			vis[i][j] = false;
		}
	queue_[0].x = x;
	queue_[0].y = y;
	temp = 1;
	vis[x][y] = true;
	temp1 = 0;
	temp2 = 0;
	while (temp1 <= temp2)
	{
		for (i = temp1; i <= temp2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				x = queue_[i].x + dx[j];
				y = queue_[i].y + dy[j];
				if (x >= 0 && x < r && y >= 0 && y < c && !vis[x][y])
				{

					vv = mat[x][y];
					if (api[x][y][0] != '#' && !(vv > 0 && api[x][y][0] >= '0' && api[x][y][0] <= '9' && state & (1 << vv)))
					{
						queue_[temp].x = x;
						queue_[temp++].y = y;
						if (api[x][y][0] == '=')
						{
							return true;
						}
						vis[x][y] = true;
					}
				}
			}
		}
		temp1 = temp2 + 1;
		temp2 = temp - 1;
	}
	return false;
}
void bfs(point can_lst[], int &cnt_can, int id)
{
	int i, j, s, p, q, x, y, temp1, temp2, temp;
	temp = 0;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
		{
			vis[i][j] = false;
		}
	for (i = 0; i < cnt_lst; i++)
	{
		queue_[temp++] = land_lst[i];
		vis[land_lst[i].x][land_lst[i].y] = true;
	}
	temp1 = 0;
	temp2 = temp - 1;
	while (temp1 <= temp2)
	{
		for (i = temp1; i <= temp2; i++)
		{
			for (j = 0; j < 4; j++)
			{
				x = queue_[i].x + dx[j];
				y = queue_[i].y + dy[j];
				if (x >= 0 && x < r && y >= 0 && y < c && !vis[x][y])
				{
					if (api[x][y][0] != '#' && !(api[x][y][0] >= '0' && api[x][y][0] <= '9' && mat[x][y]))
					{

						queue_[temp].x = x;
						queue_[temp++].y = y;
						vis[x][y] = true;
						if (api[x][y][0] >= '0' && api[x][y][0] <= '9' && mat[x][y] == 0)
						{
							can_lst[cnt_can++] = queue_[temp - 1];
						}
					}
				}
			}
		}
		temp1 = temp2 + 1;
		temp2 = temp - 1;
	}


}
bool dfs(int id, int state, long long hs)
{
	int la, id_r, id_c, i, j, s, p, q, vv, nst, x, y, temp;
	long long nhs;
	bool res;
	if (id >= 2 * n)
	{
		return true;
	}



	vv = lst[id];
	cnt[vv] ^= 1;
	if (cnt[vv] == 0)
	{
		id_r = at[0][vv];
		id_c = at[1][vv];


		at[0][vv] = at[1][vv] = -1;
		temp = mat[id_r][id_c];
		while (temp == 0)
		{
			puts("orz");
		}
		mat[id_r][id_c] = 0;
		nhs = hs - ex[value[id_r][id_c]];
		nhs = (nhs % big_mod + big_mod) % big_mod;
		res = dfs(id + 1, state ^ (1 << vv), nhs);
		cnt[vv] ^= 1;
		mat[id_r][id_c] = temp;
		at[0][vv] = id_r;
		at[1][vv] = id_c;
		return res;
	}
	point can_lst[101];
	int cnt_can = 0;
	bfs(can_lst, cnt_can, id);




	int ct = 0;
	for (i = id; i < 2 * n; i++)
	{
		if (ld[i][0] == '+')
		{
			ct++;
		}
		else
		{
			break;
		}
	}
	nst = (state & st[vv]);


	int lst[22], cl = 0;
	for (i = 1; i <= n; i++)
	{
		if (nst & (1 << i))
		{
			lst[cl++] = i;
		}
	}
	lst[cl++] = vv;
	for (i = 0; i < cnt_can && ct <= cnt_can; i++)
	{




		x = can_lst[i].x;
		y = can_lst[i].y;


		while (mat[x][y] != 0)
		{
			puts("orz");
		}
		mat[x][y] = vv;
		at[0][vv] = x;
		at[1][vv] = y;
		nhs = hs + ex[value[x][y]];
		nhs %= big_mod;
		ans[vv] = value[x][y];
		int jj;
		for (jj = 0; jj < cl; jj++)
		{
			j = lst[jj];






			if (!judge(at[0][j], at[1][j], (state | (1 << vv)) & ep[j]))
			{
				break;
			}

		}
		if (jj >= cl && dfs(id + 1, state | (1 << vv), nhs))
		{
			return true;
		}
		mat[x][y] = 0;
		at[0][vv] = at[1][vv] = -1;


	}
	cnt[vv] ^= 1;
	return false;
}
int main()
{
	int i, j, s, p, q, vv, tst = 0, ax;
	while (scanf("%d", &n) && n)
	{
		scanf("%d%d", &r, &c);
		tst++;
		memset(pos, -1, sizeof(pos));
		cnt_lst = 0;
		ax = 0;
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
			{
				scanf("%s", api[i][j]);
				if (api[i][j][0] >= '0' && api[i][j][0] <= '9')
				{
					value[i][j] = 10 * (api[i][j][0] - '0') + api[i][j][1] - '0';
					pos[0][value[i][j]] = i;
					pos[1][value[i][j]] = j;
					ax = max(ax, value[i][j]);
				}
				if (api[i][j][0] == '=')
				{
					land_lst[cnt_lst].x = i;
					land_lst[cnt_lst++].y = j;
				}
			}
		ex[0] = 1;
		for (i = 1; i <= ax + 1; i++)
		{
			ex[i] = (ex[i - 1] << 1) % big_mod;
		}

		for (i = 0; i < 2 * n; i++)
		{
			scanf("%s", ld[i]);
		}
		memset(st, 0, sizeof(st));
		memset(ep, 0, sizeof(ep));
		for (i = 0; i < 2 * n; i++)
		{
			vv = 0;
			int len = strlen(ld[i]);
			while (len >= 10 || len <= 1)
			{
				puts("orz");
			}
			for (j = 1; j < len; j++)
			{
				vv = 10 * vv + ld[i][j] - '0';
			}
			lst[i] = vv;
			while (vv <= 0 || vv > n)
			{
				puts("orz");
			}

			if (ld[i][0] == '-')
			{
				memset(cnt, 0, sizeof(cnt));
				for (j = 0; j <= i; j++)
				{
					cnt[lst[j]] ^= 1;
				}
				for (j = 1; j <= n; j++)
				{
					if (cnt[j])
					{
						st[j] |= (1 << vv);
						ep[vv] |= (1 << j);


					}
				}
			}
		}
		memset(cnt, 0, sizeof(cnt));
		memset(mat, 0, sizeof(mat));
		memset(at, -1, sizeof(at));
		memset(num, 0, sizeof(num));
		printf("Case %d: ", tst);
		if (!dfs(0, 0, 0))
		{
			puts("No");
		}
		else
		{
			puts("Yes");
			for (i = 1; i <= n; i++)
			{
				if (i > 1)
				{
					putchar(' ');
				}
				if (ans[i] >= 10)
				{
					printf("%d", ans[i]);
				}
				else
				{
					printf("0%d", ans[i]);
				}
			}
			printf("\n");
		}

	}
	return 0;
}
