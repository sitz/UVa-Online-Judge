#include <bits/stdc++.h>

using namespace std;

long long int B[2][2], C[2][2], T[2][2];
void ini(int p, int q)
{
	B[0][0] = B[1][1] = 1, B[0][1] = B[1][0] = 0;
	C[0][0] = 0, C[0][1] = 1, C[1][0] = -q, C[1][1] = p;
}
void mult(long long int M1[2][2], long long int M2[2][2])
{
	T[0][0] = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
	T[0][1] = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
	T[1][0] = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
	T[1][1] = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];
	M1[0][0] = T[0][0], M1[0][1] = T[0][1];
	M1[1][0] = T[1][0], M1[1][1] = T[1][1];
}
void print(long long int M1[2][2])
{
	printf("%10lld %10lld\n%10lld %10lld\n", M1[0][0], M1[0][1], M1[1][0], M1[1][1]);
}
int main()
{
	int i, j, p, q, n;
	while (scanf("%d%d%d", &p, &q, &n) == 3)
	{
		if (n-- == 0)
		{
			printf("2\n");
			continue;
		}
		for (ini(p, q); n; n >>= 1)
		{
			if (n & 1)
			{
				mult(B, C);
			}
			mult(C, C);
		}
		printf("%lld\n", 2 * B[1][0] + p * B[1][1]);
	}
	return 0;
}
