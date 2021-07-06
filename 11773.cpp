#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000
#define FORALL(it, o) for (__typeof((o).begin()) it = (o).begin(); it != (o).end(); ++it)

vector<int> vprimes;
void MakePrime()
{
	vprimes.reserve(MAX);
	bool isPrime[MAX];
	isPrime[0] = false;
	isPrime[1] = false;
	isPrime[2] = true;
	for (int i = 2; i < MAX; ++i)
	{
		isPrime[i] = true;
	}
	for (long long int i = 2; i < MAX; ++i)
	{
		if (isPrime[i])
		{
			for (long long int j = 2; i * j < MAX; ++j)
			{
				isPrime[i * j] = false;
			}
		}
	}
	for (int i = 0; i < MAX; ++i)
	{
		if (isPrime[i])
		{
			vprimes.push_back(i);
		}
	}
}
void Factorization(long long int n, vector<long long int> &vp, map<long long int, int> &optional)
{
	if (n == 1)
	{
		vp.push_back(1);
		optional[1] = 1;
		return;
	}
	for (int i = 0; i < (int)vprimes.size(); ++i)
	{
		if (vprimes[i] > n)
		{
			break;
		}
		while (n % vprimes[i] == 0)
		{
			n /= vprimes[i];
			optional[vprimes[i]]++;
			vp.push_back(vprimes[i]);
		}
		if (n == 1)
		{
			break;
		}
	}
	if (n != 1)
	{
		vp.push_back(n);
	}
	optional[n]++;
}
long long int mypow(long long int a, int b)
{
	long long int ret = 1;
	for (int i = 0; i < b; ++i)
	{
		ret *= a;
	}
	return ret;
}
int main()
{
	MakePrime();
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		long long int K;
		map<long long int, int> primes;
		vector<long long int> factors;
		long long int L = -1, W = -1, max_diff = 0;
		cin >> K;
		Factorization(K, factors, primes);
		FORALL(itm, primes)
		{
			long long int tw = mypow(itm->first, itm->second);
			long long int tl = K / itm->first;
			if (tl > tw && tl < K)
			{
				if (max_diff < tl - tw)
				{
					max_diff = tl - tw;
					L = tl;
					W = tw;
				}
				else if (max_diff == tl - tw && tl > L)
				{
					L = tl;
					W = tw;
				}
			}
		}
		if (L < 0)
		{
			printf("Case %d: Impossible\n", tc);
		}
		else
		{
			printf("Case %d: %lld %lld\n", tc, L, W);
		}
	}
	return 0;
}
