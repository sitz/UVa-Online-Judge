#include <bits/stdc++.h>

using namespace std;

#define MAXN 670000

int left_[MAXN], right_[MAXN], parent[MAXN], key[MAXN], cnt[MAXN], N, root;
char lucky[2010000];

// idx of k-th smallest elem
int find(int k)
{
	for (int x = root;;)
	{
		if (k < cnt[left_[x]])
		{
			x = left_[x];
		}
		else if (k == cnt[left_[x]])
		{
			return x;
		}
		else
		{
			k -= cnt[left_[x]] + 1, x = right_[x];
		}
	}
	return -1;
}

// rm elem(idx=x)
void rm(int x)
{
	int y;
	if (left_[x] != 0 && right_[x] != 0)
	{
		if (cnt[right_[x]] >= cnt[left_[x]])
		{
			for (y = right_[x]; left_[y] != 0; y = left_[y])
				;
		}
		else
		{
			for (y = left_[x]; right_[y] != 0; y = right_[y])
				;
		}
		key[x] = key[y];
		x = y;
	}
	if (left_[x] == 0 && right_[x] == 0)
	{
		if (left_[parent[x]] == x)
		{
			left_[parent[x]] = 0;
		}
		else
		{
			right_[parent[x]] = 0;
		}
	}
	else
	{
		y = (left_[x] == 0) ? right_[x] : left_[x];
		if (parent[x] == 0)
		{
			parent[root = y] = 0;
			return;
		}
		if (left_[parent[x]] == x)
		{
			left_[parent[x]] = y;
		}
		else
		{
			right_[parent[x]] = y;
		}
		parent[y] = parent[x];
	}

	for (x = parent[x]; x != 0; x = parent[x])
	{
		cnt[x]--;
	}
}

// construct balanced tree with b-a+1 elements; returns idx@root
// tree's nodes will get consecutive idxs in tree order
int build(int a, int b)
{
	if (a > b)
	{
		return 0;
	}
	if (a == b)
	{
		N++;
		left_[N] = right_[N] = 0;
		cnt[N] = 1;
		return N;
	}
	int c = (a + b) / 2, t = build(a, c - 1);
	left_[++N] = t;
	t = N;
	right_[t] = build(c + 1, b);
	cnt[t] = cnt[left_[t]] + cnt[right_[t]] + 1;
	parent[left_[t]] = parent[right_[t]] = t;
	return t;
}

void mark(int x)
{
	for (; x; x = right_[x])
	{
		lucky[key[x]] = 1, mark(left_[x]);
	}
}

// construct lst of lucky #
void make()
{
	int i, j, k;
	// init
	N = cnt[0] = 0;
	parent[root = build(0, 666667)] = 0;

	// start with tree, containing all #
	// of form 6k+1 and 6k+3, in range of interest
	// these are remaining # after 1st 2 elimination rds
	for (i = 1, j = 1; i <= 666700; j += 6)
	{
		key[i++] = j, key[i++] = j + 2;
	}

	// simulate
	for (k = 2; k < cnt[root]; k++)
	{
		j = key[find(k)] - 1;
		if (j >= cnt[root])
		{
			break;
		}
		for (i = j; i < cnt[root]; i += j)
		{
			rm(find(i));
		}
	}
	// mark remaining # in lucky[]
	memset(lucky, 0, sizeof(lucky));
	mark(root);
}

int main()
{
	int a, n;
	for (make(); scanf("%d", &n) == 1;)
	{
		a = 0;
		if (n >= 1 && (n & 1) == 0)
		{
			for (a = n / 2; a > 0 && !lucky[a]; a--)
				;
			for (; a > 0; a -= 2)
			{
				if (lucky[a] && lucky[n - a])
				{
					break;
				}
			}
		}
		if (a <= 0)
		{
			printf("%d is not the sum of two luckies!\n", n);
		}
		else
		{
			printf("%d is the sum of %d and %d.\n", n, a, n - a);
		}
	}
	return 0;
}
