#include <bits/stdc++.h>

using namespace std;

typedef struct MAP
{
	int to, v, flag;
	MAP *next;
} MAP;
MAP node[1010], *alp[26];
int n, cou, ind[26], outd[26];
int beg;
int vis[26][26];
int pre[26], used[26];
char words[1010][25];
void init()
{
	cou = 0;
	memset(alp, '\0', sizeof(alp));
	memset(node, '\0', sizeof(node));
	for (int i = 0; i < 26; i++)
	{
		pre[i] = i;
	}
	memset(vis, 0, sizeof(vis));
	memset(used, 0, sizeof(used));
	memset(ind, 0, sizeof(ind));
	memset(outd, 0, sizeof(outd));
}
int isoula()
{
	int i;
	int sum = 0, out[26];
	for (i = 0; i < 26; i++)
		if (ind[i] != outd[i])
		{
			out[sum] = i;
			sum++;
		}
	if (sum == 0)
	{
		i = 0;
		while (!used[i])
		{
			i++;
		}
		beg = i;
		return 1;
	}
	if (sum == 2)
	{
		int x = out[0], y = out[1];
		if (ind[x] - outd[x] == 1 && outd[y] - ind[y] == 1)
		{
			beg = y;
			return 1;
		}
		if (ind[y] - outd[y] == 1 && outd[x] - ind[x] == 1)
		{
			beg = x;
			return 1;
		}
	}
	return 0;
}
int find(int x)
{
	while (x != pre[x])
	{
		x = pre[x];
	}
	return x;
}
int isconnect()
{
	int tmp, i = 0, k;
	while (!used[i])
	{
		i++;
	}
	tmp = i;
	for (k = i + 1; k < 26; k++)
		if (find(k) != tmp && used[k])
		{
			return 0;
		}
	return 1;
}
void Union(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a < b)
	{
		pre[b] = pre[x] = pre[y] = a;
	}
	if (b < a)
	{
		pre[a] = pre[x] = pre[y] = b;
	}
}
stack<int> s;
void output(int u)
{
	MAP *head = alp[u];
	while (head != NULL)
	{
		if (head->flag == 0)
		{
			head->flag = 1;
			output(head->v);
			s.push(head->to);
		}
		head = head->next;
	}
}
int cmp(const void *a, const void *b)
{
	char *x = (char *)a;
	char *y = (char *)b;
	return -strcmp(x, y);
}
int main()
{
	int ncases, i, len;
	scanf("%d", &ncases);
	while (ncases--)
	{
		init();
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%s", words[i]);
		}
		qsort(words, n, sizeof(words[0]), cmp);
		for (i = 0; i < n; i++)
		{
			len = strlen(words[i]);
			int x = words[i][0] - 'a';
			int y = words[i][len - 1] - 'a';
			outd[x]++;
			ind[y]++;
			used[x] = used[y] = 1;
			Union(x, y);
			node[cou].to = i;
			node[cou].v = y;
			node[cou].next = alp[x];
			alp[x] = &node[cou++];
		}
		if (!isconnect() || !isoula())
		{
			printf("***\n");
			continue;
		}
		output(beg);
		int k = s.top();
		s.pop();
		printf("%s", words[k]);
		while (!s.empty())
		{
			k = s.top();
			s.pop();
			printf(".%s", words[k]);
		}
		printf("\n");
	}
	return 0;
}
