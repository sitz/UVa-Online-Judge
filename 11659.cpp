#include <bits/stdc++.h>

using namespace std;

bool informants[20];
int i, a, j, k, ans;

int main()
{
	while (true)
	{
		scanf("%d %d", &i, &a);
		if ((i | a) == 0)
		{
			break;
		}
		memset(informants, true, i);
		ans = i;
		while (a--)
		{
			scanf("%d %d", &j, &k);
			if (k < 0 && informants[-k - 1])
			{
				ans--;
				informants[-k - 1] = false;
			}
		}
		printf("%d\n", ans);
	}
}
