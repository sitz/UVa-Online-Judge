#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> xy;

const int vx[] = {-1, 0, 1, 0};
const int vy[] = {0, 1, 0, -1};

char c[9][10];
bool visit[9][9];
vector<xy> v;

void dfs(int x, int y)
{
	if (c[x][y] == '.')
	{
		v.push_back(xy(x, y));
	}
	if (c[x][y] != 'o')
	{
		return;
	}
	visit[x][y] = true;
	for (int vi = 0; vi < 4; vi++)
	{
		int nx = x + vx[vi], ny = y + vy[vi];
		if (nx < 0 || nx >= 9 || ny < 0 || ny >= 9)
		{
			continue;
		}
		if (visit[nx][ny])
		{
			continue;
		}
		dfs(nx, ny);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		fill(visit[0], visit[8] + 9, false);
		for (int i = 0; i < 9; i++)
		{
			scanf("%s", c[i]);
		}
		bool flag = false;
		for (int i = 0; i < 9 && !flag; i++)
		{
			for (int j = 0; j < 9 && !flag; j++)
			{
				if (c[i][j] == 'o' && !visit[i][j])
				{
					v.clear();
					dfs(i, j);
					sort(v.begin(), v.end());
					v.resize(unique(v.begin(), v.end()) - v.begin());
					if (v.size() == 1)
					{
						flag = true;
					}
				}
			}
		}
		printf("Case #%d: Can", t);
		if (!flag)
		{
			printf(" not");
		}
		printf(" kill in one move!!!\n");
	}
}
