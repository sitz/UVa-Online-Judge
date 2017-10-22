#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 10000;

char str[1000000];
int inOrder[MAXSIZE], postOrder[MAXSIZE], cntIn, cntPost, best, leaf;

void init()
{
	cntIn = cntPost = 0;
	best = 0x3fffffff;
	leaf = 0;
}

void parseIn()
{
	char *cp = strtok(str, " ");
	if (cp)
	{
		inOrder[cntIn++] = atoi(cp);
	}
	while (cp = strtok(NULL, " "))
	{
		inOrder[cntIn++] = atoi(cp);
	}
}

void parsePost()
{
	char *cp = strtok(str, " ");
	if (cp)
	{
		postOrder[cntPost++] = atoi(cp);
	}
	while (cp = strtok(NULL, " "))
	{
		postOrder[cntPost++] = atoi(cp);
	}
}

void backtrace(int lIn, int rIn, int lPost, int rPost, int sum)
{
	if (lIn > rIn || lPost > rPost)
	{
		return;
	}
	if (lIn == rIn)
	{
		if (sum + inOrder[lIn] < best)
		{
			best = sum + inOrder[lIn];
			leaf = lIn;
		}
		return;
	}
	int inRoot;
	for (inRoot = lIn; inRoot <= rIn; inRoot++)
		if (inOrder[inRoot] == postOrder[rPost])
		{
			break;
		}
	int lSize = inRoot - lIn;
	int rSize = rIn - inRoot;
	backtrace(lIn, inRoot - 1, lPost, lPost + lSize - 1, sum + inOrder[inRoot]);
	backtrace(inRoot + 1, rIn, rPost - rSize, rPost - 1, sum + inOrder[inRoot]);
}

void solve()
{
	backtrace(0, cntIn - 1, 0, cntPost - 1, 0);
}

int main()
{
	while (cin.getline(str, 1000000))
	{
		init();
		parseIn();
		cin.getline(str, 1000000);
		parsePost();
		solve();
		cout << inOrder[leaf] << endl;
	}
	return 0;
}
