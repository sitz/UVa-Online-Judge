#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

class fraction
{
public:
	long long n, d;
	fraction(long long n, long long d)
	{
		this->n = n;
		this->d = d;
		long long g = gcd(abs(n), abs(d));
		n /= g;
		d /= g;
		if (n == 0)
		{
			d = 1;
		}
		if (n < 1 && d < 1)
		{
			n *= -1;
			d *= -1;
		}
		else if (n < 1 || d < 1)
		{
			n = abs(n);
			d = abs(d);
			n *= -1;
		}
	}
	fraction()
	{
		n = 0;
		d = 1;
	}
};

bool hasSol;
int rankA, rankAC, N, NumberOfUnknowns, NumberOfEquations;
fraction mat[50][50], x[50];

void simplify(fraction &f)
{
	long long g = gcd(abs(f.n), abs(f.d));
	f.n /= g;
	f.d /= g;
	if (f.n == 0)
	{
		f.d = 1;
	}
	if (f.n < 1 && f.d < 1)
	{
		f.n *= -1;
		f.d *= -1;
	}
	else if (f.n < 1 || f.d < 1)
	{
		f.n = abs(f.n);
		f.d = abs(f.d);
		f.n *= -1;
	}
}

fraction operator/(const fraction &f1, const fraction &f2)
{
	fraction ret(f1.n * f2.d, f1.d * f2.n);
	simplify(ret);
	return ret;
}

fraction operator*(const fraction &f1, const fraction &f2)
{
	fraction ret(f1.n * f2.n, f1.d * f2.d);
	simplify(ret);
	return ret;
}

fraction operator+(const fraction &f1, const fraction &f2)
{
	fraction ret((f1.n * f2.d) + (f2.n * f1.d), f1.d * f2.d);
	simplify(ret);
	return ret;
}

fraction operator+=(fraction &f1, const fraction &f2)
{
	return f1 = f1 + f2;
}

fraction operator*(long long &x, const fraction &f)
{
	fraction ret(x * f.n, f.d);
	simplify(ret);
	return ret;
}
fraction operator*=(fraction &f1, const fraction &f2)
{
	return f1 = f1 * f2;
}
fraction operator-(const fraction &f)
{
	fraction ret(f.n, f.d);
	ret.n *= -1;
	simplify(ret);
	return ret;
}

fraction operator-(const fraction &f1, const fraction &f2)
{
	fraction ret = f1 + (-f2);
	return ret;
}

bool operator>(const fraction &f1, const fraction &f2)
{
	bool ret = abs(f1.n * f2.d) > abs(f2.n * f1.d);
	return ret;
}

void printMatrix()
{
	for (int i = 1; i <= NumberOfEquations; ++i)
	{
		for (int j = 1; j <= NumberOfUnknowns + 1; ++j)
			printf("%lld/%lld ", mat[i][j].n, mat[i][j].d);
		printf("\n");
	}
}

void swapRows(int r1, int r2)
{
	for (int j = 1; j <= NumberOfUnknowns + 1; ++j)
		swap(mat[r1][j], mat[r2][j]);
}

void gauss()
{
	for (int p = 1; p <= NumberOfUnknowns; ++p)
	{
		int maxR = p;
		for (int i = p + 1; i <= NumberOfEquations; ++i)
			if (mat[i][p] > mat[maxR][p])
				maxR = i;
		swapRows(p, maxR);
		if (mat[p][p].n != 0)
		{
			fraction x(mat[p][p].d, mat[p][p].n);
			for (int i = 1; i <= (NumberOfUnknowns + 1); ++i)
				mat[p][i] *= x;
			for (int i = p + 1; i <= NumberOfEquations; ++i)
			{
				x = (-mat[i][p]);
				for (int j = 1; j <= NumberOfUnknowns + 1; ++j)
					mat[i][j] += (x * mat[p][j]);
			}
		}
	}
}

void rank_()
{
	rankA = rankAC = NumberOfEquations;
	bool allZeroes;
	for (int i = 1; i <= NumberOfEquations; ++i)
	{
		allZeroes = true;
		for (int j = 1; j <= (NumberOfUnknowns); ++j)
		{
			if (mat[i][j].n != 0)
			{
				allZeroes = false;
				break;
			}
		}
		if (allZeroes)
		{
			--rankA;
			if (mat[i][NumberOfUnknowns + 1].n == 0)
				--rankAC;
		}
	}
}

void back()
{
	for (int p = NumberOfUnknowns; p >= 1; --p)
	{
		fraction s(0, 1);
		for (int k = p + 1; k <= NumberOfUnknowns; ++k)
			s += (x[k] * mat[p][k]);
		x[p] = (mat[p][NumberOfUnknowns + 1] - s) / mat[p][p];
	}
}

int main()
{
	char c;
	bool isFirst = true;
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
		{
			break;
		}
		if (!isFirst)
		{
			printf("\n");
		}
		scanf("%d%d", &NumberOfUnknowns, &NumberOfEquations);
		for (int i = 1; i <= NumberOfEquations; ++i)
		{
			for (int j = 1; j <= (NumberOfUnknowns + 1); ++j)
			{
				scanf("%lld", &mat[i][j].n);
				scanf("%c", &c);
				if (c == '/')
				{
					scanf("%lld", &mat[i][j].d);
				}
				else
				{
					mat[i][j].d = 1;
				}
			}
		}
		hasSol = true;
		gauss();
		rank_();
		if (rankAC != rankA)
		{
			hasSol = false;
		}
		if (hasSol && rankAC == NumberOfUnknowns)
		{
			back();
		}
		printf("Solution for Matrix System # %d\n", N);
		if (!hasSol)
		{
			printf("No Solution.\n");
		}
		else
		{
			if (rankAC < NumberOfUnknowns)
			{
				printf("Infinitely many solutions containing %d arbitrary constants.\n", NumberOfUnknowns - rankAC);
			}
			else
			{
				for (int i = 1; i <= NumberOfUnknowns; ++i)
				{
					printf("x[%d] = ", i);
					if (x[i].d == 1)
						printf("%lld\n", x[i].n);
					else
						printf("%lld/%lld\n", x[i].n, x[i].d);
				}
			}
		}
		isFirst = false;
	}
	return 0;
}
