#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sc scanf
#define pf printf
#define pi 2 * acos(0.0)

int main()
{
	string s[200], p[100], r;
	int n, k, q;
	while (cin >> n)
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			getline(cin, s[i]);
			getline(cin, p[i]);
		}
		cin >> q;
		getchar();
		while (q--)
		{
			getline(cin, r);
			for (int i = 0; i < n; i++)
			{
				if (s[i] == r)
				{
					cout << p[i] << endl;
					break;
				}
			}
		}
	}
	return 0;
}
