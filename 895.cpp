#include <bits/stdc++.h>

using namespace std;

int V[1005][128] = {0}, len, vec[128];
char W[20];
int main()
{
	int i, j, ok, ans;
	for (len = 0; gets(W); len++)
	{
		if (W[0] == '#')
		{
			break;
		}
		for (i = 0; W[i]; i++)
		{
			V[len][W[i]]++;
		}
	}
	while (gets(W))
	{
		if (W[0] == '#')
		{
			break;
		}
		for (i = 'a'; i <= 'z'; i++)
		{
			vec[i] = 0;
		}
		for (i = 0; W[i]; i++)
		{
			vec[W[i]]++;
		}
		for (i = ans = 0; i < len; i++)
		{
			for (j = 'a', ok = 1; j <= 'z'; j++)
			{
				if (vec[j] < V[i][j])
				{
					ok = 0;
					break;
				}
			}
			ans += ok;
		}
		printf("%d\n", ans);
	}
	return 0;
}
