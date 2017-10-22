#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long start, end, house, counter = 1;
	while (cin >> start >> end >> house && !(start == 0 && end == 0 && house == 0))
	{
		long long ans = 0, last;
		long long S, d, E, N;
		if ((house - 1) % 2 == 0)
		{
			last = start + house - 1;
			d = house - 1;
			N = (end - start) / (house - 1);
		}
		else
		{
			last = start + 2 * (house - 1);
			d = 2 * (house - 1);
			N = ((end - start) / (house - 1)) / 2;
		}
		S = end - last + 1;
		E = S - (N - 1) * d;
		ans = (N * (S + E)) / 2;
		cout << "Case " << counter++ << ": " << ans << endl;
	}
	return 0;
}
