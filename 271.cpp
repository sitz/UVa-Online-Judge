#include <bits/stdc++.h>

using namespace std;

bool FitSyntax(char &a)
{
	if ((a >= 'p' && a <= 'z') || a == 'N' || a == 'C' || a == 'D' || a == 'E' || a == 'I')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char buf[1000];
	while (cin.getline(buf, 1000))
	{
		int cnt = 0, i;
		for (i = strlen(buf) - 1; i >= 0; i--)
		{
			if (!FitSyntax(buf[i]))
			{
				cnt = 0;
				break;
			}
			if (FitSyntax(buf[i]))
			{
				if (buf[i] >= 'p' && buf[i] <= 'z')
				{
					cnt++;
				}
				if (buf[i] == 'C' || buf[i] == 'D' || buf[i] == 'E' || buf[i] == 'I')
				{
					if (cnt >= 2)
					{
						cnt--;
					}
					else
					{
						cnt = 0;
						break;
					}
				}
				if (buf[i] == 'N')
					if (cnt == 0)
					{
						break;
					}
			}
		}
		if (cnt == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
