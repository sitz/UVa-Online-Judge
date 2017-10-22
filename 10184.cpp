#include <bits/stdc++.h>

using namespace std;

typedef struct A
{
	double x, y, z;
} AA;
AA a[105];
map<string, int> MAP;

int main()
{
	int i, j, all = 0, i1, i2, i3;
	double lat, lng;
	string s1, s2, s3;
	MAP.clear();
	while (cin >> s1)
	{
		if (s1 == "#")
		{
			break;
		}
		MAP[s1] = all;
		cin >> lat >> lng;
		lat = lat * acos(-1) / 180;
		lng = lng * acos(-1) / 180;
		a[all].x = (double)6378 * cos(lat) * cos(lng);
		a[all].y = (double)6378 * cos(lat) * sin(lng);
		a[all].z = (double)6378 * sin(lat);
		all++;
	}
	while (cin >> s1)
	{
		if (s1 == "#")
		{
			break;
		}
		cin >> s2 >> s3;
		if (MAP.find(s1) == MAP.end() || MAP.find(s2) == MAP.end() || MAP.find(s3) == MAP.end())
		{
			cout << s3 << " is ? km off " << s1 << "/" << s2 << " equidistance." << endl;
		}
		else
		{
			i1 = MAP[s1];
			i2 = MAP[s2];
			i3 = MAP[s3];
			if (a[i1].x == a[i2].x && a[i1].y == a[i2].y && a[i1].z == a[i2].z)
			{
				cout << s3 << " is 0 km off " << s1 << "/" << s2 << " equidistance." << endl;
			}
			else
			{
				double dx = a[i1].x - a[i2].x;
				double dy = a[i1].y - a[i2].y;
				double dz = a[i1].z - a[i2].z;
				// inner product
				double child = dx * a[i3].x + dy * a[i3].y + dz * a[i3].z;
				double mom = sqrt(dx * dx + dy * dy + dz * dz) * sqrt(a[i3].x * a[i3].x + a[i3].y * a[i3].y + a[i3].z * a[i3].z);
				double final = fabs(child / mom);
				final = acos(final);
				final = acos(-1) / 2 - final;
				final = final * 6378;
				cout << s3 << " is " << floor(final + 0.5) << " km off " << s1 << "/" << s2 << " equidistance." << endl;
			}
		}
	}
	return 0;
}
