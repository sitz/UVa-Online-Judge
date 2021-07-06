#include <bits/stdc++.h>

using namespace std;

char str[500], ttt[500];
int len;
unsigned long long int v, ans;
unsigned long long int GCD(unsigned long long int a, unsigned long long int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		len = strlen(str);
		sscanf(str, "%lld", &v);
		ans = -1;
		for (int i = 1; i <= len; i++)
		{
			unsigned long long int base = 1;
			for (int j = 1; j <= i; j++)
			{
				base *= 10;
			}
			unsigned long long int mul = 1, temp;
			for (int k = i + 1; k <= len + len; k += i)
			{
				if (i != 1 && i + k - 1 > 2 * len)
				{
					break;
				}
				mul = (unsigned long long int)mul * base + (unsigned long long int)1;
				if (i == 1 && k == 1)
				{
					continue;
				}
				unsigned long long int d = GCD(mul, v);
				temp = v / d;
				sprintf(ttt, "%lld", temp);
				int len1 = strlen(ttt);
				if (len1 <= i)
				{
					if (temp == 1)
					{
						while (len1 < i)
						{
							temp *= 10;
							len1++;
						}
					}
					else
					{
						unsigned long long int sbase = temp;
						while (len1 < i)
						{
							temp += sbase;
							sprintf(ttt, "%d", temp);
							len1 = strlen(ttt);
						}
					}
					unsigned long long int s1 = (unsigned long long int)temp * mul;
					if (ans == -1 || s1 < ans)
					{
						//printf("%I64d %I64d\n", temp, mul);
						ans = s1;
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
}
