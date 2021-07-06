#include <bits/stdc++.h>

using namespace std;

struct Point {int x, y;} ref_;

vector<Point> points;
const int infinity = 2147483647;
int flag;

int is_left_special(Point p0, Point p1, Point p2)
{
	long long int cross_product = (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
	if (cross_product > 0)
	{
		return 1;
	}
	else if (cross_product < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

bool is_left(Point p0, Point p1, Point p2)
{
	long long int cross_product = (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
	if (cross_product > 0)
	{
		return true;
	}
	else if (cross_product < 0)
	{
		return false;
	}
	else
	{
		if ((p0.x == p1.x) && (p0.y == p1.y))
		{
			return true;
		}
		else if ((p0.x == p2.x) && (p0.y == p2.y))
		{
			return false;
		}
		else
		{
			return false;
		}
	}
}

bool compare(Point p2, Point p1)
{
	return !is_left(ref_, p1, p2);
}

void graham_scan()
{
	stack<Point> final;
	int i = 0;
	int count = 0;
	int n_vertex = points.size();
	int left_flag;
	if (i < n_vertex)
	{
		final.push(points[i]);
		i++;
		count++;
	}
	if (i < n_vertex)
	{
		final.push(points[i]);
		i++;
		count++;
	}
	Point p0, p1, p2;
	while ((count <= n_vertex) && (count > 1))
	{
		p2 = points[i % n_vertex];
		p1 = final.top();
		final.pop();
		p0 = final.top();
		left_flag = is_left_special(p0, p1, p2);
		if (left_flag >= 0)
		{
			final.push(p1);
			final.push(p2);
			i++;
			count++;
		}
		else
		{
			flag = 0;
		}
	}
}

int main()
{
	int n_vertex;
	Point input;
	while (cin >> n_vertex)
	{
		if (n_vertex == 0)
		{
			break;
		}
		int i = 0;
		flag = 1;
		ref_.x = infinity;
		ref_.y = infinity;
		points.clear();
		while (i < n_vertex)
		{
			cin >> input.x >> input.y;
			points.push_back(input);
			if (input.y < ref_.y)
			{
				ref_ = input;
			}
			else if ((input.y == ref_.y) && (input.x < ref_.x))
			{
				ref_ = input;
			}
			i++;
		}
		sort(points.begin(), points.end(), compare);
		graham_scan();
		if (flag == 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
