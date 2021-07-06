#include <bits/stdc++.h>

using namespace std;

/*
   ACM North Central Region, 1993-94
   Problem E, The Finite State Text-Processing Machine

   Ed Karrels, April 1996
*/

typedef struct
{
	char *in_set, *out_str;
	char st_nm[9];
} Trans;

typedef struct
{
	char name[9];
	int n_tr;
	Trans *tr;
} State;

char *CvtStr(char *str)
{
	char *outs, *r, *w;
	outs = (char *)malloc(strlen(str) + 1);
	r = str;
	w = outs;
	while (*r)
	{
		if (*r == '\\')
		{
			r++;
			switch (*r)
			{
			case 'b':
				*w++ = ' ';
				break;
			case 'n':
				*w++ = '\n';
				break;
			case '\\':
				*w++ = '\\';
				break;
			case '0':
				*w++ = 0;
				break;
			case 'c':
				*w++ = -1;
			}
			r++;
		}
		else
		{
			*w++ = *r++;
		}
	}
	*w = 0;
	return outs;
}

int FindSt(State *st, int n_st, const char *st_nm)
{
	int i;
	for (i = 0; i < n_st; i++)
		if (!strcmp(st_nm, st[i].name))
		{
			return i;
		}
	fprintf(stderr, "no state %s\n", st_nm);
	return 0;
}

int main()
{
	int n_st, i, j;
	State *st;
	char buf[1000], c, *w;
	int cur_st, catch_all, tr_no, mch_no = 1;
	scanf("%d", &n_st);
	while (n_st)
	{
		printf("Finite State Machine %d:\n", mch_no++);
		n_st++;
		st = (State *)malloc(sizeof(State) * n_st);
		strcpy(st[0].name, "END");
		for (i = 1; i < n_st; i++)
		{
			scanf("%s %d", st[i].name, &st[i].n_tr);
			st[i].tr = (Trans *)malloc(sizeof(Trans) * st[i].n_tr);
			for (j = 0; j < st[i].n_tr; j++)
			{
				scanf("%s", buf);
				st[i].tr[j].in_set = CvtStr(buf);
				scanf("%s", st[i].tr[j].st_nm);
				scanf("%s", buf);
				st[i].tr[j].out_str = CvtStr(buf);
			}
		}
		scanf("%*[^\n]");
		getchar();
		cur_st = FindSt(st, n_st, "START");
		while (cur_st != 0)
		{
			c = getchar();
			catch_all = tr_no = -1;
			for (i = 0; i < st[cur_st].n_tr; i++)
			{
				if (strchr(st[cur_st].tr[i].in_set, c))
				{
					tr_no = i;
					break;
				}
				else if (strchr(st[cur_st].tr[i].in_set, -1))
				{
					catch_all = i;
				}
			}
			if (tr_no == -1)
			{
				tr_no = catch_all;
			}
			if (tr_no != -1)
			{
				for (w = st[cur_st].tr[tr_no].out_str; *w; w++)
				{
					if (*w == -1)
					{
						putchar(c);
					}
					else
					{
						putchar(*w);
					}
				}
				cur_st = FindSt(st, n_st, st[cur_st].tr[tr_no].st_nm);
			}
		}
		for (i = 1; i < n_st; i++)
		{
			for (j = 0; j < st[i].n_tr; j++)
			{
				free(st[i].tr[j].in_set);
				free(st[i].tr[j].out_str);
			}
			free(st[i].tr);
		}
		scanf("%d", &n_st);
	}
	return 0;
}
