#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF && n)
	{
		if (n <= 3)
		{
			puts("1");
		}
		else if (n == 4)
		{
			puts("2");
		}
		else if (n > 4)
		{
			printf("%d\n", n);
		}
	}
	return 0;
}
