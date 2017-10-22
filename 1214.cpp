#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define inf 0x3fffffff
#define N 13
#define MOD 60007
#define STA 1000010

int n, m, S;
struct HashMap
{
	int hd[MOD], nxt[STA], sta[STA], f[STA], size;
	void init()
	{
		size = 0;
		memset(hd, -1, sizeof(hd));
	}
	void add(int s, int a)
	{
		int h = s % MOD;
		for (int i = hd[h]; i + 1; i = nxt[i])
		{
			if (sta[i] == s)
			{
				f[i] = min(f[i], a);
				return;
			}
		}
		nxt[size] = hd[h];
		sta[size] = s;
		f[size] = a;
		hd[h] = size++;
		return;
	}
} hs[2];

int mmap[N][N];
int solve()
{
	S = (1 << ((m + 1) << 1)) - 1;
	int cur = 0;
	hs[0].init();
	hs[0].add(0, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			hs[cur = !cur].init();
			for (int k = 0; k < hs[cur ^ 1].size; k++)
			{
				int s = hs[cur ^ 1].sta[k];
				int fk = hs[cur ^ 1].f[k] + 1;
				int x = (3 << (j << 1)) & s;
				int y = (3 << ((j + 1) << 1)) & s;
				int left = x >> (j << 1);
				int up = y >> ((j + 1) << 1);
				if (mmap[i][j] == 1)
				{
					if (left == 0 && up == 0)
					{
						hs[cur].add(s, fk - 1);
						if (mmap[i + 1][j] && mmap[i][j + 1])
						{
							hs[cur].add(s | (2 << (j << 1)) | (2 << ((j + 1) << 1)), fk);
							hs[cur].add(s | (3 << (j << 1)) | (3 << ((j + 1) << 1)), fk);
						}
					}
					else if (left == up && left)
					{
						hs[cur].add(s ^ x ^ y, fk);
					}
					else if ((left == 0 && up == 2) || (left == 2 && up == 0))
					{
						if (mmap[i + 1][j])
							hs[cur].add(s ^ y | (2 << (j << 1)), fk);
						if (mmap[i][j + 1])
							hs[cur].add(s ^ x | (2 << ((j + 1) << 1)), fk);
					}
					else if ((left == 0 && up == 3) || (left == 3 && up == 0))
					{
						if (mmap[i + 1][j])
							hs[cur].add(s ^ y | (3 << (j << 1)), fk);
						if (mmap[i][j + 1])
							hs[cur].add(s ^ x | (3 << ((j + 1) << 1)), fk);
					}
				}
				else if (mmap[i][j] == 2)
				{
					if (left == 2 && up == 0)
						hs[cur].add(s ^ x, fk);
					else if (left == 0 && up == 2)
						hs[cur].add(s ^ y, fk);
					else if (left == 0 && up == 0)
					{
						if (mmap[i + 1][j] == 1 || mmap[i + 1][j] == 2)
							hs[cur].add(s | (2 << (j << 1)), fk);
						if (mmap[i][j + 1] == 1 || mmap[i][j + 1] == 2)
							hs[cur].add(s | (2 << ((j + 1) << 1)), fk);
					}
				}
				else if (mmap[i][j] == 3)
				{
					if (left == 3 && up == 0)
						hs[cur].add(s ^ x, fk);
					else if (left == 0 && up == 3)
						hs[cur].add(s ^ y, fk);
					else if (left == 0 && up == 0)
					{
						if (mmap[i + 1][j] == 1 || mmap[i + 1][j] == 3)
							hs[cur].add(s | (3 << (j << 1)), fk);
						if (mmap[i][j + 1] == 1 || mmap[i][j + 1] == 3)
							hs[cur].add(s | (3 << ((j + 1) << 1)), fk);
					}
				}
				else
				{
					if (left == 0 && up == 0)
						hs[cur].add(s, fk - 1);
				}
			}
		}
		hs[cur ^ 1].init();
		for (int i = 0; i < hs[cur].size; i++)
			hs[cur ^ 1].add((hs[cur].sta[i] << 2) & S, hs[cur].f[i]);
		cur ^= 1;
	}
	cur ^= 1;
	for (int i = 0; i < hs[cur].size; i++)
		if (hs[cur].sta[i] == 0)
			return hs[cur].f[i] - 2;
	return 0;
}

int main()
{

	int ans;
	while (scanf("%d%d", &n, &m) != EOF && (m || n))
	{

		memset(mmap, 0, sizeof(mmap));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &mmap[i][j]);
				if (mmap[i][j] < 2)
					mmap[i][j] ^= 1;
			}

		ans = solve();
		printf("%d\n", ans);
	}
}
