#include <bits/stdc++.h>

using namespace std;

char dic[500][100];
int nodes, nodes1;
char ident1[100], ident2[100], str[1000], a[100], b[100];
bool g1[500][500], g2[500][500];
bool v[500];
int find(char *s)
{
	for (int i = 0; i < nodes; i++)
		if (strcmp(s, dic[i]) == 0)
		{
			return i;
		}
	strcpy(dic[nodes++], s);
	return nodes - 1;
}
bool DFS(int start, int end)
{
	if (g2[start][end])
	{
		return true;
	}
	v[start] = true;
	for (int i = nodes1; i < nodes; i++)
		if (!v[i] && g2[start][i] && DFS(i, end))
		{
			return true;
		}
	return false;
}
int main()
{
	while (gets(str) != NULL)
	{
		sscanf(str, "%s", ident1);
		if (strcmp(ident1, "END") == 0)
		{
			break;
		}
		nodes = 0;
		memset(g1, false, sizeof(g1));
		while (gets(str) != NULL)
		{
			if (str[0] == '*')
			{
				break;
			}
			sscanf(str, "%s %s", a, b);
			int x = find(a), y = find(b);
			g1[x][y] = g1[y][x] = true;
		}
		nodes1 = nodes;
		gets(str);
		sscanf(str, "%s", ident2);
		memset(g2, false, sizeof(g2));
		while (gets(str) != NULL)
		{
			if (str[0] == '*')
			{
				break;
			}
			sscanf(str, "%s %s", a, b);
			int x = find(a), y = find(b);
			g2[x][y] = g2[y][x] = true;
		}
		bool ans = true;
		for (int i = 0; i < nodes1 && ans; i++)
			for (int j = 0; j < nodes1 && ans; j++)
			{
				if (!g1[i][j])
				{
					continue;
				}
				memset(v, false, sizeof(v));
				ans &= DFS(i, j);
			}
		if (ans)
		{
			printf("YES: %s is a more detailed version of %s\n", ident2, ident1);
		}
		else
		{
			printf("NO: %s is not a more detailed version of %s\n", ident2, ident1);
		}
	}
}
