#include <bits/stdc++.h>

using namespace std;

char in[10000];
int main()
{
	int t, len;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", in);
		if (strcmp(in, "1") == 0 || strcmp(in, "4") == 0 || strcmp(in, "78") == 0)
		{
			printf("+\n");
			continue;
		}
		if ((len = strlen(in)) < 2)
		{
			continue;
		}
		if (in[len - 2] == '3' && in[len - 1] == '5')
		{
			printf("-\n");
			continue;
		}
		if (in[0] == '9' && in[len - 1] == '4')
		{
			printf("*\n");
			continue;
		}
		if (strncmp(in, "190", 3) == 0)
		{
			printf("?\n");
		}
	}
	return 0;
}
