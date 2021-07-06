#include <bits/stdc++.h>

using namespace std;

int N, M, op[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, ans, mini, num[12][12];
char s[12][12], final[12][12], ss[12][12];
vector<pair<int, int>> v, z;

bool check_small()
{
	int i, j, vis[25], all = z.size(), nx, ny, x, y;
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	vis[num[z[0].first][z[0].second]] = 1;
	ss[z[0].first][z[0].second] = '*';
	q.push(z[0].first);
	q.push(z[0].second);
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		for (i = 0; i < 4; i++)
		{
			nx = x + op[i][0];
			ny = y + op[i][1];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && num[nx][ny] != -1 && ss[nx][ny] == '!' && vis[num[nx][ny]] == 0)
			{
				vis[num[nx][ny]] = 1;
				ss[nx][ny] = '*';
				q.push(nx);
				q.push(ny);
			}
		}
	}
	for (i = j = 0; i < all; i++)
		if (ss[z[i].first][z[i].second] == '!')
		{
			j = 1;
		}
	if (j == 0)
	{
		return true;
	}
	return false;
}
void dfs(int lv)
{
	int i, j, nx, ny, k;
	for (i = k = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (s[i][j] == '*')
			{
				k = 1;
			}
	if (k == 0)
	{
		ans = 1;
		if (lv < mini)
		{
			for (i = 0; i < N; i++)
			{
				strcpy(final[i], s[i]);
			}
			mini = lv;
		}
		else if (lv == mini)
		{
			int which = 0;
			for (i = 0; i < N && which == 0; i++)
				for (j = 0; j < N && which == 0; j++)
					if (s[i][j] != final[i][j])
					{
						which = s[i][j] < final[i][j] ? 1 : 2;
					}
			if (which == 1)
				for (i = 0; i < N; i++)
				{
					strcpy(final[i], s[i]);
				}
		}
	}
	for (i = 0; i < v.size() && ans == 0; i++)
	{
		if (s[v[i].first][v[i].second] != '*')
		{
			continue;
		}
		int re = 0, dx = z[0].first, dy = z[0].second;
		for (k = 1; k < z.size() && re == 0; k++)
		{
			nx = z[k].first - dx + v[i].first;
			ny = z[k].second - dy + v[i].second;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || s[nx][ny] != '*')
			{
				re = 1;
			}
		}
		if (re == 0)
		{
			s[v[i].first][v[i].second] = lv + 'A';
			for (k = 1; k < z.size() && re == 0; k++)
			{
				nx = z[k].first - dx + v[i].first;
				ny = z[k].second - dy + v[i].second;
				s[nx][ny] = lv + 'A';
			}
			dfs(lv + 1);
			s[v[i].first][v[i].second] = '*';
			for (k = 1; k < z.size() && re == 0; k++)
			{
				nx = z[k].first - dx + v[i].first;
				ny = z[k].second - dy + v[i].second;
				s[nx][ny] = '*';
			}
		}
		return;
	}
}

int main()
{
	int n, m, i, j, k;
	while (scanf(" %d", &N) == 1 && N)
	{
		gets(s[0]);
		for (n = 0; n < N; n++)
		{
			gets(s[n]);
		}
		for (n = 0; n < N; n++)
		{
			strcpy(ss[n], s[n]);
		}
		v.clear();
		memset(num, -1, sizeof(num));
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (s[i][j] == '*')
				{
					v.push_back(make_pair(i, j));
					num[i][j] = v.size() - 1;
				}
		M = v.size();
		if (M == 1 || M == 2 || M == 3 || M == 5 || M == 7 || M == 11 || M == 13 || M == 17 || M == 19)
		{
			k = 0;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
					if (s[i][j] == '*')
					{
						printf("%c", k + 'A');
						k++;
					}
					else
					{
						printf("%c", s[i][j]);
					}
				printf("\n");
			}
			printf("\n");
			continue;
		}
		mini = 1e9;
		for (i = M / 2; i > 1; i--)
		{
			int per[M];
			memset(per, 0, sizeof(per));
			if (M % i != 0)
			{
				continue;
			}
			for (j = 0; j < i; j++)
			{
				per[j] = 1;
			}
			do
			{
				z.clear();
				for (j = 0; j < M; j++)
					if (per[j])
					{
						z.push_back(v[j]);
						ss[v[j].first][v[j].second] = '!';
					}
				if (check_small())
				{
					ans = 0;
					dfs(0);
				}
				for (j = 0; j < M; j++)
					if (per[j])
					{
						z.push_back(v[j]);
						ss[v[j].first][v[j].second] = '*';
					}
			} while (prev_permutation(per, per + M));
			if (mini != 1e9)
			{
				break;
			}
		}
		if (mini != 1e9)
		{
			for (i = 0; i < N; i++)
			{
				printf("%s\n", final[i]);
			}
			printf("\n");
		}
		else
		{
			k = 0;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
					if (s[i][j] == '*')
					{
						printf("%c", k + 'A');
						k++;
					}
					else
					{
						printf("%c", s[i][j]);
					}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}
