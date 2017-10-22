#include <bits/stdc++.h>

using namespace std;

struct ss
{
	int x, y, z;
	double dis;
	double fuel;
	double time;
};
queue<ss> Q;
vector<ss> v;
char visited[25];
double fuel, brate, speed, tra, ttime, lf, home;
int node;

double Dis(ss t, ss d)
{
	double dis;
	dis = (t.x - d.x) * (t.x - d.x) + (t.y - d.y) * (t.y - d.y) + (t.z - d.z) * (t.z - d.z);
	dis = sqrt(dis);
	return dis;
}

double Get(ss tt, int visit)
{
	double dis, min;
	ss dum;
	int i, next;
	while (!Q.empty())
		Q.pop();
	Q.push(tt);
	while (!Q.empty())
	{
		tt = Q.front();
		Q.pop();
		min = 2E+15;
		for (i = 0; i < v.size(); i++)
		{
			if (visited[i] == 1)
				continue;
			dis = Dis(tt, v[i]);
			if (dis < min)
			{
				min = dis;
				next = i;
			}
		}
		visited[next] = 1;
		visit++;
		dum = v[next];
		dum.dis = tt.dis + min;
		if (visit == node)
		{
			home = dum.dis;
			return home;
		}
		Q.push(dum);
	}
	return dis;
}

int BFS()
{
	int i, next, cover = 0;
	double time, dis, min, rf;
	ss temp, dum;
	temp.x = 0;
	temp.y = 0;
	temp.z = 1;
	temp.dis = 0;
	temp.fuel = fuel;
	temp.time = 0;
	Q.push(temp);
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		min = 2e+15;
		for (i = 0; i < v.size(); i++)
		{
			if (visited[i] == 1)
				continue;
			dis = Dis(temp, v[i]);
			if (dis < min)
			{
				min = dis;
				next = i;
			}
		}
		time = min / speed;
		rf = time * brate;
		rf = temp.fuel - rf;
		if (rf < 0)
		{
			rf = temp.fuel / brate;
			tra = temp.dis + rf * speed;
			temp.dis -= tra;
			home = Get(temp, cover);
			return 0;
		}
		dum = v[next];
		dum.dis = temp.dis + min;
		dum.fuel = rf;
		dum.time = temp.time + time;
		visited[next] = 1;
		Q.push(dum);
		cover++;
		if (cover == node)
		{
			ttime = dum.time;
			tra = dum.dis;
			lf = dum.fuel;
			return 1;
		}
	}
	return 0;
}

void Cal(int f, int br, int sp)
{
	int d;
	fuel = f;
	brate = br;
	speed = sp;
	d = BFS();
	if (d)
	{
		printf("SUCCESS!! Time: %.2lf", ttime);
		printf("  Traveled: %.2lf  Fuel Left: %.2lf\n", tra, lf);
	}
	else
		printf("FAILURE!! Traveled: %.2lf  From Home: %.2lf\n", tra, home);
	while (!Q.empty())
		Q.pop();
}

void Free()
{
	v.clear();
	memset(visited, 0, 20);
}

int main()
{
	int f, br, sp, n, ms = 1;
	ss temp;
	while (scanf("%d%d%d%d", &f, &br, &sp, &node))
	{
		if (!f && !br && !sp && !node)
			break;
		n = node;
		while (n--)
		{
			scanf("%d%d%d", &temp.x, &temp.y, &temp.z);
			v.push_back(temp);
		}
		printf("Mission %d: ", ms++);
		Cal(f, br, sp);
		Free();
	}
	return 0;
}
