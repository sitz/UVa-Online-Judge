#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ullint;

ullint A, B, M, MOD;

vector<int> rem;

void ini()
{
	rem.clear();
}

int find_cycle()
{
	rem.push_back(0);
	rem.push_back(1);
	while (1)
	{
		int b1 = rem[rem.size() - 2];
		int b2 = rem[rem.size() - 1];
		int b3 = (b1 + b2) % M;
		if (b3 == 0 && b2 == 1)
		{
			break;
		}
		rem.push_back(b3);
	}
	return rem.size();
}

ullint SQ(ullint in)
{
	return in * in;
}

ullint bigmod(ullint A, ullint B, ullint MOD)
{
	if (B == 0)
	{
		return 1;
	}
	if (B % 2 == 0)
	{
		return SQ(bigmod(A, B / 2, MOD) % MOD) % MOD;
	}
	return A * bigmod(A, B - 1, MOD) % MOD;
}

int process()
{
	if (M == 1)
	{
		return 0;
	}
	MOD = find_cycle();
	return rem[bigmod(A % MOD, B, MOD)];
}

int main()
{
	int datacase;
	scanf("%d", &datacase);
	while (datacase--)
	{
		ini();
		cin >> A >> B >> M;
		cout << process() << endl;
	}
	return 0;
}
