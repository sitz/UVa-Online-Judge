#include <bits/stdc++.h>

using namespace std;

// O(m^3·log(n) + m·n)

#define MAX 80
int module;

vector<vector<int>> matrixproduct(vector<vector<int>> a, vector<vector<int>> b)
{
	int m = a.size();
	vector<vector<int>> ret(m, vector<int>(m));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
			{
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= module;
			}
	return ret;
}

vector<vector<int>> exp(vector<vector<int>> a, int n)
{
	//computes a^n in O(logn) multiplications
	if (n == 1)
	{
		return a;
	}
	vector<vector<int>> ret, b;
	b = exp(a, n / 2);
	ret = matrixproduct(b, b);
	if (n % 2 != 0)
	{
		ret = matrixproduct(ret, a);
	}
	return ret;
}

vector<int> compose(vector<int> a, vector<int> b)
{
	int m = a.size();
	vector<int> ret(m);
	for (int i = 0; i < m; i++)
	{
		if (b[i] == -1)
		{
			ret[i] = -1;
		}
		else
		{
			ret[i] = a[b[i]];
		}
	}
	return ret;
}

vector<int> iterate(vector<int> a, int n)
{
	if (n == 1)
	{
		return a;
	}
	vector<int> ret, b;
	b = iterate(a, n / 2);
	ret = compose(b, b);
	if (n % 2 != 0)
	{
		ret = compose(ret, a);
	}
	return ret;
}

int main()
{
	clock_t start, finish;
	start = clock();
	for (;;)
	{
		//input
		int m, f[MAX + 1];
		cin >> m;
		if (!m)
		{
			break;
		}
		for (int i = 0; i <= m; i++)
		{
			cin >> f[i];
		}
		int n;
		cin >> n >> module;
		vector<vector<int>> a(m, vector<int>(m));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
			{
				a[i][j] = 0LL;
			}
		for (int i = 0; i < m; i++)
		{
			int x = f[i];
			int y = f[i + 1];
			if (x > y)
			{
				int z = y;
				y = x;
				x = z;
			}
			for (int j = x; j < y; j++)
			{
				a[j][i] = 1LL;
			}
		}
		a = exp(a, n);
		//the trace of this matrix will be the output after minor
		//changes concerning points of the form i/m and their neighborhoods
		int ret = 0;
		for (int i = 0; i < m; i++)
		{
			ret = (ret + a[i][i]) % module;
		}
		vector<int> b(3 * (m + 1));
		for (int i = 0; i < 3 * (m + 1); i++)
		{
			int d = (i % 3) - 1;
			int k = i / 3;
			int dir = 0;
			if (k + d >= 0 && k + d <= m)
			{
				if (f[k + d] > f[k])
				{
					dir = 1;
				}
				else if (f[k + d] < f[k])
				{
					dir = -1;
				}
			}
			b[i] = 3 * f[k] + 1 + dir;
		}
		b = iterate(b, n);
		//b[3*i+1] = 3*j+1 iff f^n(i/m) = j/m
		for (int i = 0; i < 3 * (m + 1); i++)
			if (i > 0 && i <= 3 * m && (i % 3) != 1)
				if (b[i] == i)
				{
					ret = (ret + module - 1) % module;
				}
		for (int i = 0; i <= m; i++)
			if (b[3 * i + 1] == 3 * i + 1)
			{
				ret = (ret + 1) % module;
			}
		//decide whether there is an infinite number of solutions
		bool infinite = false;
		for (int i = 0; i < m && !infinite; i++)
		{
			bool inf = true;
			int j, p = 0;
			int interval = i;
			int orientation = 1;
			for (j = 1; j <= n && inf && !p; j++)
			{
				if (abs(f[interval] - f[interval + 1]) != 1)
				{
					inf = false;
				}
				interval = min(f[interval], f[interval + 1]);
				if (f[interval] > f[interval + 1])
				{
					orientation *= -1;
				}
				if (interval == i)
				{
					p = j;
				}
			}
			if (orientation < 0)
			{
				p = 2 * p;
			}
			if (inf && p && (n % p == 0))
			{
				infinite = true;
			}
		}
		if (infinite)
		{
			cout << "Infinity" << endl;
			continue;
		}
		cout << ret << endl;
	}
	finish = clock();
	cerr << "Tiempo: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
