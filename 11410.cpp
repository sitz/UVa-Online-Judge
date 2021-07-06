#include <bits/stdc++.h>

using namespace std;

char s1[30], s2[30], res[30];
int set_[30];

int main()
{
	int count, i, j, len, alen, avn, lac, val;
	long long temp, ord;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%s", s1, s2);
		memset(set_, 0, sizeof(set_));
		for (i = 0; s2[i]; i++)
		{
			set_[s2[i] - 'A'] = 1;
		}
		for (i = 0, avn = 0; i < 26; i++)
		{
			if (set_[i] == 0)
			{
				if (avn == 0)
				{
					lac = i;
				}
				avn++;
			}
		}
		len = strlen(s1);
		for (i = 1, ord = 0; i < len; i++)
		{
			for (j = 1, temp = 1; j < i; j++)
			{
				temp *= 26;
			}
			temp *= 25;
			ord += temp;
		}
		for (i = len - 1, temp = 1; i >= 0; i--, temp *= 26)
		{
			val = s1[i] - 'A';
			if (i == 0)
			{
				val--;
			}
			ord += temp * val;
		}
		for (i = 1, temp = avn - 1;; i++, temp *= avn)
		{
			if (temp > ord)
			{
				break;
			}
			ord -= temp;
		}
		temp /= avn - 1;
		alen = i;
		for (i = 0; i < alen; i++, temp /= avn)
		{
			for (j = 0; j < 26; j++)
			{
				if (set_[j] == 0 && (i || j != lac))
				{
					if (ord < temp)
					{
						break;
					}
					ord -= temp;
				}
			}
			printf("%c", j + 'A');
		}
		printf("\n");
	}
	return 0;
}
