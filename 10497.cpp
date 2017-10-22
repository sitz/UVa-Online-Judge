#include <bits/stdc++.h>

using namespace std;

#define MAXDIGITS 2000
#define PLUS 1
#define MINUS -1
#define max(a, b) ((a > b) ? a : b)

typedef struct
{
	char digits[MAXDIGITS];
	int signbit;
	int lastdigit;
} bignum;

void print_bignum(bignum *n);
void int_to_bignum(int s, bignum *n);
void initialize_bignum(bignum *n);
int add_bignum(bignum *a, bignum *b, bignum *c);
int subtract_bignum(bignum *a, bignum *b, bignum *c);
int compare_bignum(bignum *a, bignum *b);

void int_to_bignum(int s, bignum *n)
{
	if (s >= 0)
	{
		n->signbit = PLUS;
	}
	else
	{
		n->signbit = MINUS;
	}
	int t = abs(s);
	sprintf(n->digits, "%d", t);
	n->lastdigit = strlen(n->digits);
}
void int_to_bignum(char *s, bignum *n)
{
	int i;
	if (s[0] != -1)
	{
		n->signbit = PLUS;
		i = 0;
	}
	else
	{
		i = 1;
		n->signbit = MINUS;
	}
	strcpy(n->digits, &s[i]);
	n->lastdigit = strlen(n->digits);
}
void initialize_bignum(bignum *n)
{
	int_to_bignum(0, n);
}
int add_bignum(bignum *a, bignum *b, bignum *c)
{
	int carry; /* carry digit */
	int i, j, op = 0;
	; /* counter */
	int n_carry;
	initialize_bignum(c);
	if (a->signbit == b->signbit)
	{
		c->signbit = a->signbit;
	}
	else
	{
		if (a->signbit == MINUS)
		{
			a->signbit = PLUS;
			n_carry = subtract_bignum(b, a, c);
			a->signbit = MINUS;
		}
		else
		{
			b->signbit = PLUS;
			n_carry = subtract_bignum(a, b, c);
			b->signbit = MINUS;
		}
		return n_carry;
	}
	if (a->lastdigit < b->lastdigit)
	{
		return add_bignum(b, a, c);
	}
	int k = c->lastdigit = a->lastdigit + 1;
	c->digits[k--] = '\0';
	carry = 0;
	n_carry = 0;
	for (i = b->lastdigit - 1, j = a->lastdigit - 1; i >= 0; i--, j--)
	{
		carry = b->digits[i] - '0' + a->digits[j] - '0' + carry;
		c->digits[k--] = (carry % 10) + '0';
		carry = carry / 10;
		if (carry)
		{
			n_carry++;
		}
	}
	for (; j >= 0; j--)
	{
		carry = a->digits[j] - '0' + carry;
		c->digits[k--] = (carry % 10) + '0';
		carry = carry / 10;
		if (carry)
		{
			n_carry++;
		}
	}
	if (carry)
	{
		c->digits[k] = carry + '0';
	}
	else
	{
		char string[MAXDIGITS];
		strcpy(string, &c->digits[1]);
		strcpy(c->digits, string);
	}
	c->lastdigit = c->lastdigit - k - 1;
	return n_carry;
}
int subtract_bignum(bignum *a, bignum *b, bignum *c)
{
	register int i, j, op = 0;
	; /* counter */
	int n_borrow;
	int temp;
	c->signbit = PLUS;
	if ((a->signbit == MINUS) || (b->signbit == MINUS))
	{
		b->signbit = -1 * b->signbit;
		n_borrow = add_bignum(a, b, c);
		b->signbit = -1 * b->signbit;
		return n_borrow;
	}
	if (compare_bignum(a, b) == PLUS)
	{
		n_borrow = subtract_bignum(b, a, c);
		c->signbit = MINUS;
		return n_borrow;
	}
	int k = c->lastdigit = max(a->lastdigit, b->lastdigit);
	n_borrow = 0;
	c->digits[k--] = '\0';
	for (i = a->lastdigit - 1, j = b->lastdigit - 1; j >= 0; i--, j--)
	{
		temp = a->digits[i] - '0' - (b->digits[j] - '0' + op);
		if (temp < 0)
		{
			temp += 10;
			op = 1;
			n_borrow++;
		}
		else
		{
			op = 0;
		}
		c->digits[k--] = temp + '0';
	}
	while (op)
	{
		temp = a->digits[i--] - op - '0';
		if (temp < 0)
		{
			temp += 10;
			op = 1;
			n_borrow++;
		}
		else
		{
			op = 0;
		}
		c->digits[k--] = temp + '0';
	}
	for (; i >= 0; i--)
	{
		c->digits[k--] = a->digits[i];
	}
	for (i = 0; !(c->digits[i] - '0'); i++)
		;
	c->lastdigit = c->lastdigit - i;
	if (i == a->lastdigit)
	{
		strcpy(c->digits, "0");
	}
	else
	{
		char string[MAXDIGITS];
		strcpy(string, &c->digits[i]);
		strcpy(c->digits, string);
	}
	return n_borrow;
}
int compare_bignum(bignum *a, bignum *b)
{
	int i; /* counter */
	if ((a->signbit == MINUS) && (b->signbit == PLUS))
	{
		return (PLUS);
	}
	if ((a->signbit == PLUS) && (b->signbit == MINUS))
	{
		return (MINUS);
	}
	if (b->lastdigit > a->lastdigit)
	{
		return (PLUS * a->signbit);
	}
	if (a->lastdigit > b->lastdigit)
	{
		return (MINUS * a->signbit);
	}
	for (i = 0; i < a->lastdigit; i++)
	{
		if (a->digits[i] > b->digits[i])
		{
			return (MINUS * a->signbit);
		}
		if (b->digits[i] > a->digits[i])
		{
			return (PLUS * a->signbit);
		}
	}
	return (0);
}
void multiply_bignum(bignum *a, bignum *b, bignum *c)
{
	long int n_d;
	register long int i, j, k;
	short int num1[MAXDIGITS], num2[MAXDIGITS], of = 0, res[MAXDIGITS] = {0};
	n_d = (a->lastdigit < b->lastdigit) ? b->lastdigit : a->lastdigit;
	n_d++;
	for (i = 0, j = a->lastdigit - 1; i < a->lastdigit; i++, j--)
	{
		num1[i] = a->digits[j] - 48;
	}
	for (i = 0, j = b->lastdigit - 1; i < b->lastdigit; j--, i++)
	{
		num2[i] = b->digits[j] - 48;
	}
	res[0] = 0;
	for (j = 0; j < b->lastdigit; j++)
	{
		for (i = 0, k = j; i < a->lastdigit || of; k++, i++)
		{
			if (i < a->lastdigit)
			{
				res[k] += num1[i] * num2[j] + of;
			}
			else
			{
				res[k] += of;
			}
			of = res[k] / 10;
			res[k] = res[k] % 10;
		}
	}
	for (i = k - 1, j = 0; i >= 0; i--, j++)
	{
		c->digits[j] = res[i] + 48;
	}
	c->digits[j] = '\0';
	c->lastdigit = k;
	c->signbit = a->signbit * b->signbit;
}
bignum f[802];
void Cal()
{
	bignum n1, n2, n3;
	int i;
	char temp[2000], dummy[2000];
	strcpy(temp, "1");
	strcpy(dummy, "0");
	for (i = 3; i <= 800; i++)
	{
		int_to_bignum(temp, &f[i - 1]);
		int_to_bignum(dummy, &f[i - 2]);
		add_bignum(&f[i - 1], &f[i - 2], &n1);
		int_to_bignum(i - 1, &n2);
		strcpy(temp, n1.digits);
		strcpy(dummy, n2.digits);
		int_to_bignum(temp, &n1);
		int_to_bignum(dummy, &n2);
		multiply_bignum(&n1, &n2, &n3);
		strcpy(f[i].digits, n3.digits);
		n3.digits[0] = NULL;
		strcpy(temp, f[i].digits);
		strcpy(dummy, f[i - 1].digits);
	}
}
int main()
{
	int n;
	Cal();
	while (scanf("%d", &n) == 1)
	{
		if (n < 0)
		{
			break;
		}
		if (n == 0 || n == 1)
		{
			printf("0\n");
			continue;
		}
		printf("%s\n", f[n].digits);
	}
	return 0;
}
