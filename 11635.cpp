#include <bits/stdc++.h>

using namespace std;

#define NODE 10000
#define HOTEL 102
class Edge
{
public:
	int t, c;
	Edge(){};
	Edge(int tt, int tc)
	{
		t = tt;
		c = tc;
	};
};

class Cnode
{
public:
	int now, cost;
	Cnode(){};
	Cnode(int nex, int nc)
	{
		now = nex;
		cost = nc;
	};
	bool operator<(const Cnode &a) const
	{
		return cost > a.cost;
	}
};

vector<Edge> inp[NODE];
vector<Edge> Dedge[HOTEL];//edge for dijkstra
bool ishotel[NODE];				//is the node hotel or start or dest ?
int hotelnum[NODE];				//hotel number

//graph construct dijkstra
void csDijkstra(int s, int n)//s need to be hotel number
{
	static int INF = 601;
	int cost[n];
	fill(cost, cost + n, INF);
	priority_queue<Cnode> Q;
	cost[s] = 0;
	Cnode now(s, 0);
	Q.push(now);
	while (!Q.empty())
	{
		now = Q.top();
		Q.pop();
		if (now.cost > 600)
		{
			return;
		}
		if (cost[now.now] < now.cost)
		{
			continue;
		}
		if (ishotel[now.now] == true)
		{
			Dedge[hotelnum[s]].push_back(Edge(hotelnum[now.now], now.cost));
		}
		for (int i = 0; i < inp[now.now].size(); i++)
		{
			int next = inp[now.now][i].t;
			int nc = inp[now.now][i].c + now.cost;
			if (cost[next] > nc)
			{
				cost[next] = nc;
				Q.push(Cnode(next, nc));
			}
		}
	}
}

//find answer dijkstra
class node
{
public:
	int n, t, c;
	node() {}
	node(int tn, int tt, int tc)
	{
		n = tn;
		t = tt;
		c = tc;
	}
	bool operator<(const node &a) const
	{
		return c > a.c;
	}
};
int dijkstra(int n, int s, int t)//
{
	int cost[n][601];//pos *  time//day not need because of extended graph
	static int INF = 1000;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < 601; k++)
		{
			cost[i][k] = INF;
		}
	node now[2];
	priority_queue<node> Q;
	Q.push(node(s, 0, 0));
	while (!Q.empty())
	{
		now[0] = now[1] = Q.top();
		Q.pop();
		if (cost[now[0].n][now[0].t] < now[0].c)
		{
			continue;
		}
		if (now[0].n == t)
		{
			return now[0].c;
		}
		//now 1 is one day spent on hotel
		now[1].t = 0;
		now[1].c++;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < Dedge[now[i].n].size(); j++)
			{
				int time = Dedge[now[i].n][j].c;
				int next = Dedge[now[i].n][j].t;
				if (now[i].t + time > 600)
				{
					continue;
				}
				if (cost[next][now[i].t + time] > now[i].c)
				{
					cost[next][now[i].t + time] = now[i].c;
					Q.push(node(next, now[i].t + time, now[i].c));
				}
			}
		}
	}
	return -1;
}

void initial(int n);
int main()
{
	int tn;
	while (scanf("%d", &tn) && tn)
	{
		initial(tn);
		int h, hnum = 0, s = 0, g = 0;
		scanf("%d", &h);
		for (int i = 0; i < h; i++)
		{
			int t;
			scanf("%d", &t);
			t--;
			ishotel[t] = true;
			hotelnum[t] = hnum++;
		}
		if (ishotel[0] == false)
		{
			ishotel[0] = true;
			hotelnum[0] = hnum;
			s = hnum++;
		}
		else
		{
			s = hotelnum[0];
		}
		if (ishotel[tn - 1] == false)
		{
			ishotel[tn - 1] = true;
			hotelnum[tn - 1] = hnum;
			g = hnum++;
		}
		else
		{
			g = hotelnum[tn - 1];
		}
		int edgenum;
		scanf("%d", &edgenum);
		for (int i = 0; i < edgenum; i++)
		{
			int from, to, co;
			scanf("%d%d%d", &from, &to, &co);
			from--;
			to--;
			inp[from].push_back(Edge(to, co));
			inp[to].push_back(Edge(from, co));
		}
		for (int i = 0; i < tn; i++)
		{
			if (ishotel[i] == true)
			{
				csDijkstra(i, tn);
			}
		}
		cout << dijkstra(hnum, s, g) << endl;
	}
	return 0;
}

void initial(int n)
{
	for (int i = 0; i < n; i++)
	{
		inp[i].clear();
		ishotel[i] = false;
		hotelnum[i] = -1;
	}
	for (int i = 0; i < 102; i++)
	{
		Dedge[i].clear();
	}
}
