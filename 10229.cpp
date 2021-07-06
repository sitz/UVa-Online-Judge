#include <bits/stdc++.h>

using namespace std;

long long n, m, myMode;

// (a * b + c) % d = ((a % d) * (b % d) + c % d) %d
long long Divide_Conquer_Fib(long long n)
{
	long long i, j, h, k, t;
	i = h = 1;
	j = k = 0;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			// if n is odd
			t = ((j % myMode) * (h % myMode)) % myMode;
			j = ((i % myMode) * (h % myMode) + (j % myMode) * (k % myMode) + (t % myMode)) % myMode;
			i = ((i % myMode) * (k % myMode) + (t % myMode)) % myMode;
			//          cout<<t<<"  "<<j<<"  "<<i<<endl;
		}
		t = (h % myMode) * (h % myMode) % myMode;
		h = (2 * (k % myMode) * (h % myMode) + (t % myMode)) % myMode;
		k = ((k % myMode) * (k % myMode) + (t % myMode)) % myMode;
		n = n / 2;
	}
	return j;
}

int main()
{
	while (cin >> n >> m)
	{
		myMode = (long long)pow(2, m);
		cout << Divide_Conquer_Fib(n) % myMode << endl;
	}
	return 0;
}
