#include <bits/stdc++.h>

using namespace std;

bool nprime[2000001];
int base[2000001], nsf[2000001], n, prev_[2000001];

int main()
{
	memset(nprime, 0, sizeof nprime);
	memset(base, -1, sizeof base);
	memset(nsf, 0, sizeof nsf);
	for (int i = 2; i < 1000000; i++)
	{
		if (!nprime[i])
		{
			for (int j = i; j < 2000000; j += i)
			{
				base[j] *= i;
				nprime[j] = 1;
			}
		}
	}
	memset(prev_, 0, sizeof prev_);
	for (int i = 2; i < 2000000; i++)
	{
		if (base[i] != -1)
		{
			nsf[prev_[-base[i]]] = i;
			prev_[-base[i]] = i;
		}
	}
	while (cin >> n)
	{
		if (nsf[n])
		{
			cout << nsf[n] << endl;
		}
		else
		{
			cout << "Not Exist!" << endl;
		}
	}
	return 0;
}
