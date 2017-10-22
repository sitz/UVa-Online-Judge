#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
const int INF = INT_MAX;

struct edge
{
	int u, v, wt;
};

struct node
{
	int S, T;
	bool operator<(const node &rhs) const
	{
		return S < rhs.S;
	}
};

int n, m;
int Size[MAXN + 10];
vector<node> A[MAXN + 10];
int res[MAXN + 10];

int work_time(vector<node> &pro, int blo)
{
	if (pro.size() == 0)
	{
		return 0;
	}
	if (Size[blo] < pro[0].S)
	{
		return INF;
	}
	int tmp = upper_bound(pro.begin(), pro.end(), (node){
																										Size[blo], 0}) -
						pro.begin() - 1;
	return pro[tmp].T;
}

struct KM_algorithm
{
	vector<int> G[MAXN + 10];
	vector<edge> Edge;

	int Lx[MAXN + 10], Ly[MAXN + 10], Slack[MAXN + 10];
	int nx, ny, Left[MAXN + 10];
	bool S[MAXN + 10], T[MAXN + 10];

	void init(int nx, int ny)
	{
		this->nx = nx, this->ny = ny;
		for (int u = 1; u <= nx; u++)
		{
			G[u].clear();
		}
		Edge.clear();
	}

	void Addedge(int u, int v, int wt)
	{
		Edge.push_back((edge){
				u, v, wt});
		G[u].push_back(Edge.size() - 1);
	}

	bool match(int u)
	{
		S[u] = 1;
		for (int i = 0; i < G[u].size(); i++)
		{
			edge &e = Edge[G[u][i]];
			if (!T[e.v])
			{
				int t = Lx[e.u] + Ly[e.v] - e.wt;
				if (t == 0)
				{
					T[e.v] = 1;
					if (!Left[e.v] || match(Left[e.v]))
					{
						Left[e.v] = e.u;
						return 1;
					}
				}
				Slack[e.v] = min(Slack[e.v], t);
			}
		}
		return 0;
	}

	void Update()
	{
		int i, a = INF;
		for (i = 1; i <= ny; i++)
			if (!T[i])
			{
				a = min(a, Slack[i]);
			}
		for (i = 1; i <= ny; i++)
		{
			if (S[i])
			{
				Lx[i] -= a;
			}
			if (T[i])
			{
				Ly[i] += a;
			}
			else
			{
				Slack[i] -= a;
			}
		}
	}

	int KM()
	{
		int i, ans = 0;
		for (i = 1; i <= ny; i++)
		{
			Lx[i] = Ly[i] = Left[i] = 0;
		}
		for (i = 1; i <= nx; i++)
		{
			memset(Slack, 0x3f, sizeof(Slack));
			while (1)
			{
				memset(S, 0, sizeof(S));
				memset(T, 0, sizeof(T));
				if (match(i))
				{
					break;
				}
				else
				{
					Update();
				}
			}
		}
		for (i = 1; i <= ny; i++)
		{
			ans += Lx[Left[i]] + Ly[i];
		}
		return -ans;
	}

} sp;

void read_input()
{
	sp.init(n, m * n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &Size[i]);
	}
	for (int i = 1, c; i <= n; i++)
	{
		scanf("%d", &c);
		A[i].clear();
		for (int j = 1; j <= c; j++)
		{
			node t;
			scanf("%d%d", &t.S, &t.T);
			A[i].push_back(t);
		}
		for (int j = 1; j <= m; j++)
		{
			int tmp = work_time(A[i], j);
			if (tmp == INF)
			{
				continue;
			}
			for (int k = 1; k <= n; k++)
			{
				sp.Addedge(i, (j - 1) * n + k, -k * tmp);
			}
		}
	}
}

int Start[MAXN + 10];

void work()
{
	int ans = sp.KM();
	printf("Average turnaround time = %.2lf\n", 1.0 * ans / n);
	for (int i = 1; i <= m; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			int v = (i - 1) * n + j;
			if (sp.Left[v])
			{
				res[sp.Left[v]] = i;
				int Last = j == n ? 0 : sp.Left[v + 1];
				int tmp = work_time(A[Last], i);
				Start[sp.Left[v]] = tmp + Start[Last];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("Program %d runs in region %d from %d to %d\n", i, res[i], Start[i], Start[i] + work_time(A[i], res[i]));
	}
}

int main()
{
	int t = 0;
	while (scanf("%d%d",&m,&n) == 2 && (n||m))
	{
		read_input();
		printf("Case %d\n", ++t);
		work();
		puts("");
	}
	return 0;
}
