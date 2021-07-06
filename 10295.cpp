#include <bits/stdc++.h>

using namespace std;

int numOfWords, numOfDescriptions;
char cmd[10000000];

struct Dictionary
{
	char name[20];
	double value;
} dic[1010];

void input()
{
	int i;
	for (i = 0; i < numOfWords; i++)
	{
		cin >> dic[i].name >> dic[i].value;
	}
}

int cmp(const void *a, const void *b)
{
	Dictionary *aa = (Dictionary *)a;
	Dictionary *bb = (Dictionary *)b;
	return strcmp(aa->name, bb->name);
}

// binary search
int bin_search(char *p)
{
	int low, high, mid;
	low = 0;
	high = numOfWords - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (!strcmp(dic[mid].name, p))
		{
			return mid;
		}
		else if (strcmp(p, dic[mid].name) < 0)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

void solve()
{
	input();
	qsort(dic, numOfWords, sizeof(Dictionary), cmp);
	char *p;
	int i;
	cin.get();
	for (i = 0; i < numOfDescriptions; i++)
	{
		double cnt = 0.0;
		while (cin.getline(cmd, 100000))
		{
			int index;
			if (!strcmp(cmd, "."))
			{
				break;
			}
			p = strtok(cmd, " ");
			if (p)
			{
				index = bin_search(p);
				if (index >= 0)
				{
					cnt += dic[index].value;
				}
			}
			while (p = strtok(NULL, " "))
			{
				index = bin_search(p);
				if (index >= 0)
				{
					cnt += dic[index].value;
				}
			}
		}
		cout << cnt << endl;
	}
}

int main()
{
	while (cin >> numOfWords >> numOfDescriptions)
	{
		solve();
	}
	return 0;
}
