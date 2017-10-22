#include <bits/stdc++.h>

using namespace std;

int used[400];
int vec[6];
int ans[10];
int M, N;
bool DFS(int depth)
{
	if (depth == M)
	{
		int count, add;
		int s[400];
		for (int i = 2; i <= M; i++)
		{
			add = 0;
			memset(s, 0, sizeof(s));
			for (int j = depth - 1; j >= 0; j--)
			{
				int k = ans[j] * i + add;
				add = k / N;
				k %= N;
				s[k]++;
			}
			for (int i = 0; i < N; i++)
				if (s[i] != used[i])
				{
					return false;
				}
		}
		for (int i = 0; i < depth; i++)
		{
			if (i)
			{
				putchar(' ');
			}
			printf("%d", ans[i]);
		}
		puts("");
		return true;
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			if (used[vec[i]])
			{
				continue;
			}
			if (depth == 0 && vec[i] * M >= N)
			{
				continue;
			}
			if (depth == 0 && vec[i] == 0)
			{
				continue;
			}
			used[vec[i]] = true;
			ans[depth] = vec[i];
			if (DFS(depth + 1))
			{
				return true;
			}
			used[vec[i]] = false;
		}
		return false;
	}
}
int main()
{
	while (scanf("%d %d", &M, &N) == 2)
	{
		if (!M && !N)
		{
			break;
		}
		bool flag = false;
		memset(used, false, sizeof(used));
		if (M != 6 && M != 4)
		{
			puts("Not found.");
			continue;
		}
		for (int i = 5; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				vec[j] = (i * (j + 1)) % N;
			}
			if ((flag = DFS(0)))
			{
				break;
			}
		}
		if (!flag)
		{
			puts("Not found.");
		}
	}
}
