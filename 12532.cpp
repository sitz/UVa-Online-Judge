#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;

class SegmentTree
{
public:
	VI A, tree;
	SegmentTree(VI &_A) : A(_A)
	{
		int N = A.size();
		tree = VI(4 * N, 1);
		build(1, 0, N - 1);
	}

	void build(int node, int lo, int hi)
	{
		if (lo == hi)
		{
			tree[node] = A[lo];
			return;
		}
		int mid = (lo + hi) / 2;
		// compute the values in the left and right subtrees
		build(2 * node, lo, mid);
		build(2 * node + 1, mid + 1, hi);
		// each parent node is equal to the product of his childs
		tree[node] = tree[2 * node] * tree[2 * node + 1];
	}

	int query(int i, int j)
	{
		return _query(1, 0, A.size() - 1, i, j);
	}

	int _query(int node, int lo, int hi, int i, int j)
	{
		// if the current interval doesn't intersect the query
		// interval return 1, this value is not going to affect
		// the sign of the final product
		if (hi < i || lo > j)
		{
			return 1;
		}
		// if the current interval is included in the query
		// interval return tree[node]
		if (lo >= i && hi <= j)
		{
			return tree[node];
		}
		int mid = (lo + hi) / 2;
		// product of the intervals included in the query
		return _query(2 * node, lo, mid, i, j) * _query(2 * node + 1, mid + 1, hi, i, j);
	}

	void update(int ind, int val)
	{
		_update(1, ind, val, 0, A.size() - 1);
	}

	void _update(int node, int ind, int val, int lo, int hi)
	{
		// if the current index is not contained in the interval,
		// skip this interval
		if (ind < lo || ind > hi)
		{
			return;
		}
		if (lo == hi)
		{
			tree[node] = val;
			return;
		}
		int mid = (lo + hi) / 2;
		// update the values in the left and right subtrees
		_update(2 * node, ind, val, lo, mid);
		_update(2 * node + 1, ind, val, mid + 1, hi);
		tree[node] = tree[2 * node] * tree[2 * node + 1];
	}
};

vector<int> X;

int main()
{
	char cmd;
	int n, q, x, ind, val, lo, hi, s;
	while (cin >> n >> q)
	{
		X.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			// replace the positive values with 1's
			// and the negative with -1's
			if (x > 0)
			{
				x = 1;
			}
			if (x < 0)
			{
				x = -1;
			}
			X.push_back(x);
		}
		SegmentTree st(X);
		while (q-- > 0)
		{
			cin >> cmd;
			if (cmd == 'C')
			{
				cin >> ind >> val;
				--ind;
				// replace the positive values with 1's
				// and the negative with -1's
				if (val > 0)
				{
					val = 1;
				}
				if (val < 0)
				{
					val = -1;
				}
				st.update(ind, val);
				X[ind] = val;
			}
			else
			{
				cin >> lo >> hi;
				--lo, --hi;
				s = st.query(lo, hi);
				if (s > 0)
				{
					cout << '+';
				}
				else if (s < 0)
				{
					cout << '-';
				}
				else
				{
					cout << '0';
				}
			}
		}
		cout << endl;
	}
	return 0;
}
