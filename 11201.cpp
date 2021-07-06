#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define mp make_pair

const int N = 10000;
const int inf = (1 << 21);
typedef long long ll;
double table[] =
		{
				12.53,
				1.42,
				4.68,
				5.86,
				13.68,
				0.69,
				1.01,
				0.70,
				6.25,
				0.44,
				0.00,
				4.97,
				3.15,
				6.71,
				8.68,
				2.51,
				0.88,
				6.87,
				7.98,
				4.63,
				3.93,
				0.90,
				0.02,
				0.22,
				0.90,
				0.52,
};

string aiueo[2] =
		{
				"bcdfghjklmnpqrstvwxyz",
				"aeiuo"};

double average[22][8] =
		{
				0};
double num[22][8] =
		{
				0};

void maketable(int *cnt, int now, double val, int start)
{
	if (now == 8)
	{
		return;
	}
	average[start][now] += val;
	num[start][now]++;
	int tmp = now % 2;
	rep(i, aiueo[tmp].size())
	{
		if (cnt[aiueo[tmp][i]] == 2)
		{
			continue;
		}
		cnt[aiueo[tmp][i]]++;
		maketable(cnt, now + 1, val + (1 + now) * table[aiueo[tmp][i] - 'a'], start);
		cnt[aiueo[tmp][i]]--;
	}
}

main()
{
	int cnt[255] = {0};
	int mapping[255];
	rep(i, aiueo[0].size()) mapping[aiueo[0][i]] = i;
	rep(i, aiueo[0].size())
	{
		cnt[aiueo[0][i]]++;
		maketable(cnt, 1, table[aiueo[0][i] - 'a'], i);
		cnt[aiueo[0][i]]--;
	}
	int te;
	cin >> te;
	string in;
	getline(cin, in);
	while (te--)
	{
		double val = 0;
		getline(cin, in);
		rep(i, in.size())
		{
			val += table[in[i] - 'a'] * (i + 1);
		}
		double tmp = average[mapping[in[0]]][in.size()] / num[mapping[in[0]]][in.size()];
		//    cout << val <<" " << tmp << endl;
		if (val >= tmp)
		{
			puts("above or equal");
		}
		else
		{
			puts("below");
		}
	}
}
