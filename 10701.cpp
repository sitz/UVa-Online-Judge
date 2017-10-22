#include <bits/stdc++.h>

using namespace std;

/*
536
Tree Recovery
*/
#define MAXN 60
char in[MAXN], pre[MAXN], F[MAXN];
int indin[MAXN], indpre[MAXN];
int lenin, lenpre;
struct ss
{
	int left, right;
} node[MAXN];
void Ini()
{
	int i, k;
	for (i = 0; i < MAXN; i++)
	{
		node[i].left = node[i].right = -1;
		F[i] = 0;
	}
	lenin = strlen(in);
	lenpre = strlen(pre);
	for (i = 0; i < lenin; i++)
	{
		k = in[i] - 'A';
		indin[k] = i;
	}
	for (i = 0; i < lenpre; i++)
	{
		k = pre[i] - 'A';
		indpre[k] = i;
	}
}
int FindLeft(int ind)
{
	int i, j, k, min = 100;
	for (i = ind - 1; i >= 0; i--)
	{
		k = in[i] - 'A';
		if (F[k])
		{
			break;
		}
		if (indpre[k] < min)
		{
			min = indpre[k];
			j = in[i];
		}
	}
	if (min < 100)
	{
		return j - 'A';
	}
	return -1;
}
int FindRight(int ind)
{
	int i, j, k, min = 100;
	for (i = ind + 1; i < lenin; i++)
	{
		k = in[i] - 'A';
		if (F[k])
		{
			break;
		}
		if (indpre[k] < min)
		{
			min = indpre[k];
			j = in[i];
		}
	}
	if (min < 100)
	{
		return j - 'A';
	}
	return -1;
}
void Construct(int n)
{
	int k;
	F[n] = 1;
	k = FindLeft(indin[n]);
	if (k >= 0)
	{
		F[k] = 1;
		node[n].left = k;
		Construct(k);
	}
	k = FindRight(indin[n]);
	if (k >= 0)
	{
		F[k] = 1;
		node[n].right = k;
		Construct(k);
	}
}
void Print(int n)
{
	if (n < 0)
	{
		return;
	}
	Print(node[n].left);
	Print(node[n].right);
	printf("%c", n + 'A');
}
int main()
{
	int kase, node;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d%s%s", &node, pre, in);
		Ini();
		Construct(pre[0] - 'A');
		Print(pre[0] - 'A');
		printf("\n");
	}
	return 0;
}
