#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi pset(200005);

void initSet(int N)
{
	pset.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		pset[i] = i;
	}
}
int findSet(int i)
{
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j)
{
	pset[findSet(i)] = findSet(j);
}

int main()
{
	int V, E, u, v, w, Cost;
	vector<pair<int, ii>> EdgeList;
	map<string, int> stations;
	char st[10], end[10];
	scanf("%d %d", &V, &E);
	while (V != 0 || E != 0)
	{
		Cost = 0;
		stations.clear();
		EdgeList.clear();
		for (int i = 0; i < V; i++)
		{
			scanf("%s", st);
			stations[st] = i;
		}
		for (int i = 0; i < E; i++)
		{
			scanf("%s %s %d", st, end, &w);
			u = stations[st];
			v = stations[end];
			EdgeList.push_back(make_pair(w, ii(u, v)));
		}
		scanf("%s", st);
		sort(EdgeList.begin(), EdgeList.end());
		initSet(V);
		int j = 0;
		for (int i = 0; i < E; i++)
		{
			pair<int, ii> front = EdgeList[i];
			if (!isSameSet(front.second.first, front.second.second))
			{
				Cost += front.first;
				unionSet(front.second.first, front.second.second);
				j++;
				if (j == V - 1)
				{
					break;
				}
			}
		}
		if (j == V - 1)
		{
			printf("%d\n", Cost);
		}
		else
		{
			printf("Impossible\n");
		}
		scanf("%d %d", &V, &E);
	}
	return 0;
}
