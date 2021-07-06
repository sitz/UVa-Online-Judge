#include <bits/stdc++.h>

using namespace std;

#define BUF_LEN 40

void split_input(char *buf, char *a, char *b, char *c);
int is_correct(char *a, char *b, char *c);
int cal_value(char *a);
int map_(char c);
int cal_char_num(char *a, char *b, char *c);
void dfs(int cur, char *str);

static int dep, vis[10];
char combuf[BUF_LEN], temp[10], abuf[BUF_LEN], bbuf[BUF_LEN], cbuf[BUF_LEN];
int combuflen, lena, lenb, lenc, solnum;

int main()
{
	char buf[BUF_LEN];
	setvbuf(stdout, NULL, _IONBF, 0);
	while (fgets(buf, BUF_LEN, stdin) && buf[0] != '#')
	{
		split_input(buf, abuf, bbuf, cbuf);
		if (is_correct(abuf, bbuf, cbuf))
		{
			printf("Correct ");
		}
		else
		{
			printf("Incorrect ");
		}
		dep = cal_char_num(abuf, bbuf, cbuf);
		lena = strlen(abuf);
		lenb = strlen(bbuf);
		lenc = strlen(cbuf);
		combuflen = lena + lenb + lenc;
		memset(vis, 0, sizeof(vis));
		solnum = 0;
		strcpy(combuf, abuf);
		strcat(combuf, bbuf);
		strcat(combuf, cbuf);
		dfs(0, combuf);
		if (solnum == 0)
		{
			printf("impossible\n");
		}
		else if (solnum == 1)
		{
			printf("valid\n");
		}
		else
		{
			printf("ambiguous\n");
		}
	}
	return 0;
}

void split_input(char *buf, char *a, char *b, char *c)
{
	int aflag, bflag, cflag;
	int alen, blen, clen;
	int len;
	int i;
	len = strlen(buf);
	aflag = 1, bflag = 0, cflag = 0;
	alen = blen = clen = 0;
	for (i = 0; i < len; i++)
	{
		if (isalpha(buf[i]))
		{
			if (aflag)
			{
				a[alen++] = buf[i];
			}
			else if (bflag)
			{
				b[blen++] = buf[i];
			}
			else if (cflag)
			{
				c[clen++] = buf[i];
			}
		}
		else if (buf[i] == '+')
		{
			a[alen] = '\0';
			aflag = 0;
			bflag = 1;
			cflag = 0;
		}
		else if (buf[i] == '=')
		{
			b[blen] = '\0';
			aflag = 0;
			bflag = 0;
			cflag = 1;
		}
	}
	c[clen] = '\0';
}

int is_correct(char *a, char *b, char *c)
{
	int v1, v2, v3;
	v1 = cal_value(a);
	v2 = cal_value(b);
	v3 = cal_value(c);
	return v1 + v2 == v3;
}

int cal_value(char *a)
{
	int len, i;
	int value;
	int v1, v2;
	len = strlen(a);
	value = 0;
	for (i = 0; i < len - 1; i++)
	{
		v1 = map_(a[i]);
		v2 = map_(a[i + 1]);
		if (v1 < v2)
		{
			value -= v1;
		}
		else
		{
			value += v1;
		}
	}
	value += map_(a[len - 1]);
	return value;
}

int map_(char c)
{
	int value;
	switch (c)
	{
	case 'I':
		value = 1;
		break;
	case 'V':
		value = 5;
		break;
	case 'X':
		value = 10;
		break;
	case 'L':
		value = 50;
		break;
	case 'C':
		value = 100;
		break;
	case 'D':
		value = 500;
		break;
	case 'M':
		value = 1000;
		break;
	}
	return value;
}

int cal_char_num(char *a, char *b, char *c)
{
	int alen, blen, clen;
	int len = 0;
	int i, j;
	char ch;
	alen = strlen(a);
	for (i = 0; i < alen; i++)
	{
		ch = a[i];
		for (j = 0; j < len; j++)
		{
			if (temp[j] == ch)
			{
				break;
			}
		}
		if (j == len)
		{
			temp[len++] = ch;
		}
	}
	blen = strlen(b);
	for (i = 0; i < blen; i++)
	{
		ch = b[i];
		for (j = 0; j < len; j++)
		{
			if (ch == temp[j])
			{
				break;
			}
		}
		if (j == len)
		{
			temp[len++] = ch;
		}
	}
	clen = strlen(c);
	for (i = 0; i < clen; i++)
	{
		ch = c[i];
		for (j = 0; j < len; j++)
		{
			if (ch == temp[j])
			{
				break;
			}
		}
		if (j == len)
		{
			temp[len++] = ch;
		}
	}
	temp[len] = '\0';
	return len;
}

void dfs(int cur, char *str)
{
	int i, j;
	int a, b, c;
	char tempa[BUF_LEN], tempb[BUF_LEN], tempc[BUF_LEN], s[BUF_LEN];
	if (cur >= dep)
	{
		memcpy(tempa, str, lena);
		memcpy(tempb, str + lena, lenb);
		memcpy(tempc, str + lena + lenb, lenc);
		tempa[lena] = '\0';
		tempb[lenb] = '\0';
		tempc[lenc] = '\0';
		sscanf(tempa, "%d", &a);
		sscanf(tempb, "%d", &b);
		sscanf(tempc, "%d", &c);
		if (a + b == c)
		{
			solnum++;
		}
		return;
	}
	for (i = 0; i < 10; i++)
	{
		if (!vis[i])
		{
			strcpy(s, str);
			for (j = 0; j < combuflen; j++)
			{
				if (s[j] == temp[cur])
				{
					s[j] = i + '0';
				}
			}
			if ((lena > 1 && s[0] == '0') || (lenb > 1 && s[lena] == '0') || (lenc > 1 && s[lena + lenb] == '0'))
			{
				continue;
			}
			vis[i] = 1;
			dfs(cur + 1, s);
			vis[i] = 0;
		}
	}
}
