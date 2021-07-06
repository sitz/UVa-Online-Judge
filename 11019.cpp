#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 1000;
const int M = 100;
char m[N][N + 20];
char in[M][M + 20];
char *ptr[N];
int atm[N][N + 20];

struct PMA
{
	PMA *next[30];//next[0] is for fail, 0x100 = 256
	int id;
	vector<int> ac;
	PMA()
	{
		fill(next, next + 30, (PMA *)0);
		id = -1;
	}
};

PMA *buildPMA(char *p[M], int size, int *acdata)
{
	PMA *root = new PMA;
	int cnt = 0;
	rep(i, size)
	{
		PMA *t = root;
		for (int j = 0; p[i][j] != '\0'; j++)
		{
			char c = p[i][j] - 'a' + 1;
			if (t->next[c] == NULL)
			{
				t->next[c] = new PMA;
			}
			t = t->next[c];
		}
		if (t->id == -1)
		{
			t->id = cnt++;
		}
		acdata[i] = t->id;
		t->ac.push_back(t->id);
	}
	queue<PMA *> Q;
	REP(i, 1, 30)
	{
		char c = i;
		if (root->next[c])
		{
			root->next[c]->next[0] = root;
			Q.push(root->next[c]);
		}
		else
		{
			root->next[c] = root;
		}
	}
	while (!Q.empty())
	{
		PMA *t = Q.front();
		Q.pop();
		for (int c = 'a' - 'a' + 1; c <= 'z' - 'a' + 1; c++)
		{
			if (t->next[c])
			{
				Q.push(t->next[c]);
				PMA *r = t->next[0];
				while (!r->next[c])
				{
					r = r->next[0];
				}
				t->next[c]->next[0] = r->next[c];
				copy(r->next[c]->ac.begin(), r->next[c]->ac.end(),
						 back_inserter(t->next[c]->ac));
			}
		}
	}
	return root;
}

void match(PMA *r, char *tar, int *res)
{
	for (int i = 0; tar[i] != '\0'; i++)
	{
		char c = tar[i] - 'a' + 1;
		while (!r->next[c])
		{
			r = r->next[0];
		}
		r = r->next[c];
		rep(j, r->ac.size())
		{
			//res[r->ac[j]]++;
			res[i] = r->id;//ac[j];
		}
	}
}

int kmp(int p1, int *text, int p2, int *word)
{
	static int table[N];
	int i = 2, j = 0;//i:searching word j:backtracking point
	table[0] = -1;	 //
	table[1] = 0;		 //
	while (i <= p2)	//make table
	{
		if (word[i - 1] == word[j])
		{
			table[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
		{
			j = table[j];
		}
		else
		{
			table[i] = 0;
			i++;
		}
	}
	//the main part of KMP algorithm
	int pos;	//
	int m = 0;//
	int cnt = 0;
	i = 0;//
	while (m + i < p1)
	{
		if (word[i] == text[m + i])
		{
			i++;
			if (i == p2)
			{
				//return m;
				cnt++;
				m = m + i - table[i];
				if (i > 0)
				{
					i = table[i];
				}
			}
		}
		else
		{
			m = m + i - table[i];
			if (i > 0)
			{
				i = table[i];
			}
		}
	}
	return cnt;
}

int baker_bird(int r, int c, int p)
{
	int ret = 0;
	static int ac[M + 10], tres[N + 10];
	rep(i, p) ptr[i] = in[i];
	PMA *root = buildPMA(ptr, p, ac);
	rep(i, r)
	{
		rep(j, c) tres[j] = -1;
		match(root, m[i], tres);
		rep(j, c) atm[i][j] = tres[j];
	}
	rep(j, c)
	{
		rep(i, r) tres[i] = atm[i][j];
		ret += kmp(r, tres, p, ac);
	}
	return ret;
}

main()
{
	int te;
	scanf("%d", &te);
	while (te--)
	{
		int r, c, pr, pc;
		scanf("%d%d", &r, &c);
		rep(i, r)
		{
			scanf("%s", m[i]);
		}
		scanf("%d%d", &pr, &pc);
		rep(i, pr)
		{
			scanf("%s", in[i]);
		}
		cout << baker_bird(r, c, pr) << endl;
	}
	return 0;
}
