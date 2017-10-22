#include <bits/stdc++.h>

using namespace std;

bitset<1010> pres[1010];
bitset<1010> use[1010];
bitset<1010> bef[1010];
bitset<1010> aft[1010];
set<int> preds[1010];
char buf[100000];
bitset<1010> seen;
vector<int> po;
int endofedge[1010];
int N, M, I;
void printset(char *msg, bitset<1010> s)
{
	bool first = true;
	printf(msg);
	for (int i = 0; i < I; i++)
	{
		if (s.test(i))
		{
			if (!first)
			{
				printf(" ");
			}
			printf("%d", i);
			first = false;
		}
	}
	puts("");
}
bitset<1010> readset()
{
	bitset<1010> ret = bitset<1010>();
	gets(buf);
	char *tok = strtok(buf, " ");
	while (tok)
	{
		int i;
		if (1 == sscanf(tok, "%d", &i))
		{
			ret.set(i);
		}
		tok = strtok(0, " ");
	}
	return ret;
}
void dfs(int i)
{
	if (seen[i])
	{
		return;
	}
	seen.set(i);
	for (set<int>::iterator it = preds[i].begin(); it != preds[i].end(); it++)
	{
		dfs(*it);
	}
	po.push_back(i);
}
int main()
{
	int NN;
	gets(buf);
	sscanf(buf, "%d ", &NN);
	while (NN--)
	{
		gets(buf);
		sscanf(buf, "%d %d %d ", &N, &M, &I);
		for (int i = 0; i < N; i++)
		{
			use[i] = readset();
			pres[i] = ~readset();
			bef[i] = bitset<1010>();
			aft[i] = bitset<1010>();
			preds[i] = set<int>();
		}
		for (int i = 0; i < M; i++)
		{
			int x, y;
			scanf("%d %d ", &x, &y);
			preds[y].insert(x);
			endofedge[i] = y;
		}
		seen = bitset<1010>();
		po = vector<int>();
		for (int i = 0; i < N; i++)
		{
			dfs(i);
		}
		bool change = true;
		while (change)
		{
			change = false;
			for (vector<int>::reverse_iterator it = po.rbegin(); it != po.rend(); it++)
			{
				bitset<1010> old = bef[*it];
				bef[*it] = (aft[*it] & pres[*it]) | use[*it];
				if (bef[*it] != old)
				{
					change = true;
				}
				for (set<int>::iterator it2 = preds[*it].begin(); it2 != preds[*it].end(); it2++)
				{
					old = aft[*it2];
					aft[*it2] |= bef[*it];
					if (aft[*it2] != old)
					{
						change = true;
					}
				}
			}
		}
		for (int i = 0; i < M; i++)
		{
			printset("", bef[endofedge[i]]);
		}
		/*
		for(int i = 0; i < N; i++) {
		  printf("%d:\n", i);
		  printset("use " , use[i]);
		  printset("pres ", pres[i]);
		  printset("bef ", bef[i]);
		  printset("aft ", aft[i]);
		}
		*/
	}
	return 0;
}
