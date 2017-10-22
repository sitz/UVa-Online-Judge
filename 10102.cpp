#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

vector<string> G;
int dist[1000][1000];
int cx[] = {0, 0, 1, -1};
int cy[] = {1, -1, 0, 0};
vector<pair<int, int>> axis1;
vector<pair<int, int>> axis3;
int M;

void BFS()
{
	queue<pair<int, int>> Q;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < axis3.size(); i++)
	{
		int x = axis3[i].first;
		int y = axis3[i].second;
		dist[x][y] = 0;
		Q.push(make_pair(x, y));
	}
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tempx = x + cx[i];
			int tempy = y + cy[i];
			if (tempx >= 0 && tempx < M && tempy >= 0 && tempy < M &&
					dist[tempx][tempy] == -1)
			{
				dist[tempx][tempy] = dist[x][y] + 1;
				Q.push(make_pair(tempx, tempy));
			}
		}
	}
}

int main()
{
	while (cin >> M)
	{
		int maxstep = 0;
		axis1.clear();
		axis3.clear();
		G.resize(M);
		for (int i = 0; i < M; i++)
		{
			string line;
			cin >> line;
			G[i] = line;
			for (int j = 0; j < M; j++)
			{
				if (G[i][j] == '1')
				{
					axis1.push_back(make_pair(i, j));
				}
				if (G[i][j] == '3')
				{
					axis3.push_back(make_pair(i, j));
				}
			}
		}
		BFS();
		for (int i = 0; i < axis1.size(); i++)
		{
			int x = axis1[i].first;
			int y = axis1[i].second;
			if (dist[x][y] > maxstep)
			{
				maxstep = dist[x][y];
			}
		}
		cout << maxstep << endl;
	}
	return 0;
}
