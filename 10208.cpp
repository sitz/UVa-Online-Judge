#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
#define ex 2.7182818284590452354
#define pi acos(-1.0)
#define inf 0x3fffffff
#define DC(n) printf("Case #%d:", ++n)
#define SD(n) scanf("%d", &n)
#define SS(str) scanf("%s", str)
#define SDB(n) scanf("%lf", &n)
#define ll long long
#define mm 1000000007
#define mmax 10000010

bool fg[mmax];

void pre()
{
	memset(fg, 0, sizeof fg);
	for (int i = 2; i * i < mmax; i++)
	{
		if (!fg[i])
		{
			for (int j = i * i; j < mmax; j += i)
			{
				fg[j] = 1;
			}
		}
	}
}
int ans[60];
int getcnt(int x, int n)
{
	int ans = 0;
	while (n)
	{
		ans += n / x;
		n /= x;
	}
	return ans;
}

int main()
{
	pre();
	int n, ca = 0;
	string str;
	while (cin >> str)
	{
		if (ca)
		{
			printf("\n");
		}
		ca++;
		char c = str[str.size() - 1];
		n = 0;
		bool ft = 0;
		if (c != '!')
		{
			for (int i = 0; i < str.size(); i++)
			{
				n = 10 * n + str[i] - '0';
			}
			for (int i = 0; i * i <= n; i++)
			{
				int d = n - i * i;
				int tmp = sqrt(d);
				if (tmp * tmp == d)
				{
					printf("He might be honest.\n");
					ft = 1;
					break;
				}
			}
			if (!ft)
			{
				printf("He is a liar.\n");
			}
		}
		if (c == '!')
		{
			for (int i = 0; i < str.size() - 1; i++)
			{
				n = 10 * n + str[i] - '0';
			}
			int cnt = 0;
			for (int i = 3; i <= n; i++)
			{
				if ((i % 4 == 3) && (!fg[i]))
				{
					int num = getcnt(i, n);
					if (num & 1)
					{
						ft = 1;
						ans[cnt++] = i;
						if (cnt >= 50)
						{
							break;
						}
					}
				}
			}
			if (!ft)
			{
				printf("He might be honest.\n");
			}
			else
			{
				printf("He is a liar.\n");
				for (int i = 0; i < cnt; i++)
				{
					printf("%d%c", ans[i], i == cnt - 1 ? '\n' : ' ');
				}
			}
		}
	}
	return 0;
}
