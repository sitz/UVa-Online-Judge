#include <bits/stdc++.h>

using namespace std;

#define For(i, a) for ((i) = 0; i < (a); ++(i))
#define Rep(i, v) for ((i) = (v).begin(); (v).end() != (i); ++i)
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define sz(a) (sizeof(a))
#define MEM(a) (memset((a), 0, sizeof(a)))
#define MEME(a) (memset((a), -1, sizeof(a)))
#define MEMX(a) (memset((a), 0x7f, sizeof(a)))
#define pb(a) push_back(a)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;

template <class T>
inline void checkmin(T &a, T b)
{
	if (a > b)
	{
		a = b;
	}
}
template <class T>
inline void checkmax(T &a, T b)
{
	if (a < b)
	{
		a = b;
	}
}

const int oo = 1 << 30;
const double eps = 1e-7;
const int N = 330000;
const int M = 20010;
const ll P = 10000000097ll;

//char s[N];  /// 长度+1，对于非字符串，加一个小于最小值的元素，
int sa[N];/// 倍增算法，结果 下标 1-n，第 i 大的是 sa[i]
int rk[N];/// 第 i 位开始的后缀，的排名为 rk[i]
int wa[N], wb[N], wv[N], rmq[20][N];
int to[N];

bool cmp(int *y, int a, int b, int L)
{
	return y[a] == y[b] && y[a + L] == y[b + L];
}

void da_(char *s, int *sa, int len, int dn)
{
	int i, j, p;
	int *x, *y, *t;
	x = wa;
	y = wb;
	For(i, dn) rk[i] = 0;
	For(i, len) rk[x[i] = s[i]]++;
	For(i, dn) rk[i + 1] += rk[i];
	for (i = len - 1; i >= 0; i--)
	{
		sa[--rk[x[i]]] = i;
	}
	for (j = 1, p = 1; p < len; j *= 2, dn = p)
	{
		For(p, j) y[p] = len - j + p;
		For(i, len) if (sa[i] >= j)
		{
			y[p++] = sa[i] - j;
		}
		For(i, len) wv[i] = x[y[i]];
		For(i, dn) rk[i] = 0;
		For(i, len) rk[wv[i]]++;
		For(i, dn) rk[i + 1] += rk[i];
		for (i = len - 1; i >= 0; i--)
		{
			sa[--rk[wv[i]]] = y[i];
		}
		swap(x, y);
		x[sa[0]] = 0;
		for (p = i = 1; i < len; i++)
		{
			p += !cmp(y, sa[i], sa[i - 1], j);
			x[sa[i]] = p - 1;
		}
	}
}

void da(char *s, int *sa, int len, int dn)
{
	int i, j, p;
	int *x, *y, *t;
	x = wa;
	y = wb;
	///For(i, len) x[i]=s[i],sa[i]=i;
	///sort(sa, sa+len, sacmp);
	/// 注意此时也应传入正确dn。
	For(i, dn) rk[i] = 0;
	For(i, len) rk[x[i] = s[i]]++;
	For(i, dn) rk[i + 1] += rk[i];
	for (i = len - 1; i >= 0; i--)
	{
		sa[--rk[x[i]]] = i;
	}
	for (j = 1, p = 1; p < len; j *= 2, dn = p)
	{
		For(p, j) y[p] = len - j + p;
		For(i, len) if (sa[i] >= j)
		{
			y[p++] = sa[i] - j;
		}
		For(i, len) wv[i] = x[y[i]];
		For(i, dn) rk[i] = 0;
		For(i, len) rk[wv[i]]++;
		For(i, dn) rk[i + 1] += rk[i];
		for (i = len - 1; i >= 0; i--)
		{
			sa[--rk[wv[i]]] = y[i];
		}
		swap(x, y);
		x[sa[0]] = 0;
		for (p = 1, i = 1; i < len; i++)/// 注意 (p-1):(p++)
		{
			x[sa[i]] = (cmp(y, sa[i], sa[i - 1], j) ? (p - 1) : (p++));
		}
		dn = p;
	}
}

void find_height(char *s, int *sa, int len)
{
	int *h = rmq[0];/// sa中为 i 的点，与 i-1 的最长公共前缀
	int i, j, k = 0;
	for (i = 1; i <= len; i++)
	{
		rk[sa[i]] = i;
	}
	For(i, len)
	{
		if (k > 0)
		{
			k--;
		}
		j = sa[rk[i] - 1];
		while (s[i + k] == s[j + k])
		{
			k++;
		}
		h[rk[i]] = k;
	}
}

void RMQ(int n)
{
	int i, j, k;
	int rn = floor(log(n * 2.0) / log(2.0));
	for (i = 1; i < rn; i++)
		For(j, n + 2 - (1 << (i - 1)))
				rmq[i][j] = MIN(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
}

int askRMQ(int a, int b)/// [a,b]闭区间
{
	///int rq = floor( log(b-a+0.0) / log(2.0) );
	if (a == b)
	{
		return 1 << 20;
	}
	a++;
	int rq = to[b - a];
	return MIN(rmq[rq][a], rmq[rq][b + 1 - (1 << rq)]);
}

void pre_log()
{
	int i;
	to[0] = to[1] = 0;
	for (i = 1; i * 2 < N; i++)
	{
		to[i * 2] = to[i * 2 + 1] = to[i] + 1;
	}
}

char str[N];
int sn;
int stn[M];
int val[M];
int tree[N * 4];
int n;

void suffix()
{
	da(str, sa, sn + 1, 128);
	find_height(str, sa, sn);
	RMQ(sn);
}

void find_lr(int id, int len, int &l, int &r)
{
	int low, high, mid;
	low = 0;
	high = id;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (askRMQ(mid, id) < len)
		{
			low = mid + 1;
		}
		else
		{
			high = mid;
		}
	}
	l = high;
	low = id;
	high = sn;
	while (low < high)
	{
		mid = (low + high + 1) / 2;
		if (askRMQ(id, mid) < len)
		{
			high = mid - 1;
		}
		else
		{
			low = mid;
		}
	}
	r = low;
}

int find_mx(int tk, int tl, int tr, int l, int r)
{
	if (l <= tl && tr <= r)
	{
		return tree[tk];
	}
	int mid = (tl + tr) / 2;
	int mx = 0;
	if (l <= mid)
	{
		checkmax(mx, find_mx(tk * 2, tl, mid, l, r));
	}
	if (r > mid)
	{
		checkmax(mx, find_mx(tk * 2 + 1, mid + 1, tr, l, r));
	}
	return mx;
}

void add_mx(int tk, int tl, int tr, int id, int val)
{
	checkmax(tree[tk], val);
	if (tl == tr)
	{
		return;
	}
	int mid = (tl + tr) / 2;
	if (id <= mid)
	{
		add_mx(tk * 2, tl, mid, id, val);
	}
	else
	{
		add_mx(tk * 2 + 1, mid + 1, tr, id, val);
	}
}

int work()
{
	int ret = 0;
	int start;
	start = sn;
	memset(tree, 0, sizeof(int) * 4 * N);
	for (int i = n - 1; i >= 0; i--)
	{
		start -= stn[i] + 1;
		int l, r;
		find_lr(rk[start], stn[i], l, r);
		int get = find_mx(1, 1, sn, l, r) + val[i];
		for (int j = 0; j < stn[i]; j++)
		{
			add_mx(1, 1, sn, rk[start + j], get);
		}
		checkmax(ret, get);
	}
	return ret;
}

int doit()
{
	sn = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s %d", str + sn, &val[i]);
		checkmax(val[i], 0);
		stn[i] = strlen(str + sn);
		sn += stn[i];
		str[sn++] = '$';
	}
	str[sn] = 0;
	suffix();
	return work();
}

int main()
{
	pre_log();
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int ans = doit();
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}

/**

Sample Input
2
5
a 1
ab 2
abb 3
baba 5
abbab 8
5
abbab 8
baba 5
abb 3
ab 2
a 1

Sample Output
Case #1: 14

**/
