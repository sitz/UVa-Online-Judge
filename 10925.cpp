#include <bits/stdc++.h>

using namespace std;

#define BASE 1000000
#define MAX_DIGIT 350

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long INT;

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
	void div(BigNum, INT, INT &);			 //ok- , third param is the remainder
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
/*
  while providing 's', ensure that there
  are no leading spaces in it
*/
void BigNum::operator=(char *s)
{
	INT i, v, p;
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
  -1                less
*/
INT BigNum::comp(BigNum n)
{
	INT i;
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
INT BigNum::absComp(BigNum n)
{
	INT i;
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
	INT pos, borrow, t;
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
	//assert(borrow == 0);//, "|B| > |A|; can't handle this");
}
void BigNum::absAdd(BigNum a, BigNum b)
{
	INT pos, carry;
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
void BigNum::add(BigNum a, INT n)
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
void BigNum::subtract(BigNum a, INT n)
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
void BigNum::mult(BigNum a, BigNum b)
{
	INT i, pos;
	clear();
	for (pos = 0; pos < b.len; ++pos)
	{
		multAndAdd(a, b.digit[pos], pos);
	}
	sign = (a.sign + b.sign) % 2;
}
void BigNum::div(BigNum a, INT s, INT &r)
{
	INT pos;
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
	INT i, pos, lower, upper, mid;
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
	r = (INT)0;
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
	INT i;
	if (sign)
	{
		printf("-");
	}
	printf("%ld", digit[len - 1]);
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
			printf("%03ld", digit[i]);
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
/* ----------------------------------- Big Integer Class
-----------------------------*/
void Cal(int n, int f)
{
	BigNum a, b, d, e;
	char nn[100];
	a = "0";
	while (n--)
	{
		gets(nn);
		b = nn;
		d.add(a, b);
		a = d;
	}
	b = f;
	printf("costs ");
	a.print();
	printf(": each friend should pay ");
	d.div(a, b, e);
	d.print();
	printf("\n");
}
int main()
{
	char st[100];
	int N, F, k = 1;
	while (gets(st))
	{
		sscanf(st, "%d%d", &N, &F);
		if (!N && !F)
		{
			break;
		}
		printf("Bill #%d ", k++);
		Cal(N, F);
		printf("\n");
	}
	return 0;
}
