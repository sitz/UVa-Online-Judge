#include <bits/stdc++.h>

using namespace std;

int num, side;
char buffer[1010], ch;

int number(int a, int b)
{
	int i, j;
	int sum;
	sum = 0;
	for (i = b, j = 0; i >= a; i--, j++)
	{
		if (buffer[i] == 'T')
		{
			sum += (int)pow(2.0, (double)j);
		}
	}
	return sum;
}

int main()
{
	while (cin >> num >> ch >> side && num)
	{
		cin >> buffer;
		int len = (int)ceil(log(side * 1.0) / log(2.0));
		if (side == 1)
		{
			if (strlen(buffer) >= num)
			{
				cout << num << endl;
			}
			else
			{
				cout << -1 << endl;
			}
			continue;
		}
		int cnt = 0;
		int sum = 0;
		bool success = false;
		for (int i = 0; i < strlen(buffer) - len + 1; i++)
		{
			int value = number(i, i + len - 1) + 1;
			if (value <= side)
			{
				cnt++;
				sum += value;
			}
			i = i + len - 1;
			if (cnt == num)
			{
				success = true;
				break;
			}
		}
		if (success)
		{
			cout << sum << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
