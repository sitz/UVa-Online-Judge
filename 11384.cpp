#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long twos[35] = {0};
	for (long long i = 0; i < 35; i++)
	{
		twos[i] = (long long)pow(2.0, (double)i);
	}
	long long n;
	while (cin >> n)
	{
		for (long long i = 0; i < 35; i++)
		{
			if (n < twos[i])
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
