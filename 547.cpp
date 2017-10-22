#include <bits/stdc++.h>

using namespace std;

int length[3010];
int from, to;
int kase = 1;

int numValue(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int factor(int n)
{
	int i;
	int sum = 0;
	for (i = 1; i <= n; i++)
	{
		if (!(n % i))
		{
			sum += numValue(i);
		}
	}
	return sum;
}

void fun_DDF(int x)
{
	int cnt = 1;
	int m, n;
	m = x;
	n = factor(m);
	while (m != n)
	{
		cnt++;
		m = n;
		n = factor(m);
	}
	length[x] = cnt;
}

void print_DDF(int x)
{
	cout << "Output" << kase++ << ": ";
	int m, n;
	m = x;
	n = factor(m);
	while (m != n)
	{
		cout << m << " ";
		m = n;
		n = factor(m);
	}
	cout << m << endl;
}

void preCompute()
{
	int i;
	for (i = 0; i <= 3000; i++)
	{
		fun_DDF(i);
	}
}

void solve(int from, int to)
{
	int i;
	if (from > to)
	{
		i = from;
		from = to;
		to = i;
	}
	int max = 0;
	for (i = from; i <= to; i++)
	{
		if (length[i] > max)
		{
			max = length[i];
		}
	}
	for (i = from; i <= to; i++)
	{
		if (length[i] == max)
		{
			print_DDF(i);
			break;
		}
	}
}

int main()
{
	preCompute();
	while (cin >> from >> to)
	{
		cout << "Input" << kase << ": " << from << " " << to << endl;
		solve(from, to);
	}
	return 0;
}
