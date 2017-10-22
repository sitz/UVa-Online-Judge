#include <bits/stdc++.h>

using namespace std;

void is_equal(int *array, int *buf, int n, int p)
{
	int i;
	for (i = 0; i < 2 * p; i++)
	{
		array[buf[i]] = 1;
	}
}

void not_equal(int *array, int *buf, int n, int p)
{
	int i;
	for (i = 0; i < 2 * p; i++)
		if (array[buf[i]] != 1)
		{
			array[buf[i]] = 2;
		}
}

int main()
{
	int n, k, p, array[200], i, t, buf[200];
	char c;
	int a, b;
	cin >> a;
	int f = 0;
	for (b = 0; b < a; b++)
	{
		if (f)
		{
			cout << endl;
		}
		f = 1;
		cin >> n >> k;
		memset(array, 0, sizeof(array));
		for (t = 0; t < k; t++)
		{
			cin >> p;
			for (i = 0; i < 2 * p; i++)
			{
				cin >> buf[i];
			}
			cin >> c;
			if (c == '=')
			{
				is_equal(array, buf, n, p);
			}
			if (c == '>' || c == '<')
			{
				not_equal(array, buf, n, p);
			}
		}
		int cnt_0 = 0, cnt_2 = 0;
		int flag_0, flag_2;
		for (i = 1; i <= n; i++)
		{
			if (array[i] == 0)
			{
				cnt_0++;
				flag_0 = i;
			}
			if (array[i] == 2)
			{
				cnt_2++;
				flag_2 = i;
			}
		}
		if (cnt_2 > 1)
		{
			cout << 0 << endl;
			continue;
		}
		if (cnt_2 == 0 && cnt_0 > 1)
		{
			cout << 0 << endl;
			continue;
		}
		if (cnt_0 == 1 && cnt_2 == 0)
		{
			cout << flag_0 << endl;
			continue;
		}
		if (cnt_2 == 1)
		{
			cout << flag_2 << endl;
		}
	}
	return 0;
}
