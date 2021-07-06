#include <bits/stdc++.h>

using namespace std;

bool match[5][5];
int map_[5][5];

bool chk_1()
{
	bool temp = false;
	for (int i = 0; i < 5; i++)
	{
		bool chk = true;
		for (int j = 0; j < 5; j++)
		{
			if (!match[i][j])
			{
				chk = false;
			}
		}
		if (chk)
		{
			temp = true;
			printf("BINGO #1\n");
			for (int j = 0; j < 5; j++)
			{
				printf("%d,%d,", i + 1, j + 1);
				if (map_[i][j] == 0)
				{
					printf("FREE\n");
				}
				else
				{
					printf("%d\n", map_[i][j]);
				}
			}
		}
	}
	return temp;
}

bool chk_2()
{
	bool temp = false;
	for (int i = 0; i < 5; i++)
	{
		bool chk = true;
		for (int j = 0; j < 5; j++)
		{
			if (!match[j][i])
			{
				chk = false;
			}
		}
		if (chk)
		{
			temp = true;
			printf("BINGO #2\n");
			for (int j = 0; j < 5; j++)
			{
				printf("%d,%d,", j + 1, i + 1);
				if (map_[j][i] == 0)
				{
					puts("FREE");
				}
				else
				{
					printf("%d\n", map_[j][i]);
				}
			}
		}
	}
	return temp;
}

bool chk_3()
{
	if (!match[0][0] || !match[0][4] || !match[4][0] || !match[4][4])
	{
		return false;
	}
	printf("BINGO #3\n");
	printf("1,1,");
	if (map_[0][0] == 0)
	{
		puts("FREE");
	}
	else
	{
		printf("%d\n", map_[0][0]);
	}
	printf("1,5,");
	if (map_[0][4] == 0)
	{
		puts("FREE");
	}
	else
	{
		printf("%d\n", map_[0][4]);
	}
	printf("5,1,");
	if (map_[4][0] == 0)
	{
		puts("FREE");
	}
	else
	{
		printf("%d\n", map_[4][0]);
	}
	printf("5,5,");
	if (map_[4][4] == 0)
	{
		puts("FREE");
	}
	else
	{
		printf("%d\n", map_[4][4]);
	}
	return true;
}

bool chk_4()
{
	int cnt = 0;
	bool chk = true;
	for (int i = 0; i < 5; i++)
	{
		if (!match[i][i])
		{
			chk = false;
		}
	}
	if (chk)
	{
		printf("BINGO #4\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d,%d,", i + 1, i + 1);
			if (map_[i][i] == 0)
			{
				puts("FREE");
			}
			else
			{
				printf("%d\n", map_[i][i]);
			}
		}
		cnt++;
	}
	chk = true;
	for (int i = 0; i < 5; i++)
	{
		if (!match[i][4 - i])
		{
			chk = false;
		}
	}
	if (chk)
	{
		printf("BINGO #4\n");
		for (int i = 0; i < 5; i++)
		{
			printf("%d,%d,", i + 1, 5 - i);
			if (map_[i][4 - i] == 0)
			{
				puts("FREE");
			}
			else
			{
				printf("%d\n", map_[i][4 - i]);
			}
		}
		cnt++;
	}
	return cnt != 0;
}

int main()
{
	int t;
	while (scanf("%d", &t) == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == 0 && j == 0)
				{
					map_[i][j] = t;
				}
				else
				{
					scanf("%d", &map_[i][j]);
				}
				match[i][j] = map_[i][j] == 0;
			}
		}

		bool flag = false;
		if (chk_1())
		{
			flag = true;
		}
		if (chk_2())
		{
			flag = true;
		}
		if (chk_3())
		{
			flag = true;
		}
		if (chk_4())
		{
			flag = true;
		}

		while (scanf("%d", &t), t)
		{
			if (flag)
			{
				continue;
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (map_[i][j] == t)
					{
						match[i][j] = true;
					}
				}
			}
			if (chk_1())
			{
				flag = true;
			}
			if (chk_2())
			{
				flag = true;
			}
			if (chk_3())
			{
				flag = true;
			}
			if (chk_4())
			{
				flag = true;
			}
		}

		if (!flag)
		{
			printf("No BINGO on this card.\n");
		}
		printf("\n");
	}
	return 0;
}
