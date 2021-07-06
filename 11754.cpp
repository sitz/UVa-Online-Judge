#include <bits/stdc++.h>

using namespace std;

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::greater;
using std::endl;

typedef long long LL;

const int MAXN(110);

template <typename T>
struct SBT
{
	struct NODE
	{
		T key;
		int size;
		NODE *left, *right;
	};

	NODE pool[MAXN];
	NODE *root, *NIL, *rear;
	T tkey;

	void init()
	{
		NIL = pool;
		NIL->left = NIL->right = NIL;
		NIL->size = 0;
		rear = pool + 1;
		root = NIL;
	}

	void newnode(NODE *&sour, const T &value)
	{
		rear->key = value;
		rear->size = 1;
		rear->left = rear->right = NIL;
		sour = rear++;
	}

	void left_rotate(NODE *&sour)
	{
		NODE *temp = sour->right;
		sour->right = temp->left;
		temp->left = sour;
		temp->size = sour->size;
		sour->size = sour->left->size + sour->right->size + 1;
		sour = temp;
	}

	void right_rotate(NODE *&sour)
	{
		NODE *temp = sour->left;
		sour->left = temp->right;
		temp->right = sour;
		temp->size = sour->size;
		sour->size = sour->left->size + sour->right->size + 1;
		sour = temp;
	}

	void maintain(NODE *&sour, bool flag)
	{
		if (flag == false)
		{
			if (sour->left->left->size > sour->right->size)
			{
				right_rotate(sour);
			}
			else if (sour->left->right->size > sour->right->size)
			{
				left_rotate(sour->left);
				right_rotate(sour);
			}
			else
			{
				return;
			}
		}
		else
		{
			if (sour->right->right->size > sour->left->size)
			{
				left_rotate(sour);
			}
			else if (sour->right->left->size > sour->left->size)
			{
				right_rotate(sour->right);
				left_rotate(sour);
			}
			else
			{
				return;
			}
		}
		maintain(sour->left, false);
		maintain(sour->right, true);
	}

	void insert(const T &value)
	{
		tkey = value;
		insert_(root);
	}

	void insert_(NODE *&sour)
	{
		if (sour == NIL)
		{
			newnode(sour, tkey);
			return;
		}
		++sour->size;
		if (tkey < sour->key)
		{
			insert_(sour->left);
		}
		else
		{
			insert_(sour->right);
		}
		maintain(sour, tkey >= sour->key);
	}

	NODE *search(const T &value)
	{
		NODE *sour = root;
		while (root != NIL && value != sour->key)
		{
			if (value < sour->key)
			{
				sour = sour->left;
			}
			else
			{
				sour = sour->right;
			}
		}
		return sour;
	}
};

void ex_gcd(LL a, LL b, LL &x, LL &y, LL &g)
{
	if (!b)
	{
		g = a;
		x = 1;
		y = 0;
		return;
	}
	ex_gcd(b, a % b, y, x, g);
	y -= x * (a / b);
}

LL inv(LL a, LL n)
{
	LL ret, temp, g;
	ex_gcd(a, n, ret, temp, g);
	return g == 1LL ? (ret + n) % n : -1;
}

LL pow_mod(LL a, LL p, LL n)
{
	LL ret = 1LL;
	for (int i = 0; (1LL << i) <= p; a = a * a % p)
		if (p & (1LL << i))
		{
			ret = ret * a % p;
		}
	return ret;
}

LL china(int n, int *a, int *m)
{
	LL M = 1LL, ret = 0LL, x, y, g;
	for (int i = 0; i < n; ++i)
	{
		M *= m[i];
	}
	for (int i = 0; i < n; ++i)
	{
		LL w = M / m[i];
		ex_gcd(w, m[i], x, y, g);
		ret = (ret + x * w * a[i]) % M;
	}
	return (ret + M) % M;
}

int C, S;
int Y[10][100];
int quant[10];
int X[10];
const int LIMIT(10000);

//SBT<int> st[10];
set<int> st[10];

void solve_enum(int best)
{
	int count = 0;
	for (int i = 0; i < C; ++i)
		if (i != best)
		{
			//st[i].init();
			st[i].clear();
			for (int j = 0; j < quant[i]; ++j)
			{
				st[i].insert(Y[i][j]);
			}
		}
	sort(Y[best], Y[best] + quant[best]);
	for (int i = 0; count != S; ++i)
		for (int j = 0; j < quant[best]; ++j)
		{
			LL temp = Y[best][j] + (LL)X[best] * i;
			if (temp == 0LL)
			{
				continue;
			}
			bool flag = true;
			for (int i = 0; i < C; ++i)
				if (i != best && st[i].find(temp % X[i]) == st[i].end())//st[i].search(temp%X[i]) == st[i].NIL)
				{
					flag = false;
					break;
				}
			if (flag)
			{
				printf("%lld\n", temp);
				if (++count == S)
				{
					break;
				}
			}
		}
}

vector<int> ans;
int arr[10];
void dfs(int dep)
{
	if (dep == C)
	{
		ans.push_back(china(C, arr, X));
	}
	else
	{
		for (int i = 0; i < quant[dep]; ++i)
		{
			arr[dep] = Y[dep][i];
			dfs(dep + 1);
		}
	}
}

void solve_china()
{
	ans.clear();
	dfs(0);
	sort(ans.begin(), ans.end());
	LL M = 1LL;
	for (int i = 0; i < C; ++i)
	{
		M *= X[i];
	}
	int count = 0;
	for (int i = 0; count != S; ++i)
		for (int j = 0; j < ans.size(); ++j)
		{
			LL temp = ans[j] + M * i;
			if (temp > 0LL)
			{
				printf("%lld\n", temp);
				if (++count == S)
				{
					break;
				}
			}
		}
}

int main()
{
	while (scanf("%d%d", &C, &S), C + S)
	{
		int best = 0, tot = 1;
		for (int i = 0; i < C; ++i)
		{
			scanf("%d%d", X + i, quant + i);
			for (int j = 0; j < quant[i]; ++j)
			{
				scanf("%d", Y[i] + j);
			}
			if (quant[i] * X[best] < quant[best] * X[i])
			{
				best = i;
			}
			tot *= quant[i];
		}
		if (tot > LIMIT)
		{
			solve_enum(best);
		}
		else
		{
			solve_china();
		}
		putchar('\n');
	}
	return 0;
}
