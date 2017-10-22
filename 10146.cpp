#include <bits/stdc++.h>

using namespace std;

#define MAX 10

void ToRun(void)
{
	char tmp[MAX + 1], in[MAX + 1];
	int space, i, min;
	gets(tmp);
	puts(tmp);
	for (space = 0; gets(in);)
	{
		if (!strlen(in))
		{
			break;
		}
		min = strlen(tmp);
		min = min < strlen(in) ? min : strlen(in);
		for (i = 0; i < min; ++i)
			if (tmp[i] != in[i])
			{
				break;
			}
		if (i > space)
		{
			++space;
		}
		else
		{
			space = i;
		}
		for (i = 0; i < space; ++i)
		{
			putchar(' ');
		}
		puts(in);
		strcpy(tmp, in);
	}
}

int main()
{
	int N_case;
	scanf("%d\n\n", &N_case);
	for (; N_case; --N_case)
	{
		ToRun();
		if (N_case - 1)
		{
			putchar('\n');
		}
	}
	return 0;
}
