#include <bits/stdc++.h>

using namespace std;

char strPreOrder[30], strInOrder[30];

void backtrace(int leftPre, int rightPre, int leftIn, int rightIn)
{
	if (leftPre > rightPre || leftIn > rightIn)
	{
		return;
	}
	if (leftPre == rightPre)
	{
		cout << strPreOrder[leftPre];
		return;
	}
	int preRoot, inRoot;
	preRoot = leftPre;
	for (inRoot = leftIn; inRoot <= rightIn; inRoot++)
		if (strInOrder[inRoot] == strPreOrder[preRoot])
		{
			break;
		}
	int leftSize, rightSize;
	leftSize = inRoot - leftIn;
	rightSize = rightPre - leftPre - leftSize;
	backtrace(leftPre + 1, leftPre + leftSize, leftIn, inRoot - 1);
	backtrace(leftPre + leftSize + 1, rightPre, inRoot + 1, rightIn);
	cout << strPreOrder[preRoot];
}

int main()
{
	while (cin >> strPreOrder >> strInOrder)
	{
		int n = strlen(strPreOrder);
		backtrace(0, n - 1, 0, n - 1);
		cout << endl;
	}
	return 0;
}
