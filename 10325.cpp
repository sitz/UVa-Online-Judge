#include <bits/stdc++.h>

using namespace std;

typedef long long ss;
vector<ss> lt;
int N, M;
ss A[20], Sum;

ss gcd(ss a, ss b)
{
	return b ? gcd(b, a % b) : a;
}
ss Count(ss limit)
{
	ss i, lcm = A[1], gd, pro;
	for (i = 2; i <= limit; i++)
	{
		gd = gcd(lcm, A[i]);
		pro = lcm * A[i];
		lcm = pro / gd;
	}
	return N / lcm;
}
ss Recur(ss n, ss level, ss limit)
{
	ss i;
	if (level >= 0)
	{
		A[level] = lt[n];
	}
	if (level == limit)
	{
		if (limit % 2)
		{
			Sum += Count(limit);
		}
		else
		{
			Sum -= Count(limit);
		}
		return 0;
	}
	for (i = n + 1; i < M; i++)
	{
		Recur(i, level + 1, limit);
	}
	return 0;
}
void Cal()
{
	int i, j;
	Sum = 0;
	for (i = 0; i < M; i++)
	{
		Sum += N / lt[i];
	}
	for (i = 2; i <= M; i++)
	{
		Recur(-1, 0, i);
	}
	j = N - Sum;
	cout << j << endl;
}

int main()
{
	int i, n;
	while (cin >> N >> M)
	{
		for (i = 0; i < M; i++)
		{
			cin >> n;
			lt.push_back(n);
		}
		Cal();
		lt.clear();
	}
	return 0;
}
