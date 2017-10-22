#include <bits/stdc++.h>

using namespace std;

const int mod = 100000007;
typedef long long ll;
map<int, int> prime_factor(int a)
{
	map<int, int> res;
	for (int i = 2; i * i <= a; i++)
	{
		while (a % i == 0)
		{
			a /= i;
			res[i]++;
		}
	}
	if (a != 1)
	{
		res[a]++;
	}
	return res;
}

int main()
{
	int N, M, T;
	int cs = 1;
	while (cin >> N >> M >> T && (N | M | T))
	{
		map<int, int> m = prime_factor(N);
		ll res = 1;
		ll b = 1;
		for (map<int, int>::iterator it = m.begin();
				 it != m.end(); it++)
		{
			it->second *= M;
			res = (res * (1 + (it->second) / T)) % mod;
			// ll a=(it->second+1)
			//    -((it->second/T)-(it->second/(T+1)));
			ll a = (it->second / (T + 1) + 1);
			b = (b * a) % mod;
		}
		res = (res - b + mod) % mod;
		cout << "Case " << cs++ << ": ";
		cout << res << endl;
	}
	return 0;
}
