#include <bits/stdc++.h>

using namespace std;

int base[31];
int main()
{
	int t;
	scanf("%d", &t);
	base[0] = 1;
	for (int i = 1; i < 31; i++)
	{
		base[i] = base[i - 1] * 2;
	}
	while (t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		int temp = k, best = 0, worst = base[n], s = 0;
		bool flag = true;
		for (int i = 0; i < n; i++, temp >>= 1)
		{
			if (temp & 1)
			{
				flag = false;
			}
			best += temp & 1;
			if (flag)
			{
				s++;
			}
		}
		worst -= base[s] - 1;
		printf("%d %d\n", best + 1, worst);
	}
	return 0;
}
