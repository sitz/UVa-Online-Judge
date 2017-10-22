#include <bits/stdc++.h>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long

int ar[50], the_index;

void fibo()
{
	LL a = 0, b = 1, c = 1;
	the_index = 0;
	while (c <= 2000000000)
	{
		ar[the_index++] = c;
		a = b;
		b = c;
		c = a + b;
	}
}

int numsOfFibo(int n)
{
	int ret = 0;
	for (int i = the_index - 1; i >= 0; i--)
	{
		if (n == 0)
		{
			return ret;
		}
		else if (ar[i] <= n)
		{
			n -= ar[i];
			ret++;
		}
	}
	return ret;
}

int main()
{
	fibo();
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int d;
		scanf("%d", &d);
		int input;
		LL cnt = 1;
		for (int i = 0; i < d; i++)
		{
			scanf("%d", &input);
			cnt *= numsOfFibo(input);
		}
		cout << "Case " << ++cases << ": " << cnt << endl;
	}
	return 0;
}
