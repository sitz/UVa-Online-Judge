#include <bits/stdc++.h>

using namespace std;

int main()
{
	char p[1000];
	int i, array[52], max;
	while (cin.getline(p, 1000))
	{
		max = 0;
		for (i = 0; i < 52; i++)
		{
			array[i] = 0;
		}
		for (i = 0; p[i] != '\0'; i++)
		{
			if (isalpha(p[i]))
			{
				if (isupper(p[i]))
				{
					array[p[i] - 'A']++;
				}
				if (islower(p[i]))
				{
					array[p[i] - 'a' + 26]++;
				}
			}
		}
		for (i = 0; i < 52; i++)
			if (array[i] > max)
			{
				max = array[i];
			}
		for (i = 0; i < 52; i++)
			if (array[i] == max)
			{
				if (i < 26)
				{
					cout << char(i + 'A');
				}
				if (i >= 26)
				{
					cout << char(i - 26 + 'a');
				}
			}
		cout << ' ' << max << endl;
	}
	return 0;
}
