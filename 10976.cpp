#include <bits/stdc++.h>

using namespace std;

struct ss
{
	int x, y;
};
ss A[10000000];
char Fg[10000000];
int ind, N, M, K;
void Cal()
{
	int i, j, d, g, l;
	ss t;
	ind = 0;
	for (i = K + 1; i <= 2 * K; i++)
	{
		//  if(Fg[i]) break;
		d = i * K;
		g = i - K;
		l = d % g;
		if (!l)
		{
			t.x = d / g;
			t.y = i;
			//      Fg[i] = Fg[d/g] = 1;
			A[ind++] = t;
		}
	}
	printf("%d\n", ind);
	for (i = 0; i < ind; i++)
	{
		printf("1/%d = 1/%d + 1/%d\n", K, A[i].x, A[i].y);
		//  Fg[A[i].x] = Fg[A[i].y] = 0;
	}
}
int main()
{
	while (scanf("%d", &K) == 1)
	{
		Cal();
	}
	return 0;
}
