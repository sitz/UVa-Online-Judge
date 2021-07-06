#include <bits/stdc++.h>

using namespace std;

char s1[10002], num[10002], s2[20002];
int l1, l2, K, F1[30], F2[30];

int Pro(int k)
{
	int i, f = 0, l3;
	l1 = strlen(s1);
	l2 = strlen(s2);
	l3 = strlen(num);
	if (k != l1 + l2 + l3 + 2)
		return 0;
	if (l3 > 4)
		return 0;
	for (i = 0; i < l1; i++)
	{
		if (isupper(s1[i]) || !isalpha(s1[i]))
			return 0;
		F1[s1[i] - 'a']++;
	}
	for (i = 0; i < l2; i++)
	{
		if (isupper(s2[i]) || !isalpha(s2[i]))
			return 0;
		F2[s2[i] - 'a']++;
	}
	if (l1 == 0 || l1 > 1000 || l2 > 2000 || l2 == 0)
		return 0;
	for (i = 0; num[i]; i++)
		if (!isdigit(num[i]))
			return 0;
	K = atoi(num);
	if (K > 1000)
		return 0;
	return 1;
}

int isP(int lo, int up)
{
	if (s2[lo] != s2[up])
		return 0;
	if (lo >= up)
		return 1;
	return isP(lo + 1, up - 1);
}

int App()
{
	int i;
	for (i = 0; i < 26; i++)
		if (F1[i] > 0 && F2[i] == 0)
			return 0;
	return 1;
}

int Fre()
{
	for (int i = 0; i < 26; i++)
		if (F1[i] > F2[i])
			return 0;
	return 1;
}

int From()
{
	int i, j, k = 0, f;
	for (i = 0; i < l1; i++)
	{
		f = 1;
		for (j = k; j < l2; j++)
		{
			if (s1[i] == s2[j])
			{
				f = 0;
				k = j + 1;
				break;
			}
		}
		if (f)
			return 0;
	}
	return 1;
}

int Len()
{
	if (l2 != l1 + K)
		return 0;
	return 1;
}

int Len2()
{
	if (K >= l1)
		return 0;
	return 1;
}

int Cal(int k)
{
	int f = 0, d;
	if (!Pro(k))
	{
		printf("FFFFFFF");
		return 0;
	}
	printf("T");//
	d = isP(0, l2 - 1);
	if (!d)
	{
		printf("F");
		f = 1;
	}
	else
	{
		printf("T");
	}
	d = App();
	if (!d)
	{
		printf("F");
		f = 1;
	}
	else
	{
		printf("T");//
	}
	d = Fre();
	if (!d)
	{
		printf("F");
		f = 1;
	}
	else
	{
		printf("T");//
	}
	d = From();
	if (!d)
	{
		printf("F");
		f = 1;
	}
	else
	{
		printf("T");//
	}
	d = Len();
	if (!d)
	{
		printf("F");
		f = 1;
	}
	else
	{
		printf("T");//
	}
	d = Len2();
	if (!d)
	{
		printf("F");
		f = 1;
	}
	else
		printf("T");//
	if (f)
		return 0;
	return 1;
}

int main()
{
	int d, l;
	char input[5002];
	while (gets(input))
	{
		l = strlen(input);
		sscanf(input, "%s%s%s", s1, num, s2);
		d = Cal(l);
		if (d)
			printf(" The solution is accepted\n");
		else
			printf(" The solution is not accepted\n");
		memset(F1, 0, sizeof(int) * 30);
		memset(F2, 0, sizeof(int) * 30);
	}
	return 0;
}
