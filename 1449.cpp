#include <bits/stdc++.h>

using namespace std;

struct node
{
	int count, id;
	struct node *next[26];
	struct node *fail;
	void init()
	{
		int i;
		for (i = 0; i < 26; i++)
		{
			next[i] = NULL;
		}
		count = 0;
		fail = NULL;
		id = -1;
	}
} * root;
void insert(char *str, int id)
{
	int len, k;
	node *p = root;
	len = strlen(str);
	for (k = 0; k < len; k++)
	{
		int pos = str[k] - 'a';
		if (p->next[pos] == NULL)
		{
			p->next[pos] = new node;
			p->next[pos]->init();
			p = p->next[pos];
		}
		else
		{
			p = p->next[pos];
		}
	}
	p->count++;
	p->id = id;
}
void getfail()
{
	int i;
	node *p = root, *son, *temp;
	queue<struct node *> que;
	que.push(p);
	while (!que.empty())
	{
		temp = que.front();
		que.pop();
		for (i = 0; i < 26; i++)
		{
			son = temp->next[i];
			if (son != NULL)
			{
				if (temp == root)
				{
					son->fail = root;
				}
				else
				{
					p = temp->fail;
					while (p)
					{
						if (p->next[i])
						{
							son->fail = p->next[i];
							break;
						}
						p = p->fail;
					}
					if (!p)
					{
						son->fail = root;
					}
				}
				que.push(son);
			}
		}
	}
}
int num[200];
char str[1000000 + 100];
void query()
{
	int len, i, cnt = 0;
	len = strlen(str);
	node *p, *temp;
	p = root;
	for (i = 0; i < len; i++)
	{
		int pos = str[i] - 'a';
		while (!p->next[pos] && p != root)
		{
			p = p->fail;
		}
		p = p->next[pos];//
		if (!p)
		{
			p = root;//
		}
		temp = p;
		/*不要用*temp=*p  因为*p表示一个node，而*temp也表示一个node 但是由于*temp没有分配空间 所以是不能进行赋值的 但是可以用temp指针去指向p*/
		while (temp != root)
		{
			if (temp->count >= 1)
			{
				if (temp->id != -1)
				{
					num[temp->id]++;
				}
				// temp->count=-1;
			}
			temp = temp->fail;
		}
	}
	//printf("%d\n",cnt);
}
char rem[160][100];
int main()
{
	int cas, n;
	while (scanf("%d", &n) != EOF)
	{
		if (!n)
		{
			break;
		}
		root = new node;
		root->init();
		root->fail = NULL;
		int i;
		getchar();
		for (i = 0; i < n; i++)
		{
			gets(rem[i]);
			// gets(str);
			insert(rem[i], i);
		}
		getfail();
		memset(num, 0, sizeof(num));
		gets(str);
		query();
		int maxnum = -1;
		for (i = 0; i < n; i++)
		{
			// printf("num[%d]=%d\n",i,num[i]);
			if (num[i] > maxnum)
			{
				maxnum = num[i];
			}
		}
		printf("%d\n", maxnum);
		for (i = 0; i < n; i++)
			if (maxnum == num[i])
			{
				printf("%s\n", rem[i]);
			}
	}
	return 0;
}
