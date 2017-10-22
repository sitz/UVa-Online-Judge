#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 100;
const int inf = (1 << 21);
const int M = 25;

class state
{
public:
	int now, time, cost;
	bool needcost(int dep)
	{
		if (time <= dep)
		{
			if (time <= 12 && 12 <= dep)
			{
				return true;
			}
		}
		else
		{
			if (time >= 18 && dep <= 6)
			{
				return false;
			}
			return true;
		}
		return false;
	}
	bool operator<(const state &a) const
	{
		return cost > a.cost;
	}
};
class Edge
{
public:
	int dep, arr, to;
	bool isvalid()
	{
		if (!(18 <= dep || dep <= 6) || !(18 <= arr || arr <= 6))
		{
			return false;
		}
		return true;
	}
};
vector<Edge> edge[N];
int cost[N][M];
int dijkstra(int n, int s, int d)
{
	if (s == d)
	{
		return 0;
	}
	rep(i, n) rep(j, M) cost[i][j] = inf;
	priority_queue<state> Q;
	rep(i, 7) Q.push((state){
			s, i, 0});
	REP(i, 18, 25)
	Q.push((state){
			s, i, 0});
	while (!Q.empty())
	{
		state now = Q.top();
		Q.pop();
		if (cost[now.now][now.time] != inf)
		{
			continue;
		}
		cost[now.now][now.time] = now.cost;
		if (now.now == d)
		{
			return now.cost;
		}
		rep(i, edge[now.now].size())
		{
			int nec = now.cost;
			if (now.needcost(edge[now.now][i].dep))
			{
				nec++;
			}
			Q.push((state){
					edge[now.now][i].to, edge[now.now][i].arr, nec});
		}
	}
	return -1;
}
int getname(string in, map<string, int> &M)
{
	int index = M.size();
	if (M.find(in) == M.end())
	{
		M[in] = index;
	}
	return M[in];
}
int main()
{
	int te, tc = 1;
	cin >> te;
	while (te--)
	{
		int n;
		map<string, int> M;
		cin >> n;
		rep(i, 100) edge[i].clear();
		rep(i, n)
		{
			Edge in;
			string from, to;
			int f;
			cin >> from >> to;
			f = getname(from, M);
			in.to = getname(to, M);
			cin >> in.dep >> in.arr;
			if (in.arr > 12)
			{
				continue;
			}
			if (in.arr == 12 && in.dep == 6)
			{
				continue;
			}
			in.arr = (in.dep + in.arr) % 24;
			in.dep %= 24;
			if (in.isvalid())
			{
				edge[f].push_back(in);
			}
			//,cout << from <<" " << to <<" " <<  in.dep <<" " << in.arr << endl;
		}
		cout << "Test Case " << tc++ << "." << endl;
		string start, dest;
		cin >> start >> dest;
		if (M.find(start) == M.end() || M.find(dest) == M.end())
		{
			if (start == dest)
			{
				cout << "Vladimir needs " << 0 << " litre(s) of blood." << endl;
			}
			else
			{
				cout << "There is no route Vladimir can take." << endl;
			}
			continue;
		}
		int s = getname(start, M), d = getname(dest, M);
		int ans = dijkstra(M.size(), s, d);
		if (ans == -1)
		{
			cout << "There is no route Vladimir can take." << endl;
		}
		else
		{
			cout << "Vladimir needs " << ans << " litre(s) of blood." << endl;
		}
	}
	return 0;
}
