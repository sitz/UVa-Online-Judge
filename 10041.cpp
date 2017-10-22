#include <bits/stdc++.h>

using namespace std;

#define MAXN 30001

int RELATIVE[MAXN];
long long DIFF, MID;

int sf(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void COM_DIFF(int N)
{
	int i;
	DIFF = 0;
	for (i = 0; i < N; i++)
	{
		DIFF += abs(RELATIVE[i] - MID);
	}
	printf("%lld\n", DIFF);
}

int main()
{
	int N, i, kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &RELATIVE[i]);
		}
		qsort(RELATIVE, N, sizeof(int), sf);
		int k = N / 2;
		if (N % 2 == 0)
		{
			MID = (RELATIVE[k - 1] + RELATIVE[k]) / 2;
		}
		else
		{
			MID = RELATIVE[k];
		}
		COM_DIFF(N);
	}
	return 0;
}
