#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b :)
#define MAXN 1000000

int N, MAX, LIMIT, SEQ[MAXN], TEMP[MAXN], Par[MAXN];

// binary search
int FIND_BEST(int key)
{
	int lo, up, mid;
	lo = 1;
	up = LIMIT;
	mid = (lo + up) / 2;
	if (SEQ[TEMP[1]] > key)
		return 1;
	else if (SEQ[TEMP[LIMIT]] < key)
		return LIMIT + 1;
	while (lo < up && SEQ[TEMP[mid]] != key)
	{
		if (SEQ[TEMP[mid]] < key)
			lo = mid + 1;
		else if (SEQ[TEMP[mid]] > key)
		{
			if (SEQ[TEMP[mid - 1]] < key)
				return mid;
			up = mid - 1;
		}
		mid = (lo + up) / 2;
	}
	return mid;
}

void FIND_LIS()
{
	int pos, i;
	TEMP[1] = 0;
	LIMIT = 1;
	Par[0] = -1;
	TEMP[0] = -1;
	for (i = 1; i < N; i++)
	{
		pos = FIND_BEST(SEQ[i]);
		if (pos > LIMIT)
		{
			LIMIT = pos;
			TEMP[pos] = i;
			Par[i] = TEMP[pos - 1];
		}
		else if (SEQ[TEMP[pos]] > SEQ[i])
		{
			TEMP[pos] = i;
			Par[i] = TEMP[pos - 1];
		}
	}
}

void Print(int n)
{
	if (Par[n] == -1)
	{
		printf("%d\n", SEQ[n]);
		return;
	}
	Print(Par[n]);
	printf("%d\n", SEQ[n]);
}

int main()
{
	N = 0;
	int n;
	while (scanf("%d", &n) == 1)
		SEQ[N++] = n;
	FIND_LIS();
	printf("%d\n", LIMIT);
	printf("-\n");
	Print(TEMP[LIMIT]);
	return 0;
}
