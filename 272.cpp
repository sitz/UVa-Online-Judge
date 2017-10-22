#include <bits/stdc++.h>

using namespace std;

int main()
{
	char buf[1000];
	int flag = 0;
	while (gets(buf))
	{
		int i;
		for (i = 0; buf[i]; i++)
		{
			if (buf[i] == '"')
			{
				if (flag == 0)
				{
					cout << "``";
					flag = 1;
				}
				else if (flag == 1)
				{
					cout << "''";
					flag = 0;
				}
			}
			else
			{
				cout << buf[i];
			}
		}
		cout << endl;
	}
	return 0;
}
