#include <bits/stdc++.h>

using namespace std;

int mul[3][3] = {1, 1, 0,
								 2, 1, 0,
								 0, 2, 2};

char str[150], output[150][150], comp, ans;

struct Edge
{
	char s[150];
	int len;
	Edge *next;
} *g[1001];

int hash_(char *s)
{
	int sum = 0;
	for (int i = 0; s[i]; i++)
	{
		sum = (sum * 3 + s[i] - 'a') % 1001;
	}
	return sum;
}
bool find(char *s, int key)
{
	int l = strlen(s);
	for (Edge *p = g[key]; p; p = p->next)
	{
		if (p->len != l)
		{
			continue;
		}
		if (strcmp(p->s, s) == 0)
		{
			return true;
		}
	}
	return false;
}
void add(char *s, int key)
{
	int l = strlen(s);
	Edge *p = new Edge;
	strcpy(p->s, s);
	p->len = l;
	p->next = g[key];
	g[key] = p;
}
void free(Edge *&p)
{
	if (p)
	{
		free(p->next);
		delete p;
	}
}
bool run(char *s, int len)
{
	if (len == 1)
	{
		if (*s == ans)
		{
			strcpy(output[len], s);
		}
		return *s == ans;
	}
	char temp[150];
	int lenp;
	for (int i = 0; i < len - 1; i++)
	{
		for (lenp = 0; lenp < i; lenp++)
		{
			temp[lenp] = s[lenp];
		}
		int a = s[i] - 'a', b = s[i + 1] - 'a';
		temp[lenp++] = mul[a][b] + 'a';
		for (; lenp < len - 1; lenp++)
		{
			temp[lenp] = s[lenp + 1];
		}
		temp[lenp] = '\0';
		int key = hash_(temp);
		if (find(temp, key))
		{
			continue;
		}
		add(temp, key);
		if (run(temp, len - 1))
		{
			strcpy(output[len], s);
			return true;
		}
	}
	return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s %c", str, &ans);
		for (int i = 0; i < 1001; i++)
		{
			g[i] = NULL;
		}
		int len = strlen(str);
		if (!run(str, len))
		{
			printf("None exist!\n");
		}
		else
		{
			for (int i = len; i >= 1; i--)
			{
				printf("%s\n", output[i]);
			}
		}
		for (int i = 0; i < 1001; i++)
		{
			free(g[i]);
		}
		if (t)
		{
			printf("\n");
		}
	}
	return 0;
}
