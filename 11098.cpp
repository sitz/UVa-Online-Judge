#include <bits/stdc++.h>

using namespace std;

#define eps 1e-7
#define N 1000

int x[N], y[N], n, t, order[N], visited[N], rep[N], in[N], cgraph[N][N], ra[N];
vector<int> graph[N];
vector<int> rgraph[N];
double r[N], repr[N];
int mat[N][N], cnt, p;

void dfs(int s)
{
	visited[s] = true;
	for (int i = 0; i < (int)graph[s].size(); i++)
		if (!visited[graph[s][i]])
		{
			dfs(graph[s][i]);
		}
	order[n - (++p)] = s;
}
void dfs2(int s)
{
	visited[s] = cnt;
	if (repr[cnt] > r[s] + eps)
	{
		repr[cnt] = r[s];
		rep[cnt] = s;
	}
	for (int i = 0; i < (int)rgraph[s].size(); i++)
		if (visited[rgraph[s][i]] == -1)
		{
			dfs2(rgraph[s][i]);
		}
}
double sqr(int a)
{
	return a * a;
}
double dis(int i, int j)
{
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}
int main()
{
	cin >> t;
	for (int I = 1; I <= t; I++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i] >> ra[i] >> r[i];
		}
		memset(mat, 0, sizeof mat);
		for (int i = 0; i < n; i++)
		{
			graph[i].clear(), rgraph[i].clear();
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dis(i, j) < r[i] + ra[i] + ra[j] + eps)
				{
					//cout << "From " << i << " to " << j << endl;
					mat[i][j] = true;
					graph[i].push_back(j);
					rgraph[j].push_back(i);
				}
		for (int i = 0; i < N; i++)
		{
			repr[i] = 99999999;
		}
		p = 0;
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < n; i++)
			if (!visited[i])
			{
				dfs(i);
			}
		cnt = 0;
		memset(visited, -1, sizeof visited);
		for (int i = 0; i < n; i++)
			if (visited[order[i]] == -1)
			{
				dfs2(order[i]), cnt++;
			}
		memset(in, 0, sizeof in);
		memset(cgraph, 0, sizeof cgraph);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (int)graph[i].size(); j++)
				if (visited[i] != visited[graph[i][j]])
				{
					cgraph[visited[i]][visited[graph[i][j]]] = true;
				}
		for (int i = 0; i < cnt; i++)
			for (int j = 0; j < cnt; j++)
				if (cgraph[i][j])
				{
					in[j]++;
				}
		set<int> result;
		int count = 0;
		double sum = 0;
		int max_i = 0;
		for (int i = 0; i < cnt; i++)
			if (in[i] == 0)
			{
				result.insert(i);
				//cout << "Inserting " << i << endl;
				max_i = max(max_i, rep[i]);
				sum += repr[i];
				count++;
			}
		vector<pair<double, int>> remaining;
		for (int i = 0; i < cnt; i++)
			if (result.find(i) == result.end())
			{
				remaining.push_back(pair<double, int>(repr[i], i));
			}
		sort(remaining.begin(), remaining.end());
		for (int i = 0; i < (int)remaining.size(); i++)
			if (remaining[i].first * count < sum - eps)
			{
				count++;
				sum += remaining[i].first;
				result.insert(remaining[i].second);
				max_i = max(max_i, remaining[i].second);
			}
		int topsort[N];
		bool mark[N];
		for (int i = 0; i < cnt; i++)
		{
			mark[i] = false;
		}
		for (int i = 0; i < cnt; i++)
		{
			int v = -1;
			for (int j = 0; j < cnt; j++)
				if (!mark[j] && in[j] == 0)
				{
					v = j;
					break;
				}
			if (v == -1)
			{
				cout << "Gand khord" << endl;
			}
			mark[v] = true;
			for (int j = 0; j < cnt; j++)
				if (cgraph[v][j])
				{
					in[j]--;
				}
			topsort[i] = v;
		}
		vector<int> vresult;
		for (int i = cnt - 1; i >= 0; i--)
			if (result.find(topsort[i]) != result.end())
			{
				vresult.push_back(rep[topsort[i]]);
			}
		cout << "Case #" << I << ":";
		for (int i = 0; i < (int)vresult.size(); i++)
		{
			cout << " " << vresult[i];
		}
		cout << endl;
	}
	return 0;
}
