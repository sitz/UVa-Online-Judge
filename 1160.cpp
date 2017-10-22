#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int p[MAX], ans;

int find(int x)
{
	if (p[x] == x)
	{
		return x;
	}
	return p[x] = find(p[x]);
}

int main()
{
	int a, b;
	while (scanf("%d", &a) != EOF)
	{
		for (int i = 0; i < MAX; i++)
		{
			p[i] = i;
		}
		ans = 0;
		while (1)
		{
			scanf("%d", &b);
			int ita = find(a);
			int itb = find(b);
			if (ita == itb)
			{
				ans++;
			}
			else
			{
				p[ita] = itb;
			}
			scanf("%d", &a);
			if (a == -1)
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
