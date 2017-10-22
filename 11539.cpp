#include <bits/stdc++.h>

using namespace std;

typedef struct a
{
	bool terminal;
	int value;
	char c;
	struct a *child[26];
} node;
char s[150];
char word[11000];
int len, value, best[10001];
node *trie, *temp;
int trieIdx;

void insert(node *trieId, int idx)
{
	if (trieId->child[s[idx] - 'a'] == 0)
	{
		temp = new node();
		memset(temp->child, 0, sizeof(temp->child));
		temp->c = s[idx];
		trieId->child[s[idx] - 'a'] = temp;
	}
	if (idx == len - 1)
	{
		trieId->child[s[idx] - 'a']->terminal = 1;
		trieId->child[s[idx] - 'a']->value = value;
	}
	else
	{
		insert(trieId->child[s[idx] - 'a'], idx + 1);
	}
}

int search(int L, int R, node *idx)
{
	if (L > R)
	{
		return idx->terminal ? idx->value : -1;
	}
	if (idx->child[word[L] - 'a'] != NULL)
	{
		return search(L + 1, R, idx->child[word[L] - 'a']);
	}
	return -1;
}

void destroy(node *t)
{
	for (int i = 0; i < 26; i++)
		if (t->child[i] != NULL)
		{
			destroy(t->child[i]);
		}
	delete (t);
}

int main()
{
	int t, n, p, xx = 0, len2, k, limit;
	scanf("%d", &t);
	while (t--)
	{
		trie = new node();
		trie->c = trie->terminal = trie->value = 0;
		memset(trie->child, 0, sizeof(trie->child));
		scanf("%d %d", &n, &p);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s %d", s, &value);
			len = strlen(s);
			insert(trie, 0);
		}
		scanf("%s", word);
		best[0] = 0;
		len2 = strlen(word);
		for (int i = 1; i <= len2; i++)
		{
			best[i] = best[i - 1] - p;
			limit = min(i, 100);
			for (int j = 0; j <= limit; j++)
			{
				k = search(i - j, i - 1, trie);
				if (k >= 0)
				{
					best[i] = max(best[i], best[i - j] + k);
				}
			}
		}
		destroy(trie);
		printf("Case %d: %d\n", ++xx, best[len2]);
	}
	return 0;
}
