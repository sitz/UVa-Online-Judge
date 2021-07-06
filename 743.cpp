#include <bits/stdc++.h>

using namespace std;

char in[40], out[120000];
int rec(int x)
{
	int len;
	switch (in[x])
	{
	case '2':
		if (in[x + 1] == '\0')
		{
			return -1;
		}
		strcpy(out, in + x + 1);
		return 1;
	case '3':
		if (rec(x + 1) < 0)
		{
			return -1;
		}
		len = strlen(out);
		strcpy(out + len + 1, out);
		out[len] = '2';
		return 1;
	default:
		return -1;
	}
}
int main()
{
	int i, len1, len2;
	while (gets(in))
	{
		if (in[0] == '0' && in[1] == '\0')
		{
			break;
		}
		for (i = 0; in[i]; i++)
		{
			if (in[i] == '0')
			{
				break;
			}
		}
		if (in[i] == '0')
		{
			printf("NOT ACCEPTABLE\n");
			continue;
		}
		if (rec(0) < 0)
		{
			printf("NOT ACCEPTABLE\n");
			continue;
		}
		else
		{
			printf("%s\n", out);
		}
	}
	return 0;
}
