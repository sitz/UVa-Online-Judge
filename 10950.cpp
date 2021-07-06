#include <bits/stdc++.h>

using namespace std;

char En[202];
int N, ts, len;

struct ss
{
	char ch[10];
	char val[5];
	int len;
};
ss Link[30];

int Com(const void *a, const void *b)
{
	ss *x;
	ss *y;
	x = (ss *)a;
	y = (ss *)b;
	return strcmp(x->ch, y->ch);
}

int Match(int len, char pat[], int ind)
{
	int i, j, f = 1, p;
	for (i = ind; En[i]; i++)
	{
		if (f == 0 && En[i - 1] != '0')
			return -1;
		f = 1;
		p = i;
		for (j = 0; pat[j] && En[p]; j++)
			if (En[p++] != pat[j])
			{
				f = 0;
				break;
			}
		if (f && j == len)
			return i + len;
	}
	return -1;
}

int Recur(string en, int ind)
{
	int i, d, k, j, f, c;
	string t;
	if (ind == len)
	{
		ts++;
		cout << en.c_str() << endl;
		if (ts == 100)
			return 1;
		return 0;
	}
	for (j = 0; j < N; j++)
	{
		d = Match(Link[j].len, Link[j].val, ind);
		if (d >= 0)
		{
			c = Recur(en + Link[j].ch, d);
			if (c)
				return 1;
		}
	}
	return 0;
}

void Cal()
{
	ts = 0;
	qsort(Link, N, sizeof(ss), Com);
	len = strlen(En);
	Recur("", 0);
}

int main()
{
	int d = 1, k;
	while (cin >> N && N)
	{
		if (!N)
			break;
		k = 0;
		while (k < N)
		{
			cin >> Link[k].ch >> Link[k].val;
			Link[k].len = strlen(Link[k].val);
			k++;
		}
		cin >> En;
		cout << "Case #" << d++ << "\n";
		Cal();
		cout << endl;
	}
	return 0;
}
