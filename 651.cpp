#include <bits/stdc++.h>

using namespace std;

double lst[99999];

void work()
{
	long i;
	lst[0] = 0.5;
	for (i = 1; i < 99999; i++)
	{
		lst[i] = lst[i - 1] + (double)0.5 / (i + 1);
	}
}

bool input()
{
	long n;
	while (!cin.eof() && !isdigit(cin.peek()))
	{
		cin.get();
	}
	if (cin.eof())
	{
		return false;
	}
	cin >> n;
	printf("%5ld%10.3lf\n", n, lst[n - 1]);
	return true;
}

int main()
{
	printf("# Cards Overhang\n");
	work();
	while (input())
		;
	return 0;
}
