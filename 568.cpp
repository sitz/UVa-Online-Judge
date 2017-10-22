#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	while (cin >> N)
	{
		int i;
		long result = 1;
		for (i = 1; i <= N; i++)
		{
			result *= i;
			while (result % 10 == 0)
			{
				result /= 10;
			}
			result %= 100000;
		}
		cout << setw(5) << N << " -> " << result % 10 << endl;
	}
	return 0;
}
