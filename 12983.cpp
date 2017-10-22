#include <bits/stdc++.h>

using namespace std;

// i should use the bit to write
// because the recursion is very slow
// line segment tree if it is done n * m inquiries
// instead of checking n times each check m will be tle
// maintain num [k] for interval [i, j] with line segment tree
// the representative says that the ending value is in [i, j]
// the number of incremented sequences of length k

#define MOD (int)(1e9 + 7)

// do not re-arrange order
int N, M, clk = 0, A[1000], num[1001];

struct node
{
	int num[1001];
	node *l, *r;
	node()
	{
		l = r = NULL;
		for (int Mi = 1; Mi <= M; Mi++)
		{
			num[Mi] = 0;
		}
	}
};
node *root, mem[2000];

node *get()
{
	mem[clk] = node();
	return mem + (clk++);
}

node *build(int L, int R)
{
	node *r = get();
	if (L + 1 < R)
	{
		r->l = build(L, (L + R) / 2);
		r->r = build((L + R) / 2, R);
	}
	return r;
}

void add(node *O, int L, int R, int x)
{
	if (x + 1 <= L || R <= x)
	{
		return;
	}
	else if (x <= L && R <= x + 1)
	{
		for (int Mi = 1; Mi <= M; Mi++)
		{
			O->num[Mi] += num[Mi], O->num[Mi] %= MOD;
		}
	}
	else
	{
		add(O->l, L, (L + R) / 2, x);
		add(O->r, (L + R) / 2, R, x);
		for (int Mi = 1; Mi <= M; Mi++)
		{
			O->num[Mi] = O->l->num[Mi] + O->r->num[Mi];
			O->num[Mi] %= MOD;
		}
	}
}

void ask(node *O, int L, int R, int A, int B)
{
	if (B <= L || R <= A)
		;
	else if (A <= L && R <= B)
	{
		for (int Mi = 1; Mi <= M; Mi++)
		{
			num[Mi] += O->num[Mi];
			num[Mi] %= MOD;
		}
	}
	else
	{
		ask(O->l, L, (L + R) / 2, A, B);
		ask(O->r, (L + R) / 2, R, A, B);
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		clk = 0;
		scanf("%d%d", &N, &M);
		vector<int> v;
		for (int Ni = 0; Ni < N; Ni++)
		{
			scanf("%d", &A[Ni]), v.push_back(A[Ni]);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		map<int, int> m;
		for (int vi = 0; vi < v.size(); vi++)
		{
			m[v[vi]] = vi;
		}
		for (int Ni = 0; Ni < N; Ni++)
		{
			A[Ni] = m[A[Ni]];
		}
		root = build(0, N);
		for (int Ni = 0; Ni < N; Ni++)
		{
			for (int Mi = 1; Mi <= M; Mi++)
			{
				num[Mi] = 0;
			}
			ask(root, 0, N, 0, A[Ni]);
			for (int Mi = M; Mi >= 2; Mi--)
			{
				num[Mi] = num[Mi - 1];
			}
			num[1] = 1;
			add(root, 0, N, A[Ni]);
		}
		for (int Mi = 1; Mi <= M; Mi++)
		{
			num[Mi] = 0;
		}
		ask(root, 0, N, 0, N);
		printf("Case #%d: %d\n", t, num[M]);
	}
	return 0;
}
