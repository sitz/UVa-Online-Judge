#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = 0; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define DON 0
#define SERVER 1
#define QUERY 2

const double eps = 1e-10;
const double INF = 1e100;
void solve(queue<double> *Q, double *ser)
{
	int p = 0;
	while (!Q[QUERY].empty())
	{
		int minindex = -1;
		double t = INF;
		//find minimum event
		rep(i, 3)
		{
			//if (!Q[i].empty())cout << i <<" " << Q[i].front()<<" " <<t<<endl;
			if (!Q[i].empty() && Q[i].front() + eps < t)
			{
				minindex = i;
				t = Q[i].front();
			}
		}
		//reduce remaining time
		rep(i, 3)
		{
			if (!Q[i].empty())
			{
				Q[i].front() -= t;
			}
		}
		//cout << "minindex is " << minindex << endl;
		if (minindex == DON)//DON pass the remaining to SERVER
		{
			Q[SERVER].push(ser[p++]);
		}
		else if (minindex == QUERY)//DON's query
		{
			if (Q[SERVER].empty())
			{
				puts("clear");
			}
			else
			{
				puts("full");
			}
		}
		Q[minindex].pop();
	}
	return;
}

main()
{
	int te, tc = 0;
	cin >> te;
	while (te--)
	{
		if (tc)
		{
			puts("");
		}
		tc++;
		double r[2];
		int n, q;
		cin >> r[DON] >> r[SERVER] >> n >> q;
		double ser[n];
		queue<double> Q[3];
		rep(i, n)
		{
			double s, g;
			cin >> s >> g;
			Q[DON].push(g / r[DON]);
			ser[i] = (s - g) / r[SERVER] + eps;
		}
		double last = 0;
		rep(i, q)
		{
			double tmp;
			cin >> tmp;
			Q[QUERY].push(tmp - last);
			last = tmp;
		}
		solve(Q, ser);
	}
	return false;
}
