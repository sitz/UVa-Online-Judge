#include <bits/stdc++.h>

using namespace std;

char cmd[10], hash_[84000][6];
int curr_idx = 0;

void init()
{
	memset(hash_, '\0', sizeof(hash_));
	int i, j, k, m, n;
	for (i = 0; i < 26 - 0; i++)
	{
		hash_[curr_idx][0] = (char)('a' + i);
		curr_idx++;
	}
	for (i = 0; i < 26 - 1; i++)
	{
		for (j = i + 1; j < 26 - 0; j++)
		{
			hash_[curr_idx][0] = (char)('a' + i);
			hash_[curr_idx][1] = (char)('a' + j);
			curr_idx++;
		}
	}
	for (i = 0; i < 26 - 2; i++)
	{
		for (j = i + 1; j < 26 - 1; j++)
		{
			for (k = j + 1; k < 26 - 0; k++)
			{
				hash_[curr_idx][0] = (char)('a' + i);
				hash_[curr_idx][1] = (char)('a' + j);
				hash_[curr_idx][2] = (char)('a' + k);
				curr_idx++;
			}
		}
	}
	for (i = 0; i < 26 - 3; i++)
	{
		for (j = i + 1; j < 26 - 2; j++)
		{
			for (k = j + 1; k < 26 - 1; k++)
			{
				for (m = k + 1; m < 26 - 0; m++)
				{
					hash_[curr_idx][0] = (char)('a' + i);
					hash_[curr_idx][1] = (char)('a' + j);
					hash_[curr_idx][2] = (char)('a' + k);
					hash_[curr_idx][3] = (char)('a' + m);
					curr_idx++;
				}
			}
		}
	}
	for (i = 0; i < 26 - 4; i++)
	{
		for (j = i + 1; j < 26 - 3; j++)
		{
			for (k = j + 1; k < 26 - 2; k++)
			{
				for (m = k + 1; m < 26 - 1; m++)
				{
					for (n = m + 1; n < 26 - 0; n++)
					{
						hash_[curr_idx][0] = (char)('a' + i);
						hash_[curr_idx][1] = (char)('a' + j);
						hash_[curr_idx][2] = (char)('a' + k);
						hash_[curr_idx][3] = (char)('a' + m);
						hash_[curr_idx][4] = (char)('a' + n);
						curr_idx++;
					}
				}
			}
		}
	}
}

bool isValid()
{
	for (int i = 0; i < strlen(cmd) - 1; i++)
	{
		if (cmd[i] >= cmd[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	init();
	while (cin >> cmd)
	{
		if (isValid())
		{
			for (int idx = 0; idx < curr_idx; idx++)
			{
				if (!strcmp(cmd, hash_[idx]))
				{
					printf("%d\n", idx+1);
					break;
				}
			}
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
