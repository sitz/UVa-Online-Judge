#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int N;
char str[MAXN], visit[MAXN];
vector<int> V[100000];
queue<int> Q;

void MakeLink()
{
	char *p;
	int u, v;
	p = strtok(str, " ");
	while (p)
	{
		u = atoi(p);
		p = strtok(NULL, " ");
		v = atoi(p);
		V[u].push_back(v);
		V[v].push_back(u);
		p = strtok(NULL, " ");
	}
}
void BFS(int s)
{
	int i, u, v;
	Q.push(s);
	visit[s] = 1;
	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for (i = 0; i < V[u].size(); i++)
		{
			v = V[u][i];
			if (visit[v] == 0)
			{
				visit[v] = 1;
				Q.push(v);
			}
		}
	}
}
void Cal()
{
	int i, c = 0;
	for (i = 1; i <= N; i++)
	{
		if (visit[i] == 0)
		{
			c++;
			BFS(i);
		}
	}
	cout << c << endl;
}
int EEmpty()
{
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
	return strlen(str) == 0;
}
void Free()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		V[i].clear();
		visit[i] = 0;
	}
}

int main()
{
	int ks;
	gets(str);
	ks = atoi(str);
	gets(str);
	while (ks--)
	{
		gets(str);
		N = atoi(str);
		while (gets(str))
		{
			if (EEmpty())
			{
				break;
			}
			MakeLink();
		}
		Cal();
		if (ks)
		{
			cout << endl;
			Free();
		}
	}
	return 0;
}
