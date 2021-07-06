#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, sq;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		sq = (long long)sqrt(n);
		if (n == sq * sq)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
