#include <bits/stdc++.h>

using namespace std;

char s1[128], s2[128];

int main()
{
	while (scanf("%s%s", s1, s2) == 2)
	{
		int n1 = strlen(s1), n2 = strlen(s2);
		int res = n1 + n2;
		for (int i = -n2; i <= n1; i++)
		{
			int ok = 1;
			for (int j = 0; j < n2 && ok; j++)
			{
				if (i + j >= 0 && i + j < n1)
				{
					ok &= s1[i + j] - '0' + s2[j] - '0' <= 3;
				}
			}
			if (ok)
			{
				res = min(res, max(n1, i + n2) - min(i, 0));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
