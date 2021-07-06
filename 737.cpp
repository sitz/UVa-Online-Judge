#include <bits/stdc++.h>

using namespace std;

#define MAXCUBES 10000
#define CUBESDATA 4
#define maxi(a, b) (a < b ? b : a)
#define mini(a, b) (a < b ? a : b)

int main()
{
	int cubes[MAXCUBES][CUBESDATA];
	int n;
	int maxx, minx;
	int maxy, miny;
	int maxz, minz;
	int vol;
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> cubes[i][0];
			cin >> cubes[i][1];
			cin >> cubes[i][2];
			cin >> cubes[i][3];
		}
		minx = cubes[0][0];
		miny = cubes[0][1];
		minz = cubes[0][2];
		maxx = minx + cubes[0][3];
		maxy = miny + cubes[0][3];
		maxz = minz + cubes[0][3];
		for (int i = 1; i < n; i++)
		{
			minx = maxi(minx, cubes[i][0]);
			miny = maxi(miny, cubes[i][1]);
			minz = maxi(minz, cubes[i][2]);
			maxx = mini(maxx, cubes[i][0] + cubes[i][3]);
			maxy = mini(maxy, cubes[i][1] + cubes[i][3]);
			maxz = mini(maxz, cubes[i][2] + cubes[i][3]);
		}
		vol = maxi(0, (maxx - minx) * (maxy - miny) * (maxz - minz));
		cout << vol << endl;
	}
	return 0;
}
