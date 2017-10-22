#include <bits/stdc++.h>

using namespace std;

int lis(vector<int> a, vector<int> w)
{
	int Sum[a.size()];
	for (size_t i = 0; i < a.size(); i++)
	{
		Sum[i] = w[i];
		for (size_t j = 0; j < i; j++)
			if (a[i] < a[j])
			{
				Sum[i] = max(Sum[i], Sum[j] + w[i]);
			}
	}
	return *max_element(Sum, Sum + a.size());
}
int main()
{
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> N;
		vector<int> a(N), w(N);
		for (int i = 0; i < N; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> w[i];
		}
		int LDS = lis(a, w);
		reverse(a.begin(), a.end()), reverse(w.begin(), w.end());
		int LIS = lis(a, w);
		if (LIS >= LDS)
		{
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", t, LIS, LDS);
		}
		else
		{
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", t, LDS, LIS);
		}
	}
	return 0;
}
