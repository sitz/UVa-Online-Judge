#include <bits/stdc++.h>

using namespace std;

const int cost_del = 2, cost_ins = 2, cost_trans = 2;

int min_edit(const string &s1, const string &s2);
int min_3(int a, int b, int c);
void init_subst_tab();
void set_close_subst(unsigned char c1, unsigned char c2);
int subst_cost(unsigned char c1, unsigned char c2);

class strie;

class node
{
	friend class strie;

public:
	node(char c, node *parent, int depth);
	inline bool is_term()
	{
		return w.size() != 0;
	}

	char c;
	int depth;
	string w;
	node *parent;
	set<int> ssize;
	map<char, node> children;
	vector<int> d;
};

class nodeinheap
{
	friend class strie;

public:
	nodeinheap(int h, node *p);
	inline bool operator<(const nodeinheap &o) const
	{
		return (h < o.h);
	}
	inline bool operator==(const nodeinheap &o) const
	{
		return (h == o.h);
	}
	inline bool operator!=(const nodeinheap &o) const
	{
		return (h != o.h);
	}

	int h;
	node *p;
};

class strie
{
public:
	typedef map<char, node>::iterator child_iterator;
	typedef map<char, node>::const_iterator const_child_iterator;
	strie();
	bool insert(const string &word);
	int me_search(const string &word);//a* srch
	bool exact_search(const string &word) const;
	const vector<string> &getresult() const;

	void me_visit(node *c);
	int me_est(node *c);// heuristic estimate
	node root;
	int maxl;
	int bestd;
	int worstd;
	int wsize;
	string w;
	multiset<nodeinheap> heap;
	vector<string> result;
};

const size_t TDIM = 256;

static int subst_tab[TDIM][TDIM];

int min_3(int a, int b, int c)
{
	int m = a;
	if (b < m)
	{
		m = b;
	}
	if (c < m)
	{
		m = c;
	}
	return (m);
}

void init_subst_tab()
{
	for (size_t i = 0; i < TDIM; i++)
	{
		for (size_t j = 0; j < TDIM; j++)
		{
			if (i == j)
			{
				subst_tab[i][j] = 0;
			}
			else
			{
				subst_tab[i][j] = 2;
			}
		}
	}
	return;
}

void set_close_subst(unsigned char c1, unsigned char c2)
{
	subst_tab[c1][c2] = 1;
	subst_tab[c2][c1] = 1;
	return;
}

int subst_cost(unsigned char c1, unsigned char c2)
{
	return (subst_tab[c1][c2]);
}

node::node(char c, node *parent, int depth)
		: c(c), parent(parent), depth(depth)
{
}

nodeinheap::nodeinheap(int h, node *p) : h(h), p(p)
{
}

strie::strie() : root('\0', 0, 0), maxl(0)
{
}
bool strie::insert(const string &w)
{
	node *p = &root;
	bool is_new = false;
	if (w.size() > (size_t)maxl)
	{
		maxl = w.size();
	}
	for (size_t i = 0; i < w.size(); i++)
	{
		char c = w[i];
		pair<child_iterator, bool> t = p->children.insert(
				make_pair(c, node(c, p, i + 1)));
		child_iterator it = t.first;
		p = &(it->second);
		int sleft = w.size() - i - 1;
		if (sleft > 0)
		{
			p->ssize.insert(sleft);
		}
	}
	if (p->w.size() == 0)
	{
		is_new = true;
		p->w = w;
	}
	return (is_new);
}
int strie::me_search(const string &word)
{
	w = word;
	wsize = w.size();
	worstd = bestd = (wsize + maxl) * 2;
	root.d = vector<int>(wsize + 1);
	for (int i = 0; i <= wsize; i++)
	{
		root.d[i] = i * cost_del;
	}
	heap.clear();
	result.clear();
	me_visit(&root);
	while (!heap.empty())
	{
		multiset<nodeinheap>::iterator it = heap.begin();
		node *cur = it->p;
		if (it->h > bestd)
		{
			break;
		}
		heap.erase(it);
		me_visit(cur);
	}
	sort(result.begin(), result.end());
	return (bestd);
}
void strie::me_visit(node *c)
{
	for (child_iterator it = c->children.begin(); it != c->children.end(); it++)
	{
		int h = me_est(&(it->second));
		node &child = (it->second);
		if (child.w.size() > 0)// terminal node
		{
			int &curd = child.d[wsize];
			if (curd < bestd)
			{
				bestd = curd;
				result.clear();
				result.push_back(child.w);
			}
			else if (curd == bestd)
			{
				result.push_back(child.w);
			}
		}
		if (h <= bestd && child.children.size() > 0)
		{
			heap.insert(nodeinheap(h, &(it->second)));
		}
	}
}
int strie::me_est(node *c)
{
	c->d.resize(wsize + 1);
	vector<int> &d = c->d;
	d[0] = c->depth * cost_ins;
	node *p = c->parent;
	node *gp = p->parent;
	set<int>::const_iterator cs_it, ns_it;
	cs_it = ns_it = c->ssize.begin();
	if (ns_it != c->ssize.end())
	{
		ns_it++;
	}
	int besth = worstd;// start with very high heuristic
	for (int i = 1; i <= wsize; i++)
	{
		d[i] = min_3(p->d[i - 1] + subst_cost(w[i - 1], c->c),
									d[i - 1] + cost_del,
									p->d[i] + cost_ins);
		if (i > 1 && c->depth > 1 && w[i - 1] != c->c && w[i - 1] == p->c && w[i - 2] == c->c)
		{
			d[i] = min(d[i], gp->d[i - 2] + cost_trans);
		}
	}
	for (int i = wsize - 1; i >= 1; i--)
	{
		int h = d[i];
		if (cs_it != c->ssize.end())// estimate heuristic
		{
			int sleft = wsize - i;
			int diffsize;
			if (sleft > *cs_it && ns_it != c->ssize.end())// find best size match
			{
				if (sleft - *cs_it > *ns_it - sleft)
				{
					cs_it = ns_it;
					ns_it++;
				}
			}
			diffsize = (sleft <= *cs_it) ? (*cs_it - sleft) : (sleft - *cs_it);
			h = d[i] + diffsize * 2;
		}
		if (h < besth)
		{
			besth = h;
		}
	}
	return (besth);
}
const vector<string> &strie::getresult() const
{
	return result;
}
bool strie::exact_search(const string &word) const
{
	const node *cur = &root;
	size_t i;
	for (i = 0; i < word.size(); i++)
	{
		char c = word[i];
		const_child_iterator it = cur->children.find(c);
		if (it == cur->children.end())
		{
			break;
		}
		cur = &(it->second);
	}
	return (i == word.size() && cur->w.size() != 0);
}

int main()
{
	strie tree;
	string l;
	init_subst_tab();

	while (getline(cin, l))
	{
		if (l.empty())
		{
			break;
		}
		char c1 = l[0];
		for (size_t i = 2; i < l.size(); i++)
		{
			set_close_subst(c1, l[i]);
		}
	}

	while (getline(cin, l))
	{
		if (l.empty())
		{
			break;
		}
		tree.insert(l);
	}

	while (getline(cin, l))
	{
		if (l.empty())
		{
			break;
		}
		int min_op = tree.me_search(l);
		const vector<string> &vs = tree.getresult();
		cout << l << ":" << min_op << ":" << vs[0];
		for (size_t i = 1; i < vs.size(); i++)
		{
			cout << ' ' << vs[i];
		}
		printf("\n");
	}
	return 0;
}
