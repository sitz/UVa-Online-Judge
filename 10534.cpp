#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a);
#define MAXN 10005

int SEQ[MAXN], TEMP[MAXN], ORDER[MAXN], N, MAX, LIMIT;

// binary search
int FIND_BEST(int key)
{
	int lo, up, mid;
	lo = 1;
	up = LIMIT;
	mid = (lo + up) / 2;
	if (TEMP[1] > key)
	{
		return 1;
	}
	else if (TEMP[LIMIT] < key)
	{
		return LIMIT + 1;
	}
	else if (TEMP[LIMIT] == key)
	{
		return LIMIT;
	}
	while (lo < up && TEMP[mid] != key)
	{
		if (TEMP[mid] < key)
		{
			lo = mid + 1;
		}
		else if (TEMP[mid] > key)
		{
			if (TEMP[mid - 1] < key)
			{
				return mid;
			}
			up = mid - 1;
		}
		mid = (lo + up) / 2;
	}
	return mid;
}

void FIND_LIS()
{
	int i, pos;
	TEMP[1] = SEQ[0];
	ORDER[0] = 1;
	LIMIT = 1;
	for (i = 1; i < N; i++)
	{
		pos = FIND_BEST(SEQ[i]);
		if (pos > LIMIT)
		{
			LIMIT = pos;
			TEMP[pos] = SEQ[i];
		}
		else if (TEMP[pos] > SEQ[i])
		{
			TEMP[pos] = SEQ[i];
		}
		ORDER[i] = pos;
	}
}

void FIND_LDS()
{
	int i, pos, lis;
	MAX = 1;
	LIMIT = 1;
	TEMP[1] = SEQ[N - 1];
	for (i = N - 2; i >= 0; i--)
	{
		pos = FIND_BEST(SEQ[i]);
		if (pos > LIMIT)
		{
			LIMIT = pos;
			TEMP[pos] = SEQ[i];
		}
		else if (TEMP[pos] > SEQ[i])
		{
			TEMP[pos] = SEQ[i];
		}
		lis = MIN(ORDER[i], pos);
		if (lis > MAX)
		{
			MAX = lis;
		}
	}
	printf("%d\n", MAX * 2 - 1);
}

int main()
{
	int i;
	while (scanf("%d", &N) == 1)
	{
		for (i = 0; i < N; i++)
		{
			scanf("%d", &SEQ[i]);
		}
		FIND_LIS();
		FIND_LDS();
	}
	return 0;
}
