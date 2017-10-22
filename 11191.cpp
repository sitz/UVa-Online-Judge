#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

const int N = (1 << 11);
ll inp[N];
ll pi[N];

void solve(ll zero, ll num)
{
	ll ret = 0, ret2 = 0;
	rep(i, N)
	{
		pi[i] = 0;
	}
	ll sq[2] = {0};
	REP(i, 0, N)
	{
		if (inp[i] > 1)
		{
			ret += inp[i] * (inp[i] - 1) / 2;
		}
		rep(j, N)
		{
			int a = i, b = j, c = i ^ j;
			if (a <= b && b <= c)
				;
			else
			{
				continue;
			}
			if ((i ^ j) == (1 << 10) && inp[i] > 1 && i < j)
			{
				sq[1] += inp[i] * (inp[j]);
			}
			if ((i ^ j) == 0 && inp[i] > 1)
			{
				sq[0] += inp[i] * (inp[i] - 1) / 2;
			}
			if (i == j)
			{
				if (i == 0)
				{
					if (inp[i] > 2)
					{
						ret2 += (inp[i] * (inp[i] - 1) * (inp[i ^ j] - 2)) / 6;
					}
				}
				else if (inp[i] > 0)
				{
					ret2 += (inp[i] * (inp[i] - 1) * inp[i ^ i]) / 2;
				}
			}
			else
			{
				if (j == (i ^ j))
				{
					if (inp[j] > 1)
					{
						ret2 += (inp[i] * inp[j] * (inp[j] - 1)) / 2;
					}
				}
				else if (i == (i ^ j) && i < j)
				{
					if (inp[i] > 1)
					{
						ret2 += (inp[i] * inp[j] * (inp[i] - 1)) / 2;
					}
				}
				else if (inp[i] != 0 && inp[j] != 0 && inp[i ^ j] != 0)
				{
					ret2 += (inp[i] * inp[j] * inp[i ^ j]);
				}
			}
		}
	}
	//ret2/=6;
	if (zero >= 1)
	{
		ret += zero * num;
		ret2 += zero * num * (num - 1) / 2;
	}
	if (zero >= 2)
	{
		ret += zero * (zero - 1) / 2;
		ret2 += zero * (zero - 1) / 2 * num;
	}
	if (zero >= 3)
	{
		ret2 += (zero) * (zero - 1) * (zero - 2) / 6;
	}
	cout << ret << " " << ret2 << endl;
}

int prime[100];
int generate()
{
	int index = 0;
	REP(i, 2, 31)
	{
		bool isp = true;
		REP(j, 2, i)
		if (i % j == 0)
		{
			isp = false;
		}
		if (isp)
		{
			prime[index++] = i;
		}
	}
	return index;
}

int getdata(ll n, int index)
{
	int ret = 0;
	if (n < 0)
	{
		n *= -1, ret |= (1 << 10);
	}
	else if (n == 0)
	{
		return 0;
	}
	rep(i, index)
	{
		if (n % prime[i] == 0)
		{
			int cnt = 0;
			while (n % prime[i] == 0 && n / prime[i] > 0)
			{
				n /= prime[i], cnt++;
			}
			if (cnt % 2 == 1)
			{
				ret |= (1 << i);
			}
		}
	}
	return ret;
}

main()
{
	int index = generate();
	int te;
	cin >> te;
	rep(tc, te)
	{
		rep(i, N) inp[i] = 0;
		int n;
		cin >> n;
		ll zero = 0;
		ll num = n;
		rep(i, n)
		{
			ll tmp;
			cin >> tmp;
			if (tmp == 1)
			{
				inp[0]++;
			}
			else if (tmp == -1)
			{
				inp[(1 << 10)]++;
			}
			else if (tmp == 0)
			{
				zero++, num--;
			}
			else
			{
				int a = getdata(tmp, index);
				inp[a]++;
			}
		}
		solve(zero, num);
	}
	return false;
}
