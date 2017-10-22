#include <bits/stdc++.h>

using namespace std;

int a[1024][1024], mlen, ind;
char s[1024 * 1024];

void init()
{
	for (int i = 0; i < mlen; ++i)
		for (int j = 0; j < mlen; ++j)
			a[i][j] = 0;
}

void mark(int x, int y, int xx, int yy)
{
	for (int j = y - 1; j < yy; ++j)
		for (int i = x - 1; i < xx; ++i)
			a[j][i] = 1;
}

int block(int len, int x, int y)
{
	int flag = a[x][y];
	if (len == 1)
		return flag;
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if (flag != a[x + i][y + j])
				return -1;
	return flag;
}

void div(int len, int x, int y)
{
	int t;
	t = block(len / 2, x, y);
	if (t == -1)
	{
		s[ind++] = '*';
		div(len / 2, x, y);
	}
	else
		s[ind++] = '0' + t;
	t = block(len / 2, x, y + len / 2);
	if (t == -1)
	{
		s[ind++] = '*';
		div(len / 2, x, y + len / 2);
	}
	else
		s[ind++] = '0' + t;
	t = block(len / 2, x + len / 2, y);
	if (t == -1)
	{
		s[ind++] = '*';
		div(len / 2, x + len / 2, y);
	}
	else
		s[ind++] = '0' + t;
	t = block(len / 2, x + len / 2, y + len / 2);
	if (t == -1)
	{
		s[ind++] = '*';
		div(len / 2, x + len / 2, y + len / 2);
	}
	else
		s[ind++] = '0' + t;
}

int main()
{
	int n, x1, y1, x2, y2, t, ok;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &mlen);
		t = mlen;
		ok = true;
		while (t != 1)
		{
			if (t & 1 && t != 1)
			{
				ok = false;
				break;
			}
			t = t >> 1;
		}
		if (ok)
		{
			init();
			while (scanf(" (%d,%d)", &x1, &y1) == 2)
				if (scanf(" (%d,%d)", &x2, &y2) == 2)
					mark(x1, y1, x2, y2);
			ind = 0;
			t = block(mlen, 0, 0);
			memset(s, 0, sizeof(s));
			if (t == -1)
			{
				div(mlen, 0, 0);
				for (int i = 0; i < ind; ++i)
					printf("%c", s[i]);
			}
			printf("\n");
		}
		else
		{
			while (scanf(" (%d,%d)", &x1, &y1) == 2)
				;
			printf("Size is invalid\n");
		}
	}
	return 0;
}
