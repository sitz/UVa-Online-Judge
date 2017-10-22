#include <bits/stdc++.h>

using namespace std;

int seq[1000], n;
int main()
{
	int caseno = 1;
	while (scanf("%d", &n) == 1, n)
	{
		if (n % 4 == 1 || n % 4 == 2)
		{
			printf("Case %d: -1\n", caseno++);
			continue;
		}
		else if (n % 4 == 0)
		{
			memset(seq, 0, sizeof(seq));
			int s = 1, p;
			seq[0] = s++;
			for (p = n - 2; p >= n / 2; p -= 2)
			{
				seq[p] = s++;
			}
			for (p++; p >= 1; p -= 2)
			{
				seq[p] = s++;
			}
			for (p = 0; seq[p] != 0; p++)
				;
			seq[p] = ++s;
			for (p++; p < n; p++)
				if (seq[p] == 0)
				{
					seq[p] = ++s;
				}
		}
		else
		{
			memset(seq, 0, sizeof(seq));
			seq[0] = 1;
			int s = 2, p;
			bool flag = false;
			for (p = n - 2; p >= 1; p -= 2)
			{
				seq[p] = s++;
			}
			for (p = 2; p < n; p += 2)
			{
				if (p >= n / 2 && !flag)
				{
					s++;
					flag = true;
				}
				seq[p] = s++;
			}
		}
		printf("Case %d:", caseno++);
		for (int i = 0; i < n; i++)
		{
			printf(" %d", seq[i]);
		}
		puts("");
	}
}
