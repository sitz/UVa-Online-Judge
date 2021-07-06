#include <bits/stdc++.h>

using namespace std;

#define LL unsigned long long

char largePic[10 + 2][10 + 2], smallPic[10 + 2][10 + 2];
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
bool vis[10 + 2][10 + 2], possible;
int n, m;

void dfs(int rL, int cL, int rS, int cS)
{
	if (rS == m || rS < 0 || cS == m || cS < 0 || vis[rS][cS] || smallPic[rS][cS] != '*')
	{
		return;
	}
	vis[rS][cS] = true;
	if (rL < n && rL >= 0 && cL < n && cL >= 0)
	{
		if (largePic[rL][cL] != '*')
		{
			possible = false;
			return;
		}
		largePic[rL][cL] = '.';
	}
	else
	{
		possible = false;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		dfs(rL - dr[i], cL - dc[i], rS - dr[i], cS - dc[i]);
	}
}

void getPosition()
{
	int startRowLargePic = -1;
	int startColLargePic = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (largePic[i][j] == '*')
			{
				startRowLargePic = i;
				startColLargePic = j;
				i = j = n;
			}
		}
	}
	int startRowSmallPic;
	int startColSmallPic;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (smallPic[i][j] == '*')
			{
				startRowSmallPic = i;
				startColSmallPic = j;
				i = j = m;
			}
		}
	}
	memset(vis, false, sizeof vis);
	if (startRowLargePic == -1)
	{
		possible = false;
	}
	else
	{
		dfs(startRowLargePic, startColLargePic, startRowSmallPic, startColSmallPic);
	}
}

void print()
{
	printf("Large pic: \n");
	for (int i = 0; i < n; i++)
		printf("%s\n", largePic[i]);

	printf("Small pic: \n");
	for (int i = 0; i < m; i++)
		printf("%s\n", smallPic[i]);
}

int main()
{
	while (scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++)
			scanf("%s", largePic[i]);
		for (int i = 0; i < m; i++)
			scanf("%s", smallPic[i]);

		possible = true;
		getPosition();
		if (possible)
			getPosition();

		if (possible)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
