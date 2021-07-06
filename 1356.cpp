#include <bits/stdc++.h>

using namespace std;

/* 自适应辛普森 UVA 1356 
 * 二分求解高度 求解抛物线的长度是不是合适
 *
 * */

const int INF = ~0u >> 1;
typedef pair<int, int> P;
#define MID(x, y) ((x + y) >> 1)
#define iabs(x) ((x) > 0 ? (x) : -(x))
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define pb push_back
#define mp make_pair
#define print() cout << "--------" << endl

// 这里为了方便，把a声明成全局的。
// 这不是一个好的编程习惯，但在本题中却可以提高代码的可读性
double a;

//simpson 公式用的函数 (这个需要根据题目而改变函数)
double F(double x)
{
	return sqrt(1 + 4 * a * a * x * x);
}

//三点simpson法，这里要求F是一个全局函数
double simpson(double a, double b)
{
	double c = a + (b - a) / 2;
	return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}

//自适应simpson公式(递归)。已知整个区间[a,b]上三点的simpson值A
double asr(double a, double b, double eps, double A)
{
	double c = a + (b - a) / 2;
	double L = simpson(a, c), R = simpson(c, b);
	if (fabs(L + R - A) <= 15 * eps)
		return L + R + (L + R - A) / 15.0;
	return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}

//自适应simpson公式(主过程)
double asr(double a, double b, double eps)
{
	return asr(a, b, eps, simpson(a, b));
}

//下面这个函数依题面而异，本题求解simpson求解宽度为w,高度为h的抛物线长度
double solve(double w, double h)
{
	a = 4.0 * h / (w * w);//修改全局变量a，从而改变F的行为
	return asr(0, w / 2, 1e-5) * 2;
}

int main()
{
	int t, cas = 0;
	scanf("%d", &t);
	while (cas++ < t)
	{
		int D, H, B, L;
		scanf("%d%d%d%d", &D, &H, &B, &L);
		int n = (B + D - 1) / D;
		double D1 = (double)B / n;
		double L1 = (double)L / n;
		double x = 0, y = H;
		while (y - x > 1e-5)
		{//二分求解高度
			double m = x + (y - x) / 2;
			if (solve(D1, m) < L1)
				x = m;
			else
				y = m;
		}
		if (cas > 1)
			puts("");
		printf("Case %d:\n%.2f\n", cas, H - x);
	}

	return 0;
}
