// + 424
// - 11448
// / 10494
// % 10814 10494
// * 623 324
// < 728

// dont use (BigInt % int) in your code !

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <cassert>
#include <cstdio>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

const static int BASE = 10000, LANGE = 4;
const string BigIntBase = "10000";

enum
{
	LESS,
	EQUAL,
	GREATER
};

#define FRONT "%d"
#define FORMAT "%04d"

class BigInt
{
public:
	bool neg;
	vector<int> value;

	BigInt(void)
			: neg(false)
	{
		value.resize(1, 0);
	}
	BigInt(int s)
			: neg(false)
	{
		//value.push_back(s);
		value.resize(s);
	}
	BigInt(vector<int> v, bool sign)
			: neg(sign), value(v)
	{
	}
	BigInt(string in)
	{
		neg = false;
		if (in[0] == '-')
		{
			neg = true;
			in.erase(in.begin());
		}
		while (in.size() % LANGE != 0)
			in.insert(in.begin(), 1, '0');
		for (int i = in.size() - LANGE; i >= 0; i -= LANGE)
			value.push_back(atoi(in.substr(i, LANGE).c_str()));
		regulation();
	}
	BigInt operator+(int n)
	{
		assert(0 <= n);
		BigInt re = *this;
		re.value[0] += n;
		re.regulation();
		return re;
	}
	BigInt operator+(BigInt in)
	{
		if (sign() == in.sign())
			return add(*this, in, sign());
		else if (compare(in, true) == LESS)
			return sub(in, *this, in.sign());
		else
			return sub(*this, in, sign());
	}
	BigInt operator*(BigInt in)
	{
		return mul(*this, in, sign() != in.sign());
	}
	BigInt operator*(int in)
	{
		assert(in < BASE);
		BigInt re = *this;
		REP(i, size())
		re[i] *= in;
		re.regulation();
		re.neg = in < 0;
		return re;
	}
	BigInt operator-(BigInt in)
	{
		if (sign() != in.sign())
			return add(*this, in, sign());
		else if (compare(in, true) == GREATER)// != LESS ?
			return sub(*this, in, sign());
		else
			return sub(in, *this, !in.sign());
	}
	BigInt operator/(BigInt in)
	{
		return div(*this, in, (sign() != in.sign()));
	}
	BigInt operator/(int n)
	{
		return div(*this, n);
	}
	BigInt operator%(BigInt in)
	{
		BigInt tmp = *this - ((*this / in) * in);
		tmp.regulation();
		return tmp;
	}
	bool operator==(BigInt in)
	{
		return compare(in, false) == EQUAL;
	}
	bool operator<(BigInt in)
	{
		return compare(in, false) == LESS;
	}
	bool operator>(BigInt in)
	{
		return compare(in, false) == GREATER;
	}
	int &operator[](int n)
	{
		return value[n];
	}
	string toString(void)
	{
		char buffer[LANGE + 1];
		string re;

		if (neg == true)
			re = "-";
		sprintf(buffer, FRONT, value.back()), re += buffer;

		for (int i = value.size() - 2; i >= 0; i--)
			sprintf(buffer, FORMAT, value[i]), re += buffer;
		return re;
	}
	int size(void)
	{
		return value.size();
	}
	void resize(int n)
	{
		value.resize(n);
	}
	bool sign(void)
	{
		return neg;
	}
	void regulation(void)
	{
		value.push_back(0);
		REP(i, value.size() - 1)
		{
			value[i + 1] += value[i] / BASE;
			value[i] %= BASE;
		}
		while (value.size() > 1 && value.back() == 0)
			value.pop_back();
		if (value.size() == 1 && value[0] == 0)
		{
			neg = false;
		}
		return;
	}
	int compare(BigInt in, bool abs)
	{
		if (abs)
		{
			in.neg = sign();
			return compare(in, false);
		}
		if (sign() != in.sign())
		{
			return sign() ? LESS : GREATER;
		}
		if (size() != in.size())
		{
			if (!sign())
				return size() > in.size() ? GREATER : LESS;
			else
				return size() > in.size() ? LESS : GREATER;
		}
		for (int i = in.size(); i--;)
		{
			if (value[i] == in.value[i])
				continue;
			return (value[i] > in.value[i]) ? GREATER : LESS;
		}
		return EQUAL;
	}
	BigInt add(BigInt a, BigInt b, bool sign)
	{
		if (a.size() < b.size())
			swap(a, b);
		REP(i, b.size())
		a[i] += b[i];
		a.regulation();
		a.neg = sign;
		return a;
	}
	BigInt sub(BigInt a, BigInt b, bool sign)
	{
		BigInt re = BigInt(a.value, sign);
		re.value.resize(a.size(), 0);
		int borrow = 0;
		REP(i, re.size())
		{
			if (i < b.size())
				re[i] -= b[i] + borrow;
			else
				re[i] -= borrow;
			if (re[i] >= 0)
				borrow = 0;
			else
				borrow = 1, re[i] += BASE;
		}
		re.regulation();
		return re;
	}
	BigInt mul(BigInt a, BigInt b, bool sign)
	{
		BigInt re;
		re.value.resize(a.size() + b.size() + 1);
		REP(i, a.size())
		{
			REP(j, b.size())
			re[i + j] += a[i] * b[j];
		}
		re.neg = sign;
		re.regulation();
		return re;
	}
	BigInt div(BigInt a, int n)
	{
		int c = 0, tmp;
		for (int i = a.size(); i--;)
		{
			tmp = BASE * c + a[i];
			a[i] = tmp / n;
			c = tmp % n;
		}
		a.regulation();
		return a;
	}
	BigInt div(BigInt a, BigInt b, bool sign)
	{
		if (a < b)
			return BigInt("0");
		int f = BASE / (b[(int)b.size() - 1] + 1);
		a = a * f;
		b = b * f;
		BigInt c((int)a.size() - (int)b.size() + 1);
		for (int i = (int)a.size() - 1, k = (int)c.size() - 1; k >= 0; --i, --k)
		{
			c[k] = (i + 1 < a.size() ? a[i + 1] : 0) * BASE;
			c[k] = (c[k] + a[i]) / b[(int)b.size() - 1];
			BigInt d(k + b.size());
			REP(j, b.size())
			{
				d[k + j] = c[k] * b[j];
			}
			d.regulation();
			while (a < d)
			{
				--c[k];
				REP(j, b.size())
				{
					d[k + j] -= b[j];
				}
				REP(j, d.size())
				{
					while (d.value[j] < 0)
					{
						--d.value[j + 1];
						d.value[j] += BASE;
					}
				}
				d.regulation();
			}
			a = a - d;
		}
		c.neg = sign;
		c.regulation();
		return c;
	}
};

const int T = 1000 + 1;
BigInt t[T];

int main(void)
{
	t[0] = BigInt("1");
	for (int i = 1; i < T; ++i)
	{
		int a = 2 * (2 * i + 1);
		BigInt b = t[i - 1] * a;
		t[i] = b / (i + 2);
	}

	int n;
	while (cin >> n)
	{
		cout << t[n - 1].toString() << endl;
	}
	return 0;
}
