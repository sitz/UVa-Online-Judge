#include <bits/stdc++.h>

using namespace std;

#define IN_FILE "PROBLEMD.DAT"
char buff[100];

long raise(long x, int exponent)
{
	int i;
	long res = 1;
	for (i = 0; i < exponent; i++)
	{
		res *= x;
	}
	return res;
}

int main()
{
	long num, div, dist, range;
	long freq[10];
	int position;
	/*    FILE *in_file = fopen(IN_FILE, "r");*/
	FILE *in_file;
	char district;
	char *cp;
	int cnt = 0;
	int left_posn, i;
	/*    if (in_file == 0) {
	    fprintf(stderr, "Failed to open `%s'\n", IN_FILE);
	    exit(1);
	    }*/
	in_file = stdin;
	while (1)
	{
		fgets(buff, sizeof(buff), in_file);
		num = 0;
		for (i = 0, cp = buff; i < 10; i++, cp++)
		{
			int digit;
			if (i == 2)
			{
				district = *cp;
			}
			else
			{
				digit = *cp - '0';
				num = num == 0 && digit != 0 ? digit : num * 10 + digit;
			}
		}
		if (num == 0 && district == '0')
		{
			break;
		}
		sscanf(cp, "%d", &position);
		if (position == 0)
		{
			break;
		}
		if (cnt++ != 0)
		{
			printf("\n");
		}
		if (position == 3)
		{
			for (i = 0; i < 10; i++)
			{
				if (i == (district - '0'))
				{
					printf("%11ld\n", district == '0' ? num - 1 : num);
				}
				else
				{
					printf("%11ld\n", 0L);
				}
			}
			continue;
		}
		for (i = 0; i < 10; i++)
		{
			freq[i] = 0;
		}
		if (position == 1)
		{
			left_posn = 9;
		}
		else if (position == 2)
		{
			left_posn = 8;
		}
		else
		{
			left_posn = 11 - position;
		}
		/*
		 * Distribute everything to the digits left
		 */
		if (left_posn != 9)
		{
			dist = num - num % raise(10, left_posn);
			for (i = 0; i < 10; i++)
			{
				freq[i] += dist / 10;
			}
		}
		/*
		 * Distribute the digit.
		 */
		dist = (num % raise(10, left_posn)) - num % raise(10, left_posn - 1);
		range = dist / raise(10, left_posn - 1);
		for (i = 0; i < range; i++)
		{
			freq[i] += dist / range;
		}
		/*
		 * Distribute everything to the digit's right.
		 */
		if (left_posn != 1)
		{
			freq[range] += num % raise(10, left_posn - 1);
		}
		for (i = 0; i < 10; i++)
		{
			printf("%11ld\n", district == '0' && i == 0 ? freq[i] - 1 : freq[i]);
		}
	}
	return 0;
}
