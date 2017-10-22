#include <bits/stdc++.h>

using namespace std;

char cmd[100];

class Dictionary
{
public:
	char english[20];
	char foreign[20];
} dic[100010];

int total = 0;

int cmp(const void *a, const void *b)
{
	Dictionary *aa = (Dictionary *)a;
	Dictionary *bb = (Dictionary *)b;
	return strcmp(aa->foreign, bb->foreign);
}

void input()
{
	while (cin.getline(cmd, 100))
	{
		if (!strcmp(cmd, "\0"))
		{
			break;
		}
		char *p;
		p = strtok(cmd, " ");
		if (p)
		{
			strcpy(dic[total].english, p);
		}
		p = strtok(NULL, " ");
		if (p)
		{
			strcpy(dic[total].foreign, p);
		}
		total++;
	}
	qsort(dic, total, sizeof(Dictionary), cmp);
}

// binary search
int bin_search(char *key)
{
	int low, mid, high;
	low = 0;
	high = total - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (strcmp(key, dic[mid].foreign) == 0)
		{
			return mid;
		}
		else if (strcmp(key, dic[mid].foreign) < 0)
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

int main()
{
	input();
	while (cin.getline(cmd, 100))
	{
		int index;
		index = bin_search(cmd);
		if (index < 0)
		{
			cout << "eh" << endl;
		}
		else
		{
			cout << dic[index].english << endl;
		}
	}
	return 0;
}
