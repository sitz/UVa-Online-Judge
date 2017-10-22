#include <bits/stdc++.h>

using namespace std;

typedef double dou;

const dou eps = 1e-7;
const dou pi = acos(-1);

int sgn(dou k)
{
	return (k > eps) - (k < -eps);
}

typedef struct
{
	dou x, y, z;
} dot;
dot operator*(dou k, dot a)
{
	return (dot){
			k * a.x, k * a.y, k * a.z};
}
dot operator-(dot a, dot b)
{
	return (dot){
			a.x - b.x, a.y - b.y, a.z - b.z};
}
dot operator+(dot a, dot b)
{
	return (dot){
			a.x + b.x, a.y + b.y, a.z + b.z};
}

dou operator%(dot a, dot b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
dou dis(dot a)
{
	return sqrt(a % a);
}

dot getd(int a, int b)
{
	dou ts = sin(b * 2 * pi / 360);
	return (dot){
			cos(a * 2 * pi / 360) * ts, sin(a * 2 * pi / 360) * ts, cos(b * 2 * pi / 360)};
}

dot jiao(dot d)
{
	dot p = (dot){
			(dou)(sgn(d.x) >= 0 ? 1 : -1), (dou)(sgn(d.y) >= 0 ? 1 : -1), (dou)(sgn(d.z) >= 0 ? 1 : -1)};
	// printf("%f %f %f\n",p.x,p.y,p.z);
	// printf("%f %f %f\n",d.x,d.y,d.z);
	// t1(d)%p==1
	// t1(d%p)==1
	dou t1 = 1 / (d % p);
	return t1 * d;
}

dot rotate(dot d, int a)
{
	dou s = sin(a * 2 * pi / 360);
	dou c = cos(a * 2 * pi / 360);
	return (dot){
			d.x * c - d.y * s, d.x * s + d.y * c};
}
// 1/sqrt(2)^2+1/2^2=1/2+1/4=3/4
// sqrt(3)/2
void produce(vector<dot> &s, dot a)
{
	// fprintf(stderr,"%f %f %f\n",a.x,a.y,a.z);
	int dir = 0;
	if (sgn(a.z) < 0)
	{
		dir += 4;
		a.z *= -1;
	}

	int cnt = 0;
	for (; sgn(a.x) < 0 || sgn(a.y) < 0;)
	{
		swap(a.x, a.y);
		a.x = -a.x;
		cnt++;
	}
	// fprintf(stderr,"cnt=%d\n",cnt);
	if (cnt == 0)
	{
		dir += 0;
	}
	if (cnt == 1)
	{
		dir += 2;
	}
	if (cnt == 2)
	{
		dir += 3;
	}
	if (cnt == 3)
	{
		dir += 1;
	}
	assert(cnt < 4);

	dou A = dis(a - (dot){
											1, 0, 0});
	dou C = dis(a - (dot){
											0, 1, 0});
	dou B = sqrt(2);
	dou D = sgn(A) ? (A * A + B * B - C * C) / 2 / A / B : 1;
	if (D > 1)
	{
		D = 1;
	}
	if (D < -1)
	{
		D = -1;
	}
	dou theta = acos(D);
	dot O = (dot){
			1.0 / sqrt(2), 1.0 / sqrt(6), 0};
	dot X = (dot){
							A * cos(theta), A * sin(theta), 0} -
					O;
	if (dir & 4)
	{
		X.x = -X.x;
	}
	// fprintf(stderr,"X=(%f,%f)\n",X.x,X.y);
	/*
	fprintf(stderr,"A=%f B=%f C=%f theta=%f\n",A,B,C,theta);
	fprintf(stderr,"dir=%d\n",dir);
	*/
	s.clear();
	if (dir == 0)
	{
		s.push_back(X);
	}

	else if (dir == 1)
	{
		s.push_back(rotate(X, +60) + (2 / sqrt(6)) * getd(+30, 90));
	}
	else if (dir == 2)
	{
		s.push_back(rotate(X, 300) + (2 / sqrt(6)) * getd(150, 90));
	}
	else if (dir == 4)
	{
		s.push_back(rotate(X, 180) + (2 / sqrt(6)) * getd(270, 90));
	}

	else if (dir == 3)
	{
		s.push_back(rotate(X, 120) + sqrt(2) * getd(+60, 90));
		s.push_back(rotate(X, 240) + sqrt(2) * getd(120, 90));
	}
	else if (dir == 6)
	{
		s.push_back(rotate(X, 120) + sqrt(2) * getd(180, 90));
		s.push_back(rotate(X, 240) + sqrt(2) * getd(240, 90));
	}
	else if (dir == 5)
	{
		s.push_back(rotate(X, 120) + sqrt(2) * getd(300, 90));
		s.push_back(rotate(X, 240) + sqrt(2) * getd(0 + 0, 90));
	}

	else if (dir == 7)
	{
		s.push_back(rotate(X, 180) + (4 / sqrt(6)) * getd(30, 90) + (2 / sqrt(6)) * getd(330, 90));
		s.push_back(rotate(X, 300) + (4 / sqrt(6)) * getd(30, 90) + (2 / sqrt(6)) * getd(90, 90));

		s.push_back(rotate(X, 60) + (4 / sqrt(6)) * getd(150, 90) + (2 / sqrt(6)) * getd(90, 90));
		s.push_back(rotate(X, 180) + (4 / sqrt(6)) * getd(150, 90) + (2 / sqrt(6)) * getd(210, 90));

		s.push_back(rotate(X, 300) + (4 / sqrt(6)) * getd(270, 90) + (2 / sqrt(6)) * getd(210, 90));
		s.push_back(rotate(X, 60) + (4 / sqrt(6)) * getd(270, 90) + (2 / sqrt(6)) * getd(330, 90));

	}
}

void remap(int &a, int &c)
{
	for (; a >= 90;)
	{
		a = (a + 90) % 360;
		c = (c + 90) % 360;
	}
}

int a, b, c, d;
vector<dot> as, bs;
dou sol(int uuu)
{
	assert(0 <= a && a < 360);
	assert(0 <= b && b <= 180);
	assert(0 <= c && c < 360);
	assert(0 <= d && d <= 180);
	remap(a, c);
	if (b > 90 || (b == 90 && d > 90))
	{
		b = 180 - b;
		d = 180 - d;
	}
	// fprintf(stderr,"%d %d %d %d\n",a,b,c,d);
	assert(0 <= a && a < 90);
	assert(0 <= b && b <= 90);
	produce(as, jiao(getd(a, b)));
	produce(bs, jiao(getd(c, d)));
	dou ans = 7122;
	/*
	for(int i=0;i<(int)as.size();i++){
		printf("(%f %f)",as[i].x,as[i].y);
	}puts("");
	for(int j=0;j<(int)bs.size();j++){
		printf("(%f %f)",bs[j].x,bs[j].y);
	}puts("");
	*/
	for (int i = 0; i < (int)as.size(); i++)
	{
		for (int j = 0; j < (int)bs.size(); j++)
		{
			ans = min(ans, dis(as[i] - bs[j]));
		}
	}
	assert(sgn(ans - 7122));
	return ans;
}

int check = 1;
char s[100];

int main()
{
	int t = 1;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF && (a + 1))
	{
		printf("Case %d: %.3f\n", t++, sol(t) / sqrt(2) * 10.0);
	}
	return 0;
}
