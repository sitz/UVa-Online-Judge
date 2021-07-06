#include <bits/stdc++.h>

using namespace std;

vector<int> F;

void Cal(int n, int m)
{
	int i, d;
	if (n == m)
	{
		printf(" 0\n");
		return;
	}
	d = n - m;
	if (m >= d)
	{
		printf("\n");
		return;
	}
	for (i = 1; i * i <= d; i++)
	{
		if (d % i == 0)
		{
			if (i > m)
				F.push_back(i);
			if (d / i > m && i != d / i)
				F.push_back(d / i);
		}
	}
	sort(F.begin(), F.end());
	for (i = 0; i < F.size(); i++)
	{
		printf(" %d", F[i]);
	}
	printf("\n");
	F.clear();
}

int main()
{
	int n, ks, m, k = 1;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d%d", &n, &m);
		printf("Case #%d:", k++);
		Cal(n, m);
	}
	return 0;
}
