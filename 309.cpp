#include <bits/stdc++.h>

using namespace std;

/*
    Problem:    FORCAL
    Author:     Jan Kotas, Michal Koucky
    Algorithm:  simple parser
    Complexity: linear
*/

char m[256];
char tk[64];

int main()
{
	int i, c, te, tl, tt, nt, pt;
	memset(m, 0, sizeof(m));
	for (i = '0'; i <= '9'; i++)
	{
		m[i] = 1;
	}
	for (i = 'A'; i <= 'Z'; i++)
	{
		m[i] = 2;
	}
	for (i = 'a'; i <= 'z'; i++)
	{
		m[i] = 2;
	}
	m['_'] = 2;
	m['+'] = m[';'] = m[','] = m['('] = m[')'] = 3;
	m['-'] = 4;
	m[':'] = 5;
	m['='] = 6;
	m[' '] = m['\t'] = 7;
	/* 8 - new line */
	/* 9 - comment */
	te = 0;
	tl = 0;
	tt = 8;
	for (;;)
	{
		if ((c = getchar()) == EOF)
		{
			break;
		}
		nt = 0;
		if (c == '\n')
		{
			if (tt == 8)
			{
				if (te)
				{
					puts("TOKEN ERROR");
				}
				puts("");
				te = 0;
			}
			nt = 8;
		}
		else if (te || tt == 9)
		{
			continue;
		}
		else
			switch (m[c])
			{
			case 1: /* 0..9 */
				if (tt != 1 && tt != 2)
				{
					nt = 1;
				}
				break;
			case 2: /* a..z, A..Z */
				if (tt == 1)
				{
					tt = 2;
				}
				else if (tt != 2)
				{
					nt = 2;
				}
				break;
			case 3: /* +();, */
				nt = 3;
				break;
			case 4: /* - */
				if (tt == 4)
				{
					tt = 9;
				}
				else
				{
					nt = 4;
				}
				break;
			case 5: /* : */
				nt = 5;
				break;
			case 6: /* = */
				if (tt == 5)
				{
					tt = 6;
				}
				else
				{
					nt = -1;
					te = 1;
				}
				break;
			case 7: /* space, tab */
				nt = 7;
				break;
			default:
				nt = -1;
				te = 1;
			}
		if (nt)
		{
			pt = 0;
			switch (tt)
			{
			case 1:
				if (tl <= 8)
				{
					pt = 1;
				}
				else
				{
					te = 1;
				}
				break;
			case 2:
				if (tl <= 32)
				{
					pt = 1;
				}
				else
				{
					te = 1;
				}
				break;
			case 3:
			case 4:
				pt = 1;
				break;
			case 5:
				te = 1;
				break;
			case 6:
				pt = 1;
				break;
			}
			if (pt)
			{
				tk[tl] = 0;
				puts(tk);
			}
			tt = nt;
			tl = 0;
		}
		if (tl < 64)
		{
			tk[tl++] = c;
		}
	}
}
