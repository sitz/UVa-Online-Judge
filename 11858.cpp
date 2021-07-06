#include <bits/stdc++.h>

using namespace std;

unsigned long long result;

template <typename RandIter, typename Less>
void merge_sort(RandIter b, RandIter e, Less c)
{
	if (b >= e - 1)
		return;

	typedef typename iterator_traits<RandIter>::value_type Value;
	RandIter i = b + (e - b) / 2;
	merge_sort(b, i, c);
	merge_sort(i, e, c);
	vector<Value> L, R;
	for (RandIter j = b; j != i; j++)
		L.push_back(*j);
	for (RandIter j = i; j != e; j++)
		R.push_back(*j);
	int sz = L.size();
	RandIter l = L.begin(), r = R.begin();
	for (RandIter j = b; j != e; j++)
	{
		if (l == L.end())
			*j = *r++;
		else if (r == R.end())
			*j = *l++;
		else
		{
			if (c(*l, *r))
			{
				*j = *l++;
				sz--;
			}
			else
			{
				*j = *r++;
				result += sz;
			}
		}
	}
}

int main()
{
	int n, tmp;
	vector<int> nums(1000005);
	while (cin >> n)
	{
		if (n == 0)
			break;
		result = 0;
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		merge_sort(nums.begin(), nums.begin() + n, less_equal<int>());
		cout << result << endl;
	}
	return 0;
}
