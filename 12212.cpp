#include <bits/stdc++.h>

using namespace std;

//Md. Khairullah Gaurab
//CSE, SUST  20th
//gaurab.cse.sust@gmail.com

#define sf scanf
#define pf printf
#define mem(a, b) memset(a, b, sizeof(a))
#define am [pos][len][lnm][hnm][vall][valh]

typedef unsigned long long Long;

Long dp[22][22][2][2][2][2];
int vis[22][22][2][2][2][2], mxlen, L[22], H[22], cas;

int getLen(Long x)
{
	int len = 0;
	while (x)
	{
		len++;
		x /= 10;
	}
	return len;
}

Long rec(int pos, int len, int lnm, int hnm, int vall, int valh)
{
	Long &ret = dp am;
	if (vis am == cas)
	{
		return ret;
	}
	vis am = cas;
	if (pos == mxlen)
	{
		return ret = (vall && valh);
	}
	ret = 0;
	int nlen, a, b, c, d, st, en;
	st = lnm ? 0 : L[pos];
	en = hnm ? 9 : H[pos];
	for (int i = st; i <= en; i++)
	{
		nlen = (len == 0 and i == 0) ? 0 : len + 1;
		a = ((i > L[pos]) | lnm);
		b = ((i < H[pos]) | hnm);
		c = (!nlen || (vall and i == L[mxlen - 1 - len]) || (i > L[mxlen - 1 - len]));
		d = (nlen < pos + 1 || (valh and i == H[mxlen - 1 - len]) || i < H[mxlen - 1 - len]);
		ret += rec(pos + 1, nlen, a, b, c, d);
	}
	return ret;
}

int main(int argc, const char **argv)
{
	int test;
	char s[50];
	Long A, B;
	sf("%d", &test);
	for (cas = 1; cas <= test; cas++)
	{
		sf("%llu %llu", &A, &B);
		mxlen = getLen(B);
		sprintf(s, "%0*llu", mxlen, A);
		for (int i = 0; i < mxlen; ++i)
		{
			L[i] = s[i] - '0';
		}
		sprintf(s, "%0*llu", mxlen, B);
		for (int i = 0; i < mxlen; ++i)
		{
			H[i] = s[i] - '0';
		}
		pf("Case %d: %llu\n", cas, rec(0, 0, 0, 0, 1, 1));
	}
	return 0;
}
