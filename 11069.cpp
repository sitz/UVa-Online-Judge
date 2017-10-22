#include <bits/stdc++.h>

using namespace std;

#define maxn 78
int F[maxn];
void Table()
{
	int i;
	F[1] = 1;
	F[2] = F[3] = 2;
	for (i = 4; i <= 76; i++)
	{
		F[i] = F[i - 2] + F[i - 3];
	}
}
int main()
{
	int n;
	Table();
	while (cin >> n)
	{
		cout << F[n] << endl;
	}
	return 0;
}
