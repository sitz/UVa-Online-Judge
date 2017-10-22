#include <bits/stdc++.h>

using namespace std;

//2003/8/8 a_q206.cpp
//2003/8/11 simple sort?!
//#include <cassert>

struct PointStruct
{
	char name[32];
	int x, y;
	double theta;
	bool operator<(const PointStruct &p) const
	{
		if (fabs(theta - p.theta) > 1e-7)
		{
			return theta < p.theta;
		}
		return x * x + y * y < p.x * p.x + p.y * p.y;
	}
	void computeTheta()
	{
		//assert(x!=0 || y!=0); //ok
		theta = double(y) / double(abs(x) + abs(y));
		if (x < 0)
		{
			theta = 2 - theta;
		}
		else if (y < 0)
		{
			theta = theta + 4;
		}
		//printf("[%.0f]\n",theta*90.0);
	}
};

PointStruct p[1024];
int n, m;

int main()
{
	int c = 0;
	char line[128];
	while (gets(line))
	{
		if (c++)
		{
			puts("***********************************");
		}
		puts(line);
		gets(line);
		n = atoi(strtok(line, " \t"));
		m = atoi(strtok(NULL, " \t"));
		printf("Number of Customers: %-10d Number of Routes: %d\n\n", m, n);
		//assert(n<1024 && m<1024); //ok
		//assert(m>=n); //ok
		for (int i = 0; i < m; i++)
		{
			gets(p[i].name);
			gets(line);
			p[i].x = atoi(strtok(line, " \t"));
			p[i].y = atoi(strtok(NULL, " \t"));
			p[i].computeTheta();
		}
		sort(p, p + m);
		/*
		for (int i=0; i<m; i++)
		    printf("[%s %.0f]\n",p[i].name,p[i].theta);
		*/
		int totalmin = 0;
		int now = 0;
		for (int i = 0; i < n; i++)
		{
			printf("Route ==> %d\n", i + 1);
			int nowx = 0, nowy = 0, len = 0;
			int j = (m - now) / (n - i);
			if ((m - now) % (n - i) != 0)
			{
				j++;
			}
			while (--j >= 0)
			{
				len += abs(p[now].x - nowx);
				len += abs(p[now].y - nowy);
				nowx = p[now].x;
				nowy = p[now].y;
				printf("Customer: %s\n", p[now].name);
				now++;
			}
			len += abs(nowx);
			len += abs(nowy);
			printf("Route Length ==> %d\n\n", len);
			totalmin += len;
		}
		printf("Total Route Length ==> %d\n", totalmin);
	}
}
