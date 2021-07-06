#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

int n, lnum = 0, rnum = 0;
char in[8][100], ans[8][100], ll[8][100], rr[8][100];

int ca(int x)
{
	int cnt0 = 0, cnt1 = 0;
	while (x)
	{
		int temp = x % 2;
		if (temp == 1)
			cnt1++;
		else
			cnt0++;
		x /= 2;
	}
	return cnt1 * 500 + cnt0 * 250;
}

int calc(int type, int l)
{
	int i;
	int ans = 0;
	if (type == 1)
	{
		int t = 0;
		for (i = 1; i <= 6; i++)
			if (in[l][i] != '.')
				ans += ca(in[l][i]);
	}
	else if (type == 2)
	{
		int t = 0;
		for (i = 11; i <= 16; i++)
			if (in[l][i] != '.')
				ans += ca(in[l][i]);
	}
	return ans;
}

void make(int ln, int rn)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		if (ln >= 0 && ln <= 4)
			for (j = 0; j <= 7; j++)
				ans[i][j] = ll[ln][j];
		else
			for (j = 0; j <= 7; j++)
				ans[i][j] = '.';
		for (j = 8; j <= 9; j++)
			ans[i][j] = '|';
		if (rn >= 0 && rn <= 4)
			for (j = 10; j <= 17; j++)
				ans[i][j] = rr[rn][j - 10];
		else
			for (j = 10; j <= 17; j++)
				ans[i][j] = '.';
		ln++;
		rn++;
	}
}
void output()
{
	int i, j;
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 18; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}

int main()
{
	int i, j, T;
	scanf("%d", &T);
	gets(in[0]);
	int ttt = 0;
	while (T--)
	{
		ttt++;
		int lh, rh;
		lnum = 0;
		rnum = 0;
		for (i = 0; i <= 7; i++)
		{
			gets(in[i]);
			for (j = 1; j <= 6; j++)
				if (in[i][j] != '_')
					break;
			if (j == 7)
				lh = i;
			for (j = 11; j <= 16; j++)
				if (in[i][j] != '_')
					break;
			if (j == 17)
				rh = i;
			for (j = 0; j < 18; j++)
			{
				if (in[i][j] >= 'A' && in[i][j] <= 'Z')
				{
					int temp = ca(in[i][j]);
					if (j < 8)
						lnum += temp;
					else
						rnum += temp;
				}
			}
		}
		printf("Case %d:\n", ttt);
		if ((rnum > lnum) && (rh > lh) || (rnum < lnum) && (rh < lh) || (rnum == lnum) && (rh == lh))
			printf("The figure is correct.\n");
		else
		{
			int t = 0;
			for (i = lh - 4; i <= lh; i++)
			{
				for (j = 0; j <= 7; j++)
					ll[t][j] = in[i][j];
				t++;
			}
			t = 0;
			for (i = rh - 4; i <= rh; i++)
			{
				int k = 0;
				for (j = 10; j <= 17; j++)
				{
					rr[t][k] = in[i][j];
					k++;
				}
				t++;
			}
			if (lnum > rnum)
			{
				make(-2, 0);
				output();
			}
			else if (lnum == rnum)
			{
				make(-1, -1);
				output();
			}
			else
			{
				make(0, -2);
				output();
			}
		}
	}
	return 0;
}
