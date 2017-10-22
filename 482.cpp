#include <bits/stdc++.h>

using namespace std;

enum
{
	MAX = 1000
};

int pos[MAX];
string data[MAX];

int read_pos_array()
{
	int x, index = 0;
	while (cin >> x)
	{
		pos[x - 1] = index;//index shift (between 0 start and 1 start)
		index++;
		if (cin.get() == '\n')
			break;
	}
	return index;
}

void read_data_array(int len)
{
	for (int i = 0; i < len; ++i)
		cin >> data[i];
	cin.ignore(128, '\n');
}

int main()
{
	int num_case;
	cin >> num_case;
	while (num_case--)
	{
		cin.ignore(128, '\n');
		int len = read_pos_array();
		read_data_array(len);
		for (int i = 0; i < len; ++i)
			cout << data[pos[i]] << '\n';
		if (num_case != 0)
			putchar('\n');
	}
	return 0;
}
