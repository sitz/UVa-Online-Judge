#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int main()
{
	while (cin >> N && N)
	{
		cin >> a >> b;
		map<int, int> sets;
		int cntOfSet = 0;
		unsigned long long x = 0;
		sets[x] = cntOfSet++;
		while (1)
		{
			x = (a * ((x * x) % N) + b) % N;
			if (sets.find(x) != sets.end())
			{
				break;
			}
			else
			{
				sets[x] = cntOfSet++;
			}
		}
		cout << N - (cntOfSet - sets[x]) << endl;
	}
	return 0;
}
