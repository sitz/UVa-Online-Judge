#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define pb push_back
#define mp make_pair

typedef complex<int> P;
typedef long long LL;

const int N = 201;

struct Line
{
	int minx, maxx;
	double A, B;
};

vector<Line> cons(vector<P> &in)
{
	vector<Line> ret;
	for (int i = 0; i < in.size() - 1; i++)
	{
		if (in[i].real() == in[i + 1].real())
		{
			continue;
		}
		double A = (double)(in[i + 1].imag() - in[i].imag()) / (in[i + 1].real() - in[i].real());
		double B = -A * in[i + 1].real() + in[i + 1].imag();
		ret.pb((Line){
				min(in[i].real(), in[i + 1].real()),
				max(in[i].real(), in[i + 1].real()), A, B});
	}
	return ret;
}

LL get_sect(vector<Line> &in, int x)
{
	LL ret = 0;
	static pair<double, double> data[N];
	int p = 0;
	for (int i = 0; i < in.size(); i++)
	{
		if (in[i].minx <= x && x < in[i].maxx)
		{
			data[p++] = mp(in[i].A * x + in[i].B, in[i].A * (x + 1) + in[i].B);
			if (data[p - 1].first > data[p - 1].second)
			{
				swap(data[p - 1].first, data[p - 1].second);
			}
		}
	}
	sort(data, data + p);
	// assert(p % 2 == 0 && p < N);
	for (int i = 0; i < p; i += 2)
	{
		int tmp = (int)(floor(data[i + 1].first)) - (int)(ceil(data[i].second));
		if (tmp < 0)
		{
			continue;
		}
		ret += (int)(floor(data[i + 1].first)) - (int)(ceil(data[i].second));
	}
	return ret;
}

// y-y1 = (y2-y1)/(x2-x1)*x(x-x1);
// y    = (y2-y1)/(x2-x1)*x(x-x1) + y1;
// y = ax - ax1 + y1;
LL solve(vector<P> &in)
{
	vector<Line> a = cons(in);
	LL ret = 0LL;
	for (int i = 0; i < 100000; i++)
	{
		ret += get_sect(a, i);
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	string _;
	getline(cin, _);
	getline(cin, _);
	while (T--)
	{
		vector<P> in;
		while (getline(cin, _) && _.size() > 0)
		{
			stringstream sin(_);
			int re, im;
			sin >> re >> im;
			in.pb(P(re, im));
		}
		in.pb(in[0]);
		printf("%lld\n", solve(in));
		if (T)
		{
			printf("\n");
		}
	}
	return 0;
}
