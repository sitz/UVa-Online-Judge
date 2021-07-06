#include <bits/stdc++.h>

using namespace std;

/*
Simple Minded Hashing
10912
*/

#define MAXN 355
int V[27][MAXN];
int Sum(int n, int m)
{
	int x, y, z;
	if (n == m)
	{
		return n;
	}
	x = n + m;
	y = m - n + 1;
	return (x * y) / 2;
}
void Gen()
{
	int i, j, k, x, y;
	int max, min;
	V[1][1] = V[1][2] = 1;
	V[2][3] = 1;
	for (i = 3; i < 27; i++)
	{
		x = i - 1;
		for (j = i - 1; j >= 1; j--)
		{
			max = Sum(x - j + 1, x);
			min = Sum(1, j);
			for (k = min; k <= max; k++)
			{
				V[j + 1][k + i] += V[j][k];
			}
		}
		V[1][i] = 1;
	}
}
int main()
{
	int x, y, k = 1;
	Gen();
	while (cin >> x >> y)
	{
		if (!x && !y)
		{
			break;
		}
		if (y > 351)
		{
			cout << "Case " << k++ << ": " << 0;
		}
		else
		{
			cout << "Case " << k++ << ": " << V[x][y];
		}
		cout << endl;
	}
	return 0;
}
