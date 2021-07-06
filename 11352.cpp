#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int R, C;
char G[100][100];
int dist[100][100];
int srcx, srcy, dstx, dsty;
int cx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int cy[] = {2, -2, 1, -1, 2, -2, 1, -1};
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool inrange(int x, int y)
{
	return (x >= 0 && x < R && y >= 0 && y < C);
}

void BFS(int x, int y)
{
	queue<pair<int, int>> Q;
	dist[x][y] = 0;
	Q.push(make_pair(x, y));
	while (!Q.empty())
	{
		pair<int, int> t = Q.front();
		Q.pop();
		for (int i = 0; i < 8; i++)
		{
			int tmpx = t.first + dx[i];
			int tmpy = t.second + dy[i];
			if (inrange(tmpx, tmpy) && dist[tmpx][tmpy] == -1)
			{
				dist[tmpx][tmpy] = dist[t.first][t.second] + 1;
				Q.push(make_pair(tmpx, tmpy));
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		vector<pair<int, int>> knxy;
		memset(G, 0, sizeof(G));
		memset(dist, -1, sizeof(dist));
		cin >> R >> C;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cin >> G[i][j];
				if (G[i][j] == 'A')
				{
					srcx = i;
					srcy = j;
				}
				else if (G[i][j] == 'B')
				{
					dstx = i;
					dsty = j;
				}
				else if (G[i][j] == 'Z')
				{
					dist[i][j] = 0;
					knxy.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < knxy.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				int tempx = knxy[i].first + cx[j];
				int tempy = knxy[i].second + cy[j];
				if (inrange(tempx, tempy) && G[tempx][tempy] == '.')
				{
					dist[tempx][tempy] = 0;
				}
			}
		}
		BFS(srcx, srcy);
		if (dist[dstx][dsty] == -1)
		{
			cout << "King Peter, you can't go now!" << endl;
		}
		else
		{
			cout << "Minimal possible length of a trip is " << dist[dstx][dsty] << endl;
		}
	}
	return 0;
}
