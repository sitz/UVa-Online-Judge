#include <bits/stdc++.h>

using namespace std;

int n, ptt;
char buf[1000005], str[1000005];

typedef struct data
{
	char s[105];
	struct data *left, *right, *parent, *pres;
} data;

data pool[2005];

data *build(data *parent, data *pres)
{
	int i;
	data *ptr;
	if (n == 0)
	{
		return NULL;
	}
	gets(str);
	n--;
	if (str[1] == '/')
	{
		return NULL;
	}
	ptr = pool + ptt++;
	ptr->parent = parent;
	ptr->pres = pres;
	ptr->left = ptr->right = NULL;
	for (i = 10; str[i] && str[i] != '\''; i++)
	{
		ptr->s[i - 10] = str[i];
	}
	ptr->s[i - 10] = 0;
	ptr->left = build(ptr, NULL);
	ptr->right = build(parent, ptr);
	return ptr;
}

int main()
{
	int cas, i;
	data *ptr;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		gets(buf);
		ptt = 0;
		ptr = build(NULL, NULL);
		printf("Case %d:\n", ++cas);
		scanf("%d", &n);
		gets(buf);
		for (i = 0; i < n; i++)
		{
			gets(buf);
			if (buf[1] == 'i')
			{
				if (ptr->left)
				{
					ptr = ptr->left;
				}
			}
			else if (buf[1] == 'e')
			{
				if (ptr->right)
				{
					ptr = ptr->right;
				}
			}
			else if (buf[1] == 'r')
			{
				if (ptr->pres)
				{
					ptr = ptr->pres;
				}
			}
			else if (buf[1] == 'a')
			{
				if (ptr->parent)
				{
					ptr = ptr->parent;
				}
			}
			printf("%s\n", ptr->s);
		}
	}
	return 0;
}
