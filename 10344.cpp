#include <bits/stdc++.h>

using namespace std;

int X[5];
int check(int lv, int v)
{
	if (lv == 5)
	{
		return (v == 23);
	}
	if (check(lv + 1, v + X[lv]))
	{
		return 1;
	}
	if (check(lv + 1, v - X[lv]))
	{
		return 1;
	}
	if (check(lv + 1, v * X[lv]))
	{
		return 1;
	}
	return 0;
}
int perm(int lv)
{
	if (lv == 5)
	{
		return check(1, X[0]);
	}
	int i, t;
	if (perm(lv + 1))
	{
		return 1;
	}
	for (i = lv + 1; i < 5; i++)
	{
		t = X[lv];
		X[lv] = X[i];
		X[i] = t;
		if (perm(lv + 1))
		{
			return 1;
		}
		t = X[lv];
		X[lv] = X[i];
		X[i] = t;
	}
	return 0;
}

int main()
{
	while (scanf("%d%d%d%d%d", X, X + 1, X + 2, X + 3, X + 4) == 5)
	{
		if ((X[0] | X[1] | X[2] | X[3] | X[4]) == 0)
		{
			break;
		}
		if (perm(0))
		{
			printf("Possible\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
