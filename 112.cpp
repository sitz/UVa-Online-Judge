#include <bits/stdc++.h>

using namespace std;

// error   -1
// empty   0
// yes     1
// no      2
int parse(int tgt)
{
	char ch;
	int value;
	cin >> ch;
	if (cin.fail())
	{
		cin.clear();
		return -1;
	}
	cin >> value;
	if (cin.fail())
	{
		cin.clear();
		cin >> ch;
		if (ch != ')')
		{
			return -1;
		}
		return 0;// empty tree
	}
	int left = parse(tgt - value);
	int right = parse(tgt - value);
	cin >> ch;
	if (cin.fail())
	{
		cin.clear();
		return -1;
	}
	if (left == 0 && right == 0 && tgt == value)
	{
		return 1;
	}
	else if (left == 1 || right == 1)
	{
		return 1;
	}
	return 2;
}

int main()
{
	int tgt;
	while (scanf("%d", &tgt) == 1)
	{
		printf(parse(tgt) == 1 ? "yes\n" : "no\n");
	}
	return 0;
}
