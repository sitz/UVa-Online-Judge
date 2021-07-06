#include <bits/stdc++.h>

using namespace std;

/*
 *  Algorithm:
 *      Counting Problem.
 *      Si means the Si+1'th num from 0 which has not been used.
 *      So you can use binary search + TreeArray to calculate
 *      the Si+1'th number which has not been used.
 * */

const int MAXSIZE = 50010;

class TreeArray
{
public:
	int C[MAXSIZE], size;

	void init(int len)
	{
		size = len;
		memset(C, 0, sizeof(C));
	}

	int lowbit(int x)
	{
		return x & (x ^ (x - 1));
	}

	void insert(int k, int value)
	{
		while (k <= size)
		{
			C[k] += value;
			k += lowbit(k);
		}
	}

	int getSum(int k)
	{
		int sum = 0;
		while (k > 0)
		{
			sum += C[k];
			k -= lowbit(k);
		}
		return sum;
	}
} ta;

int K, S[50010];

void input()
{
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> S[i];
	}
}

void solve()
{
	int i;
	vector<int> ans;
	ta.init(K + 1);
	for (i = 1; i <= K; i++)
	{
		ta.insert(i, 1);
	}
	for (i = 0; i < K; i++)
	{
		int low = 1, mid, high = K;
		while (low < high)
		{
			mid = (low + high) / 2;
			int sum = ta.getSum(mid);
			if (sum < S[i] + 1)
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		ans.push_back(high);
		ta.insert(high, -1);
	}
	bool f = false;
	for (i = 0; i < (int)ans.size(); i++)
	{
		if (f)
		{
			cout << " ";
		}
		f = true;
		cout << ans[i];
	}
	cout << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		input();
		solve();
	}
	return 0;
}
