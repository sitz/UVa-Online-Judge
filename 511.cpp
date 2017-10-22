#include <bits/stdc++.h>

using namespace std;

struct A
{
	string name;
	double mianji;
	double zhong;
	double bili;
	double xiawei;
	double minx;
};
struct cmp
{
	bool operator()(const A &a, const A &b)
	{
		if (a.mianji != b.mianji)
		{
			return a.mianji < b.mianji;
		}
		else if (a.zhong != b.zhong)
		{
			return a.zhong > b.zhong;
		}
		else if (a.bili != b.bili)
		{
			return a.bili > b.bili;
		}
		else if (a.mianji != b.xiawei)
		{
			return a.xiawei < b.xiawei;
		}
		else
		{
			return a.minx > b.minx;
		}
	}
};
struct B
{
	string name1;
	double x1, x2, y1, y2, bili1, minaji1;
};
int main()
{
	string s;
	int lenl = 0, i, j, l, f = 0;
	double xx1, xx2, yy1, yy2;
	vector<B> maps;
	map<string, int> names;
	vector<A> zhao[10000];
	while (cin >> s)
	{
		if (s == "MAPS")
		{
			f = 1;
		}
		else if (s == "LOCATIONS")
		{
			f = 2;
		}
		else if (s == "REQUESTS")
		{
			f = 3;
		}
		else if (s == "END")
		{
			break;
		}
		else
		{
			if (f == 1)
			{
				cin >> xx1 >> yy1 >> xx2 >> yy2;
				double xxx1 = fabs(xx1 - xx2), yyy1 = fabs(yy1 - yy2);
				B D;
				D.name1 = s;
				D.x1 = min(xx1, xx2);
				D.x2 = max(xx1, xx2);
				D.y1 = min(yy1, yy2);
				D.y2 = max(yy1, yy2);
				D.bili1 = fabs(0.75 - 1.0 * yyy1 / xxx1);
				D.minaji1 = xxx1 * yyy1;
				maps.push_back(D);
			}
			else if (f == 2)
			{
				lenl++;
				cin >> xx1 >> yy1;
				names[s] = lenl;
				priority_queue<A, vector<A>, cmp> pp;
				int lenn = maps.size(), lenn1 = 0;
				for (i = 0; i < lenn; i++)
				{
					if (xx1 >= maps[i].x1 && xx1 <= maps[i].x2 && yy1 >= maps[i].y1 && yy1 <= maps[i].y2)
					{
						A C;
						C.mianji = maps[i].minaji1;
						C.bili = maps[i].bili1;
						C.zhong = sqrt(((maps[i].x1 + maps[i].x2) / 2.0 - xx1) * ((maps[i].x1 + maps[i].x2) / 2.0 - xx1) + ((maps[i].y1 + maps[i].y2) / 2.0 - yy1) * ((maps[i].y1 + maps[i].y2) / 2.0 - yy1));
						C.xiawei = sqrt((maps[i].x2 - xx1) * (maps[i].x2 - xx1) + (maps[i].y1 - yy1) * (maps[i].y1 - yy1));
						C.minx = maps[i].x1;
						C.name = maps[i].name1;
						pp.push(C);
						//if(s=="SanFrancisco")cout<<pp.top().name<<endl;
					}
				}
				A temp;
				if (!pp.empty())
				{
					zhao[lenl].push_back(pp.top());
					temp = pp.top();//if(s=="SanFrancisco")cout<<pp.top().name<<"+"<<pp.top().mianji<<"+"<<pp.top().zhong<<endl;
					pp.pop();
				}
				while (!pp.empty())
				{
					A XX = pp.top();
					//if(s=="SanFrancisco")cout<<pp.top().name<<"+"<<pp.top().mianji<<"+"<<pp.top().zhong<<endl;
					if (XX.mianji != temp.mianji)
					{
						zhao[lenl].push_back(XX);
						temp = XX;
					}
					pp.pop();
				}
			}
			else if (f == 3)
			{
				cin >> l;
				int weizhi = names[s];
				int lenn = zhao[weizhi].size();
				cout << s;
				if (!weizhi)
				{
					printf(" at detail level %d unknown location\n", l);
				}
				else if (!lenn)
				{
					printf(" at detail level %d no map contains that location\n", l);
				}
				else if (lenn >= l)
				{
					printf(" at detail level %d using ", l), cout << zhao[weizhi][l - 1].name << endl;
				}
				else
				{
					printf(" at detail level %d no map at that detail level; using ", l), cout << zhao[weizhi][lenn - 1].name << endl;
				}
			}
		}
	}
}
