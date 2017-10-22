#include <bits/stdc++.h>

using namespace std;

#define MAXN 4
#define MAXM 60

int mp[MAXN][MAXN];
int temp[MAXN][MAXN];
char str[MAXM];

int check(int ii, int jj, int flag)
{
	memcpy(temp, mp, sizeof(temp));
	temp[ii][jj] = flag;
	int res = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (j + 2 < 4)
			{
				bool good = true;
				if (i != ii)
				{
					good = false;
				}
				for (int k = 0; k < 3; ++k)
					if (temp[i][j + k] != flag)
					{
						good = false;
					}
				if (jj < j || jj > j + 2)
				{
					good = false;
				}
				if (good)
				{
					res += 3;
				}
			}
			if (i + 2 < 4)
			{
				bool good = true;
				if (j != jj)
				{
					good = false;
				}
				for (int k = 0; k < 3; ++k)
					if (temp[i + k][j] != flag)
					{
						good = false;
					}
				if (ii < i || ii > i + 2)
				{
					good = false;
				}
				if (good)
				{
					res += 3;
				}
			}
			if (i + 2 < 4 && j + 2 < 4)
			{
				bool good = true;
				bool got = false;
				for (int k = 0; k < 3; ++k)
				{
					if (temp[i + k][j + k] != flag)
					{
						good = false;
					}
					if (i + k == ii && j + k == jj)
					{
						got = true;
					}
				}
				if (good && got)
				{
					res += 3;
				}
			}
			if (i + 2 < 4 && j - 2 >= 0)
			{
				bool good = true;
				bool got = false;
				for (int k = 0; k < 3; ++k)
				{
					if (temp[i + k][j - k] != flag)
					{
						good = false;
					}
					if (i + k == ii && j - k == jj)
					{
						got = true;
					}
				}
				if (good && got)
				{
					res += 3;
				}
			}
			if (j + 3 < 4)
			{
				bool good = true;
				if (i != ii)
				{
					good = false;
				}
				for (int k = 0; k < 4; ++k)
					if (temp[i][j + k] != flag)
					{
						good = false;
					}
				if (jj < j || jj > j + 3)
				{
					good = false;
				}
				if (good)
				{
					res += 4;
				}
			}
			if (i + 3 < 4)
			{
				bool good = true;
				if (j != jj)
				{
					good = false;
				}
				for (int k = 0; k < 4; ++k)
					if (temp[i + k][j] != flag)
					{
						good = false;
					}
				if (ii < i || ii > i + 3)
				{
					good = false;
				}
				if (good)
				{
					res += 4;
				}
			}
			if (i + 3 < 4 && j + 3 < 4)
			{
				bool good = true;
				bool got = false;
				for (int k = 0; k < 4; ++k)
				{
					if (temp[i + k][j + k] != flag)
					{
						good = false;
					}
					if (i + k == ii && j + k == jj)
					{
						got = true;
					}
				}
				if (good && got)
				{
					res += 4;
				}
			}
			if (i + 3 < 4 && j - 3 >= 0)
			{
				bool good = true;
				bool got = false;
				for (int k = 0; k < 4; ++k)
				{
					if (temp[i + k][j - k] != flag)
					{
						good = false;
					}
					if (i + k == ii && j - k == jj)
					{
						got = true;
					}
				}
				if (good && got)
				{
					res += 4;
				}
			}
		}
	return res;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseT = 1; caseT <= cases; ++caseT)
	{
		memset(mp, 0, sizeof(mp));
		scanf("%s", &str);
		int len = strlen(str), res1 = 0, res2 = 0;
		for (int times = 0; times < len; ++times)
		{
			if (str[times] == '0')
			{
				continue;
			}
			int flag = times % 2 == 0 ? 1 : 2;
			bool rem = false;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
					if (mp[i][j] == 0)
					{
						rem = true;
					}
			int maxi = -1, x, y;
			for (int i = 0; i < 4; ++i)
				for (int j = 0; j < 4; ++j)
				{
					if (rem && mp[i][j] == 0)
					{
						int t = check(i, j, flag);
						if (t > maxi)
						{
							maxi = t, x = i, y = j;
						}
					}
					else if (!rem && mp[i][j] != flag)
					{
						int t = check(i, j, flag);
						if (t > maxi)
						{
							maxi = t, x = i, y = j;
						}
					}
				}
			int add;
			if (maxi == -1)
			{
				add = 50;
			}
			else
			{
				add = maxi;
				mp[x][y] = flag;
			}
			if (times % 2 == 0)
			{
				res1 += add;
			}
			else
			{
				res2 += add;
			}
		}
		printf("Case %d: %d %d\n", caseT, res1, res2);
	}
	return 0;
}
