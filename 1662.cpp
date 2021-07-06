#include <bits/stdc++.h>

using namespace std;

#define MAXN 1024

int op(char c)
{
	switch (c)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	}
	return 0;
}

int one_item_plus(string exp)
{// x+x-x/x*x*x
	int p = 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(')
		{
			p++;
		}
		else if (exp[i] == ')')
		{
			p--;
		}
		else if (op(exp[i]) && p == 0)
		{
			if (exp[i] == '-' || exp[i] == '+')
			{
				return 1;
			}
		}
	}
	return 0;
}

string flip_op(string exp, int flip)
{
	int p = 0;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(')
		{
			p++;
		}
		else if (exp[i] == ')')
		{
			p--;
		}
		else if (op(exp[i]) && p == 0)
		{
			if (flip == 1)
			{
				if (exp[i] == '+')
				{
					exp[i] = '-';
				}
				else if (exp[i] == '-')
				{
					exp[i] = '+';
				}
			}
			else if (flip == 2)
			{
				if (exp[i] == '*')
				{
					exp[i] = '/';
				}
				else if (exp[i] == '/')
				{
					exp[i] = '*';
				}
			}
		}
	}
	return exp;
}

string parse(string exp)
{
	if (exp.length() <= 1)
	{
		return exp;
	}
	string ret, left, right;
	int p = 0;
	int pos = -1, wp = 0x3f3f3f3f;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(')
		{
			p++;
		}
		else if (exp[i] == ')')
		{
			p--;
		}
		else if (op(exp[i]))
		{
			if (p == 0)
			{
				if (op(exp[i]) <= wp)
				{
					wp = op(exp[i]);
					pos = i;
				}
			}
		}
	}
	if (pos == -1)
	{
		return parse(exp.substr(1, exp.length() - 2));
	}
	left = exp.substr(0, pos);
	right = exp.substr(pos + 1);

	left = parse(left);
	right = parse(right);
	if (exp[pos] == '+')
	{
		ret = left + exp[pos] + right;
	}
	else if (exp[pos] == '-')
	{
		right = flip_op(right, 1);
		ret = left + exp[pos] + right;
	}
	else if (exp[pos] == '*')
	{
		if (one_item_plus(left))
		{
			left = '(' + left + ')';
		}
		if (one_item_plus(right))
		{
			right = '(' + right + ')';
		}
		ret = left + exp[pos] + right;
	}
	else if (exp[pos] == '/')
	{
		if (one_item_plus(left))
		{
			left = '(' + left + ')';
		}
		if (one_item_plus(right))
		{
			right = '(' + right + ')';
		}
		else
		{
			right = flip_op(right, 2);
		}
		ret = left + exp[pos] + right;
	}
	return ret;
}

int main()
{
	string exp;
	while (cin >> exp)
	{
		string ret = parse(exp);
		printf("%s\n", ret.c_str());
	}
	return 0;
}
