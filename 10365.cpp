#include <bits/stdc++.h>

using namespace std;

int Volume, numCase, minimum, height, weight, length;

int main()
{
	while (cin >> numCase)
	{
		while (numCase)
		{
			minimum = 10000000;
			numCase--;
			cin >> Volume;
			for (height = 1; height <= Volume; height++)
			{
				for (length = 1; length <= Volume; length++)
				{
					int tmp;
					tmp = height * length;
					if (tmp > Volume)
					{
						break;
					}
					weight = Volume / tmp;
					if (weight * height * length == Volume)
					{
						int area;
						area = 2 * (Volume / height + Volume / length + Volume / weight);
						if (area < minimum)
						{
							minimum = area;
						}
					}
				}
			}
			cout << minimum << endl;
		}
	}
	return 0;
}
