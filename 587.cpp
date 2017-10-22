#include <bits/stdc++.h>

using namespace std;

const double EPS = 0.000000001;

class Vector2f
{
public:
	double x, y;
	Vector2f(double px, double py)
	{
		x = px, y = py;
	}
	Vector2f operator+=(Vector2f right)
	{
		x += right.x, y += right.y;
	}
	Vector2f operator*(int c)
	{
		return Vector2f(x * c, y * c);
	}
	double distance(double px, double py)
	{
		double dx = x - px;
		double dy = y - py;
		return sqrt((dx * dx) + (dy * dy));
	}
};

// 8 directions
const double SQRT2 = sqrt(2) / 2;
Vector2f N(0, 1);
Vector2f NE(SQRT2, SQRT2);
Vector2f E(1, 0);
Vector2f SE(SQRT2, -SQRT2);
Vector2f S(0, -1);
Vector2f SW(-SQRT2, -SQRT2);
Vector2f W(-1, 0);
Vector2f NW(-SQRT2, SQRT2);

bool isComma(char c)
{
	return (c == ',' || c == '.');
}

// return the treasure location according to line
Vector2f findTreasure(string line)
{
	// replace comma to white-space for stringstream extraction
	replace_if(line.begin(), line.end(), isComma, ' ');
	Vector2f loc(0, 0);//current location
	istringstream sin(line);
	string direct;
	int step;
	while (sin >> step >> direct)
	{
		if (direct == "N")
			loc += N * step;
		else if (direct == "NE")
			loc += NE * step;
		else if (direct == "E")
			loc += E * step;
		else if (direct == "SE")
			loc += SE * step;
		else if (direct == "S")
			loc += S * step;
		else if (direct == "SW")
			loc += SW * step;
		else if (direct == "W")
			loc += W * step;
		else if (direct == "NW")
			loc += NW * step;
	}
	return loc;
}

int main()
{
	int mapNo = 1;
	string line;
	while (getline(cin, line))
	{
		if ("END" == line)
			break;
		Vector2f target = findTreasure(line);
		printf("Map #%d\n", mapNo++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", target.x + EPS, target.y + EPS);
		printf("The distance to the treasure is %.3lf.\n\n", target.distance(0, 0));
	}
	return 0;
}
