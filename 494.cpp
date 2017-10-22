#include <bits/stdc++.h>

using namespace std;

int process(char *p)
{
	int i, num = 0;
	for (i = 0; p[i] != '\0'; i++)
	{
		if (isalpha(p[i]) == 0)
		{
			if (isalpha(p[i - 1]))
			{
				num++;
			}
		}
	}
	return num;
}

int main()
{
	char buf[100000];
	while (cin.getline(buf, 100000))
	{
		cout << process(buf) << endl;
	}
	return 0;
}
