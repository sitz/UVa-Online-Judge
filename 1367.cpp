#include <bits/stdc++.h>

using namespace std;

// LA3532/UVa1367 Nuclear Plants
// Rujia Liu

const double eps = 5 * 1e-13;
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	else
	{
		return x < 0 ? -1 : 1;
	}
}

const double PI = acos(-1);
const double TWO_PI = PI * 2;

double NormalizeAngle(double rad, double center = PI)
{
	return rad - TWO_PI * floor((rad + PI - center) / TWO_PI);
}

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator+(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator-(Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator*(Vector A, double p)
{
	return Vector(A.x * p, A.y * p);
}
Vector operator/(Vector A, double p)
{
	return Vector(A.x / p, A.y / p);
}

// çè®ºä¸è¿ä¸ªâå°äºâè¿ç®ç¬¦æ¯éçï¼å ä¸ºå¯è½æä¸ä¸ªç¹a, b, c, aåbå¾æ¥è¿ï¼å³a<bå¥½b<aé½ä¸æç«ï¼ï¼båcå¾æ¥è¿ï¼ä½aåcä¸æ¥è¿
// æä»¥ä½¿ç¨è¿ç§âå°äºâè¿ç®ç¬¦çåææ¯è½æé¤ä¸è¿°æåµ
bool operator<(const Point &a, const Point &b)
{
	return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}

bool operator==(Point A, Point B)
{
	return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}

double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}
double Length(Vector A)
{
	return sqrt(Dot(A, A));
}
double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}

double angle(Vector v)
{
	return atan2(v.y, v.x);
}

bool OnSegment(const Point &p, const Point &a1, const Point &a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

// äº¤ç¹ç¸å¯¹äºå1çæè§ä¿å­å¨radä¸­
void getCircleCircleIntersection(Point c1, double r1, Point c2, double r2, vector<double> &rad)
{
	double d = Length(c1 - c2);
	if (dcmp(d) == 0)
	{
		return;// ä¸ç®¡æ¯åå«è¿æ¯éåï¼é½ä¸ç¸äº¤
	}
	if (dcmp(r1 + r2 - d) < 0)
	{
		return;
	}
	if (dcmp(fabs(r1 - r2) - d) > 0)
	{
		return;
	}
	double a = angle(c2 - c1);
	double da = acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
	rad.push_back(NormalizeAngle(a - da));
	rad.push_back(NormalizeAngle(a + da));
}

Point GetLineProjection(Point P, Point A, Point B)
{
	Vector v = B - A;
	return A + v * (Dot(v, P - A) / Dot(v, v));
}

// ç´çº¿ABååå¿ä¸ºCï¼åå¾ä¸ºrçåçäº¤ç¹ãç¸å¯¹äºåçæè§ä¿å­å¨radä¸­
void getLineCircleIntersection(Point A, Point B, Point C, double r, vector<double> &rad)
{
	Point p = GetLineProjection(C, A, B);
	double a = angle(p - C);
	double d = Length(p - C);
	if (dcmp(d - r) > 0)
	{
		return;
	}
	if (dcmp(d) == 0)// è¿åå¿
	{
		rad.push_back(NormalizeAngle(angle(A - B)));
		rad.push_back(NormalizeAngle(angle(B - A)));
	}
	double da = acos(d / r);
}

/////////// é¢ç®ç¸å³
const int maxn = 200 + 5;
int n, N, M;// næ¯åçæ»æ°ï¼NåMæ¯åºå°é¿å®½
Point P[maxn];
double R[maxn];

// åånoå¼§åº¦ä¸ºradçç¹
Point getPoint(int no, double rad)
{
	return Point(P[no].x + cos(rad) * R[no], P[no].y + sin(rad) * R[no]);
}

// ç¬¬noä¸ªåå¼§åº¦ä¸ºradçç¹æ¯å¦å¯è§ãç¸åçååªæç¼å·æå°çå¯è§ï¼è½ç¶å¯¹äºæ¬é¢æ¥è¯´ä¸å¿è¦ï¼
bool visible(int no, double rad)
{
	Point p = getPoint(no, rad);
	if (p.x < 0 || p.y < 0 || p.x > N || p.y > M)
	{
		return false;
	}
	for (int i = 0; i < n; i++)
	{
		if (P[no] == P[i] && dcmp(R[no] - R[i]) == 0 && i < no)
		{
			return false;
		}
		if (dcmp(Length(p - P[i]) - R[i]) < 0)
		{
			return false;
		}
	}
	return true;
}

// åºå°è¾¹çä¸çç¹pæ¯å¦å¯è§
bool visible(Point p)
{
	for (int i = 0; i < n; i++)
	{
		if (dcmp(Length(p - P[i]) - R[i]) <= 0)
		{
			return false;
		}
	}
	return true;
}

// æ±åçå¹¶å¨(0,0)-(N,M)åçé¢ç§¯
// ä½¿ç¨ä¸è¬æ²è¾¹å¾å½¢çé¢ç§¯ç®æ³ãä¸æä¸­ï¼âææ±å¾å½¢âæçæ¯ä¸è½ç§èçåºåï¼å®çè¾¹çç±åå¼§åç´çº¿æ®µææã
// ç®æ³ï¼å¯¹äºææ±å¾å½¢è¾¹çä¸çæ¯ä¸æ®µï¼å¯ä»¥æ¯æ²çº¿ï¼a~>bï¼ç´¯å Cross(a, b)åå®å¨ç´çº¿æ®µa->bå³è¾¹é¨åçé¢ç§¯ï¼å·¦è¾¹é¨åç®è´ï¼
// è¾¹çè®¡ç®ï¼
// 1. æ¯ä¸ªåè¢«å¶ä»åååºå°è¾¹çåæäºè¥å¹²æ¡åå¼§ï¼ä¸­ç¹ä¸è¢«å¶ä»åè¦çä¸å¨åºå°åçåå¼§å¨ææ±å¾å½¢è¾¹çä¸
// 2. åºå°çåæ¡è¾¹çè¢«ååæäºè¥å¹²æ¡çº¿æ®µãä¸­ç¹å¨æä¸ªååé¨ççº¿æ®µå¨ææ±å¾å½¢è¾¹çä¸
double getArea()
{
	Point b[4];
	b[0] = Point(0, 0);
	b[1] = Point(N, 0);
	b[2] = Point(N, M);
	b[3] = Point(0, M);
	double area = 0;
	// åå¼§é¨å
	for (int i = 0; i < n; i++)
	{
		vector<double> rad;
		rad.push_back(0);
		rad.push_back(PI * 2);
		// ååè¾¹ççäº¤ç¹
		for (int j = 0; j < 4; j++)
		{
			getLineCircleIntersection(b[j], b[(j + 1) % 4], P[i], R[i], rad);
		}
		// åååçäº¤ç¹
		for (int j = 0; j < n; j++)
		{
			getCircleCircleIntersection(P[i], R[i], P[j], R[j], rad);
		}
		sort(rad.begin(), rad.end());
		for (int j = 0; j < rad.size() - 1; j++)
			if (rad[j + 1] - rad[j] > eps)
			{
				double mid = (rad[j] + rad[j + 1]) / 2.0;// åå¼§ä¸­ç¹ç¸å¯¹äºåiåå¿çæè§
				if (visible(i, mid))										 // å¼§ä¸­ç¹å¯è§ï¼å æ­¤å¼§å¨å¾å½¢è¾¹çä¸
				{
					area += Cross(getPoint(i, rad[j]), getPoint(i, rad[j + 1])) / 2.0;
					double a = rad[j + 1] - rad[j];
					area += R[i] * R[i] * (a - sin(a)) / 2.0;
				}
			}
	}
	// ç´çº¿æ®µé¨å
	for (int i = 0; i < 4; i++)
	{
		Vector v = b[(i + 1) % 4] - b[i];
		double len = Length(v);
		vector<double> dist;
		dist.push_back(0);
		dist.push_back(len);
		for (int j = 0; j < n; j++)
		{
			vector<double> rad;
			getLineCircleIntersection(b[i], b[(i + 1) % 4], P[j], R[j], rad);
			for (int k = 0; k < rad.size(); k++)
			{
				Point p = getPoint(j, rad[k]);
				dist.push_back(Length(p - b[i]));
			}
		}
		sort(dist.begin(), dist.end());// å¿é¡»æç§å°èµ·ç¹çè·ç¦»æåºèä¸æ¯æç§ç¹çå­å¸åºæåºï¼å¦ååéæ¹åå¯è½ä¼å
		vector<Point> points;
		for (int j = 0; j < dist.size(); j++)
		{
			points.push_back(b[i] + v * (dist[j] / len));
		}
		for (int j = 0; j < dist.size() - 1; j++)
		{
			Point midp = (points[j] + points[j + 1]) / 2.0;
			if (!visible(midp))
			{
				area += Cross(points[j], points[j + 1]) / 2.0;// çº¿æ®µä¸­ç¹ä¸å¯è§ï¼å æ­¤çº¿æ®µå¨å¾å½¢è¾¹çä¸
			}
		}
	}
	return N * M - area;
}

int main()
{
	int ks, kl;
	while (scanf("%d%d%d%d", &N, &M, &ks, &kl) == 4 && N && M)
	{
		for (int i = 0; i < ks; i++)
		{
			scanf("%lf%lf", &P[i].x, &P[i].y);
			R[i] = 0.58;
		}
		sort(P, P + ks);
		ks = unique(P, P + ks) - P;
		for (int i = 0; i < kl; i++)
		{
			scanf("%lf%lf", &P[ks + i].x, &P[ks + i].y);
			R[ks + i] = 1.31;
		}
		sort(P + ks, P + ks + kl);
		n = unique(P + ks, P + ks + kl) - P;
		printf("%.2lf\n", getArea());
	}
	return 0;
}
