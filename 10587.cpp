#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

const int N = 20000;

class Tree
{
public:
	int lx, rx;
	Tree *l, *r;
	int node;
	Tree(){};
	Tree(int tlx, int trx) : lx(tlx), rx(trx), l(NULL), r(NULL){};

	void find()
	{
		cout << lx << " " << rx << " " << node << endl;
		if (lx == rx)
		{
			return;
		}
		l->find();
		r->find();
	}

	int insert(int ltar, int rtar, int n, bool &flag)
	{
		int mid = lx + (rx - lx) / 2;
		int ret = 0;

		if (node != -1)
		{
			return 1;
		}
		if (l != NULL && ltar <= mid)
		{
			ret += l->insert(ltar, min(rtar, mid), n, flag);
		}
		if (r != NULL && mid + 1 <= rtar)
		{
			ret += r->insert(max(ltar, mid + 1), rtar, n, flag);
		}

		if (ret == 2)
		{
			if (!(l->node == n && r->node == n))
			{
				node = (1 << 21);
				return 1;
			}
		}

		if (lx == rx)
		{
			if (node == -1)
			{
				node = n;
				flag = true;
				return 1;
			}
			else
			{
				return 0;
			}
		}

		if (ltar <= lx && rx <= rtar)
		{
			if (node == -1)
			{
				node = n;
				flag = true;
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return 0;
	}

	void construct(int ltar, int rtar)
	{
		node = -1;
		lx = ltar;
		rx = rtar;
		if (ltar == rtar)
		{
			return;
		}
		int mid = ltar + ((rtar - ltar)) / 2;
		l = new Tree(ltar, mid);
		r = new Tree(mid + 1, rtar);
		l->construct(ltar, mid);
		r->construct(mid + 1, rtar);
	}

	void destroy()
	{
		if (l != NULL)
		{
			l->destroy();
		}
		if (r != NULL)
		{
			r->destroy();
		}
		free(r);
		free(l);
		r = l = NULL;
	}
};

int main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int n;
		cin >> n;
		map<int, int> M;
		vector<pair<int, int>> in;
		vector<int> check;
		rep(i, n)
		{
			pair<int, int> tmp;
			cin >> tmp.first >> tmp.second;
			in.push_back(tmp);
			check.push_back(tmp.first);
			check.push_back(tmp.second);
		}
		sort(ALL(check));
		check.erase(unique(ALL(check)), check.end());
		rep(i, check.size()) M[check[i]] = i;
		rep(i, n)
		{
			in[i].first = M[in[i].first];
			in[i].second = M[in[i].second];
		}
		reverse(ALL(in));
		Tree root;
		root.construct(0, M.size() - 1);
		int ans = 0;
		rep(i, in.size())
		{
			bool flag = false;
			root.insert(in[i].first, in[i].second, i, flag);
			if (flag)
			{
				ans++;
			}
		}
		cout << ans << endl;
		root.destroy();
	}
	return 0;
}
