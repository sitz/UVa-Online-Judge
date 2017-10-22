#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)

const int MAXLEN = 256;
struct PMA
{
	PMA *next[MAXLEN];
	VI matched;

	PMA()
	{
		FOR(i, 0, MAXLEN)
		next[i] = 0;
	}

	~PMA()
	{
		FOR(i, 0, MAXLEN)
		if (next[i])
			delete next[i];
	}
};

inline PMA *PMA_build(char *pattern[], int cnt)
{
	PMA *root = new PMA, *now;
	root->next[0] = root;
	FOR(i, 0, cnt)
	{
		now = root;
		for (int j = 0; pattern[i][j] != '\0'; j++)
		{
			if (now->next[(int)pattern[i][j]] == 0)
				now->next[(int)pattern[i][j]] = new PMA;
			now = now->next[(int)pattern[i][j]];
		}
		now->matched.push_back(i);
	}

	queue<PMA *> que;
	FOR(i, 1, MAXLEN)
	{
		if (!root->next[i])
			root->next[i] = root;
		else
		{
			root->next[i]->next[0] = root;
			que.push(root->next[i]);
		}
	}

	while (!que.empty())
	{
		now = que.front();
		que.pop();
		FOR(i, 1, MAXLEN)
		{
			if (now->next[i])
			{
				PMA *next = now->next[0];
				while (!next->next[i])
					next = next->next[0];
				now->next[i]->next[0] = next->next[i];
				que.push(now->next[i]);
			}
		}
	}
	return root;
}

inline void PMA_match(PMA *pma, const char *s, VI &res)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		int c = s[i];
		while (!pma->next[c])
			pma = pma->next[0];
		pma = pma->next[c];
		FOR(j, 0, pma->matched.size())
		res[pma->matched[j]] = true;
	}
}

static int TCASE;
static char S[100005], *T[1005];

int main()
{
	FOR(i, 0, 1000)
	T[i] = new char[1005];

	scanf("%d", &TCASE);
	FOR(i, 0, TCASE)
	{
		scanf("%s", S);
		int q;
		scanf("%d", &q);
		FOR(i, 0, q)
		scanf("%s", T[i]);

		PMA *root = PMA_build(T, q);
		VI res(q);
		PMA_match(root, S, res);
		FOR(i, 0, q)
		puts(res[i] ? "y" : "n");
	}
	return 0;
}
