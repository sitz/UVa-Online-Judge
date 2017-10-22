#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
const double earthRadius = 6371.01;

int numOfCase;

class Place
{
public:
	double latitude, longitude;
} from, to;

void input()
{
	double a, b, c, d, e, f;
	char x, y;
	cin >> a >> b >> c >> x >> d >> e >> f >> y;
	double temp;
	temp = a * 3600 + b * 60 + c;
	temp /= 3600;
	if (x == 'S')
	{
		temp = -temp;
	}
	from.latitude = temp;
	temp = d * 3600 + e * 60 + f;
	temp /= 3600;
	if (y == 'W')
	{
		temp = -temp;
	}
	from.longitude = temp;
	cin >> a >> b >> c >> x >> d >> e >> f >> y;
	temp = a * 3600 + b * 60 + c;
	temp /= 3600;
	if (x == 'S')
	{
		temp = -temp;
	}
	to.latitude = temp;
	temp = d * 3600 + e * 60 + f;
	temp /= 3600;
	if (y == 'W')
	{
		temp = -temp;
	}
	to.longitude = temp;
}

void solve()
{
	double p_lat, q_lat, cha, res;
	/*
	     p_lat=test[a].lat/180*pi;
	     q_lat=test[b].lat/180*pi;
	     cha=(test[a].lon-test[b].lon)/180*pi;
	     res=sin(p_lat)*sin(q_lat)+cos(p_lat)*cos(q_lat)*cos(cha);
	     res=acos(res)*R;
	     printf("%.0f km\n",res);
	*/
	p_lat = from.latitude / 180 * pi;
	q_lat = to.latitude / 180 * pi;
	cha = (from.longitude - to.longitude) / 180 * pi;
	res = sin(p_lat) * sin(q_lat) + cos(p_lat) * cos(q_lat) * cos(cha);
	res = acos(res) * earthRadius;
	printf("%.2lf\n", res);
}

int main()
{
	cin >> numOfCase;
	while (numOfCase--)
	{
		input();
		solve();
		//  cout<<from.latitude<<"  "<<from.longitude<<endl;
		//  cout<<to.latitude<<"  "<<to.longitude<<endl;
	}
	return 0;
}
