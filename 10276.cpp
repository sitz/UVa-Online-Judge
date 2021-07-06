#include <bits/stdc++.h>

using namespace std;

int main()
{
	int pesos[52];
	pesos[0] = 1;
	pesos[1] = 2;
	for (int i = 2; i < 52; i = i + 2)
	{
		pesos[i] = i + 2;
		pesos[i + 1] = i + 2;
	}
	int bolas[52];
	bolas[0] = 1;
	for (int i = 1; i < 52; i++)
	{
		bolas[i] = bolas[i - 1] + pesos[i - 1];
	}
	int cases = 0;
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		int n = 0;
		cin >> n;
		cout << bolas[n] - 1 << endl;
	}
	return 0;
}
