#include <bits/stdc++.h>

using namespace std;

// Johnson's scheduling algorithm
// Part Pi has two operations, of duration Pi1, Pi2
// to be done on Machine M1, M2 in that sequence.
// #1. List A = { 1, 2, ? N }, List L1 = {}, List L2 = {}.
// #2. From all available operation durations, pick the minimum.
// 	Remove K from list A;
// 	If the minimum belongs to Pk1,
// 		Add K to end of List L1.
// 	If minimum belongs to Pk2,
// 		Add K to beginning of List L2.
// #3. Repeat Step 2 until List A is empty.
// #4. Join List L1, List L2. This is the optimal sequence.

const int MAX = 100;

static int L1[MAX], L2[MAX], e[MAX], l1, l2, n, P[2][MAX], choose[MAX];

int main()
{
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &P[0][i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &P[1][i]);
		for (int i = 0; i < n; i++)
			choose[i] = 0;
		l1 = l2 = 0;
		int time = 0;
		for (int i = 0; i < n; i++)
		{
			int min = 9999, minp, minc;
			for (int j = 0; j < n; j++)
			{
				if (choose[j])
					continue;
				if (P[0][j] < min)
				{
					min = P[0][j];
					minp = j;
					minc = 0;
				}
				if (P[1][j] < min)
				{
					min = P[1][j];
					minp = j;
					minc = 1;
				}
			}
			choose[minp] = 1;
			if (minc == 0)
				L1[l1++] = minp;
			else
				L2[l2++] = minp;
		}
		int start = 0;
		for (int i = 0; i < l1; i++)
		{
			start += P[0][L1[i]];
			e[i] = start;
		}
		for (int i = l1, j = l2 - 1; j >= 0; i++, j--)
		{
			start += P[0][L2[j]];
			e[i] = start;
		}
		for (int i = 0; i < l1; i++)
		{
			if (time < e[i])
				time = e[i];
			time += P[1][L1[i]];
		}
		for (int i = l1, j = l2 - 1; j >= 0; i++, j--)
		{
			if (time < e[i])
				time = e[i];
			time += P[1][L2[j]];
		}
		printf("%d\n", time);
	}
	return 0;
}
