#include <bits/stdc++.h>

using namespace std;

/***********************
TITLE : COUNT ON COUNTOR
   NO : 264
***********************/
int N;
int STEP(int n)
{
	int j = 0, i;
	int sum = 0;
	for (i = 1; sum < n; i++)
	{
		sum += i;
		j++;
	}
	return j;
}
void UPDOWN(int m)
{
	int k;
	int d = m, n = 1;
	k = m * (m + 1) / 2;
	while (1)
	{
		if (k == N)
		{
			break;
		}
		d--;
		n++;
		k--;
	}
	printf("TERM %d IS %d/%d\n", N, d, n);
}
void DOWNUP(int m)
{
	int k;
	int d = 1, n = m;
	k = m * (m + 1) / 2;
	while (1)
	{
		if (k == N)
		{
			break;
		}
		d++;
		n--;
		k--;
	}
	printf("TERM %d IS %d/%d\n", N, d, n);
}
int main()
{
	int j;
	while (scanf("%d", &N) == 1)
	{
		if (N == 1)
		{
			printf("TERM 1 IS 1/1\n");
			continue;
		}
		j = STEP(N);
		if (j % 2 == 0)
		{
			UPDOWN(j);
		}
		else
		{
			DOWNUP(j);
		}
	}
	return 0;
}
