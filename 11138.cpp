#include <bits/stdc++.h>

using namespace std;

int M[500][500], L[500], U[500], V[500], qU[500], qV[500], ptr, ulen, vlen, prU[500], prV[500];
int main()
{
	int t, tt, i, j, k, r, c, flow, n, ok;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d%d", &r, &c);
		for (i = 0; i < r; i++)
		{
			L[i] = 0;
			for (j = 0; j < c; j++)
			{
				scanf("%d", &ok);
				if (ok)
				{
					M[i][L[i]++] = j;
				}
			}
		}
		for (i = 0; i < r; i++)
		{
			U[i] = -1;
		}
		for (i = 0; i < c; i++)
		{
			V[i] = -1;
		}
		for (n = flow = 0; n < r; n++)
		{
			for (i = 0; i < r; i++)
			{
				prU[i] = -1;
			}
			for (i = 0; i < c; i++)
			{
				prV[i] = -1;
			}
			qU[0] = n, prU[n] = -2, ulen = 1;
			while (ulen)
			{
				for (ptr = vlen = ok = 0; ptr < ulen; ptr++)
				{
					i = qU[ptr];
					for (k = 0; k < L[i]; k++)
					{
						j = M[i][k];
						if (prV[j] != -1)
						{
							continue;
						}
						prV[qV[vlen++] = j] = i;
						if (V[j] == -1)
						{
							ok = 1;
							break;
						}
					}
					if (ok)
					{
						break;
					}
				}
				if (ok)
				{
					break;
				}
				for (ptr = ulen = 0; ptr < vlen; ptr++)
				{
					i = qV[ptr];
					j = V[i];
					prU[qU[ulen++] = j] = i;
				}
			}
			if (!ok)
			{
				continue;
			}
			flow++;
			while (j != -2)
			{
				i = prV[j];
				V[j] = i;
				U[i] = j;
				j = prU[i];
			}
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t, flow);
	}
	return 0;
}
