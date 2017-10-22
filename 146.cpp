#include <bits/stdc++.h>

using namespace std;

int main()
{
	char p[60];
	while (scanf("%s", p) == 1)
	{
		if (strcmp(p, "#") == 0)
		{
			break;
		}
		int n;
		n = (int)strlen(p);
		if (next_permutation(p, p + n))
		{
			printf("%s\n", p);
		}
		else
		{
			printf("No Successor\n");
		}
	}
	return 0;
}
