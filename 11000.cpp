#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned int X[50];
	X[0] = 0, X[1] = 1, X[2] = 2;
	for (int i = 3; i <= 49; i++)
	{
		X[i] = X[i - 1] + X[i - 2] + 1;
	}
	for (;;)
	{
		int n;
		cin >> n;
		if (n == -1)
		{
			break;
		}
		cout << X[n] << " " << X[n + 1] << endl;
	}
	return 0;
}
