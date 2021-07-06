#include <bits/stdc++.h>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)
#define loopfrom1(i, n) for (int i = 1; i < n; i++)
#define mem(array, value) memset(array, value, sizeof(array))
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define pb(a) push_back(a)
#define SZ size()
#define getint(n) scanf("%d", &n)
#define pi acos(-1.0)
#define inf 536870912// 1<<29
#define debug cout << "ok" << endl
#define ll long long int
#define mod(a) (a > 0 ? a : -a)

int main()
{
	int kases;
	getint(kases);
	double length, width, r, areaOfRectangle, areaOfCircle;
	while (kases--)
	{
		cin >> length;
		width = length * (6.0 / 10.0);
		areaOfRectangle = length * width;
		r = length / 5.0;
		areaOfCircle = pi * r * r;
		printf("%.2lf %.2lf\n", areaOfCircle, areaOfRectangle - areaOfCircle);
	}
	return 0;
}
