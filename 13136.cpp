#include <bits/stdc++.h>

using namespace std;

const int MOD = 10;

struct Matrix
{
	vector<vector<int> > A, C;
	Matrix()
	{
	}
	Matrix(int n, int m)
	{
		A = vector<vector<int> >(n, vector<int>(m, 0));
		C = vector<vector<int> >(n, vector<int>(m, 0));
	}

	void ident()
	{
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				A[i][j] = 0;
			}
		}
		for (int i = 0; i < A.size(); i++)
		{
			A[i][i] = 1;
		}
	}

	void operator*(const Matrix &B)
	{
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < B.A[0].size(); j++)
			{
				C[i][j] = 0;
				for (int k = 0; k < A[0].size(); k++)
				{
					C[i][j] = (C[i][j] + (A[i][k] * B.A[k][j]));
				}
			}
		}
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A.size(); j++)
			{
				A[i][j] = C[i][j] % MOD;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A[i].size(); j++)
			{
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
};

// B = I and will store the the matrix B^e
void mat_pow(long long e, Matrix &A, Matrix &B)
{
	while (e)
	{
		if (e & 1)
		{
			B *A;
		}
		A *A;
		e >>= 1;
	}
}

int main()
{
	int T, a, b, c;
	scanf("%d", &T);
	long long e;
	Matrix A(4, 4), B(4, 4), C(4, 1);
	while (T--)
	{
		scanf("%lld%d%d%d", &e,&a,&b,&c);
		if (e == 0)
		{
			printf("%d\n", a+b+c);
			continue;
		}
		A.A[0][0] = 1;
		A.A[0][1] = 8;
		A.A[0][2] = -6;
		A.A[0][3] = -7;
		A.A[1][0] = 0;
		A.A[1][1] = 4;
		A.A[1][2] = -3;
		A.A[1][3] = -3;
		A.A[2][0] = 0;
		A.A[2][1] = 5;
		A.A[2][2] = -4;
		A.A[2][3] = -4;
		A.A[3][0] = 0;
		A.A[3][1] = -1;
		A.A[3][2] = 1;
		A.A[3][3] = 0;
		C.A[0][0] = 0;
		C.A[1][0] = a;
		C.A[2][0] = b;
		C.A[3][0] = c;
		B.ident();
		// e % 15 because this == len(cycle)
		mat_pow(e % 15, A, B);
		B *C;
		cout << (MOD + B.A[0][0]) % 10 << endl;
	}
	return 0;
}
