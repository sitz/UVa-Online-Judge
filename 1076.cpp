#include <bits/stdc++.h>

using namespace std;

template <class T>
bool checkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <class T>
bool checkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;
const int KIND = 26, MAXN = 110;
#define code(ch) ((ch) - 'a')
struct ACNode
{
	ACNode *next[KIND], *fail;
	int mask;
} pool[MAXN], *pp, *root, *q[MAXN];
ACNode *NewNode()
{
	pp->fail = NULL;
	pp->mask = 0;
	memset(pp->next, 0, sizeof(pp->next));
	return pp++;
}
void Initial()
{
	pp = pool;
	root = NewNode();
}

void Insert(const char *str, int id)
{
	ACNode *now = root;
	while (*str)
	{
		int i = code(*str);
		now->next[i] = now->next[i] == 0 ? NewNode() : now->next[i];
		now = now->next[i];
		str++;
	}
	now->mask |= 1 << id;
}

void BuildFail(ACNode *&now, int ith)
{
	if (now == root)
		now->next[ith]->fail = root;
	ACNode *tmp = now->fail;
	while (tmp)
	{
		if (tmp->next[ith])
		{
			now->next[ith]->fail = tmp->next[ith];
			return;
		}
		tmp = tmp->fail;
	}
	if (tmp == NULL)
		now->next[ith]->fail = root;
}

void Build()
{
	int head = 0, tail = 0;
	q[tail++] = root;
	while (head != tail)
	{
		ACNode *beg = q[head++];
		for (int i = 0; i < KIND; i++)
		{
			if (beg->next[i] == NULL)
				continue;
			BuildFail(beg, i);
			beg->next[i]->mask |= beg->next[i]->fail->mask;
			q[tail++] = beg->next[i];
		}
	}
}

ACNode *GoStatus(ACNode *now, int ith)
{
	while (now->next[ith] == NULL && now != root)
	{
		now = now->fail;
	}
	now = now->next[ith];
	return now == NULL ? root : now;
}
const int LEN = 30;
const int MASK = 1 << 10;
LL dp[LEN][MAXN][MASK];
vector<string> pwd;
char buffer[LEN];
int s, tot;
void DFS(int len, int status, int MASK)
{
	if (dp[len][status][MASK] == 0)
		return;
	if (len == 0)
	{
		pwd.push_back(buffer);
		return;
	}
	for (int j = 0; j < s; j++)
	{
		for (int mask = 0; mask < tot; mask++)
		{
			for (char c = 0; c < KIND; c++)
			{
				buffer[len - 1] = c + 'a';
				int k = GoStatus(pool + j, c) - pool, mask_ = pool[k].mask;
				if (dp[len - 1][j][mask] != 0 && ((mask | mask_) == MASK) && k == status)
				{
					DFS(len - 1, j, mask);
				}
			}
		}
	}
}
int main()
{
	int n, m, cas = 1;
	while (cin >> n >> m && (n + m))
	{
		vector<string> dict(m);
		for (int i = 0; i < m; i++)
			cin >> dict[i];
		sort(dict.begin(), dict.end());
		dict.erase(unique(dict.begin(), dict.end()), dict.end());
		m = int(dict.size());

		Initial();
		for (int i = 0; i < m; i++)
			Insert(dict[i].c_str(), i);
		Build();
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		s = pp - pool, tot = (1 << m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < s; j++)
			{
				for (int mask = 0; mask < tot; mask++)
				{
					if (dp[i][j][mask] == 0)
						continue;
					for (int c = 0; c < KIND; c++)
					{
						int k = GoStatus(pool + j, c) - pool, mask_ = pool[k].mask;
						dp[i + 1][k][mask | mask_] += dp[i][j][mask];
					}
				}
			}
		}
		LL res = 0;
		for (int i = 0; i < s; i++)
		{
			res += dp[n][i][tot - 1];
		}
		printf("Case %d: %lld suspects\n", cas++, res);
		memset(buffer, 0, sizeof(buffer));
		pwd.clear();
		if (res <= 42)
		{
			for (int i = 0; i < s; i++)
			{
				DFS(n, i, tot - 1);
			}
			sort(pwd.begin(), pwd.end());
			for (vector<string>::iterator i = pwd.begin(); i != pwd.end(); ++i)
			{
				cout << *i << endl;
			}
		}
	}

	return 0;
}
