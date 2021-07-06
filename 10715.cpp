#include <bits/stdc++.h>

using namespace std;

#define MAXI (10000)
#define MAXV ((MAXI * 1.02) / 2.02)
#define MINV ((MAXI * 0.98) / 1.98)
#define POSI(a) ((int)(MAXI * (a) / tot))

double pes[110], norm_[110], possiv[MAXI + 10];
int n, qual[MAXI + 10], pre[MAXI + 10], possi[MAXI + 10];

void imprime(int p)
{
	if (qual[p] == -1 || pre[p] == -1)
	{
		return;
	}
	imprime(pre[p]);
	cout << (qual[p] + 1) << " ";
}

int main()
{
	while (1)
	{
		double tot = 0;
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		for (int i = 0; i != n; i++)
		{
			cin >> pes[i];
			tot += pes[i];
		}
		for (int i = 0; i != n; i++)
		{
			norm_[i] = (tot * pes[i]) / MAXI;
		}
		for (int i = 0; i <= MAXI; i++)
		{
			possi[i] = 0;
		}
		possi[0] = 1;
		possiv[0] = 0.0;
		pre[0] = -1;
		qual[0] = -1;
		int maxip = 0;
		int npos;
		for (int i = 0; i != n; i++)
		{
			for (int j = maxip; j >= 0; j--)
			{
				if (possi[j])
				{
					npos = POSI(possiv[j] + pes[i]);
					if (npos > MAXV)
					{
						continue;
					}
					if (npos < MAXV && npos > MINV)
					{
						imprime(j);
						cout << (i + 1) << endl;
						goto f;
					}
					if (!possi[npos])
					{
						if (npos > maxip)
						{
							maxip = npos;
						}
						possi[npos] = 1;
						pre[npos] = j;
						qual[npos] = i;
						possiv[npos] = possiv[j] + pes[i];
					}
				}
			}
		}
	f:;
	}
	return 0;
}
