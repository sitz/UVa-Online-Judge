#include <bits/stdc++.h>

using namespace std;

int num[13];
int pile[13][4];
int ary[104];
char buf[2008];

int trans(char now)
{
	if (now == 'A')
	{
		return 10;
	}
	else if (now == 'T')
	{
		return 9;
	}
	else if (now == 'J')
	{
		return 0;
	}
	else if (now == 'Q')
	{
		return 11;
	}
	else if (now == 'K')
	{
		return 12;
	}
	return now - 49;
}

int play()
{
	int c, now;
	memset(num, 0, sizeof(num));
	now = pile[12][num[12]++];
	c = 1;
	for (;;)
	{
		if (num[now] < 4)
		{
			c++;
			now = pile[now][num[now]++];
		}
		else
		{
			break;
		}
	}
	/*printf("%d\n", c);*/
	return c == 52;
}

int main()
{
	int n, i, j, ans;
	while (scanf("%s", buf) == 1)
	{
		if (buf[0] == '0')
		{
			break;
		}
		n = 0;
		do
		{
			ary[n] = ary[n + 52] = trans(buf[0]);
			n++;
			/*printf("%d\n", ary[n-1]);*/
		} while (n < 52 && scanf("%s", buf) == 1);
		for (i = 0, ans = 0; i < 52; i++)
		{
			for (j = 0; j < 52; j += 4)
			{
				memcpy(pile[j / 4], ary + i + j, sizeof(int) * 4);
				/*if(!i)printf("%d\n", pile[j][j/13]);*/
			}
			ans += play();
		}
		printf("%d\n", ans);
	}
	return 0;
}
