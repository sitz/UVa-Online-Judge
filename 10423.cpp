#include <bits/stdc++.h>

using namespace std;

int main()
{
	int tc = 1;
	while (true)
	{
		int T;
		cin >> T;
		if (T == 0)
		{
			break;
		}
		int res = -1;
		int min_diff = 1 << 25;
		vector<int> trams;
		vector<pair<int, int>> times;
		for (int i = 0; i < T; ++i)
		{
			int id;
			cin >> id;
			char dam;
			cin >> dam;
			while (true)
			{
				int time;
				cin >> time;
				if (time == -1)
				{
					break;
				}
				times.push_back(make_pair(time, id));
			}
		}
		int m, n;
		cin >> m >> n;
		int st = 0;
		sort(times.begin(), times.end());
		for (int i = 0; i < (int)times.size(); ++i)
		{
			int diff = times[i].first - m;
			if (diff < 0)
			{
				diff = times[i].first + 60 - m;
			}
			if (min_diff > diff)
			{
				min_diff = diff;
				st = i;
			}
		}
		for (int i = st; i < times.size(); ++i)
		{
			if (n - 1 == i - st)
			{
				res = times[i].second;
			}
		}
		if (res < 0)
		{
			res = times[((n - 1) - (times.size() - st)) % times.size()].second;
		}
		cout << "Case " << tc << ": Peter arrives at stop " << n << " by tram " << res << "." << endl;
		++tc;
	}
	return 0;
}
