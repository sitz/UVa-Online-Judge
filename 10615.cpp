#include <bits/stdc++.h>

using namespace std;

int res_color[111][111];
char g[111][111];
int N;

vector<int> adj[111];
int M[111];// matched people with y[i];
int V[111];// visit check
int c;

void print_grid()
{
	printf("===============\n");
	for (int i = 0; i < N; i++)
	{
		printf("%s\n", g[i]);
	}
	printf("===============\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j)
			{
				printf(" ");
			}
			printf("%d", res_color[i][j]);
		}
		printf("\n");
	}
	printf("===============\n");
}

bool dfs(int v)
{
	if (V[v] == c)
	{
		return false;
	}
	V[v] = c;
	for (int i = 0; i < (int)adj[v].size(); i++)
	{
		int t = adj[v][i];
		//if(res_color[v][t] != 0) continue;
		if (M[t] == -1 || (v != M[t] && dfs(M[t])))
		{
			M[t] = v;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%s", g[i]);
		}
		for (int i = 0; i < N; i++)
		{
			adj[i].clear();
		}
		int ldeg[111], rdeg[111];
		int max_degree = 0;
		memset(ldeg, 0, sizeof(ldeg));
		memset(rdeg, 0, sizeof(rdeg));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (g[i][j] == '*')
				{
					adj[i].push_back(j);
					max_degree = max(max_degree, ++ldeg[i]);
					max_degree = max(max_degree, ++rdeg[j]);
				}
		for (int l = 0, r = 0; l < N && r < N;)
		{
			if (ldeg[l] == max_degree)
			{
				l++;
			}
			else if (rdeg[r] == max_degree)
			{
				r++;
			}
			else
			{
				adj[l].push_back(r);
				ldeg[l]++;
				rdeg[r]++;
			}
		}
		memset(res_color, 0, sizeof(res_color));
		int res_max_color = max_degree;
		for (int i = 1; i <= max_degree; i++)
		{
			memset(V, -1, sizeof(V));
			memset(M, -1, sizeof(M));
			for (c = 0; c < N; c++)
			{
				dfs(c);
			}
			for (int j = 0; j < N; j++)
				if (M[j] != -1)
				{
					vector<int> &a = adj[M[j]];
					a.erase(find(a.begin(), a.end(), j));
					//printf("(%d %d)\n", M[j], j);
					if (g[M[j]][j] == '*')
					{
						res_color[M[j]][j] = i;
					}
				}
			//printf("\n");
		}
		assert(res_max_color == max_degree);
		printf("%d\n", res_max_color);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (j)
				{
					printf(" ");
				}
				printf("%d", res_color[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (res_color[i][j] == 0 && g[i][j] == '*')
				{
					print_grid();
					assert(false);
				}
				if (res_color[i][j] != 0 && g[i][j] == '.')
				{
					assert(false);
				}
			}
		for (int k = 0; k < N; k++)
		{
			for (int i = 0; i < N; i++)
				for (int j = i + 1; j < N; j++)
				{
					assert(res_color[k][i] != '*' || res_color[k][j] != '*' || res_color[k][i] != res_color[k][j]);
				}
		}
	}
	return 0;
}
