#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long n;
	while (cin >> n)
	{
		n--;
		cout << n + (int)log2(n) << endl;
	}
	return 0;
}
