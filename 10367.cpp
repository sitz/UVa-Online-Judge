#include <bits/stdc++.h>

using namespace std;

int a[2], b[2], c[2];
char str[200];
bool fatalerror;

void analyze(char *s, int p)
{
	int temp = 0;
	int pos = 1, sign = 1;
	a[p] = b[p] = c[p] = 0;
	while (*s)
	{
		if (*s == ' ')
		{
			s++;
			continue;
		}
		if (*s == '=')
		{
			sign = -1;
			s++;
			continue;
		}
		if (*s == '+')
		{
			s++;
			while (*s == ' ')
			{
				s++;
			}
			if (*s == '-')
			{
				pos = -1;
				s++;
			}
			if (*s == '+')
			{
				s++;
			}
			while (isdigit(*s))
			{
				temp = temp * 10 + (*s++ - '0');
			}
			temp *= pos;
			if (temp == 0 && isalpha(*s))
			{
				temp = pos;
			}
			if (*s == 'x')
			{
				s++;
				a[p] += sign * temp;
			}
			else if (*s == 'y')
			{
				s++;
				b[p] += sign * temp;
			}
			else
			{
				c[p] -= sign * temp;
			}
		}
		else if (*s == '-')
		{
			s++;
			while (*s == ' ')
			{
				s++;
			}
			if (*s == '-')
			{
				pos = -1;
				s++;
			}
			if (*s == '+')
			{
				s++;
			}
			while (isdigit(*s))
			{
				temp = temp * 10 + (*s++ - '0');
			}
			temp *= pos;
			if (temp == 0 && isalpha(*s))
			{
				temp = pos;
			}
			if (*s == 'x')
			{
				s++;
				a[p] -= sign * temp;
			}
			else if (*s == 'y')
			{
				s++;
				b[p] -= sign * temp;
			}
			else
			{
				c[p] += sign * temp;
			}
		}
		else
		{
			while (*s == ' ')
			{
				s++;
			}
			if (*s == '-')
			{
				pos = -1;
				s++;
			}
			if (*s == '+')
			{
				s++;
			}
			while (isdigit(*s))
			{
				temp = temp * 10 + (*s++ - '0');
			}
			temp *= pos;
			if (temp == 0 && isalpha(*s))
			{
				temp = pos;
			}
			if (*s == 'x')
			{
				s++;
				a[p] += sign * temp;
			}
			else if (*s == 'y')
			{
				s++;
				b[p] += sign * temp;
			}
			else
			{
				c[p] -= sign * temp;
			}
		}
		temp = 0;
		pos = 1;
	}
	if (a[p] == 0 && b[p] == 0 && c[p] != 0)
	{
		fatalerror = true;
	}
	// printf("%d %d %d\n",a[p],b[p],c[p]);
}
int GCD(int a, int b)
{
	return (b == 0) ? a : GCD(b, a % b);
}
void solvex()
{
	bool pos = true;
	int m = -999999, d, delta, deltax, gcd, tempm, tempd;
	if (a[0] != 0 && b[0] == 0)
	{
		if (m == -999999)
		{
			d = c[0];
			m = a[0];
		}
		else
		{
			tempm = a[0], tempd = c[0];
			if (tempm * d != tempd * m)
			{
				puts("don't know");
				return;
			}
		}
	}
	if (a[1] != 0 && b[1] == 0)
	{
		if (m == -999999)
		{
			d = c[1];
			m = a[1];
		}
		else
		{
			tempm = a[1], tempd = c[1];
			if (tempm * d != tempd * m)
			{
				puts("don't know");
				return;
			}
		}
	}
	if (m == -999999)
	{
		m = a[0] * b[1] - a[1] * b[0];
		d = c[0] * b[1] - c[1] * b[0];
	}
	else
	{
		tempm = a[0] * b[1] - a[1] * b[0];
		tempd = c[0] * b[1] - c[1] * b[0];
		if (tempm * d != tempd * m)
		{
			puts("don't know");
			return;
		}
	}
	if (m * d < 0)
	{
		pos = false;
	}
	m = (m > 0) ? m : -m;
	d = (d > 0) ? d : -d;
	if (m == 0)
	{
		puts("don't know");
		return;
	}
	gcd = GCD(m, d);
	if (!pos)
	{
		printf("-");
	}
	if (d % m == 0)
	{
		printf("%d\n", d / m);
	}
	else
	{
		printf("%d/%d\n", d / gcd, m / gcd);
	}
}
void solvey()
{
	bool pos = true;
	int m = -999999, d, gcd, tempm, tempd;
	if (a[0] == 0 && b[0] != 0)
	{
		if (m == -999999)
		{
			d = c[0];
			m = b[0];
		}
		else
		{
			tempm = b[0], tempd = c[0];
			if (tempm * d != tempd * m)
			{
				puts("don't know");
				return;
			}
		}
	}
	if (a[1] == 0 && b[1] != 0)
	{
		if (m == -999999)
		{
			d = c[1];
			m = b[1];
		}
		else
		{
			tempm = b[1];
			tempd = c[1];
			if (tempm * d != tempd * m)
			{
				puts("don't know");
				return;
			}
		}
	}
	if (m == -999999)
	{
		m = a[0] * b[1] - a[1] * b[0];
		d = a[0] * c[1] - a[1] * c[0];
	}
	else
	{
		tempm = a[0] * b[1] - a[1] * b[0];
		tempd = a[0] * c[1] - a[1] * c[0];
		if (tempm * d != tempd * m)
		{
			puts("don't know");
			return;
		}
	}
	if (m * d < 0)
	{
		pos = false;
	}
	m = (m > 0) ? m : -m;
	d = (d > 0) ? d : -d;
	if (m == 0)
	{
		puts("don't know");
		return;
	}
	gcd = GCD(m, d);
	if (!pos)
	{
		printf("-");
	}
	if (d % m == 0)
	{
		printf("%d\n", d / m);
	}
	else
	{
		printf("%d/%d\n", d / gcd, m / gcd);
	}
}

int main()
{
	int times;
	gets(str);
	sscanf(str, "%d", &times);
	for (int i = 0; i < times; i++)
	{
		fatalerror = false;
		if (i)
		{
			gets(str);
			puts(str);
		}
		for (int i = 0; i < 2; i++)
		{
			gets(str);
			analyze(str, i);
		}
		if (fatalerror)
		{
			puts("don't know\ndon't know");
		}
		else
		{
			solvex();
			solvey();
		}
	}
	return 0;
}
