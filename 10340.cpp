#include <bits/stdc++.h>

using namespace std;

int main()
{
	char a[100000], s[100000];
	int i, j, k, ck;
	while (scanf("%s %s", a, s) != EOF)
	{
		k = 0;
		for (i = 0; a[i]; i++)
		{
			ck = 0;
			for (j = k; s[j]; j++)
			{
				if (a[i] == s[j])
				{
					k = j + 1;
					ck = 1;
					break;
				}
			}
			if (!ck)
			{
				break;
			}
		}
		printf(ck ? "Yes\n" : "No\n");
	}
	return 0;
}
