#include <bits/stdc++.h>

using namespace std;

/*
11042
*/

typedef long SS;
SS X, Y;
int Cal()
{
	double temp, dump, A, B;
	double sum = 0;
	double limit = pow(2, 32);
	SS n = 1;
	A = (double)X;
	B = (double)Y;
	if (X == 0 && Y == 0)
	{
		return 1;
	}
	while (1)
	{
		if (sum > limit)
		{
			return -1;
		}
		if (A == 0)
		{
			return n * 2;
		}
		if (B == 0)
		{
			return n;
		}
		temp = (A * A) + ((B * B) * (-1));
		dump = A * B * 2;
		A = temp;
		B = dump;
		sum = fabs(A + B);
		n *= 2;
	}
	return -1;
}
int main()
{
	int ks, x;
	cin >> ks;
	while (ks--)
	{
		cin >> X >> Y;
		x = Cal();
		if (x < 0)
		{
			cout << "TOO COMPLICATED" << endl;
		}
		else
		{
			cout << x << endl;
		}
	}
	return 0;
}
