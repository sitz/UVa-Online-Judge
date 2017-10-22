#include <bits/stdc++.h>

using namespace std;

char str[1005], *p;
struct Word
{
	char str[1005];
	Word *next;
} * h[1005];
int l[1005];
void add(char *ss, int len)
{
	for (Word *s = h[len]; s; s = s->next)
		if (strcmp(s->str, ss) == 0)
		{
			return;
		}
	Word *x = new Word;
	strcpy(x->str, ss);
	x->next = h[len];
	h[len] = x;
	l[len]++;
}
void freemem(Word *&p)
{
	if (p)
	{
		freemem(p->next);
		delete p;
	}
	p = NULL;
}
int main()
{
	bool flag;
	while (gets(str) != NULL)
	{
		if (strcmp(str, "") == 0)
		{
			break;
		}
		for (int i = 0; i < 1005; i++)
		{
			h[i] = NULL, l[i] = 0;
		}
		int len = strlen(str), s;
		flag = true;
		for (int i = 1; i <= len; i++)
		{
			char c = str[i];
			str[i] = '\0';
			for (p = str, s = 0; s < i; p++, s++)
			{
				add(p, i - s);
				if (l[i - s] > i - s + 1)
				{
					flag = false;
				}
			}
			str[i] = c;
			if (!flag)
			{
				printf("NO:%d\n", i);
				break;
			}
		}
		if (flag)
		{
			puts("YES");
		}
		for (int i = 0; i < 1005; i++)
		{
			freemem(h[i]);
		}
	}
}
