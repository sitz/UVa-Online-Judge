#include <bits/stdc++.h>

using namespace std;

int tbl[14][11] =
{
	0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
	0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
	0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0,
	0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
	0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
	0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0,
	0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
	0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
};

bool state[11];
int num[11], hash_[255];

void solve(char *data)
{
	memset(num, 0, sizeof(num));
	memset(state, 0, sizeof(state));
	int l = strlen(data), t;
	for (int i = 0; i < l; i++)
	{
		t = hash_[data[i]];
		for (int j = 1; j < 11; j++)
		{
			if (tbl[t][j] && !state[j])
			{
				num[j]++, state[j] = 1;
			}
			if (!tbl[t][j])
			{
				state[j] = 0;
			}
		}
	}
	for (int i = 1; i < 11; i++)
	{
		printf("%d", num[i]);
		if (i == 10)
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
}

int main()
{
	int t;
	char data[205];
	hash_['c'] = 0, hash_['d'] = 1, hash_['e'] = 2;
	hash_['f'] = 3, hash_['g'] = 4, hash_['a'] = 5;
	hash_['b'] = 6, hash_['C'] = 7, hash_['D'] = 8;
	hash_['E'] = 9, hash_['F'] = 10, hash_['G'] = 11;
	hash_['A'] = 12, hash_['B'] = 13;
	scanf("%d", &t);
	gets(data);
	while (t--)
	{
		gets(data);
		solve(data);
	}
	return 0;
}
