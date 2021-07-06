#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t;
	double xstart, ystart, xend, yend, xleft, ytop, xright, ybottom, k;
	cin >> n;
	for (t = 0; t < n; t++)
	{
		cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop >> xright >> ybottom;
		double ybigger, ysmaller, xbigger, xsmaller, tmp;
		if (ytop < ybottom)
		{
			tmp = ytop;
			ytop = ybottom;
			ybottom = tmp;
		}
		if (xright < xleft)
		{
			tmp = xright;
			xright = xleft;
			xleft = tmp;
		}
		ybigger = ystart > yend ? ystart : yend;
		ysmaller = ystart < yend ? ystart : yend;
		xbigger = xstart > xend ? xstart : xend;
		xsmaller = xstart < xend ? xstart : xend;
		if (xstart == xend && ystart == yend)//when it is an dot;
		{
			if (xstart == xleft && ystart <= ytop && ystart >= ybottom)
			{
				cout << 'T' << endl;
				continue;
			}
			if (xstart == xright && ystart <= ytop && ystart >= ybottom)
			{
				cout << 'T' << endl;
				continue;
			}
			if (ystart == ytop && xstart >= xleft && xstart <= xright)
			{
				cout << 'T' << endl;
				continue;
			}
			if (ystart == ybottom && xstart >= xleft && xstart <= xright)
			{
				cout << 'T' << endl;
				continue;
			}
			cout << 'F' << endl;
			continue;
		}
		if (xstart == xend && ystart != yend)//k==infinite
		{
			if (xstart >= xleft && xstart <= xright)
			{
				if (ybigger > ytop && ysmaller > ytop)
				{
					cout << 'F' << endl;
					continue;
				}
				if (ybigger < ybottom && ysmaller < ybottom)
				{
					cout << 'F' << endl;
					continue;
				}
			}
			cout << 'T' << endl;
			continue;
		}
		if (ystart == yend && xstart != xend)//k==0
		{
			if (ystart >= ybottom && ystart <= ytop)
			{
				if (xbigger > xright && xsmaller > xright)
				{
					cout << 'F' << endl;
					continue;
				}
				if (xbigger < xleft && xsmaller < xleft)
				{
					cout << 'F' << endl;
					continue;
				}
			}
			cout << 'T' << endl;
			continue;
		}
		if (xstart <= xright && xstart >= xleft && ystart <= ytop && ystart >= ybottom)
		{
			cout << 'T' << endl;
			continue;
		}
		if (xend <= xright && xend >= xleft && yend <= ytop && yend >= ybottom)
		{
			cout << 'T' << endl;
			continue;
		}
		//k>0&&k<infinite;
		k = (ystart - yend) / (xstart - xend);
		//line formula :
		tmp = k * (xleft - xstart) + ystart;
		if (tmp >= ybottom && tmp <= ytop && xsmaller <= xleft && xbigger >= xleft)
		{
			cout << 'T' << endl;
			continue;
		}
		tmp = k * (xright - xstart) + ystart;
		if (tmp >= ybottom && tmp <= ytop && xsmaller <= xright && xbigger >= xright)
		{
			cout << 'T' << endl;
			continue;
		}
		tmp = (ytop - ystart) / k + xstart;
		if (tmp >= xleft && tmp <= xright && ysmaller <= ytop && ybigger >= ytop)
		{
			cout << 'T' << endl;
			continue;
		}
		tmp = (ybottom - ystart) / k + xstart;
		if (tmp >= xleft && tmp <= xright && ysmaller <= ybottom && ybigger >= ybottom)
		{
			cout << 'T' << endl;
			continue;
		}
		cout << 'F' << endl;
	}
	return 0;
}
