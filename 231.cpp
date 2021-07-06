#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 300001;

struct Element
{
	int key, pre;

	bool operator>(Element const &another)
	{
		if (this->key < another.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(Element const &another)
	{
		if (this->key > another.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(Element const &another)
	{
		if (this->key == another.key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

Element arr[MAXSIZE]; // arr of elements
int lis[MAXSIZE];			// arr of indxs in a
int len;							// arr len
int last;							// lst len

int binSearch(int start, int end, Element e)
{
	int low = start, mid, high = end;
	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (arr[lis[mid]] == e)
		{
			return mid;
		}
		else if (arr[lis[mid]] < e)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
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
			int x = binSearch(0, last - 1, arr[i]);
			if (arr[lis[x]] == arr[i])
			{
				arr[i].pre = arr[lis[x]].pre;
			}
			else if (arr[lis[x]] < arr[i])
			{
				arr[i].pre = lis[x];
				lis[x + 1] = i;
			}
			else
			{
				if (x == 0)
				{
					arr[i].pre = -1;
				}
				else
				{
					arr[i].pre = lis[x - 1];
				}
				lis[x] = i;
			}
		}
	}
}

void output()
{
	cout << "  maximum possible interceptions: " << last << endl;
}

int input()
{
	len = last = 0;
	cin >> arr[len++].key;
	if (arr[0].key < 0)
	{
		return 0;
	}
	while (cin >> arr[len].key && arr[len].key >= 0)
	{
		len++;
	}
	return 1;
}

int main()
{
	int t = 1, f = 0;
	while (input())
	{
		if (f)
		{
			printf("\n");
		}
		f = 1;
		solve();
		printf("Test #%d:\n", t);
		t++;
		output();
	}
	return 0;
}
