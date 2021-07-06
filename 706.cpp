#include <bits/stdc++.h>

using namespace std;

char model[10][8] =
		{
				'-', '|', '|', ' ', '|', '|', '-', '\0',
				' ', ' ', '|', ' ', ' ', '|', ' ', '\0',
				'-', ' ', '|', '-', '|', ' ', '-', '\0',
				'-', ' ', '|', '-', ' ', '|', '-', '\0',
				' ', '|', '|', '-', ' ', '|', ' ', '\0',
				'-', '|', ' ', '-', ' ', '|', '-', '\0',
				'-', '|', ' ', '-', '|', '|', '-', '\0',
				'-', ' ', '|', ' ', ' ', '|', ' ', '\0',
				'-', '|', '|', '-', '|', '|', '-', '\0',
				'-', '|', '|', '-', ' ', '|', '-', '\0',
};

int get_array(int n, int *array)
{
	int i, length = 0, tmp;
	if (n == 0)
	{
		array[0] = 0;
		return 1;
	}
	while (n)
	{
		array[length++] = n % 10;
		n /= 10;
	}
	for (i = 0; i < length / 2; i++)
	{
		tmp = array[i];
		array[i] = array[length - 1 - i];
		array[length - 1 - i] = tmp;
	}
	return length;
}

int main()
{
	int n, s, array[10], length;
	while (cin >> s >> n)
	{
		if (s == 0 && n == 0)
		{
			break;
		}
		length = get_array(n, array);
		int i, j, k;
		for (i = 0; i < length; i++)//print line 1;
		{
			cout << ' ';
			for (j = 0; j < s; j++)
			{
				cout << model[array[i]][0];
			}
			cout << ' ';
			if (i == (length - 1))
			{
				cout << endl;
			}
			else
			{
				cout << ' ';
			}
		}
		for (k = 0; k < s; k++)
		{
			for (i = 0; i < length; i++)//print line 2;
			{
				cout << model[array[i]][1];
				for (j = 0; j < s; j++)
				{
					cout << ' ';
				}
				cout << model[array[i]][2];
				if (i == (length - 1))
				{
					cout << endl;
				}
				else
				{
					cout << ' ';
				}
			}
		}
		for (i = 0; i < length; i++)//print line 3;
		{
			cout << ' ';
			for (j = 0; j < s; j++)
			{
				cout << model[array[i]][3];
			}
			cout << ' ';
			if (i == (length - 1))
			{
				cout << endl;
			}
			else
			{
				cout << ' ';
			}
		}
		for (k = 0; k < s; k++)
		{
			for (i = 0; i < length; i++)//print line 2;
			{
				cout << model[array[i]][4];
				for (j = 0; j < s; j++)
				{
					cout << ' ';
				}
				cout << model[array[i]][5];
				if (i == (length - 1))
				{
					cout << endl;
				}
				else
				{
					cout << ' ';
				}
			}
		}
		for (i = 0; i < length; i++)//print line 5;
		{
			cout << ' ';
			for (j = 0; j < s; j++)
			{
				cout << model[array[i]][6];
			}
			cout << ' ';
			if (i == (length - 1))
			{
				cout << endl;
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}
