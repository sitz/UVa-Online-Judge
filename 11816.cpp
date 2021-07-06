#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define myabs(x) ((x) < 0 ? -x : x)
typedef long long ll;

ll getdif(ll pay, ll tax)
{
	ll tmp = pay * tax;
	if (tmp % 10000 < 5000)
	{
		return tmp / 10000;
	}
	else
	{
		return tmp / 10000 + 1;
	}
}

int main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int n, m;
		char dummy;
		cin >> n >> m;
		map<string, ll> tax[3];
		rep(i, n)
		{
			string name;
			ll tp;
			string tmp;
			cin >> name;
			rep(j, 3)
			{
				cin >> tp >> dummy;
				tp = tp * 100;
				if (dummy == '.')
				{
					cin >> tmp;
					tp += (tmp[0] - '0') * 10;
					if (tmp.size() == 3)
					{
						tp += tmp[1] - '0';
					}
				}
				tax[j][name] = tp;
			}
		}
		ll dif = 0;
		rep(i, m)
		{
			string name;
			ll dol, pay;
			string cent;
			cin >> name >> dummy >> dol >> dummy >> cent;
			if (cent.size() == 2)
			{
				pay = dol * 100 + (cent[0] - '0') * 10 + cent[1] - '0';
			}
			else if (cent.size() == 1)
			{
				pay = dol * 100 + (cent[0] - '0') * 10;
			}
			dif -= getdif(pay, tax[0][name]);
			dif -= getdif(pay, tax[1][name]);
			dif += getdif(pay, tax[2][name]);
		}
		if (dif < 0)
		{
			printf("-%lld.%02lld\n", myabs(dif / 100), myabs(dif % 100));
		}
		else
		{
			printf("%lld.%02lld\n", dif / 100, myabs(dif % 100));
		}
	}
	return 0;
}
