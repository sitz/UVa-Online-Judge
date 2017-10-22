#include <bits/stdc++.h>

using namespace std;

#define maxn 21

int line, dri, stop;
vector<int> L[maxn];
char links[52][52], V[52];
queue<int> Q;

struct driver
{
	int line, st;
} D[52];

int ReadCase()
{
	char ss[1000], *p;
	int l, s, d;
	string temp;
	gets(ss);
	temp = ss;
	istringstream in(temp);
	in >> line >> dri >> stop;
	if (!line && !dri && !stop)
		return 0;
	for (l = 1; l <= line; l++)
	{
		gets(ss);
		L[l].clear();
		p = strtok(ss, " ");
		while (p)
		{
			L[l].push_back(atoi(p));
			p = strtok(NULL, " ");
		}
		gets(ss);
		p = strtok(ss, " ");
		while (p)
		{
			s = atoi(p);
			p = strtok(NULL, " ");
			d = atoi(p);
			p = strtok(NULL, " ");
			D[d].line = l;
			D[d].st = s;
		}
	}
	return 1;
}
int isConnect(int u, int v)
{
	int i, l1, l2, iu, iv;
	if (D[u].line == D[v].line && D[u].st != D[v].st)
		return 0;
	if (D[v].st == D[u].st)
		return 1;
	for (iu = 0; iu < L[D[u].line].size(); iu++)
		if (L[D[u].line][iu] == D[u].st)
			break;
	for (iv = 0; iv < L[D[v].line].size(); iv++)
		if (L[D[v].line][iv] == D[v].st)
			break;
	iu--;
	iv--;
	l1 = L[D[u].line].size();
	l2 = L[D[v].line].size();
	for (i = 0; i <= 100; i++)
	{
		iu++;
		iv++;
		iu %= l1;
		iv %= l2;
		if (L[D[u].line][iu] == L[D[v].line][iv])
			return 1;
	}
	return 0;
}
void MakeLink()
{
	int i, j;
	for (i = 1; i < dri; i++)
		for (j = i + 1; j <= dri; j++)
			if (isConnect(i, j))
				links[i][j] = links[j][i] = 1;
}
void BFS(int u)
{
	int i, v;
	V[u] = 1;
	Q.push(u);
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (i = 1; i <= dri; i++)
			if (links[u][i] == 1 && V[i] == 0)
			{
				V[i] = 1;
				Q.push(i);
			}
	}
}
int Cal()
{
	int i, total = 0;
	MakeLink();
	BFS(1);
	for (i = 1; i <= dri; i++)
		if (V[i] == 0)
			return 0;
	return 1;
}
void Free()
{
	int i;
	memset(links, 0, 52 * 52);
	memset(V, 0, 52);
}

int main()
{
	while (ReadCase())
	{
		if (Cal())
			cout << "Yes\n";
		else
			cout << "No\n";
		Free();
	}
	return 0;
}
