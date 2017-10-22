#include <bits/stdc++.h>

using namespace std;

#define MIN(a, b) (a > b ? b : a)

char V[] = "AUEOI";
char C[] = "JSBKTCLDMVNWFXGPYHQZR";
char final[300], con[200], vow[200];

int N;

int com(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

void cal()
{
	int tc, tv, cc, cv, i, j = 0, k = 0, x, temp1, temp2, l = 0;
	tv = temp1 = (N + 1) / 2;
	tc = temp2 = N - tv;
	cc = (tc + 4) / 5;
	cv = (tv + 20) / 21;
	for (i = 0; i < cv; i++)
	{
		x = MIN(21, tv);
		for (j = 0; j < x; j++)
		{
			vow[k++] = V[i];
		}
		tv -= x;
	}
	vow[k] = '\0';
	qsort(vow, temp1, sizeof(vow[0]), com);
	for (i = 0; i < cc; i++)
	{
		x = MIN(5, tc);
		for (j = 0; j < x; j++)
		{
			con[l++] = C[i];
		}
		tc -= x;
	}
	qsort(con, temp2, sizeof(con[0]), com);
	for (i = 0; i < temp2; i++)
	{
		printf("%c%c", vow[i], con[i]);
	}
	if (temp1 != temp2)
	{
		printf("%c", vow[i]);
	}
	printf("\n");
}

int main()
{
	int ks, k = 1;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d", &N);
		printf("Case %d: ", k++);
		cal();
	}
	return 0;
}
