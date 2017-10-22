#include <bits/stdc++.h>

using namespace std;

/*
11029
*/

typedef long SS;
SS Table[100001];
char Fg[100001];
SS N, K;
long Recur(SS P, SS base, SS mod)
{
	SS l, r, d;
	if (P == 1)
	{
		return base % mod;
	}
	if (P == 0)
	{
		return 1;
	}
	if (P <= 100000)
	{
		if (Fg[P] == 1)
		{
			return Table[P];
		}
	}
	if (P % 2)
	{
		l = Recur(P / 2, base, mod) % mod;
		r = Recur(P / 2 + 1, base, mod) % mod;
		d = l * r;
		d %= mod;
	}
	else
	{
		d = Recur(P / 2, base, mod) % mod;
		d *= d;
		d %= mod;
	}
	if (P <= 100000)
	{
		Fg[P] = 1;
		Table[P] = d;
	}
	return d;
}
void First()
{
	double X;
	SS m, i, d = 0;
	char dig[100];
	X = (double)K * log10(N);
	m = (SS)X;
	X -= (double)m;
	X = pow(10, X);
	sprintf(dig, "%lf", X);
	for (i = 0; dig[i] && d < 3; i++)
	{
		if (dig[i] != '.')
		{
			printf("%c", dig[i]);
			d++;
		}
	}
}
void Cal()
{
	SS x;
	First();
	x = Recur(K, N, 1000);
	printf("...");
	printf("%03ld\n", x);
}
void Free()
{
	int i;
	for (i = 0; i <= K && i < 100001; i++)
	{
		Fg[i] = 0;
	}
}
int main()
{
	SS ks;
	cin >> ks;
	while (ks--)
	{
		cin >> N >> K;
		Cal();
		Free();
	}
	return 0;
}
