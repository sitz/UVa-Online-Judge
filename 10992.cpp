#include <bits/stdc++.h>

using namespace std;

typedef long int ll;

#define BASE 1000
#define MAX_DIGIT 100

struct BigNum
{
	int sign, len;
	ll digit[MAX_DIGIT];
	void absAdd(BigNum, BigNum);
	void absSubtract(BigNum, BigNum);
	void multAndAdd(BigNum, int, int);

	void operator=(int);							 //ok
	void operator=(BigNum);						 //ok
	void operator=(char *);						 //ok
	void add(BigNum, int);						 //ok-
	void add(BigNum, BigNum);					 //ok-
	void subtract(BigNum, int);				 //ok-
	void subtract(BigNum, BigNum);		 //ok-
	void mult(BigNum, int);						 //ok-
	void mult(BigNum, BigNum);				 //ok-
	void div(BigNum, int, int &);			 //ok-, 3rd param: remainder
	void div(BigNum, BigNum, BigNum &);//ok-
	int comp(BigNum);									 //ok-
	int absComp(BigNum);							 //ok-
	void print();											 //ok-
	void update();										 //ok-
	void clear();											 //ok-
	string Rem(BigNum);
	BigNum()
	{
		clear();
	}
};
string BB;
void BigNum::operator=(int x)
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
	int i;
	clear();
	len = n.len;
	sign = n.sign;
	for (i = 0; i < len; ++i)
		digit[i] = n.digit[i];
}
/*
  while providing 's', ensure that there
  are no leading spaces in it
*/
void BigNum::operator=(char *s)
{
	int i, v, p;
	clear();
	p = 1;
	i = strlen(s) - 1;
	for (v = 0; i >= 0; i--)
	{
		if (s[i] == '-')
		{
			--i;
			sign = 1;
			break;
		}
		else if (s[i] == '+')
		{
			--i;
			break;
		}
		if (s[i] < '0' || s[i] > '9')
		{
			continue;
		}
		v = v + (s[i] - '0') * p;
		p *= 10;
		if (p == BASE)
		{
			digit[len++] = v;
			p = 1;
			v = 0;
		}
	}
	if (v)
	{
		digit[len++] = v;
	}
	update();
}
/*
  return value <===> meaning
  0             equal
  1             greater
  -1            less
*/
int BigNum::comp(BigNum n)
{
	int i;
	if (sign < n.sign)
	{
		return 1;
	}
	if (sign > n.sign)
	{
		return -1;
	}
	i = max(len, n.len) - 1;
	for (; i >= 0; --i)
	{
		if (digit[i] > n.digit[i])
		{
			if (sign == 0)
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}
	return 0;
}
int BigNum::absComp(BigNum n)
{
	int i;
	if (len < n.len)
	{
		return -1;
	}
	if (len > n.len)
	{
		return 1;
	}
	for (i = len - 1; i >= 0; --i)
	{
		if (digit[i] > n.digit[i])
		{
			return 1;
		}
		else if (digit[i] < n.digit[i])
		{
			return -1;
		}
	}
	return 0;
}
void BigNum::absSubtract(BigNum a, BigNum b)
{
	int pos, borrow, t;
	borrow = 0;
	t = max(a.len, b.len);
	for (pos = 0; pos < t; ++pos)
	{
		digit[pos] = a.digit[pos] - b.digit[pos] - borrow;
		if (digit[pos] < 0)
		{
			digit[pos] += BASE;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		if (digit[pos] != 0)
		{
			len = pos + 1;
		}
	}
	update();
}
void BigNum::absAdd(BigNum a, BigNum b)
{
	int pos, carry;
	carry = 0;
	for (pos = 0; pos < max(a.len, b.len); ++pos)
	{
		digit[pos] = a.digit[pos] + b.digit[pos] + carry;
		carry = digit[pos] / BASE;
		digit[pos] %= BASE;
	}
	if (carry != 0)
	{
		//check for overflow
		digit[max(a.len, b.len)] = carry;
		len = max(a.len, b.len) + 1;
	}
	else
	{
		len = max(a.len, b.len);
	}
	update();
}
void BigNum::add(BigNum a, int n)
{
	BigNum t;
	t = n;
	add(a, t);
}
void BigNum::add(BigNum a, BigNum b)
{
	clear();
	if (a.sign == b.sign)
	{
		absAdd(a, b);
		sign = a.sign;
	}
	else
	{
		if (a.absComp(b) >= 0)
		{
			absSubtract(a, b);
			sign = a.sign;
		}
		else
		{
			absSubtract(b, a);
			sign = b.sign;
		}
	}
}
void BigNum::subtract(BigNum a, int n)
{
	BigNum t;
	t = n;
	subtract(a, t);
}
void BigNum::subtract(BigNum a, BigNum b)
{
	BigNum t;
	clear();
	t = b;
	t.sign = 1 - b.sign;
	add(a, t);
}
void BigNum::mult(BigNum a, int s)
{
	int pos, carry;
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
void BigNum::multAndAdd(BigNum a, int s, int offset)
{
	int pos, carry;
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
void BigNum::mult(BigNum a, BigNum b)
{
	int pos;
	clear();
	for (pos = 0; pos < b.len; ++pos)
	{
		multAndAdd(a, b.digit[pos], pos);
	}
	sign = (a.sign + b.sign) % 2;
}
void BigNum::div(BigNum a, int s, int &r)
{
	int pos;
	r = 0;
	len = 0;
	sign = a.sign;
	if (s < 0)
	{
		sign = 1 - sign;
		s = -s;
	}
	for (pos = a.len - 1; pos >= 0; --pos)
	{
		r = r * BASE + a.digit[pos];
		digit[pos] = r / s;
		if (digit[pos] > 0 && pos >= len)
		{
			len = pos + 1;
		}
		r %= s;
	}
	update();
}
void BigNum::div(BigNum a, BigNum b, BigNum &r)
{
	int i, pos, lower, upper, mid;
	BigNum d, e, t;
	if (b.sign)
	{
		t = b;
		t.sign = 0;
		div(a, t, r);
		sign = 1 - a.sign;
		return;
	}
	for (i = 0; i < len; ++i)
	{
		digit[i] = 0;
	}
	len = 0;
	r = (int)0;
	for (pos = a.len - 1; pos >= 0; --pos)
	{
		r.mult(r, BASE);
		r.add(r, a.digit[pos]);
		lower = 0;
		upper = BASE - 1;
		while (upper > lower)
		{
			mid = (upper + lower) / 2 + 1;
			d.mult(b, mid);
			e.subtract(r, d);
			if (e.sign == 0)
			{
				lower = mid;
			}
			else
			{
				upper = mid - 1;
			}
		}
		digit[pos] = lower;
		d.mult(b, lower);
		r.subtract(r, d);
		if (digit[pos] > 0 && pos >= len)
		{
			len = pos + 1;
		}
	}
	update();
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
void BigNum::print()
{
	int i;
	char ss[100];
	BB = "";
	if (sign)
	{
		printf("-");
	}
	sprintf(ss, "%ld", digit[len - 1]);
	BB += ss;
	for (i = len - 2; i >= 0; --i)
	{
		//BE CAREFUL HERE
		switch (BASE)
		{
		case 10:
			printf("%ld", digit[i]);
			break;
		case 100:
			printf("%02ld", digit[i]);
			break;
		case 1000:
			sprintf(ss, "%03ld", digit[i]);
			BB += ss;
			break;
		case 10000:
			printf("%04ld", digit[i]);
			break;
		case 100000:
			printf("%05ld", digit[i]);
			break;
		case 1000000:
			printf("%06ld", digit[i]);
			break;
		case 10000000:
			printf("%07ld", digit[i]);
			break;
		case 100000000:
			printf("%08ld", digit[i]);
			break;
		case 1000000000:
			printf("%09ld", digit[i]);
			break;
		default:
			break;
		}
	}
}
string BigNum::Rem(BigNum b)
{
	int i;
	string A = "";
	char xx[100];
	for (i = b.len - 1; i >= 0; i--)
	{
		sprintf(xx, "%ld", b.digit[i]);
		A += xx;
	}
	return A;
}
int Zero(string A, int k)
{
	int i, c = 0, n, d;
	for (i = 0; i < (int)A.size(); i++)
	{
		n = A[i] - '0';
		d = c * 10 + n;
		c = d % k;
	}
	if (c == 0)
	{
		return 0;
	}
	return 1;
}
int Leap(string A)
{
	int d, k;
	d = Zero(A, 400);
	if (d == 0)
	{
		return 1;
	}
	d = Zero(A, 4);
	k = Zero(A, 100);
	if (d == 0 && k != 0)
	{
		return 1;
	}
	return 0;
}
void Cal(BigNum ini)
{
	BigNum a, z, x;
	string A;
	int pf, f = 0, d;
	a = "2148";
	d = ini.absComp(a);
	if (d < 0)
	{
		printf("No ghost will come in this year\n");
		return;
	}
	x.subtract(ini, a);
	ini.print();
	pf = Leap(BB);
	x.print();
	A = BB;
	if (Zero(A, 2) == 0)
	{
		printf("Ghost of Tanveer Ahsan!!!\n");
		f = 1;
	}
	if (Zero(A, 5) == 0)
	{
		printf("Ghost of Shahriar Manzoor!!!\n");
		f = 1;
	}
	if (Zero(A, 7) == 0)
	{
		printf("Ghost of Adrian Kugel!!!\n");
		f = 1;
	}
	if (Zero(A, 11) == 0)
	{
		printf("Ghost of Anton Maydell!!!\n");
		f = 1;
	}
	if (Zero(A, 15) == 0)
	{
		printf("Ghost of Derek Kisman!!!\n");
		f = 1;
	}
	if (Zero(A, 20) == 0)
	{
		printf("Ghost of Rezaul Alam Chowdhury!!!\n");
		f = 1;
	}
	if (Zero(A, 28) == 0)
	{
		printf("Ghost of Jimmy Mardell!!!\n");
		f = 1;
	}
	if (Zero(A, 36) == 0)
	{
		printf("Ghost of Monirul Hasan!!!\n");
		f = 1;
	}
	if (pf)
	{
		printf("Ghost of K. M. Iftekhar!!!\n");
		f = 1;
	}
	if (f == 0)
	{
		printf("No ghost will come in this year\n");
	}
}

int main()
{
	int k = 0;
	char st[1000];
	BigNum t, s, rem, x;
	x = "0";
	while (scanf("%s", st))
	{
		if (!strcmp(st, "0"))
			break;
		if (k++)
			printf("\n");
		printf("%s\n", st);
		t = st;
		Cal(t);
	}
	return 0;
}
