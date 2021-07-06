#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(), a.end()
#define I1(n) scanf("%d", &n)
#define I2(n1, n2) scanf("%d%d", &n1, &n2)
#define I3(n1, n2, n3) scanf("%d%d%d", &n1, &n2, &n3)
#define F(i, a, b) for (i = (a); i <= (b); i++)
#define FR(i, a, b) for (i = (a); i <= (b); i++)
#define Fs(i, sz) for (size_t i = 0; i < sz.size(); i++)
#define Fe(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define Pr(x)                                                 \
	for (typeof(x.begin()) it = x.begin(); it != x.end(); it++) \
		cout << *it << " ";                                       \
	cout << endl;
#define pb push_back
#define pi acos(-1.0)
#define MEM(a, val) memset(a, val, sizeof(a))
#define eps 1e-9
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
#define sz(a) ((int)(a).size())

#define lim 50007

struct node
{
	int st, ed, cnt, start, en;
	node *l, *r;
	node(int _, int __)
	{
		st = _;
		ed = __;
		cnt = 0;
		l = r = NULL;
	}
};

void Insert(node *ob, int idx, int s, int e)
{
	if (ob->st == ob->ed)
	{
		ob->cnt = e - s + 1;
		ob->start = s;
		ob->en = e;
		return;
	}
	int mid = (ob->st + ob->ed) >> 1;
	if (ob->l == NULL)
		ob->l = new node(ob->st, mid);
	if (ob->r == NULL)
		ob->r = new node(mid + 1, ob->ed);
	if (idx <= mid)
		Insert(ob->l, idx, s, e);
	else
		Insert(ob->r, idx, s, e);
	ob->cnt = ob->l->cnt + ob->r->cnt;
	return;
}

int ans;

void query(node *ob, int tg)
{
	if (ob->st == ob->ed)
	{
		ans = ob->start + tg - 1;
		return;
	}
	int mid = (ob->st + ob->ed) >> 1;
	if (ob->l->cnt >= tg)
		query(ob->l, tg);
	else
		query(ob->r, tg - ob->l->cnt);
}

int main()
{
	int tc, cas = 1, n, m, i, j, k, a, b, q, cnt;
	int call[lim], arr[lim];
	scanf("%d", &tc);
	while (tc--)
	{
		printf("Case %d:\n", cas++);
		scanf("%d%d%d", &n, &k, &q);
		arr[0] = 0;
		arr[k + 1] = n + 1;
		for (i = 1; i <= k; i++)
		{
			scanf("%d", &arr[i]);
			call[i] = arr[i];
		}
		sort(arr, arr + k + 2);
		cnt = 0;
		node *root = new node(0, k + 2);
		for (i = 1; i <= k + 1; i++)
			if (arr[i] > arr[i - 1] + 1)
				Insert(root, cnt++, arr[i - 1] + 1, arr[i] - 1);
		for (i = 0; i < q; i++)
		{
			scanf("%d", &a);
			if (a <= k)
				ans = call[a];
			else
				query(root, a - k);
			printf("%d\n", ans);
		}
	}
	return 0;
}
