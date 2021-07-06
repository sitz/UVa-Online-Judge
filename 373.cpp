#include <bits/stdc++.h>

using namespace std;

int temp;
char buf[2008];

int equal(char now, char tar)
{
	return now == tar || now + 32 == tar;
}

void adjust(int loc)
{
	if (!loc)
	{
		return;
	}
	/*printf("%d\n", loc);*/
	if (equal(buf[loc - 1], 'p'))
	{
		if ((loc == 1 || !equal(buf[loc - 2], 'e')) && equal(buf[loc - 1], 'p'))
		{
			if (!equal(buf[loc + 1], 'u') || !equal(buf[loc + 2], 'k'))
			{
				temp = buf[loc];
				buf[loc] = buf[loc - 1];
				buf[loc - 1] = temp;
				adjust(loc - 1);
				return;
			}
		}
	}
	if (equal(buf[loc + 1], 'p'))
	{
		if (equal(buf[loc - 1], 'e') || (equal(buf[loc + 2], 'u') && equal(buf[loc + 3], 'k')))
		{
			temp = buf[loc];
			buf[loc] = buf[loc + 1];
			buf[loc + 1] = temp;
			adjust(loc + 1);
			if (equal(buf[loc - 1], 'g'))
			{
				adjust(loc - 1);
			}
		}
	}
}

int main()
{
	int i;
	while (gets(buf))
	{
		for (i = 0; buf[i]; i++)
		{
			if (equal(buf[i], 'g'))
			{
				adjust(i);
			}
		}
		puts(buf);
	}
	return 0;
}
