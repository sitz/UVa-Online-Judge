#include <bits/stdc++.h>

using namespace std;

#define MAXN 65536

struct Frac
{
	long long x, y;

	Frac(long long a = 0, long long b = 1)
	{
		x = a, y = b;
		norm();
	}

	void norm()
	{
		if (y < 0)
		{
			x = -x;
			y = -y;
		}
		long long g = llgcd(x, y);
		x /= g;
		y /= g;
		if (y < 0)
		{
			x = -x;
			y = -y;
		}
	}
	long long llgcd(long long x, long long y) const
	{
		long long t;
		while (x % y)
		{
			t = x;
			x = y;
			y = t % y;
		}
		return y;
	}
	Frac operator-(const Frac &a) const
	{
		long long va = 0, vb = a.y / llgcd(y, a.y) * y;
		va = vb / y * x - vb / a.y * a.x;
		return Frac(va, vb);
	}
	Frac operator+(const Frac &a) const
	{
		long long va = 0, vb = a.y / llgcd(y, a.y) * y;
		va = vb / y * x + vb / a.y * a.x;
		return Frac(va, vb);
	}
	Frac operator*(const Frac a) const
	{
		long long g1 = llgcd(x, a.y), g2 = llgcd(a.x, y);
		long long va = 0, vb = 0;
		va = (x / g1) * (a.x / g2);
		vb = (y / g2) * (a.y / g1);
		return Frac(va, vb);
	}
	Frac operator/(const Frac a) const
	{
		assert(a.x);
		long long g1 = llgcd(y, a.y), g2 = llgcd(x, a.x);
		long long va = 0, vb = 0;
		va = (a.y / g1) * (x / g2);
		vb = (y / g1) * (a.x / g2);
		return Frac(va, vb);
	}
	bool operator==(const Frac &a) const
	{
		return x - a.x == 0 && y - a.y == 0;
	}
	bool operator<(const Frac &a) const
	{
		return x * a.y < a.x * y;
	}
	void print()
	{
		printf("%lld/%lld\n", x, y);
	}
};
vector<Frac> ret;

struct Node
{
	Node *l, *r;
	Frac val;
	int state;
	string token;
	Node(Frac c = Frac(), Node *a = NULL, Node *b = NULL)
			: l(a), r(b), val(c)
	{
		state = 0;
	}
} nodes[MAXN];

int dfs(Node *u)
{
	int hasX = 0;
	if (u->l != NULL)
	{
		hasX |= dfs(u->l);
	}
	if (u->r != NULL)
	{
		hasX |= dfs(u->r);
	}
	if (u->state == 1)
	{
		hasX = 1;
	}
	else if (u->state == 0)
	{
		// assert(u->l && u->r);
		if (u->l->state == 2 && u->r->state == 2)
		{
			u->state = 2;
			if (u->token == "+")
			{
				u->val = u->l->val + u->r->val;
			}
			else if (u->token == "-")
			{
				u->val = u->l->val - u->r->val;
			}
			else if (u->token == "*")
			{
				u->val = u->l->val * u->r->val;
			}
			else if (u->token == "/")
			{
				u->val = u->l->val / u->r->val;
			}
		}
		if (u->l->state == 2 && u->l->val == Frac(0, 1) && u->token == "*")
		{
			u->state = 2;
			u->val = Frac(0, 1);
		}
		if (u->r->state == 2 && u->r->val == Frac(0, 1) && u->token == "*")
		{
			u->state = 2;
			u->val = Frac(0, 1);
		}
	}
	return hasX;
}

void dfs2(Node *u, Frac tgt)
{
	if (u->r != NULL && u->r->state == 2)
	{
		Frac t;
		if (u->token == "+")
		{
			t = tgt - u->r->val;
		}
		else if (u->token == "-")
		{
			t = tgt + u->r->val;
		}
		else if (u->token == "*")
		{
			if (u->r->val.x == 0)
			{
				ret.push_back(Frac());
				ret.push_back(Frac());
				return;
			}
			t = tgt / u->r->val;
		}
		else if (u->token == "/")
		{
			t = tgt * u->r->val;
		}
		dfs2(u->l, t);
	}
	if (u->l != NULL && u->l->state == 2)
	{
		Frac t;
		if (u->token == "+")
		{
			t = tgt - u->l->val;
		}
		else if (u->token == "-")
		{
			t = u->l->val - tgt;
		}
		else if (u->token == "*")
		{
			if (u->l->val.x == 0)
			{
				ret.push_back(Frac());
				ret.push_back(Frac());
				return;
			}
			t = tgt / u->l->val;
		}
		else if (u->token == "/")
		{
			if (u->l->val.x == 0 && tgt.x == 0)
			{
				ret.push_back(Frac());
				ret.push_back(Frac());
				return;
			}
			if (u->l->val.x == 0 || tgt.x == 0)
			{
				return;
			}
			t = u->l->val / tgt;
		}
		dfs2(u->r, t);
	}
	if (u->state == 1)
	{
		ret.push_back(tgt);
	}
}

int main()
{
	string line, token;
	int x;
	while (getline(cin, line))
	{
		int nodesize = 0;
		Node *p;
		stringstream sin(line);
		stack<Node *> stk;
		while (sin >> token)
		{
			if (token == "X")
			{
				p = &nodes[nodesize++];
				*p = Node(), p->state = 1, p->token = token;
				stk.push(p);
			}
			else if (token == "*" || token == "/" || token == "+" || token == "-")
			{
				p = &nodes[nodesize++];
				*p = Node(), p->state = 0, p->token = token;
				p->r = stk.top(), stk.pop();
				p->l = stk.top(), stk.pop();
				stk.push(p);
			}
			else
			{
				stringstream vin(token);
				vin >> x;
				p = &nodes[nodesize++];
				*p = Node(), p->state = 2, p->token = token;
				p->val = Frac(x, 1);
				stk.push(p);
			}
		}
		if (stk.size() == 0)
		{
			continue;
		}
		Node *root = stk.top();
		ret.clear();
		dfs(root);
		if (root->state == 2)
		{
			if (root->val == Frac(0, 1))
			{
				printf("MULTIPLE\n");
			}
			else
			{
				printf("NONE\n");
			}
			continue;
		}
		dfs2(root, Frac(0, 1));
		if (ret.size() == 1)
		{
			printf("X = %lld/%lld\n", ret[0].x, ret[0].y);
		}
		else if (ret.size() == 0)
		{
			printf("NONE\n");
		}
		else
		{
			printf("MULTIPLE\n");
		}
	}
	return 0;
}
