#include <bits/stdc++.h>

using namespace std;

#define MAXV 0x3f3f3f3f
#define MAXE 1048576
#define MAXC 1048576
#define MAXR 1024

class DLX
{
public:
	struct DacingLinks
	{
		int left, right, up, down, ch, rh, data;// extra info
	} DL[MAXE];

	int s[MAXC], o[MAXR], used[MAXC] = {}, head, size, ans, find_flag;

	void init(int m)
	{
		size = 0;
		head = new_node(0, 0, 0, 0);
		int i;
		for (i = 1; i <= m; i++)
		{
			new_node(i, i, DL[head].left, head);
			DL[i].ch = i, s[i] = 0;
		}
	}

	void rm(int c)
	{
		static int i;
		for (i = DL[c].down; i != c; i = DL[i].down)
		{
			DL[DL[i].right].left = DL[i].left;
			DL[DL[i].left].right = DL[i].right;
			s[DL[i].ch]--;
		}
	}

	void resume(int c)
	{
		static int i;
		for (i = DL[c].down; i != c; i = DL[i].down)
		{
			DL[DL[i].right].left = i;
			DL[DL[i].left].right = i;
			s[DL[i].ch]++;
		}
	}

	int H()
	{
		static int c, ret, i, j, time = 0;
		for (c = DL[head].right, ++time, ret = 0; c != head; c = DL[c].right)
		{
			if (used[c] != time)
			{
				ret++, used[c] = time;
				for (i = DL[c].down; i != c; i = DL[i].down)
				{
					for (j = DL[i].right; j != i; j = DL[j].right)
					{
						used[DL[j].ch] = time;
					}
				}
			}
		}
		return ret;
	}

	void dfs(int k)
	{
		if (k + H() >= ans)
		{
			return;
		}
		if (DL[head].right == head)
		{
			ans = min(ans, k);
			return;
		}
		int t = MAXV, c = 0, i, j;
		for (i = DL[head].right; i != head; i = DL[i].right)
		{
			if (s[i] < t)
			{
				t = s[i];
				c = i;
			}
		}
		for (i = DL[c].down; i != c; i = DL[i].down)
		{
			o[k] = i;
			rm(i);
			for (j = DL[i].right; j != i; j = DL[j].right)
			{
				rm(j);
			}
			dfs(k + 1);
			for (j = DL[i].left; j != i; j = DL[j].left)
			{
				resume(j);
			}
			resume(i);
			if (find_flag)
			{
				break;
			}
		}
	}

	int new_node(int up, int down, int left, int right)
	{
		// assert(size < MAXE);
		DL[size].up = up, DL[size].down = down;
		DL[size].left = left, DL[size].right = right;
		DL[up].down = DL[down].up = DL[left].right = DL[right].left = size;
		return size++;
	}

	void add_row(int n, int row[], int data)
	{
		int a, r, _row = -1, k;
		for (a = 0; a < n; a++)
		{
			r = row[a];
			DL[size].ch = r, s[r]++;
			DL[size].data = data;
			if (_row == -1)
			{
				_row = new_node(DL[DL[r].ch].up, DL[r].ch, size, size);
				DL[_row].rh = a;
			}
			else
			{
				k = new_node(DL[DL[r].ch].up, DL[r].ch, DL[_row].left, _row);
				DL[k].rh = a;
			}
		}
	}
} dlx;

int main()
{
	int T, n, m, x;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		// assert(n * n < MAXC);
		int lbl = 0, cover_col = 0, lbl_h[16][16], lbl_v[16][16], enable[2048];
		vector<int> g[2048];
		for (int i = 1; i <= n + 1; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				lbl_h[i][j] = ++lbl;
				enable[lbl] = 1;
			}
			for (int j = 1; j <= n + 1; j++)
			{
				lbl_v[i][j] = ++lbl;
				enable[lbl] = 1;
			}
		}
		for (int k = 0; k <= n; k++)
		{
			for (int i = 1; i + k <= n; i++)
			{
				for (int j = 1; j + k <= n; j++)
				{
					cover_col++;
					for (int l = 0; l <= k; l++)
					{
						g[lbl_h[i][j + l]].push_back(cover_col);
						g[lbl_h[i + 1 + k][j + l]].push_back(cover_col);
						g[lbl_v[i + l][j]].push_back(cover_col);
						g[lbl_v[i + l][j + 1 + k]].push_back(cover_col);
					}
				}
			}
		}
		dlx.init(cover_col);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &x);
			enable[x] = 0;
		}
		int cover[2048] = {}, row[2028], pre_cover = 0, row_sz = 0;
		for (int i = 1; i <= lbl; i++)
		{
			if (!enable[i] || g[i].size() == 0)
			{
				for (int j = 0; j < g[i].size(); j++)
				{
					cover[g[i][j]] = 1;
				}
				continue;
			}
			row_sz = 0;
			for (int j = 0; j < g[i].size(); j++)
			{
				row[row_sz++] = g[i][j];
			}
			dlx.add_row(row_sz, row, i);
		}
		row_sz = 0;
		for (int i = 1; i <= cover_col; i++)
		{
			if (cover[i])
			{
				row[row_sz++] = i;
				pre_cover = 1;
			}
		}
		if (pre_cover)
		{
			dlx.add_row(row_sz, row, lbl + 1);
		}
		dlx.ans = 0x3f3f3f3f;
		dlx.dfs(0);
		printf("%d\n", dlx.ans - pre_cover);
	}
	return 0;
}
