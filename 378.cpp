#include <bits/stdc++.h>

using namespace std;

int main()
{
	cout << "INTERSECTING LINES OUTPUT" << endl;
	int t, N;
	double k1, k2, k3, x1, y1, x2, y2, x3, y3, x4, y4;
	double inter_x, inter_y;
	cin >> N;
	for (t = 0; t < N; t++)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if (((x1 == x2) && (x2 == x3) && (x3 == x4)) || ((y1 == y2) && (y2 == y3) && (y3 == y4)))
		{
			cout << "LINE" << endl;
			continue;
		}
		k1 = (y2 - y1) / (x2 - x1);//dot 1,2
		k2 = (y4 - y3) / (x4 - x3);//dot 3,4
		k3 = (y3 - y2) / (x3 - x2);//dot 2,3
		if (x1 == x2 && x3 == x4 && x2 != x3)
		{
			cout << "NONE" << endl;
			continue;
		}
		else if (y1 == y2 && y3 == y4 && y2 != y3)
		{
			cout << "NONE" << endl;
			continue;
		}
		else if (x1 == x2 && k1 != k2)
		{
			inter_x = x1;
			inter_y = k2 * (x1 - x3) + y3;
			printf("POINT %.2f %.2f\n", inter_x, inter_y);
		}
		else if (x3 == x4 && k1 != k2)
		{
			inter_x = x3;
			inter_y = k1 * (x3 - x1) + y1;
			printf("POINT %.2f %.2f\n", inter_x, inter_y);
		}
		else if (k1 == k2 && k2 == k3)
		{
			cout << "LINE" << endl;
			continue;
		}
		else if (k1 == k2 && k2 != k3)
		{
			cout << "NONE" << endl;
			continue;
		}
		else if (k1 != k2)
		{
			inter_x = (y3 - k2 * x3 - y1 + k1 * x1) / (k1 - k2);
			inter_y = k1 * (inter_x - x1) + y1;
			printf("POINT %.2f %.2f\n", inter_x, inter_y);
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
