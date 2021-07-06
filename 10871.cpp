#include <bits/stdc++.h>

using namespace std;

/*
10871
*/
#define maxn 10000000

char sv[maxn + 2];
int V[10000];
void Prime()
{
	int i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j < maxn; j += i)
		{
			sv[j] = 1;
		}
		for (++i; sv[i]; i++)
			;
	}
}
void Cal(int ind)
{
	int i, sum, min = 1000000, j, f = 1, l, r;
	for (i = 0; i < ind; i++)
	{
		sum = V[i];
		for (j = i + 1; j < ind; j++)
		{
			if (j - i + 1 >= min)
			{
				break;
			}
			sum += V[j];
			if (sv[sum] == 0)
			{
				min = j - i + 1;
				l = i;
				r = j;
				f = 0;
			}
		}
	}
	if (f)
	{
		printf("This sequence is anti-primed.\n");
		return;
	}
	printf("Shortest primed subsequence is length %d:", min);
	for (i = l; i <= r; i++)
	{
		printf(" %d", V[i]);
	}
	printf("\n");
}
int main()
{
	int ks, d;
	Prime();
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d", &d);
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &V[i]);
		}
		Cal(d);
		//V.clear();
	}
	return 0;
}
