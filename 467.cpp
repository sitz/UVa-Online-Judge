#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

const int lim = 60 * 60 + 1;

int table[lim];

void fillt(int val, int n)
{
	for (int i = 0; i < lim; i++)
	{
		if ((i / val) % 2 == 0 && i % val < val - 5)
		{
			table[i] |= (1 << n);
		}
	}
}

main()
{
	int tc = 1;
	string in;
	while (getline(cin, in))
	{
		rep(i, lim) table[i] = 0;
		int n = 0, sig;
		int mini = lim;
		stringstream sin(in);
		while (sin >> sig)
		{
			mini = min(sig, mini);
			fillt(sig, n);
			n++;
		}
		int ans = -1;
		REP(i, mini, lim)
		{
			if (table[i] == (1 << n) - 1)
			{
				ans = i;
				break;
			}
		}
		cout << "Set " << tc++;
		if (ans != -1)
		{
			printf(" synchs again at %d minute(s) and %d second(s) after all turning green.\n", ans / 60, ans % 60);
		}
		else
		{
			puts(" is unable to synch after one hour.");
		}
	}
}
