#include <bits/stdc++.h>

using namespace std;

/***************************
TITLE : LET ME COUNT THE WAY
   NO : 357
****************************/
#define MAXTOTAL 30002
long long nway[MAXTOTAL];
int coin[5] = {50, 25, 10, 5, 1};
void Cal()
{
	int i, j, c, v;
	v = 5;
	nway[0] = 1;
	for (i = 0; i < v; i++)
	{
		c = coin[i];
		for (j = c; j <= 30000; j++)
		{
			nway[j] += nway[j - c];
		}
	}
}
int main()
{
	int n;
	Cal();
	while (scanf("%d", &n) == 1)
	{
		if (nway[n] > 1)
		{
			printf("There are %lld ways to produce %d cents change.\n", nway[n], n);
		}
		else
		{
			printf("There is only 1 way to produce %d cents change.\n", n);
		}
	}
	return 0;
}
