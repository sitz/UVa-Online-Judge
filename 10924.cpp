#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

bool isnprime[1041];

void sieve()
{
	isnprime[0] = isnprime[1] = false;
	for (int i = 2; i <= sqrt(1041); i++)
	{
		if (!isnprime[i])
		{
			for (int j = i * i; j < 1041; j += i)
			{
				isnprime[j] = true;
			}
		}
	}
}

int main()
{
	sieve();
	string line;
	while (cin >> line)
	{
		int sum = 0;
		for (int i = 0; i < line.length(); i++)
		{
			int idx = 0;
			if (line[i] >= 'a' && line[i] <= 'z')
			{
				idx = line[i] - 'a' + 1;
			}
			if (line[i] >= 'A' && line[i] <= 'Z')
			{
				idx = line[i] - 'A' + 27;
			}
			sum += idx;
		}
		if (!isnprime[sum])
		{
			cout << "It is a prime word." << endl;
		}
		else
		{
			cout << "It is not a prime word." << endl;
		}
	}
	return 0;
}
