#include <bits/stdc++.h>

using namespace std;

/*
209
Triangular Vertices
*/
char str[100];
int P[10], N, Or[10];
int S[260];
struct ss
{
	int line;
	int left;
	int right;
} pp[10];
int com(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void Ini()
{
	int i, sum = 0;
	for (i = 1; sum < 32767; i++)
	{
		sum += i;
		S[i] = sum;
	}
}
int Line(int n)
{
	int i;
	for (i = 1; i < 260; i++)
	{
		if (S[i] >= n)
		{
			break;
		}
	}
	return i;
}
void Sep()
{
	char *p;
	N = 0;
	p = strtok(str, " ");
	P[N] = Or[N] = atoi(p);
	N++;
	while (p)
	{
		p = strtok(NULL, " ");
		if (p)
		{
			Or[N] = P[N] = atoi(p);
			N++;
		}
	}
}
void Set()
{
	int i, ll, rl;
	qsort(P, N, sizeof(int), com);
	for (i = 0; i < N; i++)
	{
		rl = Line(P[i]);
		ll = S[rl] - rl + 1;
		pp[i].line = rl;
		pp[i].right = P[i] - ll + 1;
		pp[i].left = S[rl] - P[i] + 1;
	}
}
int isTri()
{
	int dis;
	if (pp[0].line == pp[1].line)
	{
		dis = P[1] - P[0];
		if ((pp[2].line - pp[1].line) != dis)
		{
			return 0;
		}
		if (pp[0].left != pp[2].left || pp[2].right != pp[1].right)
		{
			return 0;
		}
	}
	else
	{
		if (pp[1].line != pp[2].line)
		{
			return 0;
		}
		dis = P[2] - P[1];
		if ((pp[1].line - pp[0].line) != dis)
		{
			return 0;
		}
		if (pp[0].right != pp[1].right || pp[0].left != pp[2].left)
		{
			return 0;
		}
	}
	return 1;
}
int isPara()
{
	int dis;
	if (pp[0].line != pp[1].line)
	{
		return 0;
	}
	if (pp[2].line != pp[3].line)
	{
		return 0;
	}
	dis = P[1] - P[0];
	if ((P[3] - P[2]) != dis || (pp[2].line - pp[0].line) != dis)
	{
		return 0;
	}
	if ((pp[3].line - pp[1].line) != dis)
	{
		return 0;
	}
	if (pp[0].left == pp[2].left && pp[1].left == pp[3].left)
	{
		return 1;
	}
	if (pp[0].right == pp[2].right && pp[1].right == pp[3].right)
	{
		return 1;
	}
	return 0;
}
int isPara2()
{
	int dis;
	if (pp[1].line != pp[2].line)
	{
		return 0;
	}
	dis = P[2] - P[1];
	if ((pp[3].line - pp[1].line) != dis)
	{
		return 0;
	}
	if ((pp[1].line - pp[0].line) != dis)
	{
		return 0;
	}
	if (pp[0].right != pp[1].right || pp[0].left != pp[2].left)
	{
		return 0;
	}
	if (pp[1].left != pp[3].left || pp[2].right != pp[3].right)
	{
		return 0;
	}
	return 1;
}
int isHexa()
{
	int dis;
	if (pp[0].line != pp[1].line || pp[2].line != pp[3].line)
	{
		return 0;
	}
	if (pp[4].line != pp[5].line)
	{
		return 0;
	}
	dis = P[1] - P[0];
	if ((pp[2].line - pp[0].line) != dis || (pp[4].line - pp[2].line) != dis)
	{
		return 0;
	}
	if ((pp[3].line - pp[1].line) != dis || (pp[5].line - pp[3].line) != dis)
	{
		return 0;
	}
	if (P[5] - P[4] != dis)
	{
		return 0;
	}
	if (pp[0].right == pp[2].right && pp[2].left == pp[4].left)
		if (pp[5].right == pp[3].right && pp[3].left == pp[1].left)
		{
			return 1;
		}
	return 0;
}
void Cal()
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%d ", Or[i]);
	}
	if (N == 3 && isTri())
	{
		printf("are the vertices of a triangle\n");
	}
	else if (N == 4 && (isPara() || isPara2()))
	{
		printf("are the vertices of a parallelogram\n");
	}
	else if (N == 6 && isHexa())
	{
		printf("are the vertices of a hexagon\n");
	}
	else
	{
		printf("are not the vertices of an acceptable figure\n");
	}
}
int main()
{
	Ini();
	while (gets(str))
	{
		Sep();
		Set();
		Cal();
	}
	return 0;
}
