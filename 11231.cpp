#include <bits/stdc++.h>

using namespace std;

// @ http://algoshare.blogspot.sg/2009/01/uva-problem-11231-sample-algorithm.html

int main()
{
	int n, m, c;
	while (scanf("%d%d%d", &n, &m, &c) == 3)
	{
		if (n + m + c == 0)
		{
			break;
		}
		if (c == 0)
		{
			printf("%d\n", (n - 7) * (m - 7) / 2);
		}
		else// c == 1 && (n - 7) * (m - 7) % 2 == 1
		{
			printf("%d\n", ((n - 7) * (m - 7) + 1) / 2);
		}
	}
	return 0;
}
