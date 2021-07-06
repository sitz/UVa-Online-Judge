#include <bits/stdc++.h>

using namespace std;

char com[9][45] = {"RRDLLURRDDLLURDLUURRDLURDDLLUUR",
									 "LDRRULLDDRRULDRUULLDRULDDRRUULL",
									 "LLDRRULLDDRRULDRUULLDRULDDRRUUL",
									 "RRULLDDRRULULDDRRULULDDRRUULLDD",
									 "LURRDLLURRDLLURDDLURDRULLURRDL",
									 "LLURRDDLLURURDDLLURURDDLLUURRDD",
									 "RRULLURDDRUULDDLUURDRDLLURRDLLU",
									 "LURRDLLUURRDLURDDLLURDLUURRDDLL",
									 "LLURRULDDLUURDDRUULDLDRRULLDRRU"};
int A[12];

void Cal(int z)
{
	int i, j, p;
	p = z;
	for (i = 0; com[z][i]; i++)
	{
		switch (com[z][i])
		{
		case 'L':
			A[p] = A[p - 1];
			A[p - 1] = 0;
			p--;
			break;
		case 'R':
			A[p] = A[p + 1];
			A[p + 1] = 0;
			p++;
			break;
		case 'U':
			A[p] = A[p - 3];
			A[p - 3] = 0;
			p -= 3;
			break;
		case 'D':
			A[p] = A[p + 3];
			A[p + 3] = 0;
			p += 3;
			break;
		}
	}
	p = 0;
	for (i = 0; i < 3; i++)
	{
		printf("%d", A[p++]);
		for (j = 1; j < 3; j++)
			printf(" %d", A[p++]);
		printf("\n");
	}
}

int main()
{
	int T, f = 1, i, z;
	scanf("%d", &T);
	while (T--)
	{
		for (i = 0; i < 9; i++)
		{
			scanf("%d", &A[i]);
			if (A[i] == 0)
				z = i;
		}
		printf("Puzzle #%d\n", f++);
		Cal(z);
		puts(com[z]);
		printf("\n");
	}
	return 0;
}
