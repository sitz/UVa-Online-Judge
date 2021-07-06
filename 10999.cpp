#include <bits/stdc++.h>

using namespace std;

set<string> dictionary;
int N, M, P;

struct Tile
{
	char c;
	int v;
} tile[10];

int best;

void solve(int index, int vis[])
{
	if (index >= P)
	{
		int sum = 0;
		string tmp;
		for (int i = 0; i < P; i++)
			if (vis[i] == 1)
			{
				sum += tile[i].v;
				tmp += tile[i].c;
			}
		sort(tmp.begin(), tmp.end());
		if (dictionary.count(tmp) && sum >= best)
		{
			best = sum;
		}
		return;
	}
	vis[index] = 0;
	solve(index + 1, vis);
	vis[index] = 1;
	solve(index + 1, vis);
	vis[index] = 0;
}

int main()
{
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		dictionary.insert(s);
	}
	cin >> M;
	while (M--)
	{
		cin >> P;
		for (int i = 0; i < P; i++)
		{
			cin >> tile[i].c >> tile[i].v;
		}
		best = -1;
		int vis[20];
		memset(vis, 0, sizeof(vis));
		solve(0, vis);
		cout << best << endl;
	}
	return 0;
}
