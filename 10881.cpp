#include <bits/stdc++.h>

using namespace std;

/*
 * AUTHOR : benbendog
 * DATE   : 2011/3/15
 * PROBLEM: lots of ants on a line, going either left or right. when
            2 ants meet, they go in reverse direction. Ask after T seconds,
            where is the ants and their direction ?
 * SOLUTION: the ants' relative position would not change and we can
             regard that the ants would not change, actually that's the
             final answer for the position, and the remaining problem is
             which direction the ant is ? again actually the ant succeed
             the other ant direction so just find the final position for
             each ant, then use sort and the idea of relative position to
             get the answer
 */

struct point
{
	int pos;
	char dir;
	int ind;
};
int cmp(const point &a, const point &b);
int main()
{
	int cas;
	int cnt = 1;
	int L, T, n;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d %d %d", &L, &T, &n);
		struct point p[n];
		for (int i = 0; i < n; i++)
		{
			scanf("%d %c", &(p[i].pos), &(p[i].dir));
			p[i].ind = i;
		}
		sort(p, p + n, cmp);
		int index[n];
		for (int i = 0; i < n; i++)
		{
			index[p[i].ind] = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (p[i].dir == 'L')
			{
				p[i].pos -= T;
			}
			else
			{
				p[i].pos += T;
			}
		}
		sort(p, p + n, cmp);
		printf("Case #%d:\n", cnt++);
		for (int i = 0; i < n; i++)
		{
			bool turning = false;
			int pos = p[index[i]].pos;
			int left, right;
			left = index[i] - 1;
			right = index[i] + 1;
			if (left > -1 && p[left].pos == pos)
			{
				turning = true;
			}
			if (right < n && p[right].pos == pos)
			{
				turning = true;
			}
			if (pos > L || pos < 0)
			{
				printf("Fell off\n");
			}
			else
			{
				printf("%d ", p[index[i]].pos);
				if (turning)
				{
					printf("Turning\n");
				}
				else
				{
					printf("%c\n", p[index[i]].dir);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
int cmp(const point &a, const point &b)
{
	return a.pos < b.pos;
}
