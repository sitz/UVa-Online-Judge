#include <bits/stdc++.h>

using namespace std;

int T, Y, X, sx, sy, path[100], top = 0;
char m[20][20], vis[20][20], ans[3][10] = {"left", "forth", "right"};
int dy[3] = {0, -1, 0}, dx[3] = {-1, 0, 1};
string letters = "@IEHOVA#";

void dfs(int y, int x)
{
	if (top == 7)
		for (int i = 0; i < top; i++)
		{
			printf(i ? " " : ""), printf("%s", ans[path[i]]), printf(i == top - 1 ? "\n" : "");
		}
	for (int d = 0; d < 3; d++)
	{
		int cy = y + dy[d], cx = x + dx[d];
		if (cx > X || cy > Y || cy <= 0 || cx <= 0)
		{
			continue;
		}
		if (vis[cy][cx] || letters[top + 1] != m[cy][cx])
		{
			continue;
		}
		vis[cy][cx] = 1, path[top++] = d;
		dfs(cy, cx);
		vis[cy][cx] = 0, top--;
	}
}

int main()
{
	memset(vis, 0, sizeof vis);
	scanf("%d\n", &T);
	while (T-- && scanf("%d %d\n", &Y, &X) != EOF)
	{
		for (int y = 1; y <= Y; y++, getchar())
		{
			for (int x = 1; x <= X; x++)
			{
				m[y][x] = getchar();
				if (m[y][x] == '@')
				{
					sy = y, sx = x;
				}
			}
		}
		vis[sy][sx] = 1;
		dfs(sy, sx);
		vis[sy][sx] = 0;
	}
	return 0;
}
