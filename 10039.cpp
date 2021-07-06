#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define MAXT 2400

int sr, tg, n, m, begTime, endTime, ansBeg, ansEnd, start;
int visitTime[MAXN][MAXT];
bool FIND, visitCity[MAXN];
map<string, int> city;
vector<vector<pair<int, int>>> train, g;
vector<vector<bool>> visit;
char cityName[MAXN][100];

int DFS(int now, int t)
{
	if (now == sr && t >= start)
	{
		return visitTime[now][t] = t;
	}
	if (now == sr)
	{
		return -1e9;
	}
	if (visitTime[now][t] != -1)
	{
		return visitTime[now][t];
	}
	for (int i = 0; i < g[now].size(); ++i)
	{
		int nowTrain = g[now][i].first;
		int nowStation = g[now][i].second;
		int nowTime = train[nowTrain][nowStation].first;
		if (nowTime > t)
		{
			continue;
		}
		for (int j = nowStation + 1; j < train[nowTrain].size(); ++j)
		{
			int next = train[nowTrain][j].second;
			visitTime[now][nowTime] = max(visitTime[now][nowTime], DFS(next, train[nowTrain][j].first));
		}
		visitTime[now][t] = max(visitTime[now][t], visitTime[now][nowTime]);
	}
	return visitTime[now][t];
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; ++k)
	{
		city.clear();
		train.clear();
		visit.clear();
		g.clear();
		char buf[100];
		scanf("%d", &n);
		g = vector<vector<pair<int, int>>>(n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", cityName[i]);
			city[cityName[i]] = i;
		}
		scanf("%d", &m);
		train = vector<vector<pair<int, int>>>(m);
		for (int i = 0; i < m; ++i)
		{
			int x;
			scanf("%d", &x);
			for (int j = 0; j < x; ++j)
			{
				int t;
				scanf("%d %s", &t, buf);
				t = t / 100 * 60 + t % 100;
				int c = city[buf];
				train[i].push_back(pair<int, int>(t, c));
			}
			sort(train[i].begin(), train[i].end(), cmp);
			for (int j = 0; j < x; ++j)
			{
				int c = train[i][j].second;
				g[c].push_back(pair<int, int>(i, j));
			}
		}
		scanf("%d", &start);
		start = start / 100 * 60 + start % 100;
		scanf("%s", buf);
		sr = city[buf];
		scanf("%s", buf);
		tg = city[buf];
		memset(visitTime, -1, sizeof(visitTime));
		DFS(tg, 2400);
		ansBeg = -1e9, ansEnd = 1e9;
		for (int i = 0; i < g[tg].size(); ++i)
		{
			int nowTrain = g[tg][i].first;
			int nowStation = g[tg][i].second;
			int nowTime = train[nowTrain][nowStation].first;
			if (visitTime[tg][nowTime] != -1)
			{
				if (ansEnd > nowTime)
				{
					ansBeg = visitTime[tg][nowTime], ansEnd = nowTime;
				}
				else if (ansEnd == nowTime && ansEnd - ansBeg > nowTime - visitTime[tg][nowTime])
				{
					ansBeg = visitTime[tg][nowTime], ansEnd = nowTime;
				}
			}
		}
		printf("Scenario %d\n", k + 1);
		if (ansEnd != 1e9)
		{
			printf("Departure %04d %s\nArrival   %04d %s\n\n",
						 ansBeg / 60 * 100 + ansBeg % 60,
						 cityName[sr],
						 ansEnd / 60 * 100 + ansEnd % 60,
						 cityName[tg]);
		}
		else
		{
			puts("No connection\n");
		}
	}
	return 0;
}
