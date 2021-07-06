#include <bits/stdc++.h>

using namespace std;

char ss[2][1000][70], temp[100], limit[100];

void ADD(char n[], char m[])
{
	char dummy[100];
	int j = 0, s, ln1, ln2, p, q, i;
	int carry = 0;
	ln1 = strlen(n) - 1;
	ln2 = strlen(m) - 1;
	for (;;)
	{
		p = 0;
		if (ln1 >= 0)
			p = n[ln1--] - '0';

		q = 0;
		if (ln2 >= 0)
			q = m[ln2--] - '0';

		s = p + q + carry;
		dummy[j++] = s % 10 + '0';
		carry = s / 10;
		if (ln1 < 0 && ln2 < 0)
			break;
	}
	if (carry)
		dummy[j++] = carry + '0';
	p = 0;
	dummy[j] = NULL;
	for (i = j - 1; i >= 0; i--)
		temp[p++] = dummy[i];
	temp[p] = NULL;
}
int IsBIG(char m[])
{
	int i;
	if (strlen(m) < 61)
		return 0;
	if (strlen(m) > 61)
		return 1;
	for (i = 0; i < 61; i++)
	{
		if (m[i] > limit[i])
			return 1;
		if (m[i] < limit[i])
			return 0;
	}
	return 1;
}
void Cal()
{
	int j, f = 0, s = 1, n = 1, k = 0, x = 2;
	printf("1\n");
	printf("1 1\n");
	strcpy(ss[0][0], "1");
	strcpy(ss[0][1], "1");
	for (;;)
	{
		strcpy(ss[s][0], "1");
		printf("1");
		for (j = 1; j <= n; j++)
		{
			ADD(ss[f][j - 1], ss[f][j]);
			if (IsBIG(temp))
				k = 1;
			printf(" %s", temp);
			strcpy(ss[s][j], temp);
		}
		n++;
		printf(" 1\n");
		x++;
		if (k)
			break;
		strcpy(ss[s][j], "1");
		s++;
		s %= 2;
		f++;
		f %= 2;
	}
}

int main()
{
	int i;
	limit[0] = '1';
	for (i = 1; i <= 60; i++)
		limit[i] = '0';
	limit[61] = NULL;
	Cal();
	return 0;
}
