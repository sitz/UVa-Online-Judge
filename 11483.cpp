#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t = 0;
	char str[1002];
	while (scanf("%d", &n) == 1 && n)
	{
		getchar();
		printf("Case %d:\n", ++t);
		printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
		while (n--)
		{
			gets(str);
			printf("printf(\"");
			for (int i = 0; str[i]; i++)
			{
				if (str[i] == '\\' || str[i] == '\"')
				{
					printf("\\");
				}
				printf("%c", str[i]);
			}
			printf("\\n\");\n");
		}
		printf("printf(\"\\n\");\nreturn 0;\n}\n");
	}
	return 0;
}
