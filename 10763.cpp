#include <bits/stdc++.h>

using namespace std;

/*
Foreign Exchange
10763
*/
struct xx
{
	int x, y;
} X[500002], Y[500002];
int totalcount, N;
int com1(const void *a, const void *b)
{
	xx *p = (xx *)a;
	xx *q = (xx *)b;
	if (p->x != q->x)
	{
		return p->x - q->x;
	}
	return p->y - q->y;
}
void Cal()
{
	int i;
	qsort(X, N, sizeof(xx), com1);
	qsort(Y, N, sizeof(xx), com1);
	for (i = 0; i < N; i++)
	{
		if (X[i].x != Y[i].x || X[i].y != Y[i].y)
		{
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main()
{
	int i;
	while (scanf("%d", &N), N)
	{
		if (!N)
		{
			break;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%d%d", &X[i].x, &X[i].y);
			Y[i].x = X[i].y;
			Y[i].y = X[i].x;
		}
		Cal();
	}
	return 0;
}
