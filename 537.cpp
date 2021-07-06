#include <bits/stdc++.h>

using namespace std;

char *cp;

void ReadNum(double &res)
{
	cp++;
	if (*cp != '=')
	{
		return;
	}
	cp++;
	sscanf(cp, "%lf", &res);
	while (!isalpha(*cp))
	{
		cp++;
	}
	if (*cp == 'm')
	{
		res /= 1000;
	}
	else if (*cp == 'k')
	{
		res *= 1000;
	}
	else if (*cp == 'M')
	{
		res *= 1000000;
	}
}

void solve(char *buf)
{
	double I, U, P;
	I = U = P = -1;
	for (cp = buf; *cp; cp++)
	{
		if (*cp == 'I')
		{
			ReadNum(I);
		}
		else if (*cp == 'U')
		{
			ReadNum(U);
		}
		else if (*cp == 'P')
		{
			ReadNum(P);
		}
	}
	if (I < 0)
	{
		printf("I=%.2fA\n", P / U);
	}
	else if (U < 0)
	{
		printf("U=%.2fV\n", P / I);
	}
	else if (P < 0)
	{
		printf("P=%.2fW\n", I * U);
	}
}

int main()
{
	char buf[2000];
	int n, t;
	scanf("%d\n", &n);
	for (t = 0; t < n; t++)
	{
		cout << "Problem #" << t + 1 << endl;
		cin.getline(buf, 2000);
		solve(buf);
		cout << endl;
	}
	return 0;
}
