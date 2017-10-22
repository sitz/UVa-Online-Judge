#include <bits/stdc++.h>

using namespace std;

template <class BidirectionalIterator>
void snail_sort(BidirectionalIterator first, BidirectionalIterator last)
{
	while (next_permutation(first, last))
	{
		copy(first, last, ostream_iterator<char>(cout, ""));
		cout << endl;
	}
}

int main()
{
	int n, i, len;
	cin >> n;
	char str[15];
	for (i = 0; i < n; ++i)
	{
		cin >> str;
		len = strlen(str);
		sort(str, str + len);
		cout << str << endl;
		snail_sort(str, str + len);
		cout << endl;
	}
	return 0;
}
