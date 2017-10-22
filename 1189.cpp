#include <bits/stdc++.h>

using namespace std;

bool flg;
int n;

void func()
{
	queue<string> qs;
	queue<int> qm;

	qm.push(1 % n);
	qs.push("1");

	while (!qs.empty())
	{
		int um = qm.front();
		string us = qs.front();

		qm.pop();
		qs.pop();

		if (um == 0)
		{
			cout << us << endl;
			return;
		}

		qm.push((um * 10) % n);
		qs.push(us + "0");

		qm.push((um * 10 + 1) % n);
		qs.push(us + "1");
	}
}

int main()
{
	while (cin >> n)
	{
		if (!n)
			return 0;

		flg = false;
		func();
	}

	return 0;
}
