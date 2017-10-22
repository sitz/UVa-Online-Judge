#include <bits/stdc++.h>

using namespace std;

/*
10576
Helping Fill Bates
*/

#define maxn 53
int Ind[200], len;
char Seq[1000002];
char temp[102];
set<int> SS[maxn];
void SetUp()
{
	int i, z = 65, d = 97;
	for (i = 0; i < 26; i++)
	{
		Ind[z++] = i;
		Ind[d++] = i + 26;
	}
	cin >> Seq;
	len = strlen(Seq);
	for (i = 0; Seq[i]; i++)
	{
		z = Seq[i];
		z = Ind[z];
		SS[z].insert(i);
	}
}
int Find()
{
	int i, top = -1, z, fs = 100000000;
	set<int>::iterator upper;
	for (i = 0; temp[i]; i++)
	{
		z = temp[i];
		z = Ind[z];
		upper = SS[z].upper_bound(top);
		if (upper == SS[z].end())
		{
			return 0;
		}
		top = *upper;
		if (top < fs)
		{
			fs = top;
		}
	}
	cout << "Matched " << fs << " " << top << endl;
	return 1;
}
void Cal()
{
	if (Find() == 0)
	{
		cout << "Not matched\n";
	}
}
int main()
{
	int n, k;
	SetUp();
	cin >> n;
	while (n--)
	{
		cin >> temp;
		Cal();
	}
	return 0;
}
