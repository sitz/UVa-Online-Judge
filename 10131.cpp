#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 1010;

struct Element
{
	int key, pre, num, iq;
	bool operator<(Element const &another)
	{
		return this->key < another.key;
	}

	bool operator>(Element const &another)
	{
		return this->key > another.key;
	}

	bool operator==(Element const &another)
	{
		return this->key == another.key;
	}
};

Element arr[MAXSIZE]; // arr of elements
int lis[MAXSIZE];			// arr of indexes in a
int len;							// arr len
int last;							// lis len

// bin srch
int bin_srch(int start, int end, Element e)
{
	int low = start, mid, high = end;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (arr[lis[mid]] == e)
			return mid;
		else if (arr[lis[mid]] < e)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return mid;
}

void solve()
{
	arr[0].pre = -1;
	lis[last++] = 0;
	int i;
	for (i = 1; i < len; i++)
	{
		if (arr[i] > arr[lis[last - 1]])
		{
			arr[i].pre = lis[last - 1];
			lis[last++] = i;
		}
		else
		{
			int x = bin_srch(0, last - 1, arr[i]);
			if (arr[lis[x]] == arr[i])
				arr[i].pre = arr[lis[x]].pre;
			else if (arr[lis[x]] < arr[i])
			{
				arr[i].pre = lis[x];
				lis[x + 1] = i;
			}
			else
			{
				if (x == 0)
					arr[i].pre = -1;
				else
					arr[i].pre = lis[x - 1];
				lis[x] = i;
			}
		}
	}
}

void output()
{
	int result[MAXSIZE];
	cout << last << endl;
	int x = lis[last - 1];
	for (int i = 0; i < last; i++)
	{
		result[i] = arr[x].num;
		x = arr[x].pre;
	}
	for (int i = last - 1; i >= 0; i--)
		cout << result[i] << endl;
}

int cmp(const void *a, const void *b)
{
	Element *aa = (Element *)a;
	Element *bb = (Element *)b;
	if (aa->iq != bb->iq)
		return bb->iq - aa->iq;
	else
		return bb->key - aa->key;
}

int main()
{
	len = last = 0;
	while (cin >> arr[len].key >> arr[len].iq)
	{
		arr[len].num = len + 1;
		len++;
	}
	qsort(arr, len, sizeof(Element), cmp);
	solve();
	output();
	return 0;
}
