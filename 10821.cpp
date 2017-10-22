#include <bits/stdc++.h>

using namespace std;

int N, H;
int pow2[31];
int print[10000], len;
void RUN1(int start, int n, int h)
{
	if (!h)
	{
		return;
	}
	int s = (2 * start + n - 1) >> 1;
	print[len++] = s;
	RUN1(start, pow2[h - 1], h - 1);
	RUN1(s + 1, pow2[h - 1], h - 1);
}
void RUN(int start, int n, int h)
{
	if (!n)
	{
		return;
	}
	if (n <= pow2[h - 1])
	{
		print[len++] = start;
		RUN(start + 1, n - 1, h - 1);
	}
	else
	{
		int s = start + n - pow2[h - 1];
		print[len++] = s;
		RUN(start, s - start, h - 1);
		RUN1(s + 1, pow2[h - 1], h - 1);
	}
}
int main()
{
	int caseno = 1;
	pow2[0] = 1;
	for (int i = 1; i < 31; i++)
	{
		pow2[i] = pow2[i - 1] << 1;
	}
	while (scanf("%d %d", &N, &H) == 2)
	{
		if (!N || !H)
		{
			break;
		}
		printf("Case %d:", caseno++);
		if (pow2[H] - 1 < N)
		{
			puts(" Impossible.");
		}
		else
		{
			len = 0;
			RUN(1, N, H);
			for (int i = 0; i < len; i++)
			{
				printf(" %d", print[i]);
			}
			printf("\n");
		}
	}
}
