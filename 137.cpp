#include <bits/stdc++.h>

using namespace std;

struct POINTF
{
	float x, y;
};

bool Equal(float f1, float f2)
{
	return (abs(f1 - f2) < 1e-4f);
}

bool operator==(const POINTF &p1, const POINTF &p2)
{
	return (Equal(p1.x, p2.x) && Equal(p1.y, p2.y));
}

bool operator>(const POINTF &p1, const POINTF &p2)
{
	return (p1.x > p2.x || (Equal(p1.x, p2.x) && p1.y > p2.y));
}

float operator^(const POINTF &p1, const POINTF &p2)
{
	return (p1.x * p2.y - p1.y * p2.x);
}

int Intersection(POINTF p1, POINTF p2, POINTF p3, POINTF p4, POINTF &Int)
{
		if (p1 == p2 || p3 == p4)
	{
		return -1;	}
		if (p1 > p2)
	{
		swap(p1, p2);
	}
	if (p3 > p4)
	{
		swap(p3, p4);
	}
		POINTF v1 = {p2.x - p1.x, p2.y - p1.y}, v2 = {p4.x - p3.x, p4.y - p3.y};
		float Corss = v1 ^ v2;
		if (p1 == p3 && p2 == p4)
	{
		return 6;
	}
		if (p1 == p3)
	{
		Int = p1;
				return (Equal(Corss, 0) ? 5 : 3);
	}
		if (p2 == p4)
	{
		Int = p2;
				return (Equal(Corss, 0) ? 5 : 3);
	}
		if (p1 == p4)
	{
		Int = p1;
		return 3;
	}
	if (p2 == p3)
	{
		Int = p2;
		return 3;
	}		if (p1 > p3)
	{
		swap(p1, p3);
		swap(p2, p4);
				swap(v1, v2);
		Corss = v1 ^ v2;
	}
		if (Equal(Corss, 0))
	{
				POINTF vs = {p3.x - p1.x, p3.y - p1.y};
				if (Equal(v1 ^ vs, 0))
		{
						if (p2 > p3)
			{
				Int = p3;
				return 4;			}
		}				return 0;
	}		float ymax1 = p1.y, ymin1 = p2.y, ymax2 = p3.y, ymin2 = p4.y;
	if (ymax1 < ymin1)
	{
		swap(ymax1, ymin1);
	}
	if (ymax2 < ymin2)
	{
		swap(ymax2, ymin2);
	}
		if (p1.x > p4.x || p2.x < p3.x || ymax1 < ymin2 || ymin1 > ymax2)
	{
		return 0;
	}	POINTF vs1 = {p1.x - p3.x, p1.y - p3.y}, vs2 = {p2.x - p3.x, p2.y - p3.y};
	POINTF vt1 = {p3.x - p1.x, p3.y - p1.y}, vt2 = {p4.x - p1.x, p4.y - p1.y};
	float s1v2, s2v2, t1v1, t2v1;
		if (Equal(s1v2 = vs1 ^ v2, 0) && p4 > p1 && p1 > p3)
	{
		Int = p1;
		return 2;
	}
	if (Equal(s2v2 = vs2 ^ v2, 0) && p4 > p2 && p2 > p3)
	{
		Int = p2;
		return 2;
	}
	if (Equal(t1v1 = vt1 ^ v1, 0) && p2 > p3 && p3 > p1)
	{
		Int = p3;
		return 2;
	}
	if (Equal(t2v1 = vt2 ^ v1, 0) && p2 > p4 && p4 > p1)
	{
		Int = p4;
		return 2;
	}	if (s1v2 * s2v2 > 0 || t1v1 * t2v1 > 0)
	{
		return 0;
	}		float ConA = p1.x * v1.y - p1.y * v1.x;
	float ConB = p3.x * v2.y - p3.y * v2.x;
		Int.x = (ConB * v1.x - ConA * v2.x) / Corss;
	Int.y = (ConB * v1.y - ConA * v2.y) / Corss;
		return 1;
}

bool CompareVector(const POINTF &pt1, const POINTF &pt2)
{
		float m1 = sqrt(pt1.x * pt1.x + pt1.y * pt1.y);
	float m2 = sqrt(pt2.x * pt2.x + pt2.y * pt2.y);
		float v1 = pt1.x / m1, v2 = pt2.x / m2;
		return (v1 < v2 || v1 == v2 && m1 < m2);
}

bool CalcConvexHull(vector<POINTF> &Src)
{
		if (Src.size() < 3)
	{
		return false;
	}
		vector<POINTF>::iterator i;
	POINTF ptBase = Src.front();	for (i = Src.begin() + 1; i != Src.end(); ++i)
	{
				if (i->y < ptBase.y || (i->y == ptBase.y && i->x > ptBase.x))
		{
						ptBase = *i;
		}
	}
		for (i = Src.begin(); i != Src.end();)
	{
				if (*i == ptBase)
		{
			i = Src.erase(i);
		}
		else
		{
						i->x -= ptBase.x, i->y -= ptBase.y;
			++i;
		}
	}
		sort(Src.begin(), Src.end(), &CompareVector);
		Src.erase(unique(Src.begin(), Src.end()), Src.end());
		if (Src.size() < 2)
	{
		return false;
	}
		for (vector<POINTF>::reverse_iterator ri = Src.rbegin();
			 ri != Src.rend() - 1; ++ri)
	{
		vector<POINTF>::reverse_iterator riNext = ri + 1;
				ri->x -= riNext->x, ri->y -= riNext->y;
	}
		for (i = Src.begin() + 1; i != Src.end(); ++i)
	{
				for (vector<POINTF>::iterator iLast = i - 1; iLast != Src.begin();)
		{
			float v1 = i->x * iLast->y, v2 = i->y * iLast->x;
									if (v1 > v2 || (v1 == v2 && i->x * iLast->x > 0 &&
											i->y * iLast->y > 0))
			{
				break;
			}
									i->x += iLast->x, i->y += iLast->y;
			iLast = (i = Src.erase(iLast)) - 1;
		}
	}
		Src.front().x += ptBase.x, Src.front().y += ptBase.y;
	for (i = Src.begin() + 1; i != Src.end(); ++i)
	{
		i->x += (i - 1)->x, i->y += (i - 1)->y;
	}
		Src.push_back(ptBase);
	return (Src.size() >= 3);
}

float CalcArea(vector<POINTF> &Covex)
{
	float fArea = 0;
	vector<POINTF>::iterator i, j;
		for (i = Covex.begin(); i != Covex.end(); ++i)
	{
				if ((j = i + 1) == Covex.end())
		{
			j = Covex.begin();
		}
				fArea += j->x * i->y - i->x * j->y;
	}
	return fArea / 2.0f;
}

bool PointInPolygon(POINTF pt, vector<POINTF> &Poly)
{
		for (int i = 0; i < (int)Poly.size(); ++i)
	{
				int j = (i + 1) % (int)Poly.size();
				POINTF p1 = {pt.x - Poly[i].x, pt.y - Poly[i].y};
				POINTF p2 = {Poly[j].x - Poly[i].x, Poly[j].y - Poly[i].y};
				float fCross = p1 ^ p2;
		if (fCross < 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<float> Result;
		for (int nNum; cin >> nNum && nNum != 0; ++nNum)
	{
		vector<POINTF> Poly1, Poly2;
		for (POINTF pt; nNum-- > 0 && cin >> pt.x >> pt.y; Poly1.push_back(pt))
			;
		cin >> nNum;
		for (POINTF pt; nNum-- > 0 && cin >> pt.x >> pt.y; Poly2.push_back(pt))
			;
				unique(Poly1.begin(), Poly1.end());
		unique(Poly2.begin(), Poly2.end());
		if (Poly1.size() < 3 || Poly2.size() < 3)
		{
			printf("%8.2f", 0.0f);
		}
				float fAreaUnion = CalcArea(Poly1);
		fAreaUnion += CalcArea(Poly2);
		vector<POINTF> IntPoly;
				for (int i = 0; i < (int)Poly1.size(); ++i)
		{
			if (PointInPolygon(Poly1[i], Poly2))
			{
				IntPoly.push_back(Poly1[i]);
			}
		}
				for (int i = 0; i < (int)Poly2.size(); ++i)
		{
			if (PointInPolygon(Poly2[i], Poly1))
			{
				IntPoly.push_back(Poly2[i]);
			}
		}
				for (int i = 0; i < (int)Poly1.size(); ++i)
		{
			for (int j = 0; j < (int)Poly2.size(); ++j)
			{
				POINTF Int;
				int nr = Intersection(
						Poly1[i], Poly1[(i + 1) % (int)Poly1.size()],
						Poly2[j], Poly2[(j + 1) % (int)Poly2.size()], Int);
				if (nr == 6)
				{
					IntPoly.push_back(Poly1[i]);
					IntPoly.push_back(Poly1[(i + 1) % (int)Poly1.size()]);
				}
				else if (nr > 0)
				{
					IntPoly.push_back(Int);
				}
			}
		}
				float fIntArea = CalcConvexHull(IntPoly) ? CalcArea(IntPoly) * 2 : 0;
				Result.push_back(fAreaUnion - fIntArea);
	}
		for (vector<float>::iterator i = Result.begin(); i != Result.end(); ++i)
	{
		printf("%8.2f", *i);
	}
	cout << endl;
	return 0;
}
