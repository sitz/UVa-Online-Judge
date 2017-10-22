#include <bits/stdc++.h>

using namespace std;

char s[1010];

struct TStrList
{
	int len;
	char *s;
};

int exist(char *s, struct TStrList *list, int n)
{
	int i;
	for (i = 0; i < n; i++)
		if (!strcmp(s, list->s + i * 11))
		{
			return 1;
		}
	return 0;
}

int main()
{
	int i, j, k, N;
	struct TStrList *cur, *prev;
	char *p;
	scanf("%d\n", &N);
	while (N-- > 0)
	{
		gets(s);
		prev = new TStrList;
		prev->len = 1;
		prev->s = new char[11];
		prev->s[0] = 0;
		p = s;
		while (*p)
		{
			cur = new TStrList;
			cur->s = (char *)malloc(11 * prev->len * 2);
			j = 0;
			for (i = 0; i < prev->len; i++)
			{
				if (prev->s[i * 11] == *p)
				{
					strcpy(cur->s + 11 * j, prev->s + 11 * i + 1);
					if (!exist(cur->s + j * 11, cur, j))
					{
						j++;
					}
				}
				k = strlen(prev->s + i * 11);
				if (k < 10)
				{
					strcpy(cur->s + j * 11, prev->s + i * 11);
					cur->s[j * 11 + k++] = *p;
					cur->s[j * 11 + k++] = 0;
					if (!exist(cur->s + j * 11, cur, j))
					{
						j++;
					}
				}
			}
			cur->len = j;
			/*
			            printf("->");
			            for(i=0;i<cur->len;i++)
			                printf("\"%s\" ",cur->s+i*11);
			            printf("\n");
			*/
			// printf("%d\n",cur->len);
			prev = cur;
			p++;
		}
		if (prev->len == 0)
		{
			printf("Not consistent with the theory\n");
		}
		else
		{
			for (i = j = 0; (i < prev->len) && !j; i++)
			{
				if (cur->s[i * 11] == 0)
				{
					j = 1;
				}
			}
			if (j)
			{
				printf("An echo string with buffer size ten\n");
			}
			else
			{
				printf("Not an echo string, but still consistent with the theory\n");
			}
		}
	}
	return 0;
}
