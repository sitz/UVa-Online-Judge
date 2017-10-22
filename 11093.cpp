#include <bits/stdc++.h>

using namespace std;

/*
11093
*/

#define maxn 100002
int P[maxn], Q[maxn], N;
int Oil;
int FindF()
{
	int i, p = 1;
	Oil = P[1];
	for (i = 2; i <= N; i++)
	{
		if (Oil >= Q[i - 1])
		{
			Oil -= Q[i - 1];
			Oil += P[i];
		}
		else
		{
			p = i;
			Oil = P[i];
		}
	}
	return p;
}
void Cal()
{
	int lim, i, pre;
	lim = FindF();
	if (lim == 1)
	{
		cout << "Possible from station " << lim << endl;
		return;
	}
	pre = Q[N];
	for (i = 1; i <= lim; i++)
	{
		if (Oil >= pre)
		{
			Oil -= pre;
			Oil += P[i];
			pre = Q[i];
		}
		else
		{
			cout << "Not possible\n";
			return;
		}
	}
	cout << "Possible from station " << lim << endl;
}
int main()
{
	int k, i, ks = 1;
	cin >> k;
	while (k--)
	{
		cin >> N;
		for (i = 1; i <= N; i++)
		{
			cin >> P[i];
		}
		for (i = 1; i <= N; i++)
		{
			cin >> Q[i];
		}
		cout << "Case " << ks++ << ": ";
		Cal();
	}
	return 0;
}
