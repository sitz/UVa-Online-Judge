#include <bits/stdc++.h>

using namespace std;

#define MOD 100000007
#define MX 10000000
#define ull unsigned long long
#define ll long long int
#define pb push_back

template <class T, class X>
inline T _bigmod(T n, X m)
{
	ull ret = 1, a = n % MOD;
	while (m)
	{
		if (m & 1)
			ret = (ret * a) % MOD;
		m >>= 1;
		a = (a * a) % MOD;
	}
	ret %= MOD;
	return (T)ret;
}
template <class T>
inline T _modinv(T n) { return _bigmod(n, MOD - 2); }

ll fact[MX + 10];
void factorial()
{

	fact[0] = 1;
	for (int i = 1; i <= MX; i++)
		fact[i] = (i * fact[i - 1]) % MOD;
}

bool chk[MX + 10];
void gen_prime()
{

	//    primes.pb(1);
	//    primes.pb(2);

	int lmt = sqrt((double)MX);

	for (int i = 4; i <= MX; i += 2)
		chk[i] = true;

	for (int i = 3; i <= lmt; i += 2)
	{
		if (!chk[i])
		{
			//            primes.pb(i);
			for (int j = i * 3; j <= MX; j += 2 * i)
			{
				chk[j] = true;
			}
		}
	}

	//    for(int i=3;i<=MX;i+=2)
	//        if(!chk[i]) primes.pb(i);

	//    cout<<primes.size()<<endl;
}

ll mdv[MX + 10];
void calc_modinv()
{

	mdv[1] = 1;

	for (int i = 2; i <= MX; i++)
	{
		if (!chk[i])
			mdv[i] = (mdv[i - 1] * ((1 - _modinv(i)) % MOD + MOD) % MOD) % MOD;
		else
		{
			mdv[i] = mdv[i - 1];
		}
	}
}

int main()
{
	gen_prime();
	factorial();
	calc_modinv();

	ll n, m, ans;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;

		//        cout<<fact[n]<<endl;
		ans = (fact[n] * mdv[m]) % MOD;
		cout << (ans - 1 + MOD) % MOD << endl;
	}

	return 0;
}
