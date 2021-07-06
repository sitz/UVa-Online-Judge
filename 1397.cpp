#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 25;
const double eps = 1e-9;

LL a, m, b, n, C[N][N];
int hash_[N][N], tot;
long double A[N][N];

struct Frac
{

	LL a, b;

	Frac()
	{
		a = 0;
		b = 1;
	}
	Frac(LL a, LL b)
	{
		this->a = a;
		this->b = b;
		deal();
	}

	void init()
	{
		a = 0;
		b = 1;
	}

	LL gcd(LL a, LL b)
	{
		while (b)
		{
			LL tmp = a % b;
			a = b;
			b = tmp;
		}
		return a;
	}

	void deal()
	{
		LL d = gcd(a, b);
		a /= d;
		b /= d;
		if (b < 0)
		{
			a = -a;
			b = -b;
		}
	}

	Frac operator+(Frac c)
	{
		Frac ans;
		ans.a = a * c.b + b * c.a;
		ans.b = b * c.b;
		ans.deal();
		return ans;
	}

	Frac operator-(Frac c)
	{
		Frac ans;
		ans.a = a * c.b - b * c.a;
		ans.b = b * c.b;
		ans.deal();
		return ans;
	}

	Frac operator*(Frac c)
	{
		Frac ans;
		ans.a = a * c.a;
		ans.b = b * c.b;
		ans.deal();
		return ans;
	}

	Frac operator/(Frac c)
	{
		Frac ans;
		ans.a = a * c.b;
		ans.b = b * c.a;
		ans.deal();
		return ans;
	}

	void operator+=(Frac c)
	{
		*this = *this + c;
	}
	void operator+=(LL c)
	{
		*this = *this + Frac(c, 1);
	}
	void operator-=(Frac c)
	{
		*this = *this - c;
	}
	void operator*=(Frac c)
	{
		*this = *this * c;
	}
	void operator/=(Frac c)
	{
		*this = *this / c;
	}

	bool operator>(Frac c)
	{
		return a * c.b > b * c.a;
	}
	bool operator==(Frac c)
	{
		return a * c.b == b * c.a;
	}
	bool operator<(Frac c)
	{
		return !(*this < c && *this == c);
	}
	bool operator>=(Frac c)
	{
		return !(*this < c);
	}
	bool operator<=(Frac c)
	{
		return !(*this > c);
	}
	bool operator!=(Frac c)
	{
		return !(*this == c);
	}
	bool operator!=(LL c)
	{
		return *this != Frac(c, 1);
	}

	void operator=(LL c)
	{
		this->a = c;
		this->b = 1;
	}
};

void build()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = 0.0f;
		}
	}
	A[0][0] = 1;
	for (int i = 1; i <= tot; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int l = j, r = i - j;
			long double tmp = C[i][l];
			while (l >= m)
			{
				tmp *= a;
				l -= m;
			}
			while (r >= n)
			{
				tmp *= b;
				r -= n;
			}
			A[hash_[l][r]][i] += tmp;
		}
	}
	A[tot][tot] = 1;
	A[tot][tot + 1] = 1;
	tot++;
}

void getC()
{
	for (int i = 0; i <= 20; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

void gethash_()
{
	tot = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			hash_[i][j] = tot++;
		}
	}
}

void print(double x)
{
	char s[100];
	sprintf(s, "%.0lf", x);
	if (strcmp(s, "-0") == 0)
	{
		printf(" %s", s + 1);
	}
	else
	{
		printf(" %s", s);
	}
}

void gauss()
{
	for (int i = 0; i < tot; i++)
	{
		int r;
		for (r = i; r < tot; r++)
			if (fabs(A[r][i]) > eps)
			{
				break;
			}
		if (r == tot)
		{
			continue;
		}
		for (int j = i; j <= tot; j++)
		{
			swap(A[r][j], A[i][j]);
		}
		for (int j = 0; j < tot; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (fabs(A[j][i]) >= eps)
			{
				double tmp = A[j][i] / A[i][i];
				for (int k = i; k <= tot; k++)
				{
					A[j][k] -= tmp * A[i][k];
				}
			}
		}
	}
	printf("1");
	for (int i = tot - 2; i >= 0; i--)
	{
		print(A[i][tot] / A[i][i]);
	}
	printf("\n");
}

int main()
{
	getC();
	while (~scanf("%lld%lld%lld%lld", &a, &m, &b, &n))
	{
		if (!a && !m && !b && !n)
		{
			break;
		}
		gethash_();
		build();
		gauss();
	}
	return 0;
}
