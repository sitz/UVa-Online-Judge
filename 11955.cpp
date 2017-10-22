#include <bits/stdc++.h>

using namespace std;

// nCr

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for (int i = (a); i < (b); i++)
#define Fors(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fore(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Set(a, s) memset(a, s, sizeof(a))

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

char ch[1000 + 10], a[1000 + 10], b[1000 + 10], p[10];
int power;

void parseInput()
{
	int ind = 1;
	int k = 0;
	while (ch[ind] != '+')
		a[k++] = ch[ind++];// 1st operand
	a[k] = 0;
	ind++;
	k = 0;
	while (ch[ind] != ')')
		b[k++] = ch[ind++];// 2nd operand
	b[k] = 0;
	ind += 2;
	k = 0;
	while (ch[ind])
		p[k++] = ch[ind++];
	p[k] = 0;
	power = atoi(p);
}

void printCoefficients(int n, int k)
{
	int maxi = max(n - k, k);
	LL res = 1;
	int p = 1;
	for (int i = maxi + 1; i <= n; i++)
	{
		res *= i;
		res /= p;
		p++;
	}
	if (res > 1)
		cout << res;
}

void printA(int p)
{
	if (p == 1)
		printf("*%s", a);
	else if (p == power)
		printf("%s^%d", a, p);
	else if (p > 1)
		printf("*%s^%d", a, p);
}

void printB(int p)
{
	if (p == 1)
		printf("*%s", b);
	else if (p == power)
		printf("%s^%d", b, p);
	else if (p > 1)
		printf("*%s^%d", b, p);
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		scanf("%s", ch);
		parseInput();
		printf("Case %d: ", ++cases);
		if (power == 1)
		{
			printf("%s+%s\n", a, b);
			continue;
		}
		for (int i = 0; i <= power; i++)
		{
			printCoefficients(power, i);
			printA(power - i);
			printB(i);
			if (i != power)
				printf("+");
		}
		printf("\n");
	}
	return 0;
}
