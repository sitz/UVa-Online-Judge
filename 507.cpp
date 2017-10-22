#include <bits/stdc++.h>

using namespace std;

/*
Jill Rides Again
507
*/
#define MAXN 20002
int stop, maxlen, maxst, maxend, maxval;
int Nice[MAXN];
struct ss
{
	int val;
	int st;
} table[MAXN];
void Dynamic()
{
	int i, j, k;
	table[1].val = Nice[1];
	table[1].st = 1;
	maxval = Nice[1];
	maxlen = maxst = maxend = 1;
	for (i = 2; i <= stop - 1; i++)
	{
		k = Nice[i] + table[i - 1].val;
		if (k >= Nice[i])
		{
			table[i].val = k;
			table[i].st = table[i - 1].st;
			j = i - table[i].st + 1;
			if (table[i].val > maxval)
			{
				maxval = table[i].val;
				maxlen = i - table[i].st + 1;
				maxend = i;
				maxst = table[i].st;
			}
			else if (table[i].val == maxval && maxlen < j)
			{
				maxlen = i - table[i].st + 1;
				maxend = i;
				maxst = table[i].st;
			}
		}
		else
		{
			table[i].val = Nice[i];
			table[i].st = i;
			if (table[i].val > maxval)
			{
				maxval = table[i].val;
				maxlen = i - table[i].st + 1;
				maxend = i;
				maxst = table[i].st;
			}
		}
	}
}
int main()
{
	int route, i, j;
	scanf("%d", &route);
	for (i = 1; i <= route; i++)
	{
		scanf("%d", &stop);
		for (j = 1; j <= stop - 1; j++)
		{
			scanf("%d", &Nice[j]);
		}
		Dynamic();
		if (maxval > 0)
		{
			printf("The nicest part of route %d is between stops %d and %d\n", i, maxst, maxend + 1);
		}
		else
		{
			printf("Route %d has no nice parts\n", i);
		}
	}
	return 0;
}
