#include <bits/stdc++.h>

using namespace std;

#define MAXN 5009
#define BASE 10000000
#define MAX_DIGIT 192

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long long INT;

char ss[MAXN];
int P[700], Res[700], tp, max_;

struct BigNum
{
	INT sign, len, digit[MAX_DIGIT];
	void absAdd(BigNum, BigNum);
	void absSubtract(BigNum, BigNum);
	void multAndAdd(BigNum, INT, INT);

	void operator=(INT);							 //ok
	void operator=(BigNum);						 //ok
	void operator=(char *);						 //ok
	void add(BigNum, INT);						 //ok-
	void add(BigNum, BigNum);					 //ok-
	void subtract(BigNum, INT);				 //ok-
	void subtract(BigNum, BigNum);		 //ok-
	void mult(BigNum, INT);						 //ok-
	void mult(BigNum, BigNum);				 //ok-
	void div(BigNum, INT, INT &);			 //ok-, third param is the remainder
	void div(BigNum, BigNum, BigNum &);//ok-
	INT comp(BigNum);									 //ok-
	INT absComp(BigNum);							 //ok-
	void print();											 //ok-
	void update();										 //ok-
	void clear();											 //ok-
	BigNum()
	{
		clear();
	}
};
void BigNum::mult(BigNum a, BigNum b)
{
	INT pos;
	clear();
	for (pos = 0; pos < b.len; ++pos)
	{
		multAndAdd(a, b.digit[pos], pos);
	}
	sign = (a.sign + b.sign) % 2;
}
void BigNum::multAndAdd(BigNum a, INT s, INT offset)
{
	INT pos, carry;
	carry = 0;
	for (pos = 0; pos < a.len; ++pos)
	{
		digit[pos + offset] += a.digit[pos] * s + carry;
		carry = digit[pos + offset] / BASE;
		digit[pos + offset] %= BASE;
	}
	pos = a.len + offset;
	while (carry != 0)
	{
		//check overflow
		digit[pos] += carry;
		carry = digit[pos] / BASE;
		digit[pos] %= BASE;
		++pos;
	}
	if (len < pos)
	{
		len = pos;
	}
	update();
}
void BigNum::operator=(INT x)
{
	clear();
	if (x < 0)
	{
		x = -x;
		sign = 1;
	}
	if (x == 0)
	{
		digit[len++] = 0;
		return;
	}
	while (x)
	{
		digit[len++] = x % BASE;
		x /= BASE;
	}
}
void BigNum::operator=(BigNum n)
{
	INT i;
	clear();
	len = n.len;
	sign = n.sign;
	//memset(digit, 0, sizeof(digit));
	for (i = 0; i < len; ++i)
	{
		digit[i] = n.digit[i];
	}
}
void BigNum::update()
{
	while (len > 1 && digit[len - 1] == 0)
	{
		--len;
	}
	if (len <= 1 && digit[0] == 0)
	{
		sign = 0;
	}
}
void BigNum::clear()
{
	sign = len = 0;
	memset(digit, 0, sizeof(digit));
}
void BigNum::mult(BigNum a, INT s)
{
	INT pos, carry;
	if (s < 0)
	{
		sign = 1 - a.sign;
		s = -s;
	}
	else
	{
		sign = a.sign;
	}
	carry = 0;
	for (pos = 0; pos < a.len; ++pos)
	{
		//take care about any overflow
		digit[pos] = a.digit[pos] * s + carry;
		carry = digit[pos] / BASE;
		digit[pos] %= BASE;
	}
	pos = a.len;
	while (carry != 0)
	{
		//check overflow
		digit[pos] = carry % BASE;
		carry /= BASE;
		++pos;
	}
	len = pos;
	update();
}
void BigNum::print()
{
	INT i;
	if (sign)
	{
		printf("-");
	}
	printf("%lld", digit[len - 1]);
	for (i = len - 2; i >= 0; --i)
	{
		//BE CAREFUL HERE
		switch (BASE)
		{
		case 10:
			printf("%lld", digit[i]);
			break;
		case 100:
			printf("%02lld", digit[i]);
			break;
		case 1000:
			printf("%03lld", digit[i]);
			break;
		case 10000:
			printf("%04lld", digit[i]);
			break;
		case 100000:
			printf("%05lld", digit[i]);
			break;
		case 1000000:
			printf("%06lld", digit[i]);
			break;
		case 10000000:
			printf("%07lld", digit[i]);
			break;
		case 100000000:
			printf("%08lld", digit[i]);
			break;
		case 1000000000:
			printf("%09lld", digit[i]);
			break;
		default:
			break;
		}
	}
}
void Prime_Table()
{
	int i, j;
	tp = 1;
	for (i = 2; i * i < MAXN;)
	{
		for (j = i + i; j < MAXN; j += i)
		{
			ss[j] = 1;
		}
		for (i++; ss[i]; i++)
			;
	}
	P[0] = 2;
	for (i = 3; i < MAXN; i += 2)
		if (!ss[i])
		{
			P[tp++] = i;
		}
}
void Count(int n, int k)
{
	int i, j, p;
	if (n <= 1)
		return;
	for (i = 0; i < tp && P[i] <= n; i++)
	{
		p = 0;
		for (j = P[i]; j <= n; j *= P[i])
			p += n / j;
		Res[i] += k * p;
	}
}
void ReadNumerator(int n)
{
	int p, q;
	while (n--)
	{
		scanf("%d%d", &p, &q);
		Count(p, 1);
		Count(q, -1);
		Count(p - q, -1);
		if (p > max_)
			max_ = p;
	}
}
void ReadDenominator(int m)
{
	int p, q;
	while (m--)
	{
		scanf("%d%d", &p, &q);
		Count(p, -1);
		Count(q, 1);
		Count(p - q, 1);
		if (p > max_)
			max_ = p;
	}
}
void Free()
{
	int i;
	for (i = 0; P[i] <= max_; i++)
	{
		Res[i] = 0;
	}
}
int Digits()
{
	int dig = 0, i, j;
	double x = 0.0;
	for (i = 0; P[i] <= max_; i++)
		x += Res[i] * log10(double(P[i]));
	j = int(x);
	return j + 1;
}
void Product()
{
	int i, j;
	BigNum dum;
	dum = 1;
	for (i = 0; i < tp && P[i] <= max_; i++)
	{
		if (!Res[i])
		{
			continue;
		}
		for (j = 1; j <= Res[i]; j++)
		{
			dum.mult(dum, P[i]);
		}
	}
	dum.print();
	printf("\n");
}
int isDivisible()
{
	int i;
	for (i = 0; P[i] <= max_ && i < tp; i++)
		if (Res[i] < 0)
			return 0;
	return 1;
}
void Cal()
{
	int dg;
	if (!isDivisible())
	{
		printf("0\n");
		return;
	}
	dg = Digits();
	if (dg > 100)
	{
		printf("-1\n");
		return;
	}
	Product();
}

int main()
{
	int n, m;
	Prime_Table();
	while (scanf("%d%d", &n, &m) == 2)
	{
		max_ = 0;
		ReadNumerator(n);
		ReadDenominator(m);
		Cal();
		Free();
	}
	return 0;
}
