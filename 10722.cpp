#include <bits/stdc++.h>

using namespace std;

#define MAXN 102
#define BASE 10000
#define MAX_DIGIT 250

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef long INT;

INT B, N;

struct BigNum
{
	INT sign, len, digit[MAX_DIGIT];
	void multAndAdd(BigNum, INT, INT);
	void absSubtract(BigNum, BigNum);

	void operator=(INT);
	void operator=(BigNum);
	void mult(BigNum, INT);
	void add(BigNum, BigNum);
	void subtract(BigNum, BigNum);
	void absAdd(BigNum, BigNum);
	void mult(BigNum, BigNum);
	void print();
	void clear();
	void update();
	BigNum()
	{
		clear();
	}
};
BigNum Res[129][100];
BigNum per[129][100];
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
}
void BigNum::mult(BigNum a, INT s)
{
	INT pos, carry;
	if (s < 0)
	{
		sign = 1 - a.sign;
		a = -s;
	}
	else
	{
		sign = a.sign;
	}
	carry = 0;
	for (pos = 0; pos < a.len; ++pos)
	{
		digit[pos] = a.digit[pos] * s + carry;
		carry = digit[pos] / BASE;
		digit[pos] %= BASE;
	}
	pos = a.len;
	while (carry != 0)
	{
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
	INT pos;
	clear();
	for (pos = 0; pos < b.len; ++pos)
	{
		multAndAdd(a, b.digit[pos], pos);
	}
	sign = (a.sign + b.sign) % 2;
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
	for (i = 0; i < len; ++i)
	{
		digit[i] = n.digit[i];
	}
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
		absSubtract(a, b);
		sign = a.sign;
	}
}
void BigNum::absAdd(BigNum a, BigNum b)
{
	INT pos, carry = 0;
	for (pos = 0; pos < max(a.len, b.len); ++pos)
	{
		digit[pos] = a.digit[pos] + b.digit[pos] + carry;
		carry = digit[pos] / BASE;
		digit[pos] %= BASE;
	}
	if (carry)
	{
		digit[max(a.len, b.len)] = carry;
		len = max(a.len, b.len) + 1;
	}
	else
	{
		len = max(a.len, b.len);
	}
	update();
}
void BigNum::subtract(BigNum a, BigNum b)
{
	BigNum t;
	clear();
	t = b;
	t.sign = 1 - b.sign;
	add(a, t);
}
void BigNum::clear()
{
	sign = len = 0;
	memset(digit, 0, sizeof(digit));
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
void BigNum::print()
{
	INT i;
	printf("%ld", digit[len - 1]);
	for (i = len - 2; i >= 0; --i)
	{
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
		}
	}
}
void Dynamic(int b)
{
	INT i;
	BigNum temp, dummy;
	Res[b][1] = b;
	per[b][1] = 1;
	for (i = 2; i < 100; i++)
	{
		per[b][i] = Res[b][i - 1];
		temp.mult(Res[b][i - 1], (b - 1));
		dummy.subtract(Res[b][i - 1], per[b][i - 1]);
		temp.add(temp, dummy);
		Res[b][i] = temp;
	}
}
void Gen()
{
	int i;
	for (i = 4; i < 129; i++)
	{
		Dynamic(i);
	}
}
void Cal()
{
	BigNum temp, dummy;
	if (N == 0)
	{
		printf("0\n");
		return;
	}
	if (N == 1)
	{
		printf("%ld\n", B - 1);
		return;
	}
	dummy.mult(Res[B][N - 1], B - 2);
	temp.subtract(Res[B][N - 1], per[B][N - 1]);
	dummy.add(dummy, temp);
	dummy.print();
	printf("\n");
}

int main()
{
	Gen();
	while (scanf("%ld%ld", &B, &N) == 2)
	{
		if (!B && !N)
			break;
		Cal();
	}
	return 0;
}
