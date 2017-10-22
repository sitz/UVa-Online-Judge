#include <bits/stdc++.h>

using namespace std;

int P[256][256];
unsigned char str[50000];
char temp[50000], t;
int pre(int loc)
{
	if (loc == 0)
	{
		return P[0][0];
	}
	if (loc == 1)
	{
		return P[0][str[0]];
	}
	return P[str[loc - 2]][str[loc - 1]];
}
void update(int loc, int value)
{
	if (loc == 0)
	{
		P[0][0] = value;
	}
	else if (loc == 1)
	{
		P[0][str[0]] = value;
	}
	else
	{
		P[str[loc - 2]][str[loc - 1]] = value;
	}
}
int main()
{
	int s = 0;
	while (scanf("%c", &t) == 1)
	{
		temp[s++] = t;
	}
	memset(P, -1, sizeof(P));
	for (int i = 0; i < s; i++)
	{
		str[i] = (unsigned char)temp[i];
	}
	for (int i = 0; i < s; i += 6)
	{
		unsigned char total = 64;
		unsigned char output[6];
		int len = 0;
		for (int j = 0; j < 6 && i + j < s; j++)
		{
			static int mask[6] = {1, 2, 4, 8, 16, 32};
			int predict = pre(i + j);
			if (predict == str[i + j])
			{
				total += mask[j];
			}
			else
			{
				output[len++] = str[i + j];
				update(i + j, str[i + j]);
			}
		}
		printf("%c", total);
		for (int j = 0; j < len; j++)
		{
			printf("%c", output[j]);
		}
	}
}
