#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define INF 0x5fffffff
#define rep(i, x, y) for (i = x; i <= y; i++)
#define reps(i, x, y) for (i = x; i >= y; i--)
#define sqr(x) ((x) * (x))

typedef long long LL;
typedef double DB;
typedef vector<int> VI;

struct node
{
	int val, pre, from, to;
};
vector<node> L;
const int dir[6][16] =
		{
				0, 0, 0, 1, 0, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 10,		//NW    1
				0, 0, 1, 0, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 10, 0,		//NE    2
				0, 0, 0, 2, 0, 4, 5, 0, 7, 8, 9, 0, 11, 12, 13, 14, //W     0
				0, 0, 3, 0, 5, 6, 0, 8, 9, 10, 0, 12, 13, 14, 15, 0,//E      3
				0, 2, 4, 5, 7, 8, 9, 11, 12, 13, 14, 0, 0, 0, 0, 0, //SW       5
				0, 3, 5, 6, 8, 9, 10, 12, 13, 14, 15, 0, 0, 0, 0, 0 //SE     4
																														//  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
};
int cnt = 0;
int hash_(bool *a)
{
	int val = 0, i;
	rep(i, 1, 15) val = val * 2 + a[i];
	assert(0 <= val && val <= 33000);
	return val;
}
void get(int val, bool *a)
{
	int i;
	reps(i, 15, 1) a[i] = val & 1, val >>= 1;
}
int mark[40000];
bool bo[20];
void Print(node t)
{
	VI ans;
	while (t.pre != -1)
	{
		ans.PB(t.to);
		ans.PB(t.from);
		t = L[t.pre];
	}
	printf("%d\n", ans.size() >> 1);
	for (int i = ans.size() - 1; i >= 1; i--)
	{
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[0]);
}
void solve()
{
	int i, j, k, l, q;
	cnt++;
	scanf("%d", &k);
	node t;
	t.pre = -1;
	memset(bo, 1, sizeof(bo));
	bo[k] = bo[0] = 0;
	t.val = hash_(bo);
	rep(i, 1, 15) bo[i] ^= 1;
	int mval = hash_(bo);
	L.clear();
	L.PB(t);
	for (l = 0; l < L.size(); l++)
	{
		t = L[l];
		get(t.val, bo);
		rep(i, 1, 15)
		{
			if (bo[i])
			{
				rep(k, 0, 5)
				{
					j = 0;
					int x = i;
					while (bo[x])
					{
						bo[x] = 0;
						j++;
						x = dir[k][x];
					}
					if (j >= 2 && x)
					{
						bo[x] = 1;
						t.val = hash_(bo);
						if (mark[t.val] != cnt)
						{
							t.from = i;
							t.to = x;
							t.pre = l;
							if (t.val == mval)
							{
								Print(t);
								return;
							}
							mark[t.val] = cnt;
							L.PB(t);
						}
						bo[x] = 0;
					}
					x = i;
					while (j--)
					{
						bo[x] = 1;
						x = dir[k][x];
					}
				}
			}
		}
	}
	puts("IMPOSSIBLE");
}

int main()
{
	int Case;
	scanf("%d", &Case);
	while (Case--)
	{
		solve();
	}
	return 0;
}
