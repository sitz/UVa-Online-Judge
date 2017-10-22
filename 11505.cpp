#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/115/11505.html

// @BEGIN_OF_SOURCE_CODE

#define pi acos(-1.0)
#define N 1000000

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		int command;
		scanf("%d", &command);
		double x = 0;
		double y = 0;
		double theta = 0;
		for (int i = 0; i < command; i++)
		{
			string c;
			double m;
			cin >> c >> m;
			if (c == "fd")
			{
				x += (m * cos(theta * pi / 180));
				y += (m * sin(theta * pi / 180));
				//theta = 0;
			}
			else if (c == "lt")
			{
				theta += m;
				theta = fmod(theta, 360);
			}
			else if (c == "rt")
			{
				theta -= m;
				theta = fmod(theta, 360);
			}
			else
			{
				x -= (m * cos(theta * pi / 180));
				y -= (m * sin(theta * pi / 180));
				//theta = 0;
			}
		}
		printf("%0.lf\n", sqrt(x * x + y * y));
	}
	return 0;
}

// @END_OF_SOURCE_CODE
