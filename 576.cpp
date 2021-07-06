#include <bits/stdc++.h>

using namespace std;

bool isvowel(char n)
{
	if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u' || n == 'y')
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
	char p[1000];
	int cnt1, cnt2, cnt3, i, ps1, ps2;
	while (cin.getline(p, 1000))
	{
		if (strcmp("e/o/i", p) == 0)
		{
			break;
		}
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for (i = 0; p[i] != '/'; i++)
			;
		ps1 = i;
		for (i++; p[i] != '/'; i++)
			;
		ps2 = i;
		for (i = 0; i < ps1; i++)
		{
			bool flag = false;
			while (isvowel(p[i]))
			{
				flag = true;
				i++;
			}
			if (flag == true)
			{
				cnt1++;
			}
		}
		for (i = ps1; i < ps2; i++)
		{
			bool flag = false;
			while (isvowel(p[i]))
			{
				flag = true;
				i++;
			}
			if (flag == true)
			{
				cnt2++;
			}
		}
		for (i = ps2; p[i] != '\0'; i++)
		{
			bool flag = false;
			while (isvowel(p[i]))
			{
				flag = true;
				i++;
			}
			if (flag == true)
			{
				cnt3++;
			}
		}
		//print result:
		if (cnt1 == 5 && cnt2 == 7 && cnt3 == 5)
		{
			cout << 'Y' << endl;
			continue;
		}
		if (cnt1 != 5)
		{
			cout << 1 << endl;
			continue;
		}
		if (cnt2 != 7)
		{
			cout << 2 << endl;
			continue;
		}
		if (cnt3 != 5)
		{
			cout << 3 << endl;
		}
	}
	return 0;
}
