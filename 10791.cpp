#include <bits/stdc++.h>

using namespace std;

/*
LCM
*/
#define MAX 2147483647
#define MAXN 46342
typedef long long ss;
char sv[MAXN];
int P[5000], tp, N;
void Prime_table()
{
	tp = 1;
	int i, j;
	for (i = 2; i * i <= MAXN;)
	{
		for (j = i + i; j <= MAXN; j += i)
		{
			sv[j] = 1;
		}
		for (i++; sv[i]; i++)
			;
	}
	P[0] = 2;
	for (i = 3; i < MAXN; i += 2)
		if (sv[i] == 0)
		{
			P[tp++] = i;
		}
}
ss Cal()
{
	int i, c, f = 0;
	ss total = 0, temp = N;
	for (i = 0; P[i] * P[i] <= N && i < tp; i++)
	{
		if (N % P[i] == 0)
		{
			f++;
			c = 1;
			while (N % P[i] == 0)
			{
				N /= P[i];
				c *= P[i];
			}
			total += c;
		}
	}
	if (N > 1)
	{
		f++;
	}
	if (f <= 1)
	{
		return temp + 1;
	}
	if (N > 1)
	{
		total += N;
	}
	return total;
}
int main()
{
	int k = 1;
	Prime_table();
	while (scanf("%d", &N) && N)
	{
		printf("Case %d: ", k++);
		printf("%lld\n", Cal());
	}
	return 0;
}
