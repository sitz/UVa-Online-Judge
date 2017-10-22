#include <bits/stdc++.h>

using namespace std;

struct rec {int path[52], len;} s[50];
bool map_[52][52], visited[52];
int path[52], N, M, E, ptr;

void recordpath(int depth)
{
	s[ptr].path[depth] = path[0];
	for (int i = 0; i < depth; i++)
	{
		s[ptr].path[i] = path[i];
		map_[path[i]][path[i + 1]] = false;
	}
	s[ptr].len = depth + 1;
	ptr++;
}

void DFS(int depth, int start)
{
	visited[start] = true;
	path[depth] = start;
	for (int i = 0; i < 52; i++)
	{
		if (map_[start][i])
		{
			if (visited[i])
			{
				if (i == path[0])
				{
					recordpath(depth + 1);
				}
			}
			else
			{
				DFS(depth + 1, i);
			}
		}
	}
}

bool comp(rec &a, rec &b)
{
	if (a.len > b.len)
	{
		return true;
	}
	if (a.len < b.len)
	{
		return false;
	}
	for (int i = 0; i < a.len; i++)
	{
		if (a.path[i] > b.path[i])
		{
			return true;
		}
		if (a.path[i] < b.path[i])
		{
			return false;
		}
	}
	return false;
}

int main()
{
	int times;
	char edge[30];
	scanf("%d", &times);
	for (; times; times--)
	{
		scanf("%d %d %d", &N, &M, &E);
		ptr = 0;
		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++)
			{
				map_[i][j] = false;
			}
		for (int i = 0; i < E; i++)
		{
			scanf("%s", edge);
			char s, d;
			if (edge[0] >= 'A' && edge[0] <= 'Z')
			{
				s = edge[0] - 'A';
				d = edge[2] - 'a' + 26;
			}
			else
			{
				s = edge[0] - 'a' + 26;
				d = edge[2] - 'A';
			}
			map_[s][d] = true;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				visited[j] = false;
			}
			DFS(0, i);
		}
		if (ptr == 0)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
			for (int i = 0; i < ptr; i++)
			{
				for (int j = i + 1; j < ptr; j++)
				{
					if (comp(s[i], s[j]))
					{
						rec t = s[i];
						s[i] = s[j];
						s[j] = t;
					}
				}
			}
			for (int i = 0; i < ptr; i++)
			{
				for (int j = 0; j < s[i].len; j++)
				{
					if (j)
					{
						printf("-");
					}
					char c;
					if (s[i].path[j] < 26)
					{
						c = s[i].path[j] + 'A';
					}
					else
					{
						c = s[i].path[j] - 26 + 'a';
					}
					printf("%c", c);
				}
				printf("\n");
			}
		}
		if (times != 1)
		{
			printf("\n");
		}
	}
	return 0;
}
