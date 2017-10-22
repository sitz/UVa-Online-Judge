#include <bits/stdc++.h>

using namespace std;

int L, K;
vector<int> vt[33];
map<long long, int> mp;
map<long long, int>::iterator iter;

long long Hash(int vs[])
{
	long long sb = 0;
	for (int i = 1; i < K; i++)
	{
		sb = sb * 10271 + (vs[i] - vs[0] + 5011);
	}
	return sb;
}

int Work()
{
	for (int i = 0, z, x; i < K; i++)
	{
		vt[i].clear();
		cin >> z;
		for (int j = 0; j < z; j++)
		{
			cin >> x;
			vt[i].push_back(x);
		}
		sort(vt[i].begin(), vt[i].end());
	}
	mp.clear();
	int vs[33] = {0}, ds[33] = {0};
	int ans = 0;
	mp[Hash(vs)] = -1;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < K; j++)
			if (ds[j] < vt[j].size() && vt[j][ds[j]] == i)
			{
				vs[j]++;
				ds[j]++;
			}
		long long xk = Hash(vs);
		iter = mp.find(xk);
		if (iter == mp.end())
		{
			mp[xk] = i;
		}
		else
		{
			ans = max(ans, i - iter->second);
		}
	}
	return ans;
}

int main()
{
	cin.sync_with_stdio(false);
	int tt = 0;
	while (cin >> L >> K)
	{
		if (L == 0 || K == 0)
		{
			break;
		}
		cout << "Case #" << (++tt) << ": " << Work() << " meter(s)" << endl;
	}
	return 0;
}
