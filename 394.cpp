#include <bits/stdc++.h>

using namespace std;

struct arr
{
	int base_address, arr_elem_sz, d, *c, c0;
	vector<pair<int, int>> bounds;
	friend istream &operator>>(istream &istr, arr &arr);
};

istream &operator>>(istream &istr, arr &arr)
{
	int a, b;
	istr >> arr.base_address >> arr.arr_elem_sz >> arr.d;
	for (int i = 0; i < arr.d; i++)
	{
		istr >> a >> b;
		arr.bounds.push_back(make_pair(a, b));
	}
	arr.c = new int[arr.d];
	arr.c[arr.d - 1] = arr.arr_elem_sz;
	for (int i = arr.d - 2; i >= 0; i--)
	{
		arr.c[i] = arr.c[i + 1] * (arr.bounds[i + 1].second - arr.bounds[i + 1].first + 1);
	}
	arr.c0 = arr.base_address;
	for (int i = 0; i < arr.d; i++)
	{
		arr.c0 -= arr.c[i] * arr.bounds[i].first;
	}
}

int main()
{
	int n, r, index, counter;
	string name;
	map<string, arr> m;
	cin >> n >> r;
	while (n--)
	{
		arr tmp;
		cin >> name;
		cin >> tmp;
		m[name] = tmp;
	}
	while (r--)
	{
		counter = 0;
		cin >> name;
		cout << name << "[";
		int result = m[name].c0;
		for (int i = 0; i < m[name].d; i++)
		{
			cin >> index;
			if (counter > 0)
			{
				printf(", ");
			}
			cout << index;
			result += m[name].c[i] * index;
			counter = 1;
		}
		cout << "] = " << result << endl;
	}
	return 0;
}
