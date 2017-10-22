#include <bits/stdc++.h>

using namespace std;

const int MAX_W = (int)1e5;
const int INF = 1 << 29;

int pars[2 * MAX_W];
int ranks[2 * MAX_W];

void init_uf(int n)
{
	for (int i = 0; i < n; i++)
	{
		pars[i] = i;
		ranks[i] = 0;
	}
}

int get_root(int x)
{
	if (pars[x] == x)
	{
		return x;
	}
	else
	{
		return pars[x] = get_root(pars[x]);
	}
}

void merge(int x, int y)
{
	x = get_root(x);
	y = get_root(y);
	if (x == y)
	{
		return;
	}
	if (ranks[x] < ranks[y])
	{
		pars[x] = y;
	}
	else if (ranks[y] < ranks[x])
	{
		pars[y] = x;
	}
	else
	{
		pars[x] = y;
		ranks[y]++;
	}
}

bool is_same(int x, int y)
{
	return get_root(x) == get_root(y);
}

int as[MAX_W], bs[MAX_W];
int nums[2 * MAX_W], degs[2 * MAX_W], tops[2 * MAX_W], min_degs[2 * MAX_W], max_degs[2 * MAX_W];
int W, K;

void init()
{
	for (int i = 0; i < W; i++)
	{
		scanf("%d%d", as + i, bs + i);
	}
	fill(degs, degs + 2 * MAX_W, 0);
}

pair<int, int> get_pair(int a, int b)
{
	return make_pair(min(a, b), max(a, b));
}

int compress()
{
	for (int i = 0; i < W; i++)
	{
		nums[2 * i + 0] = as[i];
		nums[2 * i + 1] = bs[i];
	}
	sort(nums, nums + 2 * W);
	int N = unique(nums, nums + 2 * W) - nums;
	set<pair<int, int>> asked;
	int p = 0;
	for (int i = 0; i < W; i++)
	{
		as[i] = lower_bound(nums, nums + N, as[i]) - nums;
		bs[i] = lower_bound(nums, nums + N, bs[i]) - nums;
		if (asked.insert(get_pair(as[i], bs[i])).second)
		{
			as[p] = as[i];
			bs[p++] = bs[i];
		}
	}
	W = p;
	return N;
}

bool solve()
{
	int N = compress();
	init_uf(N);
	for (int i = 0; i < W; i++)
	{
		merge(as[i], bs[i]);
		degs[as[i]]++;
		degs[bs[i]]++;
	}
	for (int i = 0; i < N; i++)
	{
		tops[i] = get_root(i);
	}
	sort(tops, tops + N);
	int M = unique(tops, tops + N) - tops;
	fill(min_degs, min_degs + N, INF);
	fill(max_degs, max_degs + N, 0);
	for (int i = 0; i < N; i++)
	{
		min_degs[get_root(i)] = min(min_degs[get_root(i)], degs[i]);
		max_degs[get_root(i)] = max(max_degs[get_root(i)], degs[i]);
	}
	if (N == K && M == 1)
	{
		return max_degs[tops[0]] <= 2;
	}
	for (int i = 0; i < M; i++)
	{
		if (max_degs[tops[i]] > 2 || min_degs[tops[i]] != 1)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	while (scanf("%d%d", &K, &W), K)
	{
		init();
		puts(solve() ? "Y" : "N");
	}
	return 0;
}
