#include <bits/stdc++.h>

using namespace std;

/* ********************
   *     Defines      *
   ******************** */
#define max(a, b) ((a > b) ? a : b)						 //finding max
#define min(a, b) ((a < b) ? a : b)						 //finding min
#define Max(a, b, c) max(a, max(b, c))				 //finding max between 3 numbers
#define Min(a, b, c) min(a, min(b, c))				 //finding min between 3 numbers
#define Pi acos(-1.0)													 //defining Pi for mathematical uses
#define Clear(a) memset(a, 0, sizeof(a))			 //clearing memory of an array
#define setfalse(a) memset(a, false, sizeof(a))//setting the array into false
#define settrue(a) memset(a, true, sizeof(a))	//setting the array into true
#define clrstr(a) memset(a, '\0', sizeof(a))	 //setting string array to null
#define Case(a) printf("Case %d: ", a)				 //printing case number
#define caseh(a) printf("Case #%d: ", a)			 //printing case number having '#'
#define getcase(a) scanf("%d", &a)						 //scanning case number
#define CHR getchar()													 //avoid the newline character problem
#define caseloop(a, b) for (a = 1; a <= b; a++)//making case loop
#define EPS 1e-9															 //small value for avoiding preccesion error
#define LL long long													 //long long short form
#define MX 100000															 //MAX size/value
#define PB(x) push_back(x)										 //push in vector/string
#define PP pop_back()													 //pop from vector
#define PF(x) push_front(x)										 //push in vector/string/deque from front
#define PPF(x) pop_front()										 //pop from vector/deque from front
#define IN(x) insert(x)												 //insert element in set
#define PS(x) push(x)													 //push element in stack/queue
#define P() pop()															 //pop element from stack/queue
#define MOD 1000000007												 //mod value
#define INF (1 << 28)													 //infinity value

template <typename T>
T BigMod(T b, T p, T m)
{
	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		T s = BigMod(b, p / 2, m);
		return ((s % m) * (s % m)) % m;
	}
	return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m)
{
	return BigMod(b, m - 2, m);
}
template <typename T>
void ia(T a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
template <typename T>
void pa(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
}
template <typename T>
void IA(T a[], int n)
{
	for (int i = 1; i <= n; i++)
		cin >> a[i];
}
template <typename T>
void PA(T a[], int n)
{
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << a[n - 1] << endl;
}
template <typename T>
T gcd(T a, T b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int g[2005][2005], h[2005][2005], l[2005], r[2005];

void draw_graph(int n, int m)
{
	int q, x, y, z;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &q, &x);
		z = 1;
		for (int j = 0; j < q; j++)
		{
			scanf("%d", &y);
			for (int k = 0; k < y; k++)
				g[i][z++] = (j % 2 ? (x + 1) % 2 : x);
		}
		for (int j = 1; j <= m; j++)
			h[i][j] = (g[i][j] ? 0 : 1);
	}
}

void print_graph(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d", g[i][j]);
		cout << endl;
	}
}

void make_histogram(int n, int m)
{
	for (int j = 1; j <= m; j++)
		if (h[n][j])
			h[n][j] = h[n - 1][j] + 1;
}

void print_histogram(int n, int m)
{
	for (int i = 1; i <= m; i++)
		cout << h[n][i] << " ";
	cout << endl;
}

int mx_area(int n, int m)
{
	stack<int> a;
	a.PS(0);
	for (int i = 1; i <= m; i++)
	{
		while (!a.empty() && h[n][a.top()] >= h[n][i])
			a.pop();
		int v = 0;
		if (!a.empty())
			v = a.top();
		a.PS(i);
		l[i] = h[n][i] * (i - v);
	}
	while (!a.empty())
		a.pop();

	a.PS(m + 1);
	for (int i = m; i >= 1; i--)
	{
		while (!a.empty() && h[n][a.top()] >= h[n][i])
			a.pop();
		int v = 0;
		if (!a.empty())
			v = a.top();
		a.PS(i);
		r[i] = h[n][i] * (v - i);
	}
	int mx = -1;
	for (int i = 1; i <= m; i++)
		mx = max(l[i] + r[i] - h[n][i], mx);
	return mx;
}

int main()
{
	int t, c, n, m, q, x, y, z, mx;
	getcase(t);
	caseloop(c, t)
	{
		scanf("%d%d", &n, &m);
		draw_graph(n, m);
		mx = -1;
		for (int i = 1; i <= n; i++)
		{
			make_histogram(i, m);
			mx = max(mx, mx_area(i, m));
		}
		Case(c);
		cout << mx << endl;
		Clear(h);
		Clear(r);
		Clear(l);
	}
	return 0;
}
