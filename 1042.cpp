#include <bits/stdc++.h>

using namespace std;

string ttt(double a)
{
	char s[9];
	int x = (337 + a * 760) * 60 + 1e-6;
	sprintf(s, "%02d:%02d:%02d", x / 3600, x / 60 % 60, x % 60);
	return s;
}
int main()
{
	int m[100], d[100] = {0, 0};
	for (size_t tc = 1, w, h, n; cin >> n, n; ++tc)
	{
		cin >> w >> h >> m[1];
		for (size_t i = 2; i <= n; ++i)
		{
			cin >> d[i] >> m[i];
			d[i] += d[i - 1] + w;
		}
		cout << "Apartment Complex: " << tc << endl
				 << endl;
		for (size_t b, l, q; cin >> q, q; cout << endl)
		{
			b = q % 100;
			l = q / 100;
			cout << "Apartment " << q << ": ";
			if (!b || b > n || l > m[b] || l == 0)
			{
				cout << "Does not exist" << endl;
				continue;
			}
			double a1 = 0, a2 = 0;
			for (size_t j = 1; j < b; ++j)
				if (m[j] >= l)
				{
					a1 = max(a1, atan2((m[j] - l + 1) * h, d[b] - d[j] - w));
				}
			for (size_t j = n; j > b; --j)
				if (m[j] >= l)
				{
					a2 = max(a2, atan2((m[j] - l + 1) * h, d[j] - d[b] - w));
				}
			cout << ttt(a1 / M_PI) << " - " << ttt(1 - a2 / M_PI) << endl;
		}
	}
}
