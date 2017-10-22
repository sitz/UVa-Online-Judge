#include <bits/stdc++.h>

using namespace std;

long long n;

long long cx4(long long x)
{
	return x * (x - 1) * (x - 2) * (x - 3) / 24;
}

int main()
{
	for (int te = 1; cin >> n, n; ++te)
		if (n & 1)
		{
			cout << "Case " << te << ": 0" << endl;
		}
		else
		{
			n = n + 4 >> 1;
			cout << "Case " << te << ": " << cx4(n) + cx4(n - 1) << endl;
		}
	return 0;
}
