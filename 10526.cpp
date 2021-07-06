#include <bits/stdc++.h>

using namespace std;

struct Seg
{
	char *start;
	int len;
} seg[50000];
char str[50000], *s[50000], TDP[50000], JCN[50000];
int k, lenTDP, lenJCN, ptr, prev_, flag;

int cmp(const void *a, const void *b)
{
	char *c = *(char **)a, *d = *(char **)b;
	return strcmp(c, d);
}

int cmps(const void *a, const void *b)
{
	Seg *c = (Seg *)a, *d = (Seg *)b;
	if (c->len != d->len)
	{
		return d->len - c->len;
	}
	return c->start - d->start;
}

int comp(const char *s, const char *d, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (s[i] < d[i])
		{
			return -1;
		}
		if (s[i] > d[i])
		{
			return 1;
		}
	}
	return 0;
}

bool BinarySearch(char *str, int len)
{
	int left = 0, right = lenTDP - 1, mid = (left + right) / 2, other;
	while (left <= right)
	{
		int c = comp(s[mid], str, len);
		if (c == 0)
		{
			return true;
		}
		else if (c < 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return false;
}

void add(char *start, int l, int last)
{
	seg[ptr].start = start;
	seg[ptr++].len = l;
	prev_ = last;
	flag = 1;
}

int main()
{
	int caseno = 0;
	while (gets(str), sscanf(str, "%d", &k), k)
	{
		if (caseno++)
		{
			puts("");
		}
		ptr = lenTDP = lenJCN = 0, prev_ = -1;
		strcpy(TDP, "");
		strcpy(JCN, "");
		gets(str);
		while (gets(str), strcmp(str, "END TDP CODEBASE"))
		{
			strcat(TDP, str), strcat(TDP, "\n");
		}
		gets(str);
		while (gets(str), strcmp(str, "END JCN CODEBASE"))
		{
			strcat(JCN, str), strcat(JCN, "\n");
		}
		lenTDP = strlen(TDP), lenJCN = strlen(JCN);
		for (int i = 0; i < lenTDP; i++)
		{
			s[i] = TDP + i;
		}
		qsort(s, lenTDP, sizeof(char *), cmp);
		for (int i = 0; i < lenJCN; i++)
		{
			if (BinarySearch(JCN + i, lenJCN - i))
			{
				add(JCN + i, lenJCN - i, lenJCN - 1);
				break;
			}
			if (!BinarySearch(JCN + i, 1))
			{
				continue;
			}
			for (int j = i + 1; j < lenJCN; j++)
			{
				if (j < prev_ + 1)
				{
					continue;
				}
				if (!BinarySearch(JCN + i, j - i + 1))
				{
					if (j > prev_ + 1)
					{
						add(JCN + i, j - i, j - 1);
					}
					break;
				}
			}
		}
		qsort(seg, ptr, sizeof(Seg), cmps);
		printf("CASE %d\n", caseno);
		for (int i = 0; i < k && i < ptr; i++)
		{
			printf("INFRINGING SEGMENT %d LENGTH %d POSITION %d\n",
						 i + 1, seg[i].len, seg[i].start - JCN);
			for (int j = 0; j < seg[i].len; j++)
			{
				printf("%c", *(seg[i].start + j));
			}
			printf("\n");
		}
	}
	return 0;
}
