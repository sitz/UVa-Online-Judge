#include <bits/stdc++.h>

using namespace std;

/***************************
The Hamming Distance Problem
     729
****************************/
int N, H;
void Gener()
{
	long val, i, j, p, k, q;
	char temp[20];
	val = pow(2, N - 1);
	for (i = 1; i <= pow(2, N); i++)
	{
		p = 0;
		q = 0;
		for (j = val; j > 0; j = j / 2)
		{
			if (i & j)
			{
				temp[q++] = '1';
				p++;
			}
			else
			{
				temp[q++] = '0';
			}
		}
		if (p == H)
		{
			temp[q] = NULL;
			printf("%s\n", temp);
		}
	}
}
int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d%d", &N, &H);
		Gener();
		if (kase)
		{
			putchar('\n');
		}
	}
	return 0;
}
