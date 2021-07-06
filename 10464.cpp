#include <bits/stdc++.h>

using namespace std;

char num1[3000], num2[3000], dec1[2000], dec2[2000], frk1[2000], frk2[2000];
char n1[2000], n2[2000];
int big1, big2;

int sep()
{
	int i, p1, p2, k, m;
	int l1, l2;
	k = 0;
	m = 0;
	strcpy(n1, num1);
	strcpy(n2, num2);
	l1 = strlen(num1);
	l2 = strlen(num2);
	if (num1[0] == '-')
	{
		n1[0] = 'A';
	}
	if (num2[0] == '-')
	{
		n2[0] = 'A';
	}
	for (i = 0; n1[i] != '.'; i++)
		;
	p1 = i;
	for (i = 0; n2[i] != '.'; i++)
		;
	p2 = i;
	for (i = p1 + 1; i < l1; i++)
	{
		frk1[k++] = n1[i];
	}
	frk1[k] = NULL;
	for (i = p2 + 1; i < l2; i++)
	{
		frk2[m++] = n2[i];
	}
	frk2[m] = NULL;
	if (k > m)
	{
		for (i = m; i < k; i++)
		{
			frk2[i] = 'A';
		}
		frk2[i] = NULL;
	}
	else if (m > k)
	{
		for (i = k; i < m; i++)
		{
			frk1[i] = 'A';
		}
		frk1[i] = NULL;
	}
	k = m = 0;
	for (i = p1 - 1; i >= 0; i--)
	{
		dec1[k++] = n1[i];
	}
	dec1[k] = NULL;
	if (k == 0)
	{
		dec1[k++] = 'A';
		dec1[k] = NULL;
	}
	for (i = p2 - 1; i >= 0; i--)
	{
		dec2[m++] = n2[i];
	}
	dec2[m] = NULL;
	if (m == 0)
	{
		dec2[m++] = 'A';
		dec2[m] = NULL;
	}
	if (k > m)
	{
		for (i = m; i < k; i++)
		{
			dec2[i] = 'A';
		}
		dec2[i] = NULL;
	}
	else if (m > k)
	{
		for (i = k; i < m; i++)
		{
			dec1[i] = 'A';
		}
		dec1[i] = NULL;
	}
	return 0;
}
int add()
{
	char mid1[3000], mid2[3000];
	int i, j, k, l, m;
	int cary, sum;
	l = strlen(frk1);
	cary = 0;
	k = 0;
	m = 0;
	for (i = l - 1; i >= 0; i--)
	{
		sum = (frk1[i] % 65) + (frk2[i] % 65) + cary;
		mid1[k++] = sum % 10;
		cary = sum / 10;
	}
	for (i = 0; dec1[i]; i++)
	{
		sum = (dec1[i] % 65) + (dec2[i] % 65) + cary;
		mid2[m++] = sum % 10;
		cary = sum / 10;
	}
	if (cary)
	{
		mid2[m++] = cary;
	}
	for (i = m - 1; !mid2[i] && i >= 0; i--)
		;
	if (i < 0)
	{
		printf("0");
	}
	else
		for (j = i; j >= 0; j--)
		{
			printf("%d", mid2[j]);
		}
	printf(".");
	for (i = 0; !mid1[i]; i++)
		;
	if (i >= k)
	{
		printf("0");
	}
	else
		for (j = k - 1; j >= i; j--)
		{
			printf("%d", mid1[j]);
		}
	printf("\n");
	return 0;
}
int sorter()
{
	int i, j, l, l1;
	l = strlen(dec1);
	l1 = strlen(frk1);
	big1 = 0;
	big2 = 0;
	for (i = l - 1; i >= 0; i--)
	{
		if ((dec1[i] % 65) > (dec2[i] % 65))
		{
			big1 = 1;
			goto done;
		}
		else if ((dec1[i] % 65) < (dec2[i] % 65))
		{
			big2 = 1;
			goto done;
		}
	}
	for (i = 0; i < l1; i++)
	{
		if ((frk1[i] % 65) > (frk2[i] % 65))
		{
			big1 = 1;
			goto done;
		}
		else if ((frk1[i] % 65) < (frk2[i] % 65))
		{
			big2 = 1;
			goto done;
		}
	}
	big1 = 1;
done:;
	return 0;
}
int sub()
{
	char dgr[1000], dso[1000], frg[1000], frs[1000];
	char sub1[1000], sub2[1000];
	int i, m, n, d, j, l, cary, k, p;
	if (big1)
	{
		strcpy(dgr, dec1);
		strcpy(dso, dec2);
		strcpy(frg, frk1);
		strcpy(frs, frk2);
		if (num1[0] == '-')
		{
			printf("-");
		}
	}
	else
	{
		strcpy(dgr, dec2);
		strcpy(dso, dec1);
		strcpy(frg, frk2);
		strcpy(frs, frk1);
		if (num2[0] == '-')
		{
			printf("-");
		}
	}
	l = strlen(frg);
	cary = 0;
	k = 0;
	p = 0;
	for (i = l - 1; i >= 0; i--)
	{
		m = frg[i] % 65;
		n = (frs[i] % 65) + cary;
		if (m < n)
		{
			m += 10;
			cary = 1;
		}
		else
		{
			cary = 0;
		}
		sub1[k++] = m - n;
	}
	for (i = 0; dgr[i]; i++)
	{
		m = dgr[i] % 65;
		n = (dso[i] % 65) + cary;
		if (m < n)
		{
			m += 10;
			cary = 1;
		}
		else
		{
			cary = 0;
		}
		sub2[p++] = m - n;
	}
	for (i = p - 1; !sub2[i] && i >= 0; i--)
		;
	if (i < 0)
	{
		printf("0");
	}
	else
		for (j = i; j >= 0; j--)
		{
			printf("%d", sub2[j]);
		}
	printf(".");
	for (i = 0; !sub1[i]; i++)
		;
	if (i >= k)
	{
		printf("0");
	}
	else
		for (j = k - 1; j >= i; j--)
		{
			printf("%d", sub1[j]);
		}
	printf("\n");
	return 0;
}
int main()
{
	int i, j, kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%s%s", num1, num2);
		for (i = 0; num1[i]; i++)
			if (isdigit(num1[i]))
			{
				if (num1[i] > 48)
				{
					num1[i] = num1[i] - 48;
				}
				else
				{
					num1[i] = 'A';
				}
			}
		for (i = 0; num2[i]; i++)
			if (isdigit(num2[i]))
			{
				if (num2[i] > 48)
				{
					num2[i] = num2[i] - 48;
				}
				else
				{
					num2[i] = 'A';
				}
			}
		sep();
		if (num1[0] != '-' && num2[0] != '-')
		{
			add();
			continue;
		}
		if (num1[0] == '-' && num2[0] == '-')
		{
			printf("-");
			add();
			continue;
		}
		sorter();
		sub();
	}
	return 0;
}
