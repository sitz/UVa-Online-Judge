#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int read()
{
	int static t;
	cin >> t;
	return t;
}
int main()
{
	pii x[50];
	for (int Tc = 1, n, m;; ++Tc)
	{
		n = read();
		m = read();
		if (!n && !m)
		{
			return 0;
		}
		for (int i = 0; i < n; ++i)
		{
			x[i] = pii(1 << i, read());
		}
		int t = n + read();
		for (int i = n; i < t; ++i)
		{
			int o = 0;
			for (int k = read(); k--;)
			{
				o |= 1 << read() - 1;
			}
			x[i] = pii(o, read());
			for (int k = 0; k < n; ++k)
				if (x[i].first & 1 << k)
				{
					x[k].second -= x[i].second;
				}
		}
		int ans = 0;
		unsigned sc = 0;
		for (unsigned s = 1; s < 1 << n; ++s)
			if (__builtin_popcount(s) == m)
			{
				int tmp = 0;
				for (int i = 0; i < t; ++i)
					if (s & x[i].first)
					{
						tmp += x[i].second;
					}
				if (tmp > ans)
				{
					ans = tmp;
					sc = s;
				}
				else if (tmp == ans)
				{
					for (int j = 0; j < n; ++j)
						if ((sc ^ s) & 1 << j)
						{
							if (s & 1 << j)
							{
								sc = s;
							}
							break;
						}
				}
			}
		cout << "Case Number  " << Tc << endl;
		cout << "Number of Customers: " << ans << endl;
		cout << "Locations recommended:";
		for (int i = 0; i < n; ++i)
			if (sc & 1 << i)
			{
				cout << " " << 1 + i;
			}
		cout << endl
				 << endl;
	}
}
