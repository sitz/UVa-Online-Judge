#include <bits/stdc++.h>

using namespace std;

vector<int> g[1000];
long long dis[1000];
int inq[1000] = {}, prev_[1000] = {};
queue<int> Q;

void solByspfa(int st, int ed, long long goal)
{
	int tn, i, j;
	memset(dis, 31, sizeof(dis));
	memset(inq, 0, sizeof(inq));
	memset(prev_, 0, sizeof(prev_));
	Q.push(ed);
	dis[ed] = goal;
	while (!Q.empty())
	{
		tn = Q.front(), Q.pop();
		inq[tn] = 0;
		for (i = 0; i < g[tn].size(); i++)
		{
			j = g[tn][i];
			if ('A' <= tn && tn <= 'Z')
			{//town
				if (dis[tn] % 19 == 0)
				{
					if (dis[j] > dis[tn] * 20 / 19)
					{
						dis[j] = dis[tn] * 20 / 19;
						if (inq[j] == 0)
							Q.push(j), inq[j] = 1;
						prev_[j] = tn;
					}
					if (dis[j] == dis[tn] * 20 / 19)
					{
						prev_[j] = min(prev_[j], tn);
						if (inq[j] == 0)
							Q.push(j), inq[j] = 1;
					}
				}
				else
				{
					if (dis[j] > dis[tn] * 20 / 19 + 1)
					{
						dis[j] = dis[tn] * 20 / 19 + 1;
						if (inq[j] == 0)
							Q.push(j), inq[j] = 1;
						prev_[j] = tn;
					}
					if (dis[j] == dis[tn] * 20 / 19 + 1)
					{
						prev_[j] = min(prev_[j], tn);
						if (inq[j] == 0)
							Q.push(j), inq[j] = 1;
					}
				}
			}
			else
			{// viliage
				if (dis[j] > dis[tn] + 1)
				{
					dis[j] = dis[tn] + 1;
					if (inq[j] == 0)
						Q.push(j), inq[j] = 1;
					prev_[j] = tn;
				}
				if (dis[j] == dis[tn] + 1)
				{
					prev_[j] = min(prev_[j], tn);
					if (inq[j] == 0)
						Q.push(j), inq[j] = 1;
				}
			}
		}
	}
	printf("%lld\n", dis[st]);
}

int main()
{
	int n;
	int i, j;
	int cases = 0;
	long long goal;
	char s1[10], s2[10];
	while (scanf("%d", &n) == 1 && n >= 0)
	{
		for (i = 0; i < 1000; i++)
			g[i].clear();
		for (i = 0; i < n; i++)
		{
			scanf("%s %s", s1, s2);
			g[s1[0]].push_back(s2[0]);
			g[s2[0]].push_back(s1[0]);
		}
		scanf("%lld %s %s", &goal, s1, s2);
		printf("Case %d: ", ++cases);
		solByspfa(s1[0], s2[0], goal);
	}
	return 0;
}
