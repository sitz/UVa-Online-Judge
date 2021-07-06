#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(i, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define DEC(i, s) for (int i = (s); i >= 0; i--)

#define SIZE(v) (int)((v).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define FIND(m, w) ((m).find(w) != (m).end())

int lsize, rsize;
int prime[210];
int factor[2][210];
int q[30][50];
int revq[30][50];
int qsize;
int iniplus;
map<ull, int> memo;

void printFactor()
{
	REP(i, lsize)
	{
		cout << factor[0][i] << " ";
	}
	cout << endl;
	REP(i, rsize)
	{
		cout << factor[1][i] << " ";
	}
	cout << endl;
}

inline ull nextSet(ull x)
{
	ull smallest = x & -x;
	ull ripple = x + smallest;
	ull new_smallest = ripple & -ripple;
	ull ones = ((new_smallest / smallest) >> 1) - 1;
	return ripple | ones;
}

inline int bsf(int n)
{
	int z;
	__asm__("bsf %1, %0;"
					: "=r"(z)
					: "r"(n));
	return z;
}

int calc(int depth, ull use, int minsize)
{
	if (memo.find(use) != memo.end())
	{
		return memo[use];
	}
	int size = 0;
	REP(i, qsize)
	{
		if ((use >> i) & 1)
		{
			continue;
		}
		q[depth + 1][size] = q[0][i];
		revq[depth + 1][size++] = i;
	}
	int ret = max(0, size - 1);
	FOREQ(i, minsize, size / 2)
	{
		int pexpect = 2 * ((qsize - size) / 3) + (qsize - size) % 3;
		int expect = (i - 1) * (size / i) + size % i;
		if (expect + pexpect + iniplus >= 20)
		{
			break;
		}
		if (ret <= expect)
		{
			break;
		}
		for (int bits = (1LL << i) - 1; bits < (1LL << size); bits = nextSet(bits))
		{
			ull v = bits;
			int sum = 0;
			ull nuse = 0;
			while (v)
			{
				int index = bsf(v);
				sum += q[depth + 1][index];
				nuse |= 1LL << revq[depth + 1][index];
				v -= v & -v;
			}
			if (sum == 0)
			{
				ret = min(ret, calc(depth + 1, nuse | use, i) + i - 1);
				if (ret <= expect)
				{
					break;
				}
			}
		}
	}
	return memo[use] = ret;
}

int main()
{
	MEMSET(prime, -1);
	for (int i = 2; i <= 200; i++)
	{
		if (prime[i] != -1)
		{
			continue;
		}
		for (int j = i; j <= 200; j += i)
		{
			prime[j] = i;
		}
	}
	int test;
	int test_case = 0;
	scanf("%d", &test);
	while (test--)
	{
		test_case++;
		MEMSET(factor, 0);
		REP(iter, 2)
		{
			int n;
			scanf("%d", &n);
			REP(i, n)
			{
				int num;
				scanf("%d", &num);
				while (num != 1)
				{
					int f = prime[num];
					num /= f;
					factor[iter][f]++;
				}
			}
		}
		FOREQ(i, 2, 200)
		{
			//cout << factor[0][i] << " " << factor[1][i] << endl;
			int m = min(factor[0][i], factor[1][i]);
			factor[0][i] -= m;
			factor[1][i] -= m;
		}
		iniplus = 0;
		FOREQ(i, 2, 200)
		{
			if (factor[0][i] == 0)
			{
				continue;
			}
			FOREQ(j, 2, 200)
			{
				if (factor[1][j] == 0)
				{
					continue;
				}
				if (factor[0][i] == factor[1][j])
				{
					factor[0][i] = 0;
					factor[1][j] = 0;
					iniplus++;
				}
			}
		}
		sort(factor[0], factor[0] + 200);
		sort(factor[1], factor[1] + 200);
		reverse(factor[0], factor[0] + 200);
		reverse(factor[1], factor[1] + 200);
		lsize = 0;
		rsize = 0;
		int lnum = 0;
		int rnum = 0;
		qsize = 0;
		while (factor[0][lsize] != 0)
		{
			q[0][qsize++] = factor[0][lsize];
			lnum += factor[0][lsize++];
		}
		while (factor[1][rsize] != 0)
		{
			q[0][qsize++] = -factor[1][rsize];
			rnum += factor[1][rsize++];
		}
		int ans = 20;
		memo.clear();
		if (lnum == rnum && qsize < 40 - 2 * iniplus)
		{
			ans = calc(0, 0, 3) + iniplus;
		}
		if (ans >= 20)
		{
			printf("Case %d: -1\n", test_case);
		}
		else
		{
			printf("Case %d: %d\n", test_case, ans);
		}
	}
}
