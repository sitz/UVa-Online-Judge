#include <bits/stdc++.h>

using namespace std;

#define LEN 100

int left_[LEN], right_[LEN];

void stat(int n)
{
	int tmp;
	scanf("%d", &tmp);
	if (tmp != -1)
	{
		if (n > 0)
		{
			right_[n] += tmp;
		}
		else
		{
			left_[-n] += tmp;
		}
		stat(n - 1);
		stat(n + 1);
	}
}

void build(int weight)
{
	int i, n;
	memset(left_, 0, sizeof(left_));
	memset(right_, 0, sizeof(right_));
	left_[0] = weight;
	stat(-1);
	stat(1);
	for (i = LEN; i > -1 && !left_[i]; --i)
		;
	for (; i > 0; --i)
	{
		printf("%d ", left_[i]);
	}
	printf("%d", left_[0]);
	for (n = LEN; n > -1 && !right_[n]; --n)
		;
	for (i = 1; i <= n; ++i)
	{
		printf(" %d", right_[i]);
	}
	printf("\n\n");
}

int main()
{
	int tmp, test = 1;
	while (scanf("%d", &tmp), tmp != -1)
	{
		printf("Case %d:\n", test++);
		build(tmp);
	}
	return 0;
}
