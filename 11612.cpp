#include <bits/stdc++.h>

using namespace std;

// compute non-x-ing closed path visiting all pts (convex hull)
// deal with the collinear case
// sel btm-most pt a as anchor point; foreach pt p, compute angle of seg (a,p) wrt x-axis
// traverse pt by increasing angle to yield simple closed path

struct Pt
{
	int no;
	long long x, y;
};
Pt P[1005];

bool impossible;
int n;

long long dist(Pt p1, Pt p2)
{
	long long x = p1.x - p2.x, y = p1.y - p2.y;
	return x * x + y * y;
}

long long x_prod(Pt p1, Pt p2, Pt p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

bool cmp(Pt p1, Pt p2)
{
	long long res = x_prod(P[0], p1, p2);
	if (res == 0)
	{
		return dist(P[0], p1) < dist(P[0], p2);
	}
	impossible = false;
	return res > 0;
}

bool cmp2(Pt p1, Pt p2)
{
	return dist(P[0], p1) > dist(P[0], p2);
}

void graham()
{
	int pt_start = 0;
	for (int i = 1; i <= n - 1; i++)
	{
		if (P[i].x < P[pt_start].x)
		{
			pt_start = i;
		}
		else if (P[i].x == P[pt_start].x)
		{
			if (P[i].y < P[pt_start].y)
			{
				pt_start = i;
			}
		}
	}
	Pt tmp = P[pt_start];
	P[pt_start] = P[0];
	P[0] = tmp;
	sort(P + 1, P + n, cmp);
	int mark = -1;
	for (int i = n - 1; i >= 2; i--)
	{
		if (x_prod(P[0], P[i], P[i - 1]) == 0)
		{
			mark = i;
		}
		else if (mark != -1)
		{
			sort(P + mark - 1, P + n, cmp2);
			break;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	while (scanf("%d", &n) && n)
	{
		impossible = true;
		for (int i = 0; i <= n - 1; i++)
		{
			scanf("%lld%lld", &P[i].x, &P[i].y);
			P[i].no = i;
		}

		graham();

		if (impossible)
		{
			printf("no solution\n");
		}
		else
		{
			int mark = 0;
			for (int i = 0; i < n; i++)
			{
				if (P[i].no == 0)
				{
					mark = i;
				}
			}
			printf("0 ");
			for (int i = mark + 1; i <= n - 1; i++)
			{
				printf("%d ", P[i].no);
			}
			for (int i = 0; i < mark; i++)
			{
				printf("%d ", P[i].no);
			}
			printf("0\n");
		}
	}
	return 0;
}
