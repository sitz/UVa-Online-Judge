#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

char s[1005], tmp[1005];
int ans;

void go();

int main()
{
	int T, t, i, j;
	scanf(" %d", &T);
	gets(s);
	for (t = 0; t < T; t++)
	{
		gets(s);
		for (i = 0; s[i]; i++)
		{
			tmp[i] = s[i];
		}
		ans = 99999;
		if (tmp[0] == '?')
		{
			tmp[0] = '1';
			go();
			for (i = 0; s[i]; i++)
			{
				tmp[i] = s[i];
			}
			tmp[0] = '0';
			go();
		}
		else
		{
			go();
		}
		printf("Case %d: %d\n", t + 1, ans);
	}
	return 0;
}

void go()
{
	int i, j, len1, len2;
	for (i = 1; s[i]; i++)
	{
		if (tmp[i] == '?')
		{
			if (tmp[i + 1])
			{
				if (tmp[i - 1] == '1')
				{
					if (tmp[i + 1] == '1')
					{
						tmp[i] = '0';
					}
					else if (tmp[i + 1] == '0')
					{
						len1 = len2 = 0;
						char ch;
						for (j = i - 1, ch = tmp[j]; j >= 0; j--)
							if (ch == tmp[j])
							{
								len1++;
							}
							else
							{
								break;
							}
						for (j = i + 1, ch = tmp[j]; s[j]; j++)
							if (ch == tmp[j])
							{
								len2++;
							}
							else
							{
								break;
							}
						if (len1 <= len2)
						{
							tmp[i] = tmp[i - 1];
						}
						else
						{
							tmp[i] = tmp[i + 1];
						}
					}
					else//=='?'
					{
						if (tmp[i - 1] == '0')
						{
							tmp[i] = '1';
						}
						else
						{
							tmp[i] = '0';
						}
					}
				}
				else
				{
					if (tmp[i + 1] == '0')
					{
						tmp[i] = '1';
					}
					else if (tmp[i + 1] == '1')
					{
						len1 = len2 = 0;
						char ch;
						for (j = i - 1, ch = tmp[j]; j >= 0; j--)
							if (ch == tmp[j])
							{
								len1++;
							}
							else
							{
								break;
							}
						for (j = i + 1, ch = tmp[j]; s[j]; j++)
							if (ch == tmp[j])
							{
								len2++;
							}
							else
							{
								break;
							}
						if (len1 <= len2)
						{
							tmp[i] = tmp[i - 1];
						}
						else
						{
							tmp[i] = tmp[i + 1];
						}
					}
					else//=='?'
					{
						if (tmp[i - 1] == '0')
						{
							tmp[i] = '1';
						}
						else
						{
							tmp[i] = '0';
						}
					}
				}
			}
			else
			{
				if (tmp[i - 1] == '0')
				{
					tmp[i] = '1';
				}
				else
				{
					tmp[i] = '0';
				}
			}
		}
	}
	char ch;
	for (i = len1 = 0, len2 = 0, ch = tmp[0]; s[i]; i++)
	{
		if (tmp[i] == ch)
		{
			len1++;
		}
		else
		{
			len2 = len1 > len2 ? len1 : len2;
			ch = tmp[i];
			len1 = 1;
		}
	}
	len2 = len1 > len2 ? len1 : len2;
	if (len2 < ans)
	{
		ans = len2;
	}
}
