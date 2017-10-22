#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005, INF = 1 << 30;

struct State{int dis, num;};
State q[MAX * MAX], temp, out;

bool inq[MAX][MAX];
int n, m, u[MAX * 10], v[MAX * 10], w[MAX * 10], d[MAX][MAX], fst[MAX], nxt[MAX * 10];
map<string, int> mymap;

void bellman_ford(const int &len)
{
	memset(inq, 0, sizeof(inq));
	int front = 1, rear = 1;
	int U, V, W, minVal = INF,
							 sta = 0, end = n - 1, dis;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= len; j++)
		{
			if (!i)
			{
				d[i][j] = 0;
			}
			else
			{
				d[i][j] = INF;
			}
		}
	temp.num = sta;
	temp.dis = 0;
	inq[temp.num][temp.dis] = 1;
	q[rear++] = temp;
	while (front < rear)
	{
		out = q[front++];
		U = out.num;
		dis = out.dis;
		for (int e = fst[U]; e != -1; e = nxt[e])
		{
			V = v[e];
			W = w[e];
			if (d[V][dis + 1] > d[U][dis] + W && dis + 1 <= len)
			{
				d[V][dis + 1] = d[U][dis] + W;
				if (!inq[V][dis + 1])
				{
					inq[V][dis + 1] = 1;
					temp.num = V;
					temp.dis = dis + 1;
					q[rear++] = temp;
				}
			}
		}
	}
	for (int i = 0; i <= len; i++)
	{
		if (d[end][i] < minVal)
		{
			minVal = d[end][i];
		}
	}
	if (minVal != INF)
	{
		cout << "Total cost of flight(s) is $" << minVal << endl;
	}
	else
	{
		cout << "No satisfactory flights" << endl;
	}
}
int main()
{
	int nCase, t, num = 0, Q;
	string s, su, sv;
	cin >> nCase;
	while (nCase--)
	{
		memset(fst, -1, sizeof(fst));
		if (num++)
		{
			cout << endl;
		}
		cout << "Scenario #" << num << endl;
		mymap.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			mymap[s] = i;
		}
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> su >> sv;
			u[i] = mymap[su];
			v[i] = mymap[sv];
			cin >> w[i];
			nxt[i] = fst[u[i]];
			fst[u[i]] = i;
		}
		cin >> Q;
		while (Q--)
		{
			cin >> t;
			if (t < 0)
			{
				t = 0;
			}
			if (t > n)
			{
				t = n;
			}
			bellman_ford(t + 1);
		}
	}
	return 0;
}
