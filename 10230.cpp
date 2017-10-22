#include <bits/stdc++.h>

using namespace std;

int diry[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int map_[1024][1024], n, c, r, color, cnt;

int select(int r, int c)
{
	bool used[26];
	int tr, tc, i;
	for (i = 0; i < 26; i++)
	{
		used[i] = false;
	}
	for (i = 0; i < 8; i++)
	{
		tr = r + diry[i];
		tc = c + dirx[i];
		if (tr >= 0 && tr < n && tc >= 0 && tc < n && map_[tr][tc] >= 'a' && map_[tr][tc] <= 'z')
		{
			used[map_[tr][tc] - 'a'] = true;
		}
	}
	for (i = 0; i < 8; i++)
	{
		tr = r + diry[i] - 1;
		tc = c + dirx[i];
		if (tr >= 0 && tr < n && tc >= 0 && tc < n && map_[tr][tc] >= 'a' && map_[tr][tc] <= 'z')
		{
			used[map_[tr][tc] - 'a'] = true;
		}
	}
	for (i = 0; i < 8; i++)
	{
		tr = r + diry[i];
		tc = c + dirx[i] - 1;
		if (tr >= 0 && tr < n && tc >= 0 && tc < n && map_[tr][tc] >= 'a' && map_[tr][tc] <= 'z')
		{
			used[map_[tr][tc] - 'a'] = true;
		}
	}
	for (i = 0; i < 8; i++)
	{
		tr = r + diry[i] - 1;
		tc = c + dirx[i] - 1;
		if (tr >= 0 && tr < n && tc >= 0 && tc < n && map_[tr][tc] >= 'a' && map_[tr][tc] <= 'z')
		{
			used[map_[tr][tc] - 'a'] = true;
		}
	}
	for (i = 0; i < 26; i++)
		if (!used[i])
		{
			return i;
		}
}
void paint(int sr, int sc, int dr, int dc, int size)
{
	if (size == 1)
	{
		return;
	}
	int s = size / 2;
	int c = cnt++;
	char color;
	if (dr < sr + s && dc < sc + s)
	{
		paint(sr, sc, dr, dc, s);
	}
	else
	{
		map_[sr + s - 1][sc + s - 1] = c;
		paint(sr, sc, sr + s - 1, sc + s - 1, s);
	}
	if (dr < sr + s && dc >= sc + s)
	{
		paint(sr, sc + s, dr, dc, s);
	}
	else
	{
		map_[sr + s - 1][sc + s] = c;
		paint(sr, sc + s, sr + s - 1, sc + s, s);
	}
	if (dr >= sr + s && dc < sc + s)
	{
		paint(sr + s, sc, dr, dc, s);
	}
	else
	{
		map_[sr + s][sc + s - 1] = c;
		paint(sr + s, sc, sr + s, sc + s - 1, s);
	}
	if (dr >= sr + s && dc >= sc + s)
	{
		paint(sr + s, sc + s, dr, dc, s);
	}
	else
	{
		map_[sr + s][sc + s] = c;
		paint(sr + s, sc + s, sr + s, sc + s, s);
	}
	color = select(sr + s, sc + s) + 'a';
	if (map_[sr + s - 1][sc + s - 1] == c)
	{
		map_[sr + s - 1][sc + s - 1] = color;
	}
	if (map_[sr + s - 1][sc + s] == c)
	{
		map_[sr + s - 1][sc + s] = color;
	}
	if (map_[sr + s][sc + s - 1] == c)
	{
		map_[sr + s][sc + s - 1] = color;
	}
	if (map_[sr + s][sc + s] == c)
	{
		map_[sr + s][sc + s] = color;
	}
}

int main()
{
	int i, j;
	while (scanf("%d%d%d", &n, &c, &r) == 3)
	{
		memset(map_, 0, sizeof(map_));
		map_[r - 1][c - 1] = '*';
		n = (int)pow(2, n);
		cnt = 0;
		paint(0, 0, r - 1, c - 1, n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%c", map_[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
