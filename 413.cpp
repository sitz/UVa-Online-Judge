#include <bits/stdc++.h>
#include <iostream>
#include <strstream>

using namespace std;

class InputCase
{
public:
	int ReadCase();
	void solve();
	int numCase;
	char buf[10000];
	int arr[10000];
};

int InputCase::ReadCase()
{
	numCase = 0;
	if (cin.getline(buf, 10000))
	{
		if (strcmp(buf, "0") == 0)
		{
			return 0;
		}
		istrstream input(buf);
		int n;
		while (input >> n)
		{
			arr[numCase++] = n;
		}
		numCase--;
		return 1;
	}
	else
	{
		return 0;
	}
}

void InputCase::solve()
{
	double TotalUp = 0, TotalDown = 0, Neutral = 0;
	double UpTimes = 0, DownTimes = 0;
	int i, flag = 0;
	for (i = 0; i < numCase - 1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			TotalUp += 1.0;
			TotalUp += Neutral;
			Neutral = 0;
			if (flag != 1)
			{
				UpTimes += 1.0;
			}
			flag = 1;
		}
		else if (arr[i] == arr[i + 1])
		{
			if (flag == 0)
			{
				Neutral += 1.0;
			}
			else if (flag == 1)
			{
				TotalUp += 1.0;
			}
			else if (flag == -1)
			{
				TotalDown += 1.0;
			}
		}
		else if (arr[i] > arr[i + 1])
		{
			TotalDown += 1.0;
			TotalDown += Neutral;
			Neutral = 0;
			if (flag != -1)
			{
				DownTimes += 1.0;
			}
			flag = -1;
		}
	}
	if (flag == 1)
	{
		TotalUp += Neutral;
		Neutral = 0;
	}
	if (flag == -1)
	{
		TotalDown += Neutral;
		Neutral = 0;
	}
	if (Neutral)
	{
		printf("Nr values = %d:  0.000000 0.000000\n", numCase);
	}
	else if (!Neutral)
	{
		if (UpTimes == 0)
		{
			UpTimes = 1;
		}
		if (DownTimes == 0)
		{
			DownTimes = 1;
		}
		printf("Nr values = %d:  %.6lf %.6lf\n", numCase, TotalUp / UpTimes, TotalDown / DownTimes);
	}
}

int main()
{
	InputCase test;
	while (test.ReadCase())
	{
		test.solve();
	}
	return 0;
}
