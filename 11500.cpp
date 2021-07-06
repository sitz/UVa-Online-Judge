#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define mp make_pair

typedef pair<int, int> pii;

const int N = 100;
const double eps = 1e-10;

double mat[N][N];

int getnum(pii now, map<pii, int> &M)
{
	int size = M.size();
	if (M.find(now) == M.end())
	{
		M[now] = size;
	}
	return M[now];
}

void generate(int e1, int e2, int damage, map<pii, int> &M)
{
	if (M.find(mp(e1, e2)) != M.end())
	{
		return;
	}
	getnum(mp(e1, e2), M);
	if (e1 <= 0 || e2 <= 0)
	{
		return;
	}
	generate(e1 - damage, e2 + damage, damage, M);
	generate(e1 + damage, e2 - damage, damage, M);
}

void makemat(int e1, int e2, int damage, double e1win, map<pii, int> &M,
						 set<pii> S)
{
	if (S.find(mp(e1, e2)) != S.end())
	{
		return;
	}
	S.insert(mp(e1, e2));
	int cur = M[mp(e1, e2)];
	mat[cur][cur] = 1;
	if (e1 <= 0)
	{
		mat[cur][M.size()] = 0;
	}
	else if (e2 <= 0)
	{
		mat[cur][M.size()] = 1;
	}
	else
	{
		makemat(e1 - damage, e2 + damage, damage, e1win, M, S);
		makemat(e1 + damage, e2 - damage, damage, e1win, M, S);
		mat[cur][M[mp(e1 - damage, e2 + damage)]] = 1 - e1win;
		mat[cur][M[mp(e1 + damage, e2 - damage)]] = e1win;
	}
}

bool select_pivot(int n, int k, double mat[N][N])
{
	int s = k;//selected pivot
	double val = fabs(mat[k][k]);
	REP(i, k + 1, n)
	if (fabs(mat[i][k]) > val)
	{
		val = fabs(mat[i][k]), s = i;
	}
	if (val < eps)
	{
		return false;//cannot solve this linear equations.
	}
	REP(i, k, n + 1)
	swap(mat[k][i], mat[s][i]);
	return true;//no problem for this pivot;
}

//n matrix size  x0,x1,...xn-1 =constant
//row n,column n+1
bool gauss(int n, double mat[N][N])
{
	//step1
	rep(k, n)
	{
		if (select_pivot(n, k, mat) == false)
		{
			return false;
		}
		REP(i, k + 1, n + 1)
		mat[k][i] /= mat[k][k];//devided by m[k][k];
		mat[k][k] = 1;				 //for looking the equation
		REP(i, k + 1, n)			 //代入
		{
			REP(j, k + 1, n + 1)
			mat[i][j] += -mat[i][k] * mat[k][j];
			mat[i][k] = 0;//For looking the equation
		}
	}
	//step2
	for (int i = n - 1; i >= 0; i--)//solve ith row
	{
		REP(j, i + 1, n)
		{
			mat[i][n] -= mat[i][j] * mat[j][n];
		}
	}
	return true;
}

int main()
{
	int e1, e2, at, damage;
	while (cin >> e1 >> e2 >> at >> damage && e1)
	{
		double winprob = (at) / 6.;
		rep(i, N) rep(j, N) mat[i][j] = 0;
		map<pii, int> M;
		set<pii> S;
		generate(e1, e2, damage, M);
		makemat(e1, e2, damage, winprob, M, S);
		gauss(M.size(), mat);
		printf("%.1lf\n", fabs(100 * mat[M[mp(e1, e2)]][M.size()]));
	}
	return 0;
}
