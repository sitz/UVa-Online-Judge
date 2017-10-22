#include <bits/stdc++.h>

using namespace std;

//ifstream fin("h.in");
//ofstream fout("hj.out");
//#define cin fin
//#define cout fout
int n, arr[1000];
void print(int a, int b)
{
	//  printf("a=%d b=%d\n",a,b);
	int sum = 0;
	for (int i = a; i <= b; i++)
	{
		sum += arr[i];
	}
	int tsum = 0;
	int root = a;
	int diff = 1 << 30;
	int left = 0;
	//cout << "Jumby Jimbo" << endl;
	for (int i = a; i <= b; i++)
	{
		tsum += arr[i];
		if (i == b || (arr[i] != arr[i + 1]))
		{
			int tdiff = abs((sum - tsum) - (tsum - arr[i]));
			//cout << i << " : " << tdiff << endl;
			if (tdiff < diff)
			{
				diff = tdiff;
				root = i;
				left = tsum - arr[i];
			}
			else if (tdiff == diff && left < tsum - arr[i])
			{
				diff = tdiff;
				root = i;
				left = tsum - arr[i];
			}
		}
	}
	cout << arr[root];
	if (b - a + 1 > 1)
	{
		cout << "(";
	}
	if (root != a)
	{
		print(a, root - 1);
	}
	if (root != a && root != b)
	{
		cout << ",";
	}
	if (root != b)
	{
		print(root + 1, b);
	}
	if (b - a + 1 > 1)
	{
		cout << ")";
	}
}
int main()
{
	int t;
	cin >> t;
	for (int I = 1; I <= t; I++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		cout << "Case #" << I << ": ";
		print(0, n - 1);
		cout << endl;
	}
	return 0;
}
