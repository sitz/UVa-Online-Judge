#include <bits/stdc++.h>

using namespace std;

void get(char *p, double &x)
{
	int i, size;
	for (i = 0; p[i] != '\0'; i++)
		;
	size = i;
	char tmp;
	double result = 0;
	for (i = 0; i < size / 2; i++)
	{
		tmp = p[i];
		p[i] = p[size - 1 - i];
		p[size - 1 - i] = tmp;
	}
	for (i = 0; i < size; i++)
	{
		result += ((int)p[i] - 48) * pow(10, i);
	}
	x = result;
}
int main()
{
	double a, b;
	char ch, oa[1000], ob[1000];
	while (cin >> oa >> ch >> ob)
	{
		cout << oa << " " << ch << " " << ob << endl;
		get(oa, a);
		get(ob, b);
		if (a > 2147483647.0)
		{
			cout << "first number too big" << endl;
		}
		if (b > 2147483647.0)
		{
			cout << "second number too big" << endl;
		}
		if (ch == '+')
		{
			double result = a + b;
			if (result > 2147483647.0)
			{
				cout << "result too big" << endl;
			}
		}
		if (ch == '*')
		{
			double result = a * b;
			if (result > 2147483647.0)
			{
				cout << "result too big" << endl;
			}
		}
	}
	return 0;
}
