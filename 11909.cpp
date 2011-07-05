#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI  = acos(-1.0);
const double EPS = 1e-9;

int main(){
	//freopen("testI.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	double l, w, h, theta;
	while( scanf("%lf%lf%lf%lf", &l, &w, &h, &theta) != EOF ){
		double V;
		double p = l * tan(theta * PI / 180.0);
		if (p <= h)
			V = l * w * h - 0.5 * l * l * w * tan(theta * PI / 180.0);
		else
			V = 0.5 * h * h * w * tan((90.0 - theta) * PI / 180.0);
		printf("%.3lf mL\n", V);
	}
}
