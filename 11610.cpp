#include <bits/stdc++.h>

using namespace std;

#define N 1000000
#define M 78499

set<int> deleted;
set<int>::iterator it;
char factors[N];
int rev[M];
int nFactors[M];
int sum[M];
int tree[M];
int ind(int n)
{
	n++;
	for (it = deleted.begin(); it != deleted.end() && *it <= n; it++)
	{
		n++;
	}
	return n;
}

void del(int i)
{
	deleted.insert(i);
	int val = nFactors[i];
	while (i <= M)
	{
		tree[i] -= val;
		i += (i & -i);
	}
}
int sumFactors(int i)
{
	int res = 0;
	while (i > 0)
	{
		res += tree[i];
		i -= (i & -i);
	}
	return res;
}
int lastOne(int n)
{
	return n & -n;
}
int nfactors(int n)
{
	int i, sum = 0;
	for (i = 2; i < N && n >= N; i++)
		if (factors[i] == 1)
		{
			while (n % i == 0)
			{
				sum++;
				n /= i;
			}
		}
	return sum + factors[n];
}
int reverse(int n)
{
	int res = 0;
	while (n > 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int main()
{
	int i, j, k, t;
	map<int, int> indexOf;
	for (i = 0; i < N; i++)
	{
		factors[i] = 0;
	}
	for (i = 2; i < N; i++)
	{
		if (!factors[i])
		{
			factors[i] = 1;
		}
		for (j = 2; (k = i * j) < N && j <= i; j++)
			if (factors[j] == 1)
			{
				factors[k] = factors[j] + factors[i];
			}
	}
	t = 1;
	for (i = 1000000; i <= 9999999; i++)
		if ((j = reverse(i)) < 1000000 && factors[j] == 1)
		{
			rev[t] = i;
			indexOf[i] = t;
			t++;
		}
	nFactors[1] = nfactors(rev[1]);
	sum[1] = nFactors[1];
	for (i = 2; i < t; i++)
	{
		nFactors[i] = nfactors(rev[i]);
		sum[i] = sum[i - 1] + nFactors[i];
	}
	for (i = 1; i < t; i++)
	{
		tree[i] = sum[i] - sum[i - lastOne(i) + 1] + nFactors[i - lastOne(i) + 1];
	}
	char o;
	int n;
	while (scanf("%c %d", &o, &n) == 2)
	{
		getchar();
		if (o == 'q')
		{
			printf("%d\n", sumFactors(ind(n)));
		}
		else
		{
			del(indexOf[n]);
		}
	}
	return 0;
}
