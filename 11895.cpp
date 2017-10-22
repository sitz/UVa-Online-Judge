#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define pfn printf("\n");
#define ll long long
#define INF 0x7fffffff

typedef struct dnode
{
	long long p, q, t;
	friend bool operator<(struct dnode n1, struct dnode n2)
	{
		return n1.q * n2.p < n1.p * n2.q;
	}
} node;
int n, k;
priority_queue<node> heap;

long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	int T, g;
	node nd;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		while (!heap.empty())
		{
			heap.pop();
		}
		for (int i = 0; i < n; i++)
		{
			sf("%lld %lld", &nd.p, &nd.q);
			nd.t = nd.p;
			heap.push(nd);
		}
		for (int i = 1; i < k; i++)
		{
			nd = heap.top();
			heap.pop();
			nd.q *= (nd.t - 1);
			nd.p *= nd.t;
			heap.push(nd);
		}
		nd = heap.top();
		g = gcd(nd.p, nd.q);
		nd.p /= g;
		nd.q /= g;
		pf("%lld/%lld\n", nd.q, nd.p);
	}
	return 0;
}
