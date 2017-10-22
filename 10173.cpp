#include <bits/stdc++.h>

using namespace std;

typedef double db;
const db EPS = 1e-10;
const int maxn = 5005;
const db PI = acos(-1.0);
int sign(db x)
{
	if (fabs(x) < EPS)
	{
		return 0;
	}
	return x > 0 ? 1 : -1;
}
db sqr(db x)
{
	return x * x;
}
struct TPoint
{
	db x, y;
	TPoint() {}
	TPoint(db xx, db yy) : x(xx), y(yy) {}
	TPoint sub(TPoint P)
	{
		return TPoint(x - P.x, y - P.y);
	}
	TPoint add(TPoint P)
	{
		return TPoint(x + P.x, y + P.y);
	}
	db X(TPoint P)
	{
		return x * P.y - y * P.x;
	}
	db dot(TPoint P)
	{
		return x * P.x + y * P.y;
	}
	db len()
	{
		return sqrt(sqr(x) + sqr(y));
	}
	db disTo(TPoint P)
	{
		return sqrt(sqr(x - P.x) + sqr(y - P.y));
	}
	void get()
	{
		scanf("%lf%lf", &x, &y);
	}
	void out()
	{
		printf("POS = (%.4f %.4f)\n", x, y);
	}
	bool operator<(const TPoint P) const
	{
		return sign(y - P.y) < 0 || (sign(y - P.y) == 0 && sign(x - P.x) < 0);
	}
	db X(TPoint a, TPoint b)
	{
		return (x - a.x) * (b.y - y) - (y - a.y) * (b.x - x);
	}
	TPoint rot(db c, db s)
	{
		return TPoint(x * c - y * s, x * s + y * c);
	}
};

struct TLine
{
	db A, B, C;// Bx + Ay + C = 0...
	TPoint a, b;
	void init(TPoint aa, TPoint bb)
	{
		a = aa;
		b = bb;
		A = a.x - b.x;
		B = b.y - a.y;
		C = b.X(a);
	}
	bool inter(TLine L, TPoint &P)
	{
		TPoint AA(A, L.A), BB(B, L.B), CC(C, L.C);
		db c = AA.X(BB);
		if (!sign(c))
		{
			return 0;
		}
		P = TPoint(CC.X(AA) / c, -CC.X(BB) / c);
		return 1;
	}
} vL[5];

db get_dot_ang(TPoint A, TPoint B)
{
	return A.dot(B) / 16.0 / B.len();
}
db get_X_ang(TPoint A, TPoint B)
{
	return fabs(A.X(B) / 16.0 / B.len());
}

int n;
int sta[maxn];
TPoint P[maxn], bP[maxn], TV[maxn];
bool cmp(TPoint a, TPoint b)
{
	int flg = sign(P[0].X(a, b));
	return flg ? flg < 0 : sign(a.disTo(P[0]) - b.disTo(P[0])) < 0;
}
bool eq(TPoint a, TPoint b)
{
	return sign(a.x - b.x) == 0 && sign(a.y - b.y) == 0;
}
int TuBao(TPoint P[], int n)
{
	int top = -1, i;
	sort(P, P + n);
	sort(P + 1, P + n, cmp);
	sta[++top] = 0;
	sta[++top] = 1;
	for (i = 2; i < n; ++i)
	{
		while (top && (sign(P[sta[top]].X(P[sta[top - 1]], P[i])) <= 0 || eq(P[sta[top]], P[sta[top - 1]])))
		{
			--top;
		}
		if (!eq(P[i], P[sta[top]]))
		{
			sta[++top] = i;
		}
	}
	return top + 1;
}

bool get()
{
	scanf("%d", &n);
	if (n == 0)
	{
		return 0;
	}
	int i;
	for (i = 0; i < n; ++i)
	{
		P[i].get();
	}
	return 1;
}

db cal_poly_area(TPoint P[], int n)
{
	db ans = 0.0;
	int i;
	P[n] = P[0];
	for (i = 0; i < n; ++i)
	{
		ans += P[i].X(P[i + 1]);
	}
	return fabs(ans) * 0.5;
}

void checkmin(db &x, db y)
{
	if (sign(x) < 0)
	{
		x = y;
	}
	else if (sign(y - x) < 0)
	{
		x = y;
	}
}

void work()
{
	int i, j, k, sz;
	db ans = -1.0;
	sz = TuBao(P, n);
	n = sz;
	for (i = 0; i < n; ++i)
	{
		bP[i] = P[sta[i]];
	}
	bP[n] = bP[0];
	for (i = 0; i < n; ++i)
	{
		P[i] = bP[i];
	}
	P[n] = P[0];
	if (n < 3)
	{
		puts("0.0000");
		return;
	}
	for (i = 0; i < n; ++i)
	{
		TV[i] = P[i + 1].sub(P[i]);
	}
	TPoint vec[4];
	int V[4];
	db theta[4];
	vec[0] = TPoint(-16.0, 0);
	vec[1] = TPoint(0, -16.0);
	vec[2] = TPoint(16.0, 0);
	vec[3] = TPoint(0, 16.0);
	for (i = 0; i < 4; ++i)
	{
		V[i] = 0;
	}
	for (i = 0; i < n; ++i)
	{
		if (sign(P[i].y - P[V[0]].y) > 0)
		{
			V[0] = i;
		}
		if (sign(P[i].x - P[V[1]].x) < 0)
		{
			V[1] = i;
		}
		if (sign(P[i].y - P[V[2]].y) < 0)
		{
			V[2] = i;
		}
		if (sign(P[i].x - P[V[3]].x) > 0)
		{
			V[3] = i;
		}
	}
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			vL[j].init(bP[V[j]], bP[V[j]].add(vec[j]));
		}
		int L = 0;
		for (j = 0; j < 4; ++j)
			for (k = j + 1; k < 4; ++k)
			{
				TPoint pp;
				if (vL[j].inter(vL[k], pp))
				{
					P[L++] = pp;
				}
			}
		int ss = TuBao(P, L); /*P[] may be the smallest Bounding Rectangle*/
		checkmin(ans, cal_poly_area(P, ss));
		if (i == n)
		{
			break;
		}
		for (j = 0; j < 4; ++j)
		{
			theta[j] = get_dot_ang(vec[j], TV[V[j]]);
		}
		for (k = j = 0; j < 4; ++j)
			if (sign(theta[j] - theta[k]) > 0)
			{
				k = j;
			}
		db c = theta[k], s = get_X_ang(vec[k], TV[V[k]]);
		for (j = 0; j < 4; ++j)
		{
			vec[j] = vec[j].rot(c, s);
		}
		V[k] = (V[k] + 1) % n;
	}
	printf("%.4f\n", ans);
}

int main()
{
	while (get())
	{
		work();
	}
	return 0;
}
