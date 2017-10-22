#include <bits/stdc++.h>

using namespace std;

unsigned long long int table[130][130];
char str[300];
unsigned long long int count(int left, int right)
{
	if (left == right)
	{
		return 1ull;
	}
	if (table[left][right])
	{
		return table[left][right];
	}
	bool flag1 = false, flag2 = false, flag3;
	unsigned long long int ans = 0ull;
	int o = 0;
	for (int p = right; p >= left; p--)
	{
		if (str[p] == ')')
		{
			o++;
		}
		if (str[p] == '(')
		{
			o--;
		}
		if (o == 0 && str[p] == '+')
		{
			flag1 = true;
		}
		if (o == 0 && str[p] == '*')
		{
			flag2 = true;
		}
	}
	flag3 = flag1 && flag2;
	if (flag1 || flag3)
	{
		o = 0;
		for (int p = right; p >= left; p--)
		{
			if (str[p] == ')')
			{
				o++;
			}
			if (str[p] == '(')
			{
				o--;
			}
			if (o == 0 && str[p] == '+')
			{
				ans += count(left, p - 1) * count(p + 1, right);
			}
		}
	}
	else
	{
		o = 0;
		for (int p = right; p >= left; p--)
		{
			if (str[p] == ')')
			{
				o++;
			}
			if (str[p] == '(')
			{
				o--;
			}
			if (o == 0 && str[p] == '*')
			{
				ans += count(left, p - 1) * count(p + 1, right);
			}
		}
	}
	table[left][right] = ans;
	if (ans)
	{
		return ans;
	}
	table[left][right] = count(left + 1, right - 1);
	return table[left][right];
}
int main()
{
	int len;
	while (gets(str) != NULL)
	{
		memset(table, 0, sizeof(table));
		len = strlen(str);
		if (len == 0)
		{
			break;
		}
		printf("%llu\n", count(0, len - 1));
	}
	return 0;
}
