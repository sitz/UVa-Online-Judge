#include <bits/stdc++.h>

using namespace std;

#define LL long long
int main()
{
	int n, x, y, z;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d%d", &x, &y, &z);
		if ((y == 9 || y == 11) && z == 30)
		{
			puts("YES");
			continue;
		}
		y &= 1;
		z &= 1;
		if (y == z)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
