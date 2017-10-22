#include <bits/stdc++.h>

using namespace std;

int lis[1001];

int main()
{
	int count, n, i, j, maxlen, temp;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%lld", &n, &lis[1]);
		maxlen = 1;
		for (i = 1; i < n; i++)
		{
			scanf("%d", &temp);
			for (j = maxlen; j > 0; j--)
			{
				if (lis[j] < temp)
				{
					lis[j + 1] = lis[j] + temp;
					break;
				}
			}
			maxlen += (j == maxlen);
		}
		printf("%d\n", maxlen);
	}
	return 0;
}
