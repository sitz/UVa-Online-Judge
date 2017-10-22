#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, total, butt;
	while (cin >> n >> k)
	{
		total = butt = 0;
		while (n)
		{
			total += n;
			butt += n;
			n = butt / k;
			butt %= k;
		}
		cout << total << endl;
	}
	return 0;
}
