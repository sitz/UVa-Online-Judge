#include <bits/stdc++.h>

using namespace std;

int n, m, p[111];
char a[1111], b[111];

void makestr()
{
	a[0] = 'L', a[1] = 'L', a[2] = 'R';
	for (int i = 3; i <= 10; ++i)
	{
		int t = (int)pow(2, i - 1), u = (int)pow(2, i - 2);
		a[t - 1] = 'L';
		for (int j = 0; j < t - 1; ++j)
		{
			a[j + t] = a[j];
		}
		a[t + u - 1] = 'R';
	}
}

void init()
{
	p[0] = -1;
	int i = 0, j = -1;
	while (i < m)
	{
		if (j == -1 || b[i] == b[j])
		{
			++i, ++j, p[i] = j;
		}
		else
		{
			j = p[j];
		}
	}
}

int kmp()
{
	int i = 0, j = 0, ans = 0;
	while (i < n)
	{
		if (j == -1 || b[j] == a[i])
		{
			++i, ++j;
		}
		else
		{
			j = p[j];
		}
		if (j == m)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	makestr();
	int T, k;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d", &k);
		scanf("%s", b);
		n = (k > 10 ? 1023 : (int)pow(2, k));
		m = strlen(b);
		init();
		printf("Case %d: %s\n", t, kmp() ? "Yes" : "No");
	}
	return 0;
}
