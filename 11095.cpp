#include <bits/stdc++.h>

using namespace std;

#define num 31

int mat[num][num];
vector<int> adj[num];
int dep[num];
int ans[num];
int cur[num];
int nfin;
int m, n, bestAns, t;
int mark[num];
int change[num];

void check(int x, int &size)
{
	//cout<<"new: "<<x<<' '<<size<<endl;
	dep[x] = 0;
	for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++)
		if (!mat[x][*it])
		{
			cur[size++] = *it;
			mark[*it] = 1;
			for (vector<int>::iterator jt = adj[*it].begin(); jt != adj[*it].end(); jt++)
			{
				if (!mat[*jt][*it])
				{
					nfin--;
				}
				mat[*jt][*it]++;
				mat[*it][*jt]++;
				dep[*it]--;
			}
			for (vector<int>::iterator jt = adj[*it].begin(); jt != adj[*it].end(); jt++)
				if (dep[*jt] == 1)
				{
					check(*jt, size);
				}
			return;
		}
}

void back(int x, int size)
{
	//cout<<"In Back("<<x<<" , "<<size<<")"<<endl;
	if (!nfin)
	{
		if (size < bestAns)
		{
			bestAns = size;
			for (int i = 0; i < size; i++)
			{
				ans[i] = cur[i];
			}
		}
		return;
	}
	if (size >= bestAns - 1)
	{
		return;
	}
	if (x >= n)
	{
		return;
	}
	if (mark[x])
	{
		back(x + 1, size);
		return;
	}
	int flag = 0;
	int tmat[num][num];
	int tdep[num];
	int tmark[num];
	int tnfin = nfin;
	int tsize = size;
	for (int i = 0; i < n; i++)
		if (dep[i] == 1)
		{
			if (!flag)
			{
				memcpy(tmat, mat, sizeof mat);
				memcpy(tdep, dep, sizeof dep);
				memcpy(tmark, mark, sizeof mark);
			}
			flag = 1;
			check(i, size);
		}
	if (!dep[x])
	{
		back(x + 1, size);
		if (flag)
		{
			memcpy(mat, tmat, sizeof mat);
			memcpy(dep, tdep, sizeof dep);
			memcpy(mark, tmark, sizeof mark);
			nfin = tnfin;
			size = tsize;
		}
		return;
	}
	for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++)
	{
		if (!mat[x][*it])
		{
			nfin--;
		}
		mat[x][*it]++;
		mat[*it][x]++;
		dep[*it]--;
		cur[size] = x;
	}
	int tmp = dep[x];
	dep[x] = 0;
	back(x + 1, size + 1);
	for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++)
	{
		mat[x][*it]--;
		mat[*it][x]--;
		if (!mat[x][*it])
		{
			nfin++;
		}
		dep[*it]++;
	}
	dep[x] = tmp;
	back(x + 1, size);
	if (flag)
	{
		memcpy(mat, tmat, sizeof mat);
		memcpy(dep, tdep, sizeof dep);
		memcpy(mark, tmark, sizeof mark);
		nfin = tnfin;
		size = tsize;
	}
	return;
}

int main()
{
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		bestAns = 1000000;
		memset(mat, 0, sizeof mat);
		memset(mark, 0, sizeof mark);
		cin >> n >> m;
		nfin = m;
		for (int i = 0; i < n; i++)
		{
			adj[i].clear();
			dep[i] = 0;
		}
		int x, y;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			dep[x]++;
			dep[y]++;
		}
		for (int i = 0; i < n; i++)
		{
			change[i] = i;
		}
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n - 1; i++)
				if (dep[i] < dep[i + 1])
				{
					vector<int> tmp;
					tmp = adj[i];
					adj[i] = adj[i + 1];
					adj[i + 1] = tmp;
					int td = dep[i];
					dep[i] = dep[i + 1];
					dep[i + 1] = td;
					int tc = change[i];
					change[i] = change[i + 1];
					change[i + 1] = tc;
					for (int a = 0; a < n; a++)
						for (vector<int>::iterator it = adj[a].begin(); it != adj[a].end(); it++)
							if (*it == i)
							{
								*it = i + 1;
							}
							else if (*it == i + 1)
							{
								*it = i;
							}
				}
		//      for(int i=0;i<n;i++)
		//          cout<<i<<' '<<change[i]<<endl;
		back(0, 0);
		cout << "Case #" << k + 1 << ":" << ' ' << bestAns << endl;
		for (int i = 0; i < bestAns - 1; i++)
		{
			cout << change[ans[i]] << ' ';
		}
		if (bestAns)
		{
			cout << change[ans[bestAns - 1]];
		}
		cout << endl;
	}
	return 0;
}
