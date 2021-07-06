#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1005;

struct bign
{
	int len;
	ll num[MAXN];

	bign()
	{
		len = 0;
		memset(num, 0, sizeof(num));
	}
	bign(ll number)
	{
		*this = number;
	}
	bign(const char *number)
	{
		*this = number;
	}

	void DelZero();
	void Put();

	void operator=(ll number);
	void operator=(char *number);

	bool operator<(const bign &b) const;
	bool operator>(const bign &b) const
	{
		return b < *this;
	}
	bool operator<=(const bign &b) const
	{
		return !(b < *this);
	}
	bool operator>=(const bign &b) const
	{
		return !(*this < b);
	}
	bool operator!=(const bign &b) const
	{
		return b < *this || *this < b;
	}
	bool operator==(const bign &b) const
	{
		return !(b != *this);
	}

	void operator++();
	void operator--();
	bign operator+(const int &b);
	bign operator+(const bign &b);
	bign operator-(const int &b);
	bign operator-(const bign &b);
	bign operator*(const ll &b);
	bign operator*(const bign &b);
	bign operator/(const ll &b);
	//bign operator/(const bign& b);
	int operator%(const int &b);
};

/*Code*/

int k;
long long n, f[10];

int bitcount(int x)
{
	return x == 0 ? 0 : bitcount(x >> 1) + (x & 1);
}

bign C(long long n, long long m)
{
	bign ans = 1;
	for (long long i = 0; i < m; i++)
	{
		ans = ans * (n - i) / (i + 1);
	}
	return ans;
}

int main()
{
	while (~scanf("%d%lld", &k, &n))
	{
		long long l, r;
		for (int i = 0; i < k; i++)
		{
			scanf("%lld%lld", &l, &r);
			f[i] = r - l;
			n -= l;
		}
		bign ans1 = 0LL, ans2 = 0LL;
		for (int i = 0; i < (1 << k); i++)
		{
			long long s = n;
			for (int j = 0; j < k; j++)
			{
				if (i & (1 << j))
				{
					s -= f[j] + 1;
					if (s < 0)
					{
						break;
					}
				}
			}
			if (s < 0)
			{
				continue;
			}
			if (bitcount(i) & 1)
			{
				ans2 = ans2 + C(s + k - 1, k - 1);
			}
			else
			{
				ans1 = ans1 + C(s + k - 1, k - 1);
			}
		}
		(ans1 - ans2).Put();
		printf("\n");
	}
	return 0;
}

/*********************************************/

void bign::DelZero()
{
	while (len && num[len - 1] == 0)
	{
		len--;
	}
	if (len == 0)
	{
		num[len++] = 0;
	}
}

void bign::Put()
{
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%lld", num[i]);
	}
}

void bign::operator=(char *number)
{
	len = strlen(number);
	for (int i = 0; i < len; i++)
	{
		num[i] = number[len - i - 1] - '0';
	}
	DelZero();
}

void bign::operator=(ll number)
{
	len = 0;
	while (number)
	{
		num[len++] = number % 10;
		number /= 10;
	}
	DelZero();
}

bool bign::operator<(const bign &b) const
{
	if (len != b.len)
	{
		return len < b.len;
	}
	for (int i = len - 1; i >= 0; i--)
		if (num[i] != b.num[i])
		{
			return num[i] < b.num[i];
		}
	return false;
}

void bign::operator++()
{
	int s = 1;
	for (int i = 0; i < len; i++)
	{
		s = s + num[i];
		num[i] = s % 10;
		s /= 10;
		if (!s)
		{
			break;
		}
	}
	while (s)
	{
		num[len++] = s % 10;
		s /= 10;
	}
}

void bign::operator--()
{
	if (num[0] == 0 && len == 1)
	{
		return;
	}
	int s = -1;
	for (int i = 0; i < len; i++)
	{
		s = s + num[i];
		num[i] = (s + 10) % 10;
		if (s >= 0)
		{
			break;
		}
	}
	DelZero();
}

bign bign::operator+(const int &b)
{
	bign a = b;
	return *this + a;
}

bign bign::operator+(const bign &b)
{
	int bignSum = 0;
	bign ans;
	for (int i = 0; i < len || i < b.len; i++)
	{
		if (i < len)
		{
			bignSum += num[i];
		}
		if (i < b.len)
		{
			bignSum += b.num[i];
		}
		ans.num[ans.len++] = bignSum % 10;
		bignSum /= 10;
	}
	while (bignSum)
	{
		ans.num[ans.len++] = bignSum % 10;
		bignSum /= 10;
	}
	return ans;
}

bign bign::operator-(const int &b)
{
	bign a = b;
	return *this - a;
}

bign bign::operator-(const bign &b)
{
	ll bignSub = 0;
	bign ans;
	for (int i = 0; i < len || i < b.len; i++)
	{
		bignSub += num[i];
		if (i < b.len)
		{
			bignSub -= b.num[i];
		}
		ans.num[ans.len++] = (bignSub + 10) % 10;
		if (bignSub < 0)
		{
			bignSub = -1;
		}
		else
		{
			bignSub = 0;
		}
	}
	ans.DelZero();
	return ans;
}

bign bign::operator*(const ll &b)
{
	ll bignSum = 0;
	bign ans;
	ans.len = len;
	for (int i = 0; i < len; i++)
	{
		bignSum += num[i] * b;
		ans.num[i] = bignSum % 10;
		bignSum /= 10;
	}
	while (bignSum)
	{
		ans.num[ans.len++] = bignSum % 10;
		bignSum /= 10;
	}
	return ans;
}

bign bign::operator*(const bign &b)
{
	bign ans;
	ans.len = 0;
	for (int i = 0; i < len; i++)
	{
		int bignSum = 0;
		for (int j = 0; j < b.len; j++)
		{
			bignSum += num[i] * b.num[j] + ans.num[i + j];
			ans.num[i + j] = bignSum % 10;
			bignSum /= 10;
		}
		ans.len = i + b.len;
		while (bignSum)
		{
			ans.num[ans.len++] = bignSum % 10;
			bignSum /= 10;
		}
	}
	return ans;
}

bign bign::operator/(const ll &b)
{
	bign ans;
	ll s = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		s = s * 10 + num[i];
		ans.num[i] = s / b;
		s %= b;
	}
	ans.len = len;
	ans.DelZero();
	return ans;
}

int bign::operator%(const int &b)
{
	bign ans;
	int s = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		s = s * 10 + num[i];
		ans.num[i] = s / b;
		s %= b;
	}
	return s;
}
