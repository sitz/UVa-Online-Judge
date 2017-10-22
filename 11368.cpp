#include <bits/stdc++.h>

using namespace std;

#define MAXM (20001)

struct dim
{
	int w, h;
};

struct dim dims[MAXM];
int size[MAXM + 1];
int anti_chain_size;

int cmp(const void *a, const void *b)
{
	struct dim *ta = ((struct dim *)a);
	struct dim *tb = ((struct dim *)b);
	if (ta->w != tb->w)
	{
		return ta->w - tb->w;
	}
	return tb->h - ta->h;
}

int main()
{
	int n, m, i, j;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d %d", &dims[i].w, &dims[i].h);
		}
		qsort(dims, m, sizeof(struct dim), cmp);
		anti_chain_size = 0;
		for (i = 0; i < m; i++)
		{
			int lo = 0, hi = anti_chain_size;
			while (lo < hi)
			{
				int mid = (hi + lo) / 2;
				if (size[mid] >= dims[i].h)
				{
					lo = mid + 1;
				}
				else
				{
					hi = mid;
				}
			}
			size[lo] = dims[i].h;
			anti_chain_size += (lo == anti_chain_size);
		}
		printf("%d\n", anti_chain_size);
	}
	return 0;
}
