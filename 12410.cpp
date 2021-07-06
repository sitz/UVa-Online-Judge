#include <bits/stdc++.h>

using namespace std;

/** memo
	[ what was done to make the first digit ]
	[ with the number of 1 ]
	[ difference between the ideal ]
	[ mod 3 ]
	[ mod 7 ]
	[ smaller or not ]
*/

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define each(i, c) FOR(i, c)
#define VAR(a) cout << #a << " : " << a << endl;
#define LOG() cout << __LINE__ << ", " << __func__ << endl;

typedef long long int lli;

const int D = 32;
pair<lli, lli> memo[D][D][D][3][7][2];

vector<int> ideal, v;
int maxone, K;

pair<lli, lli> rec(int digit, int one, int diff, int mod3, int mod7, bool small)
{
	pair<lli, lli> &ret = memo[digit][one][diff][mod3][mod7][small];
	if (ret.first != -1)
	{
		return ret;
	}
	if (maxone < one)
	{
		return ret = make_pair(0, 0);
	}
	if (K < diff)
	{
		return ret = make_pair(0, 0);
	}
	if (digit == v.size())
	{
		return (one && mod3 == 0 && mod7 != 0) ? make_pair(0, 1) : make_pair(0, 0);
	}
	lli sum = 0;
	lli cnt = 0;
	pair<lli, lli> p;// sum, cnt
	if (small)
	{
		// add 1
		p = rec(digit + 1,
						one + 1,
						diff + (ideal[digit] == 0),
						(mod3 * 2 + 1) % 3,
						(mod7 * 2 + 1) % 7,
						true);
		cnt += p.second;
		sum += p.second * (1 << (v.size() - digit - 1));
		sum += p.first;
		// add 0
		p = rec(digit + 1,
						one,
						diff + (ideal[digit] == 1),
						(mod3 * 2) % 3,
						(mod7 * 2) % 7,
						true);
		cnt += p.second;
		sum += p.first;
	}
	else
	{
		// add 1
		if (v[digit] == 1)
		{
			p = rec(digit + 1,
							one + 1,
							diff + (ideal[digit] == 0),
							(mod3 * 2 + 1) % 3,
							(mod7 * 2 + 1) % 7,
							false);
			cnt += p.second;
			sum += p.second * (1 << (v.size() - digit - 1));
			sum += p.first;
		}
		// add 0
		p = rec(digit + 1,
						one,
						diff + (ideal[digit] == 1),
						(mod3 * 2) % 3,
						(mod7 * 2) % 7,
						v[digit] == 1);
		cnt += p.second;
		sum += p.first;
	}
	return ret = make_pair(sum, cnt);
}

void f(vector<int> &v, int n)
{
	v.clear();
	while (n)
	{
		v.push_back(n % 2);
		n /= 2;
	}
	while (v.size() < D - 1)
	{
		v.push_back(0);
	}
	reverse(v.begin(), v.end());
	return;
}

lli g(lli n)
{
	fill(&memo[0][0][0][0][0][0],
			 &memo[D - 1][D - 1][D - 1][3 - 1][7 - 1][2],
			 make_pair(-1, -1));
	f(v, n);
	return rec(0, 0, 0, 0, 0, false).first;
}

int main(int argc, char *argv[])
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int start, end, i;
		cin >> start >> end >> maxone >> i >> K;
		f(ideal, i);
		static int tc = 0;
		cout << "Case " << ++tc << ": " << g(end) - g(start - 1) << endl;
	}
	return 0;
}
