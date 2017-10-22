#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, f, t, s, a, b, c;
	cin >> n;
	for (t = 0; t < n; t++)
	{
		cin >> f;
		int sum = 0;
		for (s = 0; s < f; s++)
		{
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << endl;
	}
	return 0;
}
