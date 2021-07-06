#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 150;
const int inf = (1 << 20);
int edge[N][N];

int st_min_cut(vector<int> &V)
{
	int n = V.size();
	int s, t;
	int mincut = 0;
	static int w[N];//cross w(A,{i})
	rep(i, n) w[i] = 0;
	rep(i, n)
	{
		s = t;
		t = max_element(w, w + n) - w;//merge (A,V[t])
		mincut = w[t];
		w[t] = -1;
		//update w(A,i)
		rep(j, n) if (w[j] != -1)
		{
			w[j] += edge[V[t]][V[j]];
		}
	}
	rep(i, n)//merge (V[s],V[t])
	{
		edge[V[i]][V[s]] += edge[V[i]][V[t]];
		edge[V[s]][V[i]] += edge[V[t]][V[i]];
	}
	V.erase(V.begin() + t);
	//cout << s <<" " << t << " " << mincut << endl;
	return mincut;
}

int global_min_cut(int n)
{
	int ret = inf;
	vector<int> node(n);
	rep(i, n) node[i] = i;
	for (int i = n; i > 1; i--)
	{
		ret = min(ret, st_min_cut(node));
	}
	return ret;
}

main()
{
	int te, tc = 1;
	cin >> te;
	while (te--)
	{
		int n, m;
		cin >> n >> m;
		rep(i, n) rep(j, n) edge[i][j] = 0;
		rep(i, m)
		{
			int f, t, c;
			cin >> f >> t >> c;
			f--;
			t--;
			edge[f][t] = edge[t][f] = c;
		}
		cout << "Case #" << tc++ << ": ";
		cout << global_min_cut(n) << endl;
	}
	return 0;
}
