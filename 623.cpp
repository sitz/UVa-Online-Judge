#include <bits/stdc++.h>

using namespace std;

/**
623
**/
#define MAXDIGITS 2569
char FAC[1001][MAXDIGITS];
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
int abs(int a)
{
	return a < 0 ? -a : a;
}
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
void copy(bignum *a, bignum *b)
{
	a->lastdigit = b->lastdigit;
	a->signbit = b->signbit;
	strcpy(a->digits, b->digits);
}
int main()
{
	int a;
	bignum n1, n2, n3;
	int_to_bignum(1, &n2);
	for (a = 1; a <= 1000; a++)
	{
		int_to_bignum(a, &n1);
		multiply_bignum(&n1, &n2, &n3);
		strcpy(FAC[a], n3.digits);
		copy(&n2, &n3);
	}
	while (scanf("%d", &a) == 1)
	{
		printf("%d!\n", a);
		if (!a)
		{
			printf("1\n");
			continue;
		}
		printf("%s\n", FAC[a]);
	}
	return 0;
}
