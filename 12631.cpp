#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define PB push_back
#define MP make_pair
typedef long long ll;

const int MOD = 1000000007;
int counter[100005];
int p[100005], mutiple[100005];
int inex_flag[100005], firstFac[100005];
int primes[100005];
bool isprime[100005];
ll cnk[100005], pow2[100005];
int inv[100005];

void GetPrime(int n)
{
	memset(isprime, 1, sizeof(isprime));
	int num = 0, i, j;
	for (i = 2; i < n; ++i)
	{
		if (isprime[i])
			primes[num++] = i;
		for (j = 0; (j < num && i * primes[j] < n); ++j)
		{
			isprime[i * primes[j]] = 0;
			firstFac[i * primes[j]] = primes[j];
			if (i % primes[j] == 0)
				break;
		}
	}
}
vector<pair<int, int>> vec;
void prepareVec()
{
	for (int i = 1; i < 100005; ++i)
	{
		int x = i;
		int last = -1;
		bool repeatFac = false;
		int cnt = 0;
		while (x > 1)
		{
			int fac = isprime[x] ? x : firstFac[x];
			if (fac == last)
			{
				repeatFac = true;
				break;
			}
			x /= fac;
			last = fac;
			cnt++;
		}
		if (!repeatFac)
		{
			vec.push_back(make_pair(i, (cnt & 1) ? -1 : 1));
		}
	}
	//REP(i, 10)
	//cout << vec[i].first << " " << vec[i].second << endl;
}
void preparePow()
{
	pow2[0] = 1;
	for (int i = 1; i < 100005; ++i)
		pow2[i] = pow2[i - 1] * 2 % MOD;
}
void prepareInv()
{
	inv[1] = 1;
	for (int i = 2; i < 100005; i++)
		inv[i] = (ll)(MOD - MOD / i) * inv[(int)(MOD % i)] % MOD;
}
int n, k;
ll C;

int main()
{
	GetPrime(100005);
	prepareVec();
	preparePow();
	prepareInv();

	int test;
	cin >> test;
	for (int cas = 1; cas <= test; ++cas)
	{
		int a, b, c;
		cin >> n >> C >> k;
		cin >> a >> b >> c;

		memset(cnk, 0, sizeof(cnk));
		for (int i = k; i < 100005; ++i)
		{
			if (i == k)
				cnk[i] = 1;
			else
				cnk[i] = (ll)cnk[i - 1] * i % MOD * inv[i - k] % MOD;
		}

		p[0] = a;
		p[1] = b;
		for (int i = 2; i < n; ++i)
		{
			p[i] = 1 + (a * (long long)p[i - 2] + b * (long long)p[i - 1] + c) % 100000;
		}
		memset(counter, 0, sizeof(counter));
		REP(i, n)
		counter[p[i]]++;

		int maxn = 0;

		REP(i, n)
		maxn = max(maxn, p[i]);

		memset(mutiple, 0, sizeof(mutiple));
		for (int i = 1; i <= maxn; ++i)
		{
			for (int j = i; j <= maxn; j += i)
			{
				mutiple[i] += counter[j];
			}
		}

		int ans2 = 0, ansk = 0;
		for (int d = 1; d <= maxn; ++d)
		{
			int cnt2 = 0;
			int cntk = 0;
			for (int i = 0; i < vec.size(); ++i)
			{
				int x = d * vec[i].first;
				if (x > maxn)
					break;
				cnt2 = (cnt2 + (pow2[mutiple[x]] - 1ll) * vec[i].second) % MOD;
				cntk = (cntk + cnk[mutiple[x]] * (ll)vec[i].second) % MOD;
			}
			ans2 = (ans2 + cnt2 * (ll)(C / d % MOD) % MOD) % MOD;
			ansk = (ansk + cntk * (ll)(C / d % MOD) % MOD) % MOD;
		}
		ans2 = (ans2 + MOD) % MOD;
		ansk = (ansk + MOD) % MOD;
		printf("Case %d: %d %d\n", cas, ans2, ansk);
	}
	return 0;
}
