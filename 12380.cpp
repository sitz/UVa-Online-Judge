#include <bits/stdc++.h>

using namespace std;

#define eps 1e-9
#define ll long long
char str[5000];

void get_data()
{
	scanf("%s", str);
}

int stk[5000], sn, stt[5000];

void disp()
{
	int i;
	for (i = 0; i < sn; i++)
	{
		printf("%d*%d ", stk[i], stt[i]);
	}
	printf("\n");
}

int run()
{
	int i, vmax = 1;
	sn = 0;
	stk[sn++] = 0;
	stt[sn - 1] = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] == '2')
		{
			stk[sn++] = 0;
			stt[sn - 1] = 0;
			if (sn > vmax)
			{
				vmax = sn;
			}
		}
		else
		{
			stk[sn - 1]++;
			stt[sn - 1] |= (1 << (str[i] - '0'));
			while (stk[sn - 1] == 4)
			{
				if (stt[sn - 1] != 3)
				{
					return -1;
				}
				sn--;
				stk[sn - 1]++;
				stt[sn - 1] |= 3;
			}
		}
	}
	if (sn == 1 && stk[sn - 1] == 1)
	{
		return vmax;
	}
	return -1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		get_data();
		int r = run();
		if (r == -1)
		{
			printf("Not Possible\n");
		}
		else
		{
			printf("2^%d*2^%d\n", r - 1, r - 1);
		}
	}
	return 0;
}
