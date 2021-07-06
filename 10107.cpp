#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, array[10010], num = 0, i, j;
	while (cin >> x)
	{
		num++;
		if (num == 1)
		{
			array[0] = x;
		}
		else
		{
			if (x == 0)
			{
				for (j = num; j > 0; j--)
				{
					array[j] = array[j - 1];
				}
				array[0] = x;
			}
			else
			{
				for (i = 1; i < num; i++)
				{
					if (x >= array[i - 1] && x <= array[i])
					{
						for (j = num; j > i; j--)
						{
							array[j] = array[j - 1];
						}
						array[j] = x;
						break;
					}
				}
				if (i == num)
				{
					array[i - 1] = x;
				}
			}
		}
		if (num % 2 == 1)
		{
			cout << array[num / 2] << endl;
		}
		else
		{
			cout << (array[num / 2 - 1] + array[num / 2]) / 2 << endl;
		}
	}
	return 0;
}
