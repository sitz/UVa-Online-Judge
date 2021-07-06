#include <bits/stdc++.h>

using namespace std;

vector<int> stk[25]; // blks
int pos[25]; // curr pos of each blk

inline void blk_init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		stk[i].clear();
		stk[i].push_back(i);
	}
	for (int i = 0; i < n; ++i)
	{
		pos[i] = i;
	}
}

inline bool same_stk(int x, int y)
{
	return pos[x] == pos[y];
}

// clr all blks above 'x'
inline void clr_above(int x)
{
	int px = pos[x];
	while (stk[px].back() != x)
	{
		// place blk 'num' in its orig stk[num]
		int num = stk[px].back();
		stk[num].push_back(num);
		pos[num] = num;
		stk[px].pop_back();
	}
}

inline void mv(int x, int y)
{
	int px = pos[x], py = pos[y];
	vector<int>::iterator mv_begin, mv_end;
	mv_begin = find(stk[px].begin(), stk[px].end(), x);
	mv_end = stk[px].end();
	// append blks (mv_begin ~ mv_end) to end of stk[pos[y]]
	stk[py].insert(stk[py].end(), mv_begin, mv_end);
	// upd pos[]
	vector<int>::const_iterator it;
	for (it = mv_begin; it != mv_end; ++it)
	{
		pos[(*it)] = py;
	}
	stk[px].erase(mv_begin, mv_end);
}

inline void print_result(int num_blks)
{
	for (int i = 0; i < num_blks; ++i)
	{
		printf("%d:", i);
		for (int j = 0; j < (int)stk[i].size(); ++j)
		{
			printf(" %d", stk[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	int num_blks;
	scanf("%d", &num_blks);
	blk_init(num_blks);
	char cmd1[10], cmd2[10];
	int a, b;
	// [mv/pile] a [onto/over] b
	while (scanf("%s %d %s %d", cmd1, &a, cmd2, &b) == 4)
	{
		// ign invalid cmd
		if (a == b)
		{
			continue;
		}
		if (same_stk(a, b))
		{
			continue;
		}
		if (strcmp("mv", cmd1) == 0)
		{
			clr_above(a);
		}
		if (strcmp("onto", cmd2) == 0)
		{
			clr_above(b);
		}
		mv(a, b);
	}
	print_result(num_blks);
	return 0;
}
