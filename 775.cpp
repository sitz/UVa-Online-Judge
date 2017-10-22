#include <bits/stdc++.h>

using namespace std;

// Hamiltonian Cycle
// Please refer the description of uva 775
const int maxn = 1000;
int n, len;
int path[maxn], t[maxn];
bool g[maxn][maxn], v[maxn];
void FindPath()
{
	len = 1;
	path[0] = 0;
	v[0] = true;
	bool find;
	do
	{
		find = false;
		for (int i = 0; i < n && !find; i++)
			if (g[path[len - 1]][i] && !v[i])
			{
				path[len++] = i;
				v[i] = true;
				find = true;
			}
	} while (find);
}
bool CycleToPath()
{
	for (int i = 0; i < n; i++)
		if (!v[i])
		{
			for (int j = 0; j < len; j++)
			{
				if (g[i][path[j]])
				{
					t[0] = i;
					int p = 1;
					for (int l = j; l >= 0; l--)
					{
						t[p++] = path[l];
					}
					for (int l = len - 1; l > j; l--)
					{
						t[p++] = path[l];
					}
					memcpy(path, t, sizeof(t));
					v[i] = true;
					len++;
					return true;
				}
			}
		}
	return false;
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", path[i] + 1);
	}
	printf("%d\n", path[0] + 1);
}
bool PathToCycle()
{
	for (int i = 2; i < len; i++)
	{
		if (g[path[0]][path[i]] && g[path[len - 1]][path[i - 1]])
		{
			memset(t, 0, sizeof(t));
			for (int l = 0; l < i; l++)
			{
				t[l] = path[l];
			}
			for (int l = len - 1, p = i; l >= i; l--)
			{
				t[p++] = path[l];
			}
			memcpy(path, t, sizeof(t));
			return true;
		}
	}
	return false;
}
bool BuildHamiltonianCycle()
{
	FindPath();
	bool result;
	while (true)
	{
		if (g[path[0]][path[len - 1]])
		{
			if (len == n)
			{
				return true;
			}
			result = CycleToPath();
			if (!result)
			{
				return false;
			}
		}
		else
		{
			result = PathToCycle();
			if (!result)
			{
				return false;
			}
		}
	}
}
int main()
{
	char str[100];
	while (gets(str) != NULL)
	{
		sscanf(str, "%d", &n);
		memset(g, false, sizeof(g));
		memset(v, false, sizeof(v));
		while (gets(str) != NULL)
		{
			if (strcmp(str, "%") == 0)
			{
				break;
			}
			int a, b;
			sscanf(str, "%d %d", &a, &b);
			a--;
			b--;
			if (a == b)
			{
				continue;
			}
			if (g[a][b])
			{
				continue;
			}
			g[a][b] = g[b][a] = true;
		}
		if (!BuildHamiltonianCycle())
		{
			puts("N");
		}
		else
		{
			print();
		}
	}
}
