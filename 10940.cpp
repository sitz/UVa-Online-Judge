#include <bits/stdc++.h>

using namespace std;

/*
10935
Thorowing cards away - 1
*/

struct ss
{
	int rem;
};
ss N[500002];
void Gen()
{
	int i, j, d;
	N[1].rem = 1;
	N[2].rem = 2;
	for (i = 3; i <= 500000; i++)
	{
		d = N[i - 1].rem + 2;
		if (d > i)
		{
			d = 2;
		}
		N[i].rem = d;
	}
}
void Print(int n)
{
	int i;
	cout << N[n].rem << endl;
}
int main()
{
	Gen();
	int n;
	while (cin >> n && n)
	{
		Print(n);
	}
	return 0;
}
