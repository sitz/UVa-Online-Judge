#include <bits/stdc++.h>

using namespace std;

struct UFDS
{
	int sz;
	vector<int> pset, set_sz;

	UFDS(int sz);
	int set_find(int a);
	bool set_same(int a, int b);
	void set_union(int a, int b);
	int set_n_disjoint();
	int set_sz_get(int a);
};

UFDS::UFDS(int sz)
{
	this->sz = sz;
	set_sz.assign(sz, 1);
	pset.assign(sz, 0);
	for (int i = 0; i < sz; i++)
	{
		pset[i] = i;
	}
}

int UFDS::set_find(int a)
{
	return pset[a] == a ? a : (pset[a] = set_find(pset[a]));
}

bool UFDS::set_same(int a, int b)
{
	return set_find(a) == set_find(b);
}

void UFDS::set_union(int a, int b)
{
	if (set_same(a, b))
	{
		return;
	}
	sz--;
	set_sz[set_find(b)] += set_sz[set_find(a)];
	pset[set_find(a)] = set_find(b);
}

int UFDS::set_n_disjoint()
{
	return sz;
}

int UFDS::set_sz_get(int a)
{
	return set_sz[set_find(a)];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int cnt = 0;
		map<string, int> m;
		UFDS ds(200000);
		int N;
		scanf("%d", &N);
		while (N--)
		{
			string a, b;
			cin >> a >> b;
			if (m.find(a) == m.end())
			{
				m[a] = cnt;
				cnt++;
			}
			if (m.find(b) == m.end())
			{
				m[b] = cnt;
				cnt++;
			}
			ds.set_union(m[a], m[b]);
			printf("%d\n", ds.set_sz_get(m[a]));
		}
	}
	return 0;
}
