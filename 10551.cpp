#include <bits/stdc++.h>

using namespace std;

int main()
{
	int b, i, array[500], num;
	char buf1[1010], buf2[100];
	long long R, s;
	while (cin >> b)
	{
		if (b == 0)
		{
			break;
		}
		cin >> buf1 >> buf2;
		R = s = 0;
		for (i = 0; buf2[i]; i++)
		{
			R *= b;
			R += buf2[i] - '0';
		}
		for (i = 0; buf1[i]; i++)
		{
			s *= b;
			s += buf1[i] - '0';
			s %= R;
		}
		if (s == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			num = 0;
			while (s)
			{
				array[num++] = s % b;
				s /= b;
			}
			for (i = num - 1; i >= 0; i--)
			{
				cout << array[i];
			}
			cout << endl;
		}
	}
	return 0;
}
