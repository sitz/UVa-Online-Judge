#include <bits/stdc++.h>

using namespace std;

/*
10602
Editor Nottabad
*/
#define MIN(a, b) (a > b ? b : a)
struct ss
{
	char str[102];
	int len;
	int pre;
} ww[102];
int N, req;
char Fix[102];
int com(const void *a, const void *b)
{
	ss *x = (ss *)a;
	ss *y = (ss *)b;
	if (y->pre != x->pre)
	{
		return y->pre - x->pre;
	}
	return strcmp(x->str, y->str);
}
void Count_prefix()
{
	int i, j, c, len, fl;
	fl = strlen(Fix);
	for (i = 0; i < N - 1; i++)
	{
		c = 0;
		len = MIN(fl, ww[i].len);
		for (j = 0; j < len; j++)
		{
			if (Fix[j] == ww[i].str[j])
			{
				c++;
			}
			else
			{
				break;
			}
		}
		ww[i].pre = c;
	}
}
void Count_req()
{
	int i, j, st, lim, c = 0;
	req = ww[0].len - ww[0].pre;
	for (i = 1; i + 1 < N; i++)
	{
		lim = MIN(ww[i].len, ww[i - 1].len);
		st = MIN(ww[i].pre, ww[i - 1].pre);
		c = 0;
		for (j = st; j < lim && (ww[i].str[j] == ww[i - 1].str[j]); j++)
		{
			c++;
		}
		req += ww[i].len - c - st;
	}
}
void Cal()
{
	Count_prefix();
	qsort(ww, N - 1, sizeof(ww[0]), com);
	Count_req();
	printf("%d\n", req + strlen(Fix));
	printf("%s\n", Fix);
	for (int i = 0; i + 1 < N; i++)
	{
		puts(ww[i].str);
	}
}
int main()
{
	int kases, i;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d", &N);
		scanf("%s", Fix);
		for (i = 1; i < N; i++)
		{
			scanf("%s", ww[i - 1].str);
			ww[i - 1].len = strlen(ww[i - 1].str);
		}
		Cal();
	}
	return 0;
}
