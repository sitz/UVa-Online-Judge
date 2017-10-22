#include <bits/stdc++.h>

using namespace std;

#define MAXN 10003
#define BASE 1000000
#define MAX_DIGIT 70

typedef long long INT;

struct BigNum
{
	INT sign, len, digit[MAX_DIGIT];
	void absAdd(BigNum, BigNum);

	void operator=(INT);		 //ok
	void operator=(BigNum);	//ok
	void operator=(char *);	//ok
	void add(BigNum, INT);	 //ok-
	void add(BigNum, BigNum);//ok-
	void print();						 //ok-
	void update();					 //ok-
	void clear();						 //ok-
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
	for (i = 0; i < len; ++i)
	{
		digit[i] = n.digit[i];
	}
}
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
	absAdd(a, b);
	sign = a.sign;
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
char X[MAXN], Z[120];
BigNum Table[2][MAXN];
int Equal()
{
	int i;
	for (i = 1; X[i]; i++)
	{
		if (X[i] != Z[i])
		{
			return 1;
		}
	}
	return 0;
}
void Assaign(int x)
{
	int i, p = 0, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j <= x; j++)
		{
			Table[i][j] = p;
		}
}
void Dynamic(int x, int z)
{
	int i, j, ind1 = 0, ind2 = 1;
	Assaign(x);
	for (i = 1; i <= x; i++)
	{
		if (X[i] == Z[1])
		{
			Table[1][i].add(Table[1][i], Table[1][i - 1]);
			Table[1][i].add(Table[1][i], 1);
		}
		else
		{
			Table[1][i] = Table[1][i - 1];
		}
	}
	for (i = 2; i <= z; i++)
	{
		for (j = 1; j <= x; j++)
		{
			if (Z[i] == X[j])
			{
				Table[ind1][j].add(Table[ind1][j - 1], Table[ind2][j - 1]);
			}
			else
			{
				Table[ind1][j] = Table[ind1][j - 1];
			}
		}
		ind1 = !ind1;
		ind2 = !ind2;
	}
	Table[ind2][x].print();
	printf("\n");
}
void Cal()
{
	int x, z;
	for (x = 1; X[x]; x++)
		;
	for (z = 1; Z[z]; z++)
		;
	x--;
	z--;
	if (x == z)
	{
		if (!Equal())
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
		return;
	}
	if (x < z)
	{
		printf("0\n");
		return;
	}
	Dynamic(x, z);
}

int main()
{
	int ks;
	char ss[20];
	gets(ss);
	sscanf(ss, "%d", &ks);
	while (ks--)
	{
		gets(X + 1);
		gets(Z + 1);
		Cal();
	}
	return 0;
}
