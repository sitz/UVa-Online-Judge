#include <bits/stdc++.h>

using namespace std;

void init(char *p)
{
	int i, j, tmp;
	for (j = 0; p[j] == ' '; j++)
		;
	for (i = j;; i++)
	{
		if (p[i] == ' ' || p[i] == '\0')
		{
			tmp = i;
			break;
		}
	}
	for (i = j; i < tmp; i++)
	{
		p[i - j] = p[i];
	}
	p[i - j] = '\0';
}

bool judge(char *p)
{
	int i, dot = -1, pe = -1, flag[2] = {-1, -1};
	int numdot = 0, nume = 0, numflag = 0;
	for (i = 0; p[i] != '\0'; i++)
		if (p[i] == '.')
		{
			dot = i;
			numdot++;
		}
	for (i = 0; p[i] != '\0'; i++)
		if (p[i] == 'e' || p[i] == 'E')
		{
			pe = i;
			nume++;
		}
	for (i = 0; p[i] != '\0'; i++)
	{
		if (p[i] == '+' || p[i] == '-')
		{
			flag[numflag] = i;
			numflag++;
		}
	}
	if (numflag == 1)
	{
		if (flag[0] > 0 && flag[0] < pe)
		{
			return false;
		}
		if (flag[0] > pe + 1)
		{
			return false;
		}
	}
	if (numflag == 2)
	{
		if (flag[0] != 0 && flag[1] != pe + 1)
		{
			return false;
		}
	}
	if (numdot == 2)
	{
		return false;
	}
	if (dot == 0)
	{
		return false;
	}
	if (numdot == 0 && nume == 0)
	{
		return false;
	}
	if (nume == 1)
	{
		if (p[pe + 1] == '\0')
		{
			return false;
		}
		for (i = pe; p[i] != '\0'; i++)
			if (p[i] == '.')
			{
				return false;
			}
		if (numdot == 0)
		{
			return true;
		}
	}
	if (p[dot - 1] < '0' || p[dot - 1] > '9')
	{
		return false;
	}
	if (p[dot + 1] < '0' || p[dot + 1] > '9')
	{
		return false;
	}
	return true;
}

int main()
{
	char buf[1000];
	while (cin.getline(buf, 1000))
	{
		if (strcmp(buf, "*") == 0)
		{
			break;
		}
		init(buf);
		cout << buf << " is ";
		if (judge(buf) == false)
		{
			cout << "illegal.";
		}
		else
		{
			cout << "legal.";
		}
		cout << endl;
	}
	return 0;
}
