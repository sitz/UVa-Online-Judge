#include <bits/stdc++.h>

using namespace std;

long long N, x;
char expression[110];

long long eval(char *str)
{
	char exp[110];
	strcpy(exp, str);
	stack<long long> num;
	char *p = strtok(exp, " ");
	if (p)// first one
	{
		if (!strcmp(p, "x"))
		{
			num.push(x);
		}
		if (!strcmp(p, "N"))
		{
			num.push(N);
		}
		if (isdigit(p[0]))
		{
			num.push(atoi(p));
		}
	}
	while ((p = strtok(NULL, " ")) != NULL && strcmp(p, "%"))
	{
		if (!strcmp(p, "x"))
		{
			num.push(x);
		}
		if (!strcmp(p, "N"))
		{
			num.push(N);
		}
		if (isdigit(p[0]))
		{
			num.push(atoi(p));
		}
		if (p[0] == '*' || p[0] == '+')
		{
			long long a, b;
			b = num.top();
			num.pop();
			a = num.top();
			num.pop();
			if (p[0] == '*')
			{
				long long temp = ((a % N) * (b % N)) % N;
				num.push(temp);
			}
			if (p[0] == '+')
			{
				long long temp = (a + b) % N;
				num.push(temp);
			}
		}
	}
	long long a, b, value;
	a = num.top();
	num.pop();
	b = num.top();
	num.pop();
	value = b % a;
	return value;
}

int main()
{
	while (cin >> N >> x)
	{
		cin.getline(expression, 100);
		if (N == 0)
		{
			break;
		}
		map<long long, long> mm;
		int times = 1;
		while (mm[x] == 0)
		{
			mm[x] = times++;
			x = eval(expression);
		}
		cout << times - mm[x] << endl;
	}
	return 0;
}
