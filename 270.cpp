#include <bits/stdc++.h>

using namespace std;

using std::vector;
using std::cin;

struct Point
{
	int x, y;
};

bool is_collinear(Point a, Point b, Point c)
{
	int pos = a.x * b.y + b.x * c.y + c.x * a.y;
	int neg = b.x * a.y + c.x * b.y + a.x * c.y;
	return (pos == neg);
}

bool is_line_exist(Point a, Point b, vector<Point> &prev_line)
{
	for (int i = 0; i < prev_line.size(); i = i + 2)
	{
		bool r1 = is_collinear(a, b, prev_line[i]);
		bool r2 = is_collinear(a, b, prev_line[i + 1]);
		if (r1 && r2)
			return true;
	}
	return false;
}

int search_lines(vector<Point> &points)
{
	int max_points = 0;
	vector<Point> prev_line;
	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = i + 1; j < points.size(); ++j)
		{
			// line pi-pj
			if (is_line_exist(points[i], points[j], prev_line))
				continue;
			vector<Point> line;
			line.push_back(points[i]);
			line.push_back(points[j]);
			for (int k = j + 1; k < points.size(); ++k)
				if (is_collinear(points[i], points[j], points[k]))
					line.push_back(points[k]);
			if (line.size() > max_points)
				max_points = line.size();
		}
	}
	return max_points;
}

int main()
{
	int num_case;
	scanf("%d\n", &num_case);
	while (num_case--)
	{
		vector<Point> points;
		char line[128];
		while (cin.getline(line, sizeof(line)))
		{
			if (0 == strlen(line))
				break;//empty line
			Point p;
			sscanf(line, "%d%d", &p.x, &p.y);
			points.push_back(p);
		}
		int max_points = search_lines(points);
		printf("%d\n", max_points);
		if (num_case != 0)
			putchar('\n');
	}
	return 0;
}
