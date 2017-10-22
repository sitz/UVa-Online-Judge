#include <bits/stdc++.h>

using namespace std;

struct POINT
{
	int x, y;
};

// determine whether two points are equal
bool operator==(const POINT &p1, const POINT &p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

// compare the two-point coordinate size, first compare the x coordinate, if the same comparison y coordinates
bool operator>(const POINT &p1, const POINT &p2)
{
	return (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y));
}

// calculate the two-vector outer product
int operator^(const POINT &p1, const POINT &p2)
{
	return (p1.x * p2.y - p1.y * p2.x);
}

// calculate the two-dimensional inner product
int operator*(const POINT &p1, const POINT &p2)
{
	return (p1.x * p2.x + p1.y * p2.y);
}

// which of the comparison vectors has a greater angle to the x-axis vector (1, 0)
bool CompareVector(const POINT &pt1, const POINT &pt2)
{
	// modulus of the vector
	float m1 = sqrt((float)(pt1.x * pt1.x + pt1.y * pt1.y));
	float m2 = sqrt((float)(pt2.x * pt2.x + pt2.y * pt2.y));
	// two vectors are (1, 0) and the inner product, respectively
	float v1 = pt1.x / m1, v2 = pt2.x / m2;
	// if the vector angles are equal, then return to the nearest one from the base point, to ensure order
	return (v1 > v2 || v1 == v2 && m1 < m2);
}

bool CalcConvexHull(vector<POINT> &Src)
{
	// a point set should have ≥3 points to form a polygon
	if (Src.size() < 3)
	{
		return false;
	}
	// find base pt
	vector<POINT>::iterator i;
	POINT ptBase = Src.front();// fst pt is preset to min pt
	for (i = Src.begin() + 1; i != Src.end(); ++i)
	{
		// if y val of curr pt < min pt, or y val ==, x val <
		if (i->y < ptBase.y || (i->y == ptBase.y && i->x > ptBase.x))
		{
			// curr pt is taken as min pt
			ptBase = *i;
		}
	}
	// vect of each pt + base pt is calc
	for (i = Src.begin(); i != Src.end();)
	{
		// exclude same pts as base pt to avoid div err in subsequent sort calc
		if (*i == ptBase)
		{
			i = Src.erase(i);
		}
		else
		{
			// dir from base pt to tgt pt
			i->x -= ptBase.x, i->y -= ptBase.y;
			++i;
		}
	}
	// sort by angle btw each vect + abscissa
	sort(Src.begin(), Src.end(), &CompareVector);
	// del repeated vect
	Src.erase(unique(Src.begin(), Src.end()), Src.end());
	// ≥2 pts left in pt set, base pt is used to form polygon
	if (Src.size() < 2)
	{
		return false;
	}
	// fst + last vect are connected
	for (vector<POINT>::reverse_iterator ri = Src.rbegin();
			 ri != Src.rend() - 1; ++ri)
	{
		vector<POINT>::reverse_iterator riNext = ri + 1;
		// vector triangle calc
		ri->x -= riNext->x, ri->y -= riNext->y;
	}
	// del vect not on convex hull
	for (i = Src.begin() + 1; i != Src.end(); ++i)
	{
		// trace back vect in opp dir of rotation + use outer product to det dir of rotation
		for (vector<POINT>::iterator iLast = i - 1; iLast != Src.begin();)
		{
			int nCross = *i ^ *iLast;
			// if cross prod < 0, no rev rot
			// if cross prod == 0, use inner product to det dir of inverse
			if (nCross < 0 || (nCross == 0 && i->x * iLast->x > 0 &&
												 i->y * iLast->y > 0))
			{
				break;
			}
			// after del prev vect, curr vect needs to be upd, leading + trailing preceding vect
			// vect triangle calc
			i->x += iLast->x, i->y += iLast->y;
			iLast = (i = Src.erase(iLast)) - 1;
		}
	}
	// end-to-end connected vect accum + convert to coord
	Src.front().x += ptBase.x, Src.front().y += ptBase.y;
	for (i = Src.begin() + 1; i != Src.end(); ++i)
	{
		i->x += (i - 1)->x, i->y += (i - 1)->y;
	}
	// base pt is added; all convex hulls calc
	Src.push_back(ptBase);
	return (Src.size() >= 3);
}

int main()
{
	while (1)
	{
		string Name;
		while (Name.empty())
		{
			getline(cin, Name);
		}
		if (Name[0] == '#')
		{
			break;
		}
		POINT Mass;
		cin >> Mass.x >> Mass.y;
		vector<POINT> Poly, Convex;
		for (POINT pt; cin >> pt.x >> pt.y && pt.x != 0 && pt.y != 0;)
		{
			Poly.push_back(pt);
		}
		Convex = Poly;
		if (!CalcConvexHull(Convex))
		{
			*(int *)0 = 0;
		}
		// del extra pt on convex hull edge
		for (int i = 0; i < (int)Convex.size(); ++i)
		{
			int j = (i + 1) % Convex.size();
			int k = (j + 1) % Convex.size();
			POINT v1 = {Convex[j].x - Convex[i].x, Convex[j].y - Convex[i].y};
			POINT v2 = {Convex[k].x - Convex[j].x, Convex[k].y - Convex[j].y};
			// outer product == 0 -> collinear -> can del
			if ((v1 ^ v2) == 0)
			{
				// del midpt
				Convex.erase(Convex.begin() + j);
				--i;
			}
		}
		int nMin = Poly.size();
		// every edge of a convex hull
		for (int i = 0; i < (int)Convex.size(); ++i)
		{
			int j = (i + 1) % (int)Convex.size();
			// construct a vector with the center of gravity to the two vertices of the edge
			POINT v1 = {Mass.x - Convex[i].x, Mass.y - Convex[i].y};
			POINT v2 = {Mass.x - Convex[j].x, Mass.y - Convex[j].y};
			POINT s1 = {Convex[j].x - Convex[i].x, Convex[j].y - Convex[i].y};
			POINT s2 = {Convex[i].x - Convex[j].x, Convex[i].y - Convex[j].y};
			// for outer plot, to det whether center of gravity in inside
			// for inner plot to det whether center of gravity btw two ends
			if ((s1 ^ v1) >= 0 && v1 * s1 >= 0 && v2 * s2 >= 0)
			{
				int nMax = 0;
				// find pt on edge of orig polygon
				for (int k = 0; k < (int)Poly.size(); ++k)
				{
					// use outer plot to det whether pt on line
					s2.x = Poly[k].x - Convex[i].x;
					s2.y = Poly[k].y - Convex[i].y;
					if ((s2 ^ s1) == 0)
					{
						// find # of edge (max # of all pts on edge)
						nMax = max(k, nMax);
					}
				}
				// find smallest numbered edge
				nMin = min(nMin, nMax);
			}
		}
		// output numbered fr 1
		cout << Name << ' ' << nMin + 1 << endl;
	}
	return 0;
}
