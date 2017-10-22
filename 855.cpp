#include <bits/stdc++.h>

using namespace std;

/*
855
Lunch in the Grid city
*/
#define MAXN 50002
int row[MAXN], col[MAXN];
int R, C, F;
int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void Cal()
{
	int a, b;
	if (F % 2)
	{
		a = F / 2;
		printf("(Street: %d, Avenue: %d)\n", row[a], col[a]);
	}
	else
	{
		a = F / 2;
		b = a - 1;
		printf("(Street: %d, Avenue: %d)\n", row[b], col[b]);
	}
}
int main()
{
	int k, i;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d%d%d", &R, &C, &F);
		for (i = 0; i < F; i++)
		{
			scanf("%d%d", &row[i], &col[i]);
		}
		qsort(row, F, sizeof(int), com);
		qsort(col, F, sizeof(int), com);
		Cal();
	}
	return 0;
}
