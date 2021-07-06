#include <bits/stdc++.h>

using namespace std;

#define MAXV 100000

struct DancingLinks {int left, right, up, down, data, ch, rh;} DL[1000001 + 3001];
int s[2001], o[2001], head, size, time_, n, m, a, b, c, tn;

void Remove(int c)
{
	DL[DL[c].right].left = DL[c].left;
	DL[DL[c].left].right = DL[c].right;
	int i, j;
	for (i = DL[c].down; i != c; i = DL[i].down)
	{
		for (j = DL[i].right; j != i; j = DL[j].right)
		{
			DL[DL[j].down].up = DL[j].up;
			DL[DL[j].up].down = DL[j].down;
			s[DL[j].ch]--;
		}
	}
}
void Resume(int c)
{
	int i, j;
	for (i = DL[c].down; i != c; i = DL[i].down)
	{
		for (j = DL[i].left; j != i; j = DL[j].left)
		{
			DL[DL[j].down].up = j;
			DL[DL[j].up].down = j;
			s[DL[j].ch]++;
		}
	}
	DL[DL[c].right].left = c;
	DL[DL[c].left].right = c;
}
void Print_board(int k)
{
	static int set[512], a, b;
	for (a = 0; a < k; a++)
	{
		set[DL[o[a]].data] = DL[o[a]].rh + 1;
	}
	for (a = 0; a < n; a++)
	{
		for (b = 0; b < n; b++)
		{
			printf("%c", set[a * 16 + b] + 'A' - 1);
		}
		puts("");
	}
}
void DFS(int k)
{
	if (time_)
	{
		return;
	}
	if (DL[head].right == head)
	{
		Print_board(k);
		time_++;
		return;
	}
	int t = MAXV, c, i, j;
	for (i = DL[head].right; i != head; i = DL[i].right)
	{
		if (s[i] < t)
		{
			t = s[i], c = i;
		}
	}
	Remove(c);
	for (i = DL[c].down; i != c; i = DL[i].down)
	{
		o[k] = i;
		for (j = DL[i].right; j != i; j = DL[j].right)
		{
			Remove(DL[j].ch);
		}
		DFS(k + 1);
		for (j = DL[i].left; j != i; j = DL[j].left)
		{
			Resume(DL[j].ch);
		}
	}
	Resume(c);
}
int new_node(int up, int down, int left, int right)
{
	DL[size].up = up, DL[size].down = down;
	DL[size].left = left, DL[size].right = right;
	DL[up].down = DL[down].up = DL[left].right = DL[right].left = size;
	return size++;
}
void new_row(int n, int Row[], int rh, int set)
{
	int r, row = -1, k;
	for (int a = 0; a < n; a++)
	{
		r = Row[a];
		DL[size].ch = r, DL[size].data = set, s[r]++;
		if (row == -1)
		{
			row = new_node(DL[DL[r].ch].up, DL[r].ch, size, size);
			DL[row].rh = rh;
		}
		else
		{
			k = new_node(DL[DL[r].ch].up, DL[r].ch, DL[row].left, row);
			DL[k].rh = rh;
		}
	}
}
void init(int m)
{
	size = 0;
	head = new_node(0, 0, 0, 0);
	for (int i = 1; i <= m; i++)
	{
		new_node(i, i, DL[head].left, head);
		DL[i].ch = i, s[i] = 0;
	}
}

int main()
{
	int map[20][20], Row[256], t, i;
	char g[20][20], first = 0;
	while (scanf("%s", g[0]) == 1)
	{
		for (i = 1; i < 16; i++)
		{
			scanf("%s", g[i]);
		}
		n = 4;
		tn = n, n *= n, m = n * n * 4;
		init(m);
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < n; b++)
			{
				if (g[a][b] == '-')
				{
					map[a][b] = 0;
				}
				else
				{
					map[a][b] = g[a][b] - 'A' + 1;
				}
				if (map[a][b] == 0)
				{
					for (c = 0; c < n; c++)
					{
						t = 0;
						Row[t++] = a * n + b + 1;
						Row[t++] = n * n + a * n + c + 1;
						Row[t++] = 2 * n * n + b * n + c + 1;
						Row[t++] = 3 * n * n + (a / tn * tn + b / tn) * n + c + 1;
						new_row(t, Row, c, a * n + b);
					}
				}
				else
				{
					c = map[a][b] - 1, t = 0;
					Row[t++] = a * n + b + 1;
					Row[t++] = n * n + a * n + c + 1;
					Row[t++] = 2 * n * n + b * n + c + 1;
					Row[t++] = 3 * n * n + (a / tn * tn + b / tn) * n + c + 1;
					new_row(t, Row, c, a * n + b);
				}
			}
		}
		if (first)
		{
			puts("");
		}
		first = 1;
		time_ = 0;
		DFS(0);
	}
	return 0;
}
