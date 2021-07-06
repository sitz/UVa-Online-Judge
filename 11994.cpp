#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define DWN(i, b, a) for (int i = int(b - 1); i >= int(a); --i)
#define REP_1(i, n) for (int i = 1; i <= int(n); ++i)
#define FOR_1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define DWN_1(i, b, a) for (int i = int(b); i >= int(a); --i)
#define REP_C(i, n) for (int n____ = int(n), i = 0; i < n____; ++i)
#define FOR_C(i, a, b) for (int b____ = int(b), i = a; i < b____; ++i)
#define DWN_C(i, b, a) for (int a____ = int(a), i = b - 1; i >= a____; --i)
#define REP_N(i, n) for (i = 0; i < int(n); ++i)
#define FOR_N(i, a, b) for (i = int(a); i < int(b); ++i)
#define DWN_N(i, b, a) for (i = int(b - 1); i >= int(a); --i)
#define REP_1_C(i, n) for (int n____ = int(n), i = 1; i <= n____; ++i)
#define FOR_1_C(i, a, b) for (int b____ = int(b), i = a; i <= b____; ++i)
#define DWN_1_C(i, b, a) for (int a____ = int(a), i = b; i >= a____; --i)
#define REP_1_N(i, n) for (i = 1; i <= int(n); ++i)
#define FOR_1_N(i, a, b) for (i = int(a); i <= int(b); ++i)
#define DWN_1_N(i, b, a) for (i = int(b); i >= int(a); --i)
#define REP_C_N(i, n) for (n____ = int(n), i = 0; i < n____; ++i)
#define FOR_C_N(i, a, b) for (b____ = int(b), i = a; i < b____; ++i)
#define DWN_C_N(i, b, a) for (a____ = int(a), i = b - 1; i >= a____; --i)
#define REP_1_C_N(i, n) for (n____ = int(n), i = 1; i <= n____; ++i)
#define FOR_1_C_N(i, a, b) for (b____ = int(b), i = a; i <= b____; ++i)
#define DWN_1_C_N(i, b, a) for (a____ = int(a), i = b; i >= a____; --i)

#define DO(n) while (n--)
#define DO_C(n)  \
	int n____ = n; \
	while (n____--)
#define TO(i, a, b)                     \
	int s_ = a < b ? 1 : -1, b_ = b + s_; \
	for (int i = a; i != b_; i += s_)
#define TO_1(i, a, b)              \
	int s_ = a < b ? 1 : -1, b_ = b; \
	for (int i = a; i != b_; i += s_)
#define SQZ(i, j, a, b) for (int i = int(a), j = int(b) - 1; i < j; ++i, --j)
#define SQZ_1(i, j, a, b) for (int i = int(a), j = int(b); i <= j; ++i, --j)
#define REP_2(i, j, n, m) REP(i, n) \
							REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) \
								REP_1(j, m)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, X) find(ALL(A), X)// != A.end()
#define CTN(T, x) (T.find(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define Rush \
	int T____; \
	RD(T____); \
	DO(T____)
#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize("O2")
#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Pascal system("fpc main.pas")

/** I/O Accelerator **/

/* ... :" We are I/O Accelerator ... Use us at your own risk;) ... " .. */

template <class T>
inline void RD(T &);
template <class T>
inline void OT(const T &);

inline int RD()
{
	int x;
	RD(x);
	return x;
}
template <class T>
inline T &_RD(T &x)
{
	RD(x);
	return x;
}

template <class T0, class T1>
inline void RD(T0 &x0, T1 &x1)
{
	RD(x0)
	, RD(x1);
}
template <class T0, class T1, class T2>
inline void RD(T0 &x0, T1 &x1, T2 &x2)
{
	RD(x0)
	, RD(x1), RD(x2);
}
template <class T0, class T1, class T2, class T3>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3)
{
	RD(x0)
	, RD(x1), RD(x2), RD(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4)
{
	RD(x0)
	, RD(x1), RD(x2), RD(x3), RD(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5)
{
	RD(x0)
	, RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6)
{
	RD(x0)
	, RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
}
template <class T0, class T1>
inline void OT(T0 &x0, T1 &x1)
{
	OT(x0)
	, OT(x1);
}
template <class T0, class T1, class T2>
inline void OT(T0 &x0, T1 &x1, T2 &x2)
{
	OT(x0)
	, OT(x1), OT(x2);
}
template <class T0, class T1, class T2, class T3>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3)
{
	OT(x0)
	, OT(x1), OT(x2), OT(x3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4)
{
	OT(x0)
	, OT(x1), OT(x2), OT(x3), OT(x4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5)
{
	OT(x0)
	, OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6)
{
	OT(x0)
	, OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);
}

template <class T>
inline void RST(T &A)
{
	memset(A, 0, sizeof(A));
}
template <class T0, class T1>
inline void RST(T0 &A0, T1 &A1)
{
	RST(A0)
	, RST(A1);
}
template <class T0, class T1, class T2>
inline void RST(T0 &A0, T1 &A1, T2 &A2)
{
	RST(A0)
	, RST(A1), RST(A2);
}
template <class T0, class T1, class T2, class T3>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3)
{
	RST(A0)
	, RST(A1), RST(A2), RST(A3);
}
template <class T0, class T1, class T2, class T3, class T4>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4)
{
	RST(A0)
	, RST(A1), RST(A2), RST(A3), RST(A4);
}
template <class T0, class T1, class T2, class T3, class T4, class T5>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5)
{
	RST(A0)
	, RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);
}
template <class T0, class T1, class T2, class T3, class T4, class T5, class T6>
inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6)
{
	RST(A0)
	, RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);
}

/** Add - On **/

// <<= ` 0. Daily Use .,

template <class T>
inline void checkMin(T &a, const T b)
{
	if (b < a)
	{
		a = b;
	}
}
template <class T>
inline void checkMax(T &a, const T b)
{
	if (b > a)
	{
		a = b;
	}
}
template <class T, class C>
inline void checkMin(T &a, const T b, C c)
{
	if (c(b, a))
	{
		a = b;
	}
}
template <class T, class C>
inline void checkMax(T &a, const T b, C c)
{
	if (c(a, b))
	{
		a = b;
	}
}
template <class T>
inline T min(T a, T b, T c)
{
	return min(min(a, b), c);
}
template <class T>
inline T max(T a, T b, T c)
{
	return max(max(a, b), c);
}
template <class T>
inline T sqr(T a)
{
	return a * a;
}
template <class T>
inline T cub(T a)
{
	return a * a * a;
}
int Ceil(int x, int y)
{
	return (x - 1) / y + 1;
}

// <<= ` 1. Bitwise Operation .,

inline bool _1(int x, int i)
{
	return x & 1 << i;
}
inline int _1(int i)
{
	return 1 << i;
}
inline int _U(int i)
{
	return _1(i) - 1;
};

inline int count_bits(int x)
{
	x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
	x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
	x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
	x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
	x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
	return x;
}

template <class T>
inline T low_bit(T x)
{
	return x & -x;
}

template <class T>
inline T high_bit(T x)
{
	T p = low_bit(x);
	while (p != x)
	{
		x -= p, p = low_bit(x);
	}
	return p;
}

// <<= ' 0. I/O Accelerator interface .,

template <class T>
inline void RD(T &x)
{
	//cin >> x;
	//scanf("%d", &x);
	char c;
	for (c = getchar(); c < '0'; c = getchar())
		;
	x = c - '0';
	for (c = getchar(); c >= '0'; c = getchar())
	{
		x = x * 10 + c - '0';
	}
	//char c; c = getchar(); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
}

inline void OT(int a, int b)
{
	printf("%d %d\n", a, b);
}

/* .................................................................................................................................. */

const int N = 50009;

int l[N], r[N], p[N], sz[N], color[N], delay[N], mask[N];
bool rt[N];
int n, m;

#define lx l[x]
#define rx r[x]

inline void Paint(int x, int c)
{
	if (x == 0)
	{
		return;
	}
	color[x] = delay[x] = mask[x] = c;
}

inline void Release(int x)
{
	if (x == 0 || !delay[x])
	{
		return;
	}
	Paint(lx, delay[x]), Paint(rx, delay[x]);
	delay[x] = 0;
}

inline void Update(int x)
{
	sz[x] = sz[lx] + sz[rx] + 1;
	mask[x] = color[x] | mask[lx] | mask[rx];
}

inline void Set(int l[], int y, int x)
{
	l[y] = x, p[x] = y;
}

inline void Rotate(int x)
{
	int y = p[x], z = p[y];
	if (!rt[y])
	{
		Release(z), Set(y == l[z] ? l : r, z, x);
	}
	else
	{
		p[x] = z;
	}
	Release(y), Release(x);
	if (x == l[y])
	{
		Set(l, y, rx), Set(r, x, y);
	}
	else
	{
		Set(r, y, lx), Set(l, x, y);
	}
	if (rt[y])
	{
		rt[y] = false, rt[x] = true;
	}
	Update(y);
}

inline void Splay(int x)
{
	while (!rt[x])
	{
		Rotate(x);
	}
}

int Access(int x)
{
	int y = 0;
	do
	{
		Splay(x), Release(x);
		rt[rx] = true, rt[rx = y] = false;
		Update(x);
		x = p[y = x];
	} while (x);
	return y;
}

inline int Root(int x)
{
	for (x = Access(x); lx; x = lx)
		;
	return x;
}

inline int Depth(int x)
{
	return sz[Access(x)];
}

inline int Lca(int x, int y)
{
	int lca;
	Access(y);
	y = 0;
	do
	{
		Splay(x), Release(x);
		if (!p[x])
		{
			lca = x;
		}
		rt[rx] = true, rt[rx = y] = false, Update(x);
		x = p[y = x];
	} while (x);
	return lca;
}

// Public :

void Query(int x, int y)
{
	if (x == y || Root(x) != Root(y))
	{
		OT(0, 0);
		return;
	}
	Access(y);
	y = 0;
	do
	{
		Splay(x), Release(x);
		if (!p[x])
		{
			OT(sz[rx] + sz[y], count_bits(mask[rx] | mask[y]));
		}
		rt[rx] = true, rt[rx = y] = false, Update(x);
		x = p[y = x];
	} while (x);
}

void Paint(int x, int y, int c)
{
	if (Root(x) != Root(y))
	{
		return;
	}
	c = _1(c - 1), Access(y);
	y = 0;
	do
	{
		Splay(x), Release(x);
		if (!p[x])
		{
			Paint(rx, c), Paint(y, c);
		}
		rt[rx] = true, rt[rx = y] = false, Update(x);
		x = p[y = x];
	} while (x);
}

void Link(int x, int y, int c)
{
	if (x == y || Root(x) == Root(y) && Lca(x, y) == x)
	{
		return;
	}
	c = _1(c - 1), Access(x), Splay(x), rt[lx] = true;
	lx = p[lx] = 0, p[x] = y, Paint(x, c), Update(x);
	Access(x);
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		REP_1(i, n)
		sz[i] = 1,
		rt[i] = true, RD(p[i]);
		REP_1(i, n)
		color[i] = mask[i] = _1(RD() - 1);

		int op, a, b, c;
		DO(m)
		{
			RD(op);
			if (op == 3)
			{
				RD(a, b)
				, Query(a, b);
			}
			else if (op == 2)
			{
				RD(a, b, c)
				, Paint(a, b, c);
			}
			else
			{
				RD(a, b, c)
				, Link(a, b, c);
			}
		}

		RST(p, l, r, delay);
	}
	return 0;
}
