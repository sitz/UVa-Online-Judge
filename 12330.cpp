#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;
const int maxm = 80005;

map<string, int> T;
int n, cnt;
char input[10000], a[20], b[20], verb[20];
int g[maxn], gr[maxn], to[maxm], np[maxm], cp;

void add(int x, int y)
{
	to[cp] = y;
	np[cp] = g[x];
	g[x] = cp++;
	to[cp] = x;
	np[cp] = gr[y];
	gr[y] = cp++;
	assert(cp <= maxm);
}

bool vis[maxn];
int Q[maxn], BEGIN, END;

bool bfs(int x, int y)
{
	if (x == y)
	{
		return true;
	}
	memset(vis, 0, sizeof(vis));
	BEGIN = END = 0;
	Q[END++] = x;
	vis[x] = true;
	while (BEGIN != END)
	{
		int x = Q[BEGIN++];
		for (int i = g[x]; i; i = np[i])
			if (!vis[to[i]])
			{
				vis[to[i]] = true;
				if (to[i] == y)
				{
					return true;
				}
				Q[END++] = to[i];
			}
	}
	return false;
}

char ask(int x, int y)
{
	return bfs(x, y) ? 'Y' : 'M';
}

bool parse(char input[])
{
	int length = strlen(input);
	while (input[length - 1] < 32)
	{
		length--;
	}
	char END = input[length - 1];
	if (END == '!')
	{
		return false;
	}
	input[length - 1] = 0;
	int u = 0, x, y, ws = 0;
	for (; input[u] != ' '; u++)
		;
	for (int i = 0; input[i]; i++)
		if (input[i] == ' ')
		{
			ws++;
		}
	if (END == '.')
	{
		if (input[u + 1] != 'w')
		{
			sscanf(input, "%s %s %s", a, verb, b);
			strcat(a, "n");
			strcat(b, verb[0] == 'a' ? "n" : "v");
		}
		else
		{
			sscanf(input, "%*s %*s %*s %s %s %s", a, verb, b);
			strcat(a, "v");
			strcat(b, verb[0] == 'a' ? "n" : "v");
		}
	}
	else
	{
		if (ws == 2)
		{
			sscanf(input, "%s %s %s", verb, a, b);
			strcat(a, "n");
			strcat(b, verb[0] == 'a' ? "n" : "v");
		}
		else
		{
			sscanf(input, "%s %*s %*s %*s %s %s", verb, a, b);
			strcat(a, "v");
			strcat(b, verb[0] == 'a' ? "n" : "v");
		}
	}
	if (T.find(a) == T.end())
	{
		x = T[a] = cnt++;
	}
	else
	{
		x = T[a];
	}
	if (T.find(b) == T.end())
	{
		y = T[b] = cnt++;
	}
	else
	{
		y = T[b];
	}
	assert(cnt <= 200);
	assert(strlen(a) <= 11);
	assert(strlen(b) <= 11);
	/*
		printf("%s\n", input);
		printf("%s %s\n", a, b);
		printf("%d %d\n", x, y);
	*/
	if (END == '.')
	{
		add(x, y);
	}
	else
	{
		printf("%c", ask(x, y));
	}
	return true;
}

int main()
{
	int ntest;
	scanf("%d", &ntest);
	fgets(input, 10000, stdin);
	for (int test = 1; test <= ntest; test++)
	{
		T.clear();
		cnt = 0;
		memset(g, 0, sizeof(g));
		memset(gr, 0, sizeof(gr));
		cp = 2;
		printf("Case #%d:\n", test);
		while (true)
		{
			fgets(input, 10000, stdin);
			if (!parse(input))
			{
				break;
			}
		}
		printf("\n");
	}
	return 0;
}
