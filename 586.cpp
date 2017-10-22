#include <bits/stdc++.h>

using namespace std;

stack<pair<int, int>> S;
int Count[15];

void Cal()
{
	string ss;
	int n, f = 0;
	char com[100];
	S.push(make_pair(1, 0));
	while (!S.empty())
	{
		cin >> com;
		ss = com;
		if (ss == "LOOP")
		{
			cin >> com;
			ss = com;
			if (ss == "n")
				S.push(make_pair(S.top().first, S.top().second + 1));
			else
			{
				n = atoi(com);
				S.push(make_pair(S.top().first * n, S.top().second));
			}
		}
		else if (ss == "OP")
		{
			cin >> n;
			n *= S.top().first;
			Count[S.top().second] += n;
		}
		else
			S.pop();
	}
	for (n = 10; n > 0; n--)
	{
		if (Count[n] > 0)
		{
			if (f)
				cout << "+";
			if (Count[n] > 1)
				cout << Count[n] << "*";
			cout << "n";
			if (n > 1)
				cout << "^" << n;
			f = 1;
		}
	}
	if (Count[0] > 0)
	{
		if (f)
			cout << "+";
		cout << Count[n];
		f = 1;
	}
	if (!f)
		cout << "0";
	cout << endl;
	memset(Count, 0, sizeof(int) * 15);
}

int main()
{
	int ks, k = 1;
	char ss[100];
	cin >> ks;
	while (ks--)
	{
		cin >> ss;
		cout << "Program #" << k++ << endl;
		cout << "Runtime = ";
		Cal();
		cout << endl;
	}
	return 0;
}
