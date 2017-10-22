#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int to, next;
};

bool hasres;
Edge edge[210000];
int head[41000], L;
int n, lc[21000], rc[21000];
char s[41000];
int l;

void addedge(int u, int v)
{
	if (u > l || v == -1)
	{
		return;
	}
	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

int main()
{
	int totcas;
	scanf("%d", &totcas);
	for (int cas = 1; cas <= totcas; cas++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &lc[i], &rc[i]);
		}
		scanf("%s", s);
		l = strlen(s);
		memset(head, -1, sizeof(head));
		L = 0;
		addedge(0, 1);
		hasres = false;
		for (int i = 0; i < l; i++)
		{
			if (head[i] == -1)
			{
				continue;
			}
			int nxt = i;
			while (nxt < l && s[nxt] == s[i])
			{
				nxt++;
			}
			int len = (nxt - i);
			int halflen = (len + 1) / 2;
			if (len == 1)//XXXRL or XXXLR
			{
				for (int j = head[i]; j != -1; j = edge[j].next)
				{
					if (s[i] == 'R')//XXXRL
					{
						addedge(i + 1, rc[edge[j].to]);
						addedge(i + 2, lc[edge[j].to]);
					}
					else//XXXLR
					{
						addedge(i + 1, lc[edge[j].to]);
						addedge(i + 2, rc[edge[j].to]);
					}
				}
			}
			else//XXXLLLLLLLLLLLR or XXXRRRRRRRRRRRRL
			{
				//to i-2 : len/2     .. len-1
				//to i-1 : (len+1)/2 .. len
				for (int j = head[i]; j != -1; j = edge[j].next)
				{
					int now = edge[j].to;
					int odd = -1;
					for (int k = 1; k <= len; k++)
					{
						if (s[i] == 'L')
						{
							now = lc[now];
						}
						else
						{
							now = rc[now];
						}
						if (now == -1)
						{
							break;
						}
						if (k == halflen - 1)
						{
							odd = now;
						}
						if (nxt == l && len % 2 == 1 && k >= halflen - 1)
						{
							hasres = true;
						}
						if (k >= halflen)//can go to nxt-1
						{
							addedge(nxt, now);
						}
					}
					if (nxt < l && odd != -1 && len % 2 == 1)
					{
						if (s[nxt] == 'L')//XXXRRRRRL
						{
							addedge(nxt + 1, lc[odd]);
						}
						else//XXXLLLLLR
						{
							addedge(nxt + 1, rc[odd]);
						}
					}
				}
			}
		}
		printf("Case %d: ", cas);
		if (hasres || head[l - 1] != -1 || head[l] != -1)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
