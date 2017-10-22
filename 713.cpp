#include <bits/stdc++.h>

using namespace std;

class High_Precision
{
public:
	High_Precision()
	{
		memset(array, 0, sizeof(array));
		len = 0;
	}
	void GetNumber(char *p);
	void PrintHP();
	int array[1000], len;
};

void High_Precision::PrintHP()
{
	int i, cnt = 0;
	for (i = 0; i < len; i++)
		if (array[i] == 0)
		{
			cnt++;
		}
	if (cnt == len)
	{
		cout << 0;
		return;
	}
	i = 0;
	while (array[i] == 0)
	{
		i++;
	}
	while (array[len - 1] == 0)
	{
		len--;
	}
	for (; i < len; i++)
	{
		cout << array[i];
	}
}

void High_Precision::GetNumber(char *p)
{
	int i;
	len = (int)strlen(p);
	for (i = 0; i < len; i++)
	{
		array[i] = p[i] - '0';
	}
}

void Plus(High_Precision &a, High_Precision &b, High_Precision &c)
{
	int length, flag = 0, i, sum;
	if (a.len >= b.len)
	{
		length = a.len;
	}
	else
	{
		length = b.len;
	}
	c.len = length;
	for (i = 0; i < length; i++)
	{
		sum = a.array[i] + b.array[i] + flag;
		if (sum >= 10)
		{
			sum %= 10;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
		c.array[i] = sum;
	}
	if (flag == 1)
	{
		c.array[length] = 1;
		c.len++;
	}
}

int main()
{
	int n, t;
	char pa[500], pb[500];
	cin >> n;
	for (t = 0; t < n; t++)
	{
		High_Precision a, b, c;
		cin >> pa >> pb;
		a.GetNumber(pa);
		b.GetNumber(pb);
		Plus(a, b, c);
		c.PrintHP();
		cout << endl;
	}
	return 0;
}
