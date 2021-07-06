#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3)
	{
		if (!n && !m && !k)
		{
			break;
		}
		if (m % 2)
		{
			puts("Keka");
		}
		else
		{
			puts("Gared");
		}
	}
	return 0;
}
