#include <bits/stdc++.h>

using namespace std;

typedef long long big;

char dig[70][50];
char temp[32];

void Rev(char *ss)
{
	int i, l = strlen(ss) - 1;
	int j = l, t;
	l /= 2;
	for (i = 0; i <= l; i++)
	{
		t = ss[i];
		ss[i] = ss[j];
		ss[j--] = t;
	}
	strcpy(temp, ss);
}
void Gen()
{
	int i, j, k, carry, d;
	strcpy(dig[1], "1");
	strcpy(dig[2], "3");
	for (i = 3; i < 65; i++)
	{
		carry = d = 0;
		for (j = strlen(dig[i - 1]) - 1; j >= 0; j--)
		{
			k = (dig[i - 1][j] - '0') * 3 + carry;
			temp[d++] = (k % 10) + '0';
			carry = k / 10;
		}
		if (carry)
		{
			temp[d++] = carry + '0';
		}
		temp[d] = '\0';
		Rev(temp);
		strcpy(dig[i], temp);
	}
}
void Cal(big n)
{
	int d = 1, m = 0, i;
	int A[70];
	while (n)
	{
		if (n % 2)
		{
			A[m++] = d;
		}
		n /= 2;
		d++;
	}
	printf("{ ");
	for (i = 0; i + 1 < m; i++)
	{
		printf("%s, ", dig[A[i]]);
	}
	printf("%s }\n", dig[A[m - 1]]);
}

int main()
{
	big n;
	Gen();
	while (scanf("%llu", &n), n)
	{
		if (n == 1)
		{
			printf("{ }\n");
			continue;
		}
		Cal(n - 1);
	}
	return 0;
}
