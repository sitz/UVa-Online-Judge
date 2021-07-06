#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

const int DIGITS = 70;
const int BASE = 100000000;
const int LOG10BASE = 8;
struct BigInt
{
	int num[DIGITS], last;

	BigInt(int v = 0)
	{
		clear();
		num[0] = v;
		last = 1;
		carry();
	}
	BigInt(BigInt *b)
	{
		FOR(i, 0, b->last)
		num[i] = b->num[i];
	}

	inline void clear()
	{
		FOR(i, 0, DIGITS)
		num[i] = 0;
	}
	inline void carry()
	{
		int c = 0;
		FOR(i, 0, last)
		{
			c = (num[i] += c) / BASE;
			num[i] %= BASE;
		}
		while (c)
		{
			num[last++] = c % BASE;
			c /= BASE;
		}
	}
	inline void show()
	{
		int i = last;
		printf("%d", num[--i]);
		while (i--)
			printf("%0*d", LOG10BASE, num[i]);
		puts("");
	}
	inline string to_string()
	{
		string res;

		int i = last;
		stringstream ss;
		ss << num[--i];
		string str = ss.str();
		res += str;

		while (i--)
		{
			char tmp[LOG10BASE + 1];
			sprintf(tmp, "%0*d", LOG10BASE, num[i]);
			res += tmp;
		}

		return res;
	}

	BigInt operator+=(const BigInt &b)
	{
		last = max(last, b.last);
		FOR(i, 0, last)
		num[i] += b.num[i];
		carry();
		return *this;
	}
	BigInt operator++(const int b)
	{
		return *this += 1;
	}
};

#define MAXN 2000

const int mxs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

static BigInt dp[MAXN + 5];

int main()
{
	// init
	FOREQ(i, 0, MAXN)
	dp[i] = 0;

	// base case: 1-9 (not 0)
	//	dp[2] = dp[3] = dp[4] = dp[7] = 1, dp[6] = 2, dp[5] = 3;
	FOREQ(i, 1, 9)
	dp[mxs[i]] += 1;

	// recursive
	/*
	FOR(i, 2, 2001)
	{
		FOR(j, 0, 10)
			dp[i+mxs[j]] += dp[i];
		dp[i] += i == 6;
		dp[i] += dp[i-1];
	}
*/
	FOREQ(i, 1, MAXN)
	FOREQ(j, 0, 9)
	dp[i + mxs[j]] += dp[i];
	dp[6]++;
	FOREQ(i, 1, MAXN)
	dp[i] += dp[i - 1];

	// answer query
	for (int n; scanf("%d", &n) == 1; dp[n].show())
		;

	return 0;
}
