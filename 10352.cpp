#include <bits/stdc++.h>

using namespace std;

struct Word
{
	char word[6];
	int times;
	Word *left, *right;
	Word(char *s)
	{
		strcpy(word, s);
		times = 1;
		left = right = NULL;
	}
} * root;

char temp[20], str[25];

int cmpstr(char *s, char *d)
{
	int i;
	for (i = 0; s[i] && d[i]; i++)
	{
		if (i == 2)
		{
			continue;
		}
		if (s[i] < d[i])
		{
			return -1;
		}
		if (s[i] > d[i])
		{
			return 1;
		}
	}
	if (d[i])
	{
		return -1;
	}
	if (s[i])
	{
		return 1;
	}
	return 0;
}
Word *find(char *s, Word *p)
{
	if (p == NULL)
	{
		return NULL;
	}
	else if (cmpstr(s, p->word) == 0)
	{
		return p;
	}
	else if (cmpstr(s, p->word) < 0)
	{
		return find(s, p->left);
	}
	else
	{
		return find(s, p->right);
	}
}
void insert(char *s, Word *&p)
{
	if (p == NULL)
	{
		p = new Word(s);
	}
	else if (cmpstr(s, p->word) < 0)
	{
		return insert(s, p->left);
	}
	else
	{
		insert(s, p->right);
	}
}
void inorder(Word *p)
{
	if (p)
	{
		inorder(p->left);
		printf("%s %d\n", p->word, p->times);
		inorder(p->right);
	}
}
void del(Word *&p)
{
	if (p)
	{
		del(p->left);
		del(p->right);
		delete p;
	}
}

int main()
{
	int caseno = 1;
	while (scanf("%s", str) == 1)
	{
		root = NULL;
		while (true)
		{
			if (strcmp(str, "#") == 0)
			{
				break;
			}
			if (strlen(str) > 4)
			{
				strncpy(temp, str, 5);
			}
			else
			{
				strcpy(temp, str);
			}
			Word *s = find(temp, root);
			if (s)
			{
				strcpy(s->word, temp);
				s->times++;
			}
			else
			{
				insert(temp, root);
			}
			scanf("%s", str);
		}
		printf("Set #%d:\n", caseno++);
		inorder(root);
		printf("\n");
		del(root);
	}
	return 0;
}
