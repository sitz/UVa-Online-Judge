#include <bits/stdc++.h>

using namespace std;

char str[250000];

struct BigNumber
{
	int man;
	vector<int> d;
	BigNumber()
	{
		man = 1;
		d.clear();
	}
	BigNumber(char *str) : man(1)
	{
		d.clear();
		int temp[4000], i = 0, j, s = 0, len = strlen(str), t;
		if (len % 4 != 0)
		{
			for (t = 0; i < len % 4; i++)
			{
				t = t * 10 + str[i] - '0';
			}
			temp[s++] = t;
		}
		while (i < len)
		{
			for (j = 0, t = 0; j < 4; j++)
			{
				t = t * 10 + str[i++] - '0';
			}
			temp[s++] = t;
		}
		for (i = s - 1; i >= 0; i--)
		{
			d.push_back(temp[i]);
		}
	}
	BigNumber operator+(BigNumber ref)
	{
		BigNumber ans;
		if (man * ref.man == 1)
		{
			add(*this, ref, ans);
			ans.man = this->man;
		}
		else
		{
			if (this->compare(ref))
			{
				sub(*this, ref, ans);
				ans.man = this->man;
			}
			else
			{
				sub(ref, *this, ans);
				ans.man = ref.man;
			}
		}
		return ans;
	}
	BigNumber operator-(BigNumber ref)
	{
		BigNumber ans;
		if (man * ref.man == -1)
		{
			add(*this, ref, ans);
			ans.man = this->man;
		}
		else
		{
			if (this->compare(ref))
			{
				sub(*this, ref, ans);
				if (this->man == 1)
				{
					ans.man = 1;
				}
				else
				{
					ans.man = -1;
				}
			}
			else
			{
				sub(ref, *this, ans);
				if (ans.man == 1)
				{
					ans.man = -1;
				}
				else
				{
					ans.man = 1;
				}
			}
		}
		return ans;
	}
	void operator=(BigNumber ref)
	{
		this->man = ref.man;
		this->d.clear();
		for (int i = 0; i < ref.d.size(); i++)
		{
			d.push_back(ref.d[i]);
		}
	}
	BigNumber operator*(BigNumber ref)
	{
		BigNumber ans;
		ans.man = this->man * ref.man;
		int temp[4000], i, j, p;
		memset(temp, 0, sizeof(temp));
		for (i = 0; i < this->d.size(); i++)
			for (j = 0; j < ref.d.size(); j++)
			{
				int t = temp[i + j] + this->d[i] * ref.d[j];
				temp[i + j + 1] += t / 10000;
				temp[i + j] = t % 10000;
			}
		for (p = 3999; temp[p] == 0; p--)
			;
		for (i = 0; i <= p; i++)
		{
			ans.d.push_back(temp[i]);
		}
		return ans;
	}
	BigNumber exp(BigNumber e)
	{
		if (e.d.size() == 0)
		{
			return BigNumber("1");
		}
		char ref[30000], temp[10];
		ref[0] = '\0';
		int i;
		BigNumber table[10], ans("1");
		table[0] = BigNumber("1");
		for (i = 1; i < 10; i++)
		{
			table[i] = table[i - 1] * (*this);
		}
		sprintf(temp, "%d", e.d[e.d.size() - 1]);
		strcat(ref, temp);
		for (i = e.d.size() - 2; i >= 0; i--)
		{
			sprintf(temp, "%04d", e.d[i]);
			strcat(ref, temp);
		}
		for (i = 0; ref[i]; i++)
		{
			BigNumber p2 = ans * ans;
			BigNumber p4 = p2 * p2;
			BigNumber p8 = p4 * p4;
			ans = p8 * p2 * table[ref[i] - '0'];
		}
		return ans;
	}
	bool compare(BigNumber &ref)
	{
		if (this->d.size() != ref.d.size())
		{
			return this->d.size() > ref.d.size();
		}
		int k = this->d.size();
		for (int i = k - 1; i >= 0; i--)
		{
			if (this->d[i] > ref.d[i])
			{
				return true;
			}
			if (this->d[i] < ref.d[i])
			{
				return false;
			}
		}
		return true;
	}
	void add(BigNumber a, BigNumber b, BigNumber &c)
	{
		int temp[4000], carry = 0, i, p;
		memset(temp, 0, sizeof(temp));
		for (i = 0; i < a.d.size(); i++)
		{
			temp[i] = a.d[i];
		}
		for (i = 0; i < b.d.size(); i++)
		{
			temp[i] += b.d[i] + carry;
			carry = temp[i] / 10000;
			temp[i] %= 10000;
		}
		temp[i] += carry;
		for (p = 3999; temp[p] == 0; p--)
			;
		for (i = 0; i <= p; i++)
		{
			c.d.push_back(temp[i]);
		}
	}
	void sub(BigNumber a, BigNumber b, BigNumber &c)
	{
		int temp[4000], carry = 0;
		memset(temp, 0, sizeof(temp));
		int i, borrow = 0, p;
		for (i = 0; i < a.d.size(); i++)
		{
			temp[i] = a.d[i];
		}
		for (i = 0; i < 4000; i++)
		{
			temp[i] += borrow;
			if (i < b.d.size())
			{
				temp[i] -= b.d[i];
			}
			if (temp[i] < 0)
			{
				temp[i] += 10000;
				borrow = -1;
			}
			else
			{
				borrow = 0;
			}
		}
		for (p = 3999; temp[p] == 0; p--)
			;
		for (i = 0; i <= p; i++)
		{
			c.d.push_back(temp[i]);
		}
	}
	void print()
	{
		if (d.size() == 0)
		{
			puts("0");
			return;
		}
		if (man == -1)
		{
			putchar('-');
		}
		printf("%d", d[d.size() - 1]);
		for (int i = d.size() - 2; i >= 0; i--)
		{
			printf("%04d", d[i]);
		}
		printf("\n");
	}
};
void preprocess()
{
	int len = strlen(str), l = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == '*' && str[i + 1] == '*')
		{
			str[l++] = '^', i++;
		}
		else
		{
			str[l++] = str[i];
		}
	str[l] = '\0';
}
BigNumber fact(char *s)
{
	char *p;
	for (p = s; *p != '\0' && *p != '^'; p++)
		;
	if (*p == '\0')
	{
		return BigNumber(s);
	}
	*p = '\0';
	BigNumber base(s), e = fact(p + 1);
	return base.exp(e);
}
BigNumber term(char *s)
{
	char *p, *t, temp;
	for (p = s; *p != '\0' && *p != '*'; p++)
		;
	if (*p == '\0')
	{
		return fact(s);
	}
	temp = *p;
	*p = '\0';
	BigNumber ans = fact(s);
	*p = temp;
	while (*p)
	{
		for (t = p + 1; *t != '\0' && *t != '*'; t++)
			;
		char temp = *t;
		*t = '\0';
		BigNumber tt = fact(p + 1);
		*t = temp;
		p = t;
		ans = ans * tt;
	}
	return ans;
}
BigNumber expr(char *s)
{
	char *p, *t, tt;
	for (p = s; *p != '\0' && *p != '+' && *p != '-'; p++)
		;
	if (*p == '\0')
	{
		return term(s);
	}
	tt = *p;
	*p = '\0';
	BigNumber ans = term(s);
	*p = tt;
	while (*p)
	{
		for (t = p + 1; *t != '\0' && *t != '+' && *t != '-'; t++)
			;
		char tt = *t;
		*t = '\0';
		BigNumber temp = term(p + 1);
		*t = tt;
		if (*p == '+')
		{
			ans = ans + temp;
		}
		else
		{
			ans = ans - temp;
		}
		p = t;
	}
	return ans;
}
int main()
{
	while (gets(str) != NULL)
	{
		if (strlen(str) == 0)
		{
			continue;
		}
		preprocess();
		BigNumber ans = expr(str);
		ans.print();
	}
}
