#include <bits/stdc++.h>

using namespace std;

// @BEGIN_OF_SOURCE_CODE

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		int b;
		scanf("%d", &b);
		int start = 0;
		for (int i = 0; i < b; i++)
		{
			int p;
			scanf("%d", &p);
			start |= (1 << (p - 1));
		}
		bool vis[1024 + 5];
		memset(vis, false, sizeof(vis));
		vis[start] = true;
		int cnt = 1;
		while (cnt != (1 << n))
		{
			for (int i = 0; i < n; i++)
			{
				int bit = start & (1 << i);
				int newNum = start;
				if (bit == 0)
				{
					newNum |= (1 << i);
				}
				else
				{
					newNum ^= (1 << i);
				}
				if (!vis[newNum])
				{
					vis[newNum] = true;
					start = newNum;
					printf("Move %d from B%d to B%d\n", i + 1, bit ? 1 : 2, bit ? 2 : 1);
					cnt++;
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

// @END_OF_SOURCE_CODE
