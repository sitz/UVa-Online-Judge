#include <bits/stdc++.h>

using namespace std;

char cmd[100], buf[100];

void delSpace()
{
	int start, end, i, j;
	for (start = 0; isspace(cmd[start]); start++)
		;
	for (end = strlen(cmd) - 1; isspace(cmd[end]); end--)
		;
	for (j = 0, i = start; i <= end; i++)
	{
		buf[j++] = cmd[i];
	}
	buf[j] = '\0';
}

bool solve()
{
	int i, j = 0, numOfEle = 0, numOfHyphen = 0;
	int sum[20];
	for (i = 0; buf[i]; i++)
	{
		if (buf[i] == '-')
		{
			numOfHyphen++;
		}
		else if (buf[i] == 'X' && numOfEle == 9)
		{
			sum[j++] = 10;
			numOfEle++;
		}
		else if (isdigit(buf[i]))
		{
			sum[j++] = buf[i] - '0';
			numOfEle++;
		}
		else
		{
			return false;
		}
	}
	if (numOfEle != 10)
	{
		return false;
	}
	for (i = 1; i < 10; i++)
	{
		sum[i] += sum[i - 1];
	}
	for (i = 1; i < 10; i++)
	{
		sum[i] += sum[i - 1];
	}
	if (sum[9] % 11 != 0)
	{
		return false;
	}
	return true;
}

int main()
{
	while (cin.getline(cmd, 100))
	{
		delSpace();
		if (solve())
		{
			cout << buf << " is correct." << endl;
		}
		else
		{
			cout << buf << " is incorrect." << endl;
		}
	}
	return 0;
}
