#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>
#include <cassert>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

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
		value.push_back(0);
	}
	BigInt(int s)
			: neg(false)
	{
		value.resize(s, 0);
	}
	BigInt(vector<int> v, bool n)
			: neg(n), value(v)
	{
	}
	BigInt(string in)
	{
		if (in[0] == '-')
		{
			neg = true;
			in.erase(in.begin());
		}
		else
			neg = false;
		while (in.size() % LANGE)
			in = '0' + in;
		for (int i = in.size() - LANGE; i >= 0; i -= LANGE)
			value.push_back(atoi(in.substr(i, LANGE).c_str()));
		regulation();
	}
	BigInt operator+(BigInt in)
	{
		return add_sub(*this, in, neg == in.neg);
	}
	BigInt operator-(BigInt in)
	{
		return add_sub(*this, in, neg != in.neg);
	}
	BigInt operator*(BigInt in)
	{
		return mul(*this, in);
	}
	BigInt operator*(int in)
	{
		return mul(*this, in);
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
		return *this - ((*this / in) * in);
	}
	bool operator==(BigInt &in)
	{
		return compare(in, false) == EQUAL;
	}
	bool operator<(BigInt &in)
	{
		return compare(in, false) == LESS;
	}
	bool operator>(BigInt &in)
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

		if (neg)
			re = "-";
		sprintf(buffer, FRONT, value.back());
		re += buffer;

		for (int i = value.size() - 2; i >= 0; i--)
		{
			sprintf(buffer, FORMAT, value[i]);
			re += buffer;
		}
		return re;
	}
	int size(void)
	{
		return value.size();
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
			while (value[i] < 0)
			{
				--value[i + 1];
				value[i] += BASE;
			}
			value[i + 1] += value[i] / BASE;
			value[i] %= BASE;
		}
		while (value.size() > 1 && value.back() == 0)
			value.pop_back();
		neg = neg || value.back() < 0;
	}
	int compare(BigInt &in, bool abs)
	{
		if (!abs && sign() != in.sign())
		{
			return sign() ? LESS : GREATER;
		}
		if (size() != in.size())
		{
			return (size() > in.size()) ? GREATER : LESS;
		}
		for (int i = in.size(); i--;)
		{
			if (value[i] == in.value[i])
				continue;
			return (value[i] > in.value[i]) ? GREATER : LESS;
		}
		return EQUAL;
	}
	BigInt add_sub(BigInt a, BigInt b, bool flg)
	{
		if (a.size() < b.size())
			swap(a, b);
		REP(i, b.size())
		{
			if (flg)
				a[i] += b[i];
			else
				a[i] -= b[i];
		}
		a.regulation();
		return a;
	}
	BigInt mul(BigInt a, int n)
	{
		assert(n < BASE);
		REP(i, size())
		a[i] *= n;
		a.regulation();
		a.neg = a.neg != n < 0;
		return a;
	}
	BigInt mul(BigInt a, BigInt b)
	{
		BigInt re(a.size() + b.size() + 1);
		REP(i, a.size())
		{
			REP(j, b.size())
			re[i + j] += a[i] * b[j];
		}
		re.regulation();
		re.neg = a.neg != b.neg;
		return re;
	}
	BigInt div(BigInt a, int n)
	{
		assert(n < BASE);
		int c = 0, tmp;
		for (int i = a.size(); i--;)
		{
			tmp = BASE * c + a[i];
			a[i] = tmp / n;
			c = tmp % n;
		}
		tmp = a.neg;
		a.regulation();
		a.neg = tmp != n < 0;
		return a;
	}
	BigInt div(BigInt a, BigInt b, bool sign)
	{
		if (a < b)
			return BigInt("0");
		int f = BASE / (b[(int)b.size() - 1] + 1);
		a = a * f;
		b = b * f;
		BigInt c(a.size() - b.size() + 1);
		for (int i = a.size() - 1, k = c.size() - 1; k >= 0; --i, --k)
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
				d.regulation();
			}
			a = a - d;
		}
		c.regulation();
		c.neg = a.neg != b.neg;
		return c;
	}
};

BigInt gcd(BigInt a, BigInt b)
{
	BigInt r = a % b;
	if (r.size() == 1 && r.value[0] == 0)
		return b;
	else
		return gcd(b, r);
}

int main()
{
	int tc;
	for (cin >> tc; tc--;)
	{
		string s, t;
		char o;
		cin >> s >> o >> t;
		BigInt a(s), b(t);
		BigInt c = (a < b) ? gcd(b, a) : gcd(a, b);
		cout << (a / c).toString() << flush;
		cout << " / " << flush;
		cout << (b / c).toString() << endl;
	}
	return 0;
}
