#include <bits/stdc++.h>

using namespace std;

int V[200005], S[200005], tmp, tV[200005], P[200005];
int merge(int st, int len)
{
	if (len < 2)
	{
		return -1;
	}
	int la = len / 2, lb = len - len / 2, i, j, k;
	int ma = st + la, mb = st + len;
	merge(st, la);
	merge(ma, lb);
	for (i = st, j = ma, k = st; i < ma || j < mb; k++)
	{
		if (j == mb)
		{
			tV[k] = V[i++];
		}
		else if (i == ma)
		{
			tV[k] = V[j];
			S[V[j]] += i - st;
			j++;
		}
		else if (V[i] < V[j])
		{
			tV[k] = V[i++];
		}
		else
		{
			tV[k] = V[j];
			S[V[j]] += i - st;
			j++;
		}
	}
	for (k = 0; k < len; k++)
	{
		V[st + k] = tV[st + k];
	}
	return -1;
}
int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &V[i]);
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &V[i]);
			V[i]--;
			S[i] = 0;
			P[V[i]] = i;
		}
		V[n] = P[n] = n;
		S[n] = 0;
		merge(0, n + 1);
		printf("0");
		for (i = 1; i < n; i++)
		{
			if (P[i + 1] > P[i])
			{
				printf(" %d", S[i + 1] - S[i] - 1);
			}
			else
			{
				printf(" %d", i - S[i] + S[i + 1]);
			}
		}
		printf("\n");
	}
	return 0;
}
