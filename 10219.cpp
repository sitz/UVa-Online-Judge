#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, k, i;
	while (cin >> n >> k)
	{
		double digit = 0;
		for (i = 1; i <= k; i++)
		{
			digit += (log(n - i + 1) - log(i)) / log(10);
		}
		cout << floor(digit) + 1 << endl;
	}
	return 0;
}
