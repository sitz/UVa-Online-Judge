#include <bits/stdc++.h>

using namespace std;

int N[20], T[20];
char in[25], out[25];
int main()
{
	int i, j, len, tl;
	while (scanf("%s", in) == 1)
	{
		if (in[0] == '*')
		{
			break;
		}
		for (i = 0; i < 20; i++)
		{
			N[i] = 0;
		}
		len = 1;
		if (in[0] > '9')
		{
			for (i = 0; in[i]; i++)
			{
				for (j = 0; j < len; j++)
				{
					N[j] *= 26;
				}
				N[0] += in[i] - '`';
				for (j = 0; j < len; j++)
				{
					N[j + 1] += N[j] / 1000;
					N[j] %= 1000;
				}
				if (N[len])
				{
					len++;
				}
			}
			for (; i < 22; i++)
			{
				in[i] = ' ';
			}
			in[22] = '\0';
		}
		else
		{
			for (i = 0; in[i]; i++)
			{
				for (j = 0; j < len; j++)
				{
					N[j] *= 10;
				}
				N[0] += in[i] - '0';
				for (j = 0; j < len; j++)
				{
					N[j + 1] += N[j] / 1000;
					N[j] %= 1000;
				}
				if (N[len])
				{
					len++;
				}
			}
			for (i = 0, tl = len; i < tl; i++)
			{
				T[i] = N[i];
			}
			for (i = 0; tl > 1 || T[0]; i++)
			{
				for (j = len - 1; j > 0; j--)
				{
					T[j - 1] += T[j] % 26 * 1000;
					T[j] /= 26;
				}
				j = T[0] % 26;
				T[0] /= 26;
				if (!j)
				{
					out[i] = 'z';
					for (T[j = 0]--; T[j] < 0; j++)
					{
						T[j + 1]--;
						T[j] += 1000;
					}
				}
				else
				{
					out[i] = '`' + j;
				}
				if (!T[tl - 1])
				{
					tl--;
				}
			}
			for (j = 0; j < i; j++)
			{
				in[j] = out[i - j - 1];
			}
			for (; j < 22; j++)
			{
				in[j] = ' ';
			}
			in[22] = '\0';
		}
		printf("%s%d", in, N[len - 1]);
		for (i = len - 2; i >= 0; i--)
		{
			printf(",%03d", N[i]);
		}
		printf("\n");
	}
	return 0;
}
