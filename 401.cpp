#include <bits/stdc++.h>

using namespace std;

char mirror1[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char mirror2[50] = "A***3**HIL*JM*O***2TUVWXY51SE*Z**8*";

bool ispalindrome(char *p)
{
	int i, j, length = (int)strlen(p);
	for (i = 0, j = length - 1; p[i] != '\0'; i++, j--)
		if (p[i] != p[j])
		{
			return false;
		}
	return true;
}

bool ismirrored(char *p)
{
	int i, j, length = (int)strlen(p);
	for (i = 0, j = length - 1; p[i] != '\0'; i++, j--)
	{
		if (isupper(p[i]))
			if (mirror2[p[i] - 'A'] != p[j])
			{
				return false;
			}
			else if (isdigit(p[i]))
				if (mirror2[p[i] - '1' + 26] != p[j])
				{
					return false;
				}
	}
	return true;
}

int main()
{
	char p[100];
	while (cin >> p)
	{
		bool ispal, ismirr;
		ispal = ispalindrome(p);
		ismirr = ismirrored(p);
		if (ispal && ismirr)
		{
			cout << p << " -- is a mirrored palindrome.\n"
					 << endl;
		}
		else if (ispal && !ismirr)
		{
			cout << p << " -- is a regular palindrome.\n"
					 << endl;
		}
		else if (!ispal && ismirr)
		{
			cout << p << " -- is a mirrored string.\n"
					 << endl;
		}
		else
		{
			cout << p << " -- is not a palindrome.\n"
					 << endl;
		}
	}
	return 0;
}
