#include <bits/stdc++.h>

using namespace std;

bool exp_[50];
char con[50][2][80], acr[50][2][80], str[160];
int len[50][2], len1[50][2], C, A;

int findcon(char *s)
{
	for (int i = 0; i < C; i++)
	{
		int length = len[i][0];
		bool flag = true;
		for (int j = 0; j < length; j++)
			if (tolower(s[j]) != tolower(con[i][0][j]))
			{
				flag = false;
			}
		if (flag)
		{
			return i + 1;
		}
	}
	return 0;
}
int findacr(char *s)
{
	for (int i = 0; i < A; i++)
	{
		int length = len1[i][0];
		bool flag = true;
		for (int j = 0; j < length; j++)
			if (s[j] != acr[i][0][j])
			{
				flag = false;
			}
		if (flag)
		{
			return i + 1;
		}
	}
	return 0;
}

int main()
{
	gets(str);
	sscanf(str, "%d %d", &C, &A);
	for (int i = 0, j = 0, l = 0; i < C; i++, l = 0)
	{
		gets(str);
		for (j = 0; str[j] != '\"'; j++)
			;
		for (j++; str[j] != '\"'; j++)
		{
			con[i][0][l++] = tolower(str[j]);
		}
		con[i][0][l] = '\0';
		len[i][0] = l;
		l = 0;
		for (j++; str[j] != '\"'; j++)
			;
		for (j++; str[j] != '\"'; j++)
		{
			con[i][1][l++] = tolower(str[j]);
		}
		con[i][1][l] = '\0';
		len[i][1] = l;
	}
	for (int i = 0, j = 0, l = 0; i < A; i++, l = 0)
	{
		gets(str);
		for (j = 0; str[j] != '\"'; j++)
			;
		for (j++; str[j] != '\"'; j++)
		{
			acr[i][0][l++] = str[j];
		}
		acr[i][0][l] = '\0';
		len1[i][0] = l;
		l = 0;
		for (j++; str[j] != '\"'; j++)
			;
		for (j++; str[j] != '\"'; j++)
		{
			acr[i][1][l++] = str[j];
		}
		acr[i][1][l] = '\0';
		len1[i][1] = l;
	}
	do
	{
		memset(exp_, false, sizeof(exp_));
		char temp[80], temp1[80], *p, k;
		if (gets(str) == NULL)
		{
			break;
		}
		while (1)
		{
			if (strcmp(str, "#") == 0)
			{
				puts("#");
				break;
			}
			for (p = str; *p;)
			{
				int ans = findcon(p);
				if (ans)
				{
					int length = len[ans - 1][1];
					if (isupper(*p))
					{
						printf("%c", toupper(con[ans - 1][1][0]));
					}
					else
					{
						printf("%c", con[ans - 1][1][0]);
					}
					if (isupper(*(p + 1)))
						for (int i = 1; i < length; i++)
						{
							printf("%c", toupper(con[ans - 1][1][i]));
						}
					else
						for (int i = 1; i < length; i++)
						{
							printf("%c", con[ans - 1][1][i]);
						}
					p += len[ans - 1][0];
				}
				else if (ans = findacr(p))
				{
					int length = len1[ans - 1][0];
					if (exp_[ans - 1])
					{
						printf("%s", acr[ans - 1][0]);
					}
					else
					{
						exp_[ans - 1] = true;
						printf("%s (%s)", acr[ans - 1][1], acr[ans - 1][0]);
					}
					p += length;
				}
				else
				{
					putchar(*p++);
				}
			}
			putchar('\n');
			gets(str);
		}
	} while (1);
	return 0;
}
