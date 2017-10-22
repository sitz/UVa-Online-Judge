#include <bits/stdc++.h>

using namespace std;

#define LL long long
int m[33], n, S, win[21][11111];
int dfs(int cur, int t)
{
	if (cur == 1)
		return -1;
	if (t > 2 * n)
		t = 1;

	if (win[t][cur])
		return win[t][cur];
	if (cur <= m[t] + 1)
		return 1;

	for (int i = 1; i <= m[t]; i++)
		if (dfs(cur - i, t + 1) < 0)
			return win[t][cur] = 1;
	return win[t][cur] = -1;
}
void init()
{
	for (int i = 1; i <= 2 * n; i++)
		for (int j = 1; j <= S; j++)
			win[i][j] = 0;
}
int main()
{
	int i, j;
	while (scanf("%d", &n) != -1 && n)
	{
		scanf("%d", &S);
		for (i = 1; i <= 2 * n; i++)
			scanf("%d", &m[i]);
		init();
		if (dfs(S, 1) > 0)
			puts("1");
		else
			puts("0");
	}
	return 0;
}
