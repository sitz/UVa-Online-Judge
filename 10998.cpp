#include <bits/stdc++.h>

using namespace std;

double h, v, H, V;
int n, kase = 1;

const double ZERO = 1e-10;

void solve(double x1, double y1, double x2, double y2, double qx, double qy, int level)
{
	//  cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	//  cout<<"level = "<<level<<"   "<<qx<<"  "<<qy<<endl;
	double mx, my;
	mx = x1 + (x2 - x1) * h;
	my = y1 + (y2 - y1) * v;
	if ((x1 < qx && qx < mx && my < qy && qy < y2) || (mx < qx && qx < x2 && y1 < qy && qy < my))
	{
		if (level % 2 == 0)
		{
			cout << "black" << endl;
		}
		else
		{
			cout << "white" << endl;
		}
		return;
	}
	if (x1 < qx && qx < mx && y1 < qy && qy < my)//left down
	{
		qx = qx - x1;
		qy = qy - y1;
		solve(x1, y1, mx, my, qx, qy, level + 1);
	}
	if (mx < qx && qx < x2 && my < qy && qy < y2)//right up
	{
		qx = qx - mx;
		qy = qy - my;
		solve(0, 0, x2 - mx, y2 - my, qx, qy, level + 1);
	}
}

int main()
{
	while (cin >> H >> V >> h >> v)
	{
		if (fabs(H) < ZERO || fabs(V) < ZERO || fabs(h) < ZERO || fabs(v) < ZERO)
		{
			break;
		}
		cout << "Case " << kase++ << ":" << endl;
		cin >> n;
		while (n--)
		{
			double x, y;
			cin >> x >> y;
			solve(0, 0, H, V, x, y, 0);
		}
	}
	return 0;
}
