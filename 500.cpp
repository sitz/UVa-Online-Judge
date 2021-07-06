#include <bits/stdc++.h>

using namespace std;

/*   @JUDGE_ID:   2905EH   500   C++  "New Judgement..."  */
// 00/04/16 =>A_Q500.c <ACCEPTED>
//          New judgement => multiple input..

typedef struct
{
	int num;
	char **cell;
} LINE;

void Line(int *len, int max, char l, char m, char r)
{
	int i = 0, j;
	printf("%c", l);//UP LINE
	while (1)
	{
		for (j = 0; j < len[i] + 2; j++)
		{
			printf("%c", (char)196);//'?
		}
		if (++i != max)
		{
			printf("%c", m);
		}
		else
		{
			break;
		}
	}
	printf("%c\n", r);
}

int main()
{
	char buff[256], *Null_Str = "";
	int c = 0;
	gets(buff);
	int n_case = atoi(buff);
	gets(buff);//blank..
	while (1)
	{
		int i, k, n_data = 0, max = 0, *len;
		LINE data[100];
		while (gets(buff) && *buff != 0)
		{
			int n;
			char *l, *r;
			if (c++ && n_data == 0)
			{
				printf("\n");
			}
			n = data[n_data].num = 0;
			data[n_data].cell = 0;
			if ((l = strchr(buff, 179)) == 0)
			{
				n_data++;//'? // --+--
				continue;
			}
			for (r = strchr(l + 1, 179); r != 0; n++, l = r, r = strchr(l + 1, 179))
			{
				char *ll = l, *rr = r;
				while (*(++ll) == ' ')
					;
				while (*(--rr) == ' ')
					;
				data[n_data].cell = (char **)realloc(data[n_data].cell, (n + 1) * sizeof(char *));
				if (ll <= rr)//found
				{
					//       *(rr+1)=0;
					data[n_data].cell[n] =
							(char *)malloc((rr - ll + 2) * sizeof(char));
					//       strcpy(data[n_data].cell[n],ll);
					memcpy(data[n_data].cell[n], ll, rr - ll + 1);
					data[n_data].cell[n][rr - ll + 1] = 0;
				}
				else
				{
					data[n_data].cell[n] = Null_Str;
				}
			}
			data[n_data].num = n;
			if (n > max)
			{
				max = n;
			}
			n_data++;
		}
		if (n_data == 0 || max == 0)
		{
			return 0;
		}
		len = (int *)calloc(max, sizeof(int));
		for (i = 0; i < n_data; i++)
			for (k = 0; k < data[i].num; k++)
				if (strlen(data[i].cell[k]) > len[k])
				{
					len[k] = strlen(data[i].cell[k]);
				}
		Line(len, max, 218, 194, 191);//"?,"?,"?
		k = 0;
		if (data[0].num == 0)
		{
			k++;
		}
		for (; k < n_data; k++)
		{
			if (data[k].num == 0)
			{
				if (k == n_data - 1)
				{
					break;
				}
				Line(len, max, 195, 197, 180);//"?,"?,"?
				continue;
			}
			for (i = 0; i < max; i++)
				if (i < data[k].num)
				{
					printf("%c %-*s ", (char)179, len[i], data[k].cell[i]);//"?
				}
				else
				{
					printf("%c %-*s ", (char)179, len[i], Null_Str);//"?
				}
			printf("%c\n", (char)179);//"?
		}
		Line(len, max, 192, 193, 217);//"?,"?,"?
		for (k = 0; k < n_data; k++)
		{
			for (i = 0; i < data[k].num; i++)
				if (data[k].cell[i] != Null_Str)
				{
					free(data[k].cell[i]);
				}
			free(data[k].cell);
		}
	}
}
/*@END_OF_SOURCE_CODE*/
