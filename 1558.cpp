#include <bits/stdc++.h>

using namespace std;

int sg[1 << 20], a[22];
int get_solve(int state, int x)
{
	for (int i = x; i <= 20; i += x)
		state &= ~(1 << (i - 2));
	for (int i = 2; i <= 20; i++)
		if (state & (1 << (i - 2)))
		{
			for (int j = x; i - j >= 2; j += x)
				if (!(state & (1 << (i - j - 2))))
				{
					state ^= 1 << (i - 2);
					break;
				}
		}
	return state;
}
int dfs(int state)
{
	if (sg[state] != -1)
		return sg[state];
	for (int i = 2; i <= 20; i++)
		if (state & (1 << (i - 2)))
			if (dfs(get_solve(state, i)) == 0)
				return sg[state] = 1;
	return sg[state] = 0;
}
int main()
{
	int t, n, i, j, k;
	memset(sg, -1, sizeof(sg));
	scanf("%d", &t);
	for (k = 1; k <= t; k++)
	{
		scanf("%d", &n);

		int state = 0;
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]), state |= 1 << (a[i] - 2);
		printf("Scenario #%d:\n", k);
		if (dfs(state) == 0)
			puts("There is no winning move.");
		else
		{
			printf("The winning moves are:");
			for (i = 2; i <= 20; i++)
				if (state & (1 << (i - 2)))
					if (dfs(get_solve(state, i)) == 0)
						printf(" %d", i);
			puts(".");
		}
		puts("");
	}
	return 0;
}
