#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)

struct SAComp
{
	const int h, *g;
	SAComp(int h, int *g) : h(h), g(g) {}
	bool operator()(int a, int b)
	{
		return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h];
	}
};

int g[100100], b[100100], v[100100];

int *buildSA(char *t, int n)
{
	REP(i, n + 1)
	v[i] = i,
	g[i] = t[i];
	b[0] = 0;
	b[n] = 0;
	sort(v, v + n + 1, SAComp(0, g));
	for (int h = 1; b[n] != n; h *= 2)
	{
		SAComp comp(h, g);
		sort(v, v + n + 1, comp);
		REP(i, n)
		b[i + 1] = b[i] + comp(v[i], v[i + 1]);
		REP(i, n + 1)
		g[v[i]] = b[i];
	}
	return v;
}

// Naive matching O(m log n)
int find(char *t, int n, char *p, int m, int *sa)
{
	int a = 0, b = n;
	while (a < b)
	{
		int c = (a + b) / 2;
		if (strncmp(t + sa[c], p, m) < 0)
		{
			a = c + 1;
		}
		else
		{
			b = c;
		}
	}
	return strncmp(t + sa[a], p, m) == 0 ? sa[a] : -1;
}

int lcp[100100];

// Kasai-Lee-Arimura-Arikawa-Park's simple LCP computation: O(n)
int *buildLCP(char *t, int n, int *a)
{
	int h = 0, b[n + 1];
	REP(i, n + 1)
	b[a[i]] = i;
	REP(i, n + 1)
	{
		if (b[i])
		{
			for (int j = a[b[i] - 1]; j + h < n && i + h < n && t[j + h] == t[i + h]; ++h)
				;
			lcp[b[i]] = h;
		}
		else
		{
			lcp[b[i]] = -1;
		}
		if (h > 0)
		{
			--h;
		}
	}
	return lcp;
}

// call RMQ = buildRMQ(lcp, n+1)
int *buildRMQ(int *a, int n)
{
	int logn = 1;
	for (int k = 1; k < n; k *= 2)
	{
		++logn;
	}
	int *r = new int[n * logn];
	int *b = r;
	copy(a, a + n, b);
	for (int k = 1; k < n; k *= 2)
	{
		copy(b, b + n, b + n);
		b += n;
		REP(i, n - k)
		b[i] = min(b[i], b[i + k]);
	}
	return r;
}

// inner LCP computation with RMQ: O(1)
int minimum(int x, int y, int *rmq, int n)
{
	int z = y - x, k = 0, e = 1, s;
	s = ((z & 0xffff0000) != 0) << 4;
	z >>= s;
	e <<= s;
	k |= s;
	s = ((z & 0x0000ff00) != 0) << 3;
	z >>= s;
	e <<= s;
	k |= s;
	s = ((z & 0x000000f0) != 0) << 2;
	z >>= s;
	e <<= s;
	k |= s;
	s = ((z & 0x0000000c) != 0) << 1;
	z >>= s;
	e <<= s;
	k |= s;
	s = ((z & 0x00000002) != 0) << 0;
	z >>= s;
	e <<= s;
	k |= s;
	return min(rmq[x + n * k], rmq[y + n * k - e + 1]);
}

// outer LCP computation: O(m - o)
int computeLCP(char *t, int n, char *p, int m, int o, int k)
{
	int i = o;
	for (; i < m && k + i < n && p[i] == t[k + i]; ++i)
		;
	return i;
}

// Mamber-Myers's O(m + log n) string matching with LCP/RMQ
#define COMP(h, k) (h == m || (k + h < n && p[h] < t[k + h]))
int find(char *t, int n, char *p, int m, int *sa, int *rmq)
{
	int l = 0, lh = 0, r = n, rh = computeLCP(t, n + 1, p, m, 0, sa[n]);
	if (!COMP(rh, sa[r]))
	{
		return -1;
	}
	for (int k = (l + r) / 2; l + 1 < r; k = (l + r) / 2)
	{
		int A = minimum(l + 1, k, rmq, n + 1), B = minimum(k + 1, r, rmq, n + 1);
		if (A >= B)
		{
			if (lh < A)
			{
				l = k;
			}
			else if (lh > A)
			{
				r = k, rh = A;
			}
			else
			{
				int i = computeLCP(t, n + 1, p, m, A, sa[k]);
				if (COMP(i, sa[k]))
				{
					r = k, rh = i;
				}
				else
				{
					l = k, lh = i;
				}
			}
		}
		else
		{
			if (rh < B)
			{
				r = k;
			}
			else if (rh > B)
			{
				l = k, lh = B;
			}
			else
			{
				int i = computeLCP(t, n + 1, p, m, B, sa[k]);
				if (COMP(i, sa[k]))
				{
					r = k, rh = i;
				}
				else
				{
					l = k, lh = i;
				}
			}
		}
	}
	return rh == m ? sa[r] : -1;
}

char entradaCE[1010];
char entrada[1010];

int main()
{
	while (true)
	{
		cin.getline(entradaCE, 1010);
		int tam = strlen(entradaCE);
		int act = 0;
		for (int i = 0; i < tam + 1; i++)
		{
			if (entradaCE[i] != ' ')
			{
				entrada[act++] = entradaCE[i];
			}
		}
		tam = strlen(entrada) - 1;
		if (tam == -1)
		{
			return 0;
		}
		entrada[tam + 1] = '$';
		entrada[tam + 2] = '\0';
		tam += 1;
		int *sa = buildSA(entrada, tam);
		int *lcp = buildLCP(entrada, tam, sa);
		for (int i = 1; i <= tam + 1; i++)
		{
			int cuenta = 1;
			int maximo = 0;
			for (int j = 1; j <= tam; j++)
			{
				if (lcp[j] >= i)
				{
					cuenta++;
				}
				else
				{
					cuenta = 1;
				}
				if (cuenta > maximo)
				{
					maximo = cuenta;
				}
			}
			if (maximo > 1)
			{
				cout << maximo << endl;
			}
			if (maximo == 0)
			{
				break;
			}
		}
		cout << endl;
	}
}
