#include <bits/stdc++.h>

using namespace std;

#define MAXN 500002

int N, p[MAXN], Temp[MAXN];
long long cnt;

void Cal(int a, int b)
{
	int md, below, mdi, ni, i;
	if (a >= b)
	{
		return;
	}
	md = p[a + (b - a) / 2];
	for (mdi = i = a; i < b; i++)
	{
		if (p[i] < md)
		{
			mdi++;
		}
	}
	below = mdi - a;
	for (ni = i = a; i < b; i++)
	{
		if (p[i] < md)
		{
			Temp[ni++] = p[i];
			below--;
		}
		else
		{
			Temp[mdi++] = p[i];
			cnt += below;
		}
	}
	for (mdi = a; Temp[mdi] != md; mdi++)
		;
	for (mdi; mdi && Temp[mdi - 1] > md; mdi--)
	{
		int tmp = Temp[mdi - 1];
		Temp[mdi - 1] = Temp[mdi];
		Temp[mdi] = tmp;
		cnt++;
	}
	for (i = a; i < b; i++)
	{
		p[i] = Temp[i];
	}
	Cal(a, mdi);
	while (mdi < b && p[mdi] == md)
	{
		mdi++;
	}
	Cal(mdi, b);
}

int main()
{
	int i;
	while (scanf("%d", &N) && N)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d", &p[i]);
		}
		cnt = 0;
		Cal(0, N);
		printf("%lld\n", cnt);
	}
	return 0;
}
