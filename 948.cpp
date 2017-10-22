#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool found;
int ar[50], in = 0;

void fibo()
{
	int a = 0, b = 1, c = 1;
	in = 0;
	while (c <= 100000000)
	{
		ar[in++] = c;
		a = b;
		b = c;
		c = a + b;
	}
}

void print(LL m)
{
	string str = "";
	while (m)
	{
		str += (m % 2) + '0';
		m /= 2;
	}
	reverse(str.begin(), str.end());
	cout << str << " (fib)" << endl;
}

void recur(int at, int num, LL mask)
{
	if (num == 0)
	{
		print(mask);
		found = true;
		return;
	}
	if (num < 0 || found)
	{
		return;
	}
	for (int i = at - 2; i >= 0; i--)
	{
		recur(i, num - ar[i], mask | ((LL)1 << i));
	}
}

int main()
{
	fibo();
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int n;
		scanf("%d", &n);
		cout << n << " = ";
		found = false;
		recur(in + 1, n, 0);
	}
	return 0;
}
