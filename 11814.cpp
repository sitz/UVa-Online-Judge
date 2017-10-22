#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
struct road
{
	int s;
	int d;
	int p;
};
bool operator<(const road r1, const road r2)
{
	if (r1.s < r2.s)
	{
		return true;
	}
	if (r1.s > r2.s)
	{
		return false;
	}
	if (r1.d < r2.d)
	{
		return true;
	}
	if (r1.d > r2.d)
	{
		return false;
	}
	if (r1.p < r2.p)
	{
		return true;
	}
	if (r1.p > r2.p)
	{
		return false;
	}
	return false;
}
queue<pi> q;
bitset<220> inq[220];
int bridge[220][220];
int qs;
int deqs;
void addbridge(int s, int d, unsigned l)
{
	if (l % 2)
	{
		*((int *)5) = 0;
	}
	unsigned cur = bridge[s][d];
	if (cur <= l)
	{
		return;
	}
	bridge[s][d] = l;
	q.push(pi(s, d));
	inq[s].set(d);
	qs++;
}
set<road> from[220];
set<road> to[220];
map<int, set<road>> top[220];
int main()
{
	int NN;
	scanf("%d", &NN);
	while (NN--)
	{
		int N, M, Q;
		scanf("%d %d %d", &N, &M, &Q);
		for (int i = 0; i < N; i++)
		{
			from[i] = set<road>();
			to[i] = set<road>();
			top[i] = map<int, set<road>>();
		}
		memset(bridge, -1, sizeof(bridge));
		for (int i = 0; i < M; i++)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			//            0 && printf("R: %d %d %d\n", x, y, z);
			road r;
			x--;
			y--;
			r.s = x;
			r.d = y;
			r.p = z;
			from[x].insert(r);
			to[y].insert(r);
			top[y][z].insert(r);
		}
		q = queue<pi>();
		for (int i = 0; i < N; i++)
		{
			set<road> fromi = from[i];
			for (set<road>::iterator it = fromi.begin(); it != fromi.end(); it++)
			{
				int p = it->p;
				if (p < 0)
				{
					continue;
				}
				int s = it->d;
				set<road> froms = from[s];
				for (set<road>::iterator it2 = froms.begin(); it2 != froms.end(); it2++)
				{
					if (it2->p == -p)
					{
						addbridge(i, it2->d, 2);
					}
				}
			}
		}
		while (q.size() > 0)
		{
			pi sd = q.front();
			int s = sd.first;
			int d = sd.second;
			q.pop();
			if (!inq[s].test(d))
			{
				continue;
			}
			inq[s].reset(d);
			deqs++;
			set<road> fromd = from[d];
			for (set<road>::iterator it = fromd.begin(); it != fromd.end(); it++)
			{
				int p = it->p;
				if (p > 0)
				{
					continue;
				}
				int dd = it->d;
				set<road> topsp = top[s][-p];
				for (set<road>::iterator it2 = topsp.begin(); it2 != topsp.end(); it2++)
				{
					int ss = it2->s;
					addbridge(ss, dd, bridge[s][d] + 2);
				}
			}
			for (int dd = 0; dd < N; dd++)
			{
				if (bridge[d][dd] != -1)
				{
					addbridge(s, dd, bridge[s][d] + bridge[d][dd]);
				}
				if (bridge[dd][s] != -1)
				{
					addbridge(dd, d, bridge[s][d] + bridge[dd][s]);
				}
			}
		}
		for (int i = 0; i < Q; i++)
		{
			int x, y;
			scanf("%d %d\n", &x, &y);
			//            0 && printf("Q: %d %d\n", x, y);
			x--;
			y--;
			if (bridge[x][y] == -1)
			{
				puts("impossible");
			}
			else
			{
				printf("%d\n", bridge[x][y]);
			}
		}
		//        0 && printf("qs: %d deqs: %d\n", qs, deqs);
	}
	return 0;
}
