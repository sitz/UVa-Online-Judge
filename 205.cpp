#include <bits/stdc++.h>

using namespace std;

/*
 * 205 getting there.cpp
 *
 *  Created on: Apr 22, 2010
 *      Author: 122513
 */

int timebetween(int starttime, int endtime)
{
	return (starttime <= endtime) ? endtime - starttime : 1440 - starttime + endtime;
}

int timeminutes(int hour, char ap, int minutes)
{
	return hour * 60 + ((ap == 'P') ? 720 : 0) + minutes;
}

char *initcap(char *p)
{
	p[0] = toupper(p[0]);
	for (int i = 1; p[i]; ++i)
	{
		p[i] = tolower(p[i]);
	}
	return p;
}

struct info
{
	int starttime, endtime, totaltime, to;
	double cost;

	info(int starttime, int endtime, double cost, int to) : starttime(starttime), endtime(endtime), to(to), cost(cost)

	{
		totaltime = timebetween(starttime, endtime);
	}
};

//Variables globales
int mintime, maxto;
double mincost;

vector<info> minroute;
map<int, vector<info>> cities;
int ntravel, ncity, citya, cityb, cases = 0;
char buffer[200];
string stringtmp, stringtmp2;

map<string, int> citiestoint;
map<int, string> inttocities;

//mode : 0 = cost, 1 = time
void minimize(int starttime, int to, vector<bool> used, int totaltime,
							double totalcost, vector<info> routes, bool mode)
{
	int tmptotaltime;
	double tmptotalcost;
	used[to] = 1;
	vector<info> from = cities[to];
	vector<info> tmproutes;
	if (to == maxto)
	{
		if (routes.size() < minroute.size() && (fabs(totalcost - mincost) < 1e-9 && totaltime == mintime))
		{
			mintime = totaltime;
			mincost = totalcost;
			minroute = routes;
		}
		else if (mode)
		{
			if (totaltime < mintime || (totaltime == mintime && totalcost < mincost))
			{
				mintime = totaltime;
				mincost = totalcost;
				minroute = routes;
			}
		}
		else if (totalcost < mincost || (fabs(totalcost - mincost) < 1e-9 && totaltime < mintime))
		{
			mintime = totaltime;
			mincost = totalcost;
			minroute = routes;
		}
		return;
	}
	for (unsigned int i = 0; i < from.size(); i++)
	{
		if (!used[from[i].to])
		{
			tmptotaltime = totaltime + timebetween(starttime, from[i].starttime) + from[i].totaltime;
			tmptotalcost = totalcost + from[i].cost;
			tmproutes = routes;
			tmproutes.push_back(from[i]);
			if (mode)
			{
				if (tmptotaltime <= mintime)
				{
					minimize(from[i].endtime, from[i].to, used, tmptotaltime,
									 tmptotalcost, tmproutes, mode);
				}
			}
			else
			{
				if (tmptotalcost < mincost || fabs(tmptotalcost - mincost) < 1e-9)
				{
					minimize(from[i].endtime, from[i].to, used, tmptotaltime,
									 tmptotalcost, tmproutes, mode);
				}
			}
		}
	}
}

bool readandstore()
{
	int r;
	//lectura
	r = scanf("%17s", buffer);
	if (buffer[0] == '#')
	{
		return 0;
	}
	initcap(buffer);
	stringtmp = string(buffer);
	if (citiestoint.count(stringtmp) == 0)
	{
		inttocities[ncity] = stringtmp;
		citiestoint[stringtmp] = ncity++;
	}
	citya = citiestoint[stringtmp];
	r = scanf("%16s", buffer);
	initcap(buffer);
	stringtmp = string(buffer);
	if (citiestoint.count(stringtmp) == 0)
	{
		inttocities[ncity] = stringtmp;
		citiestoint[stringtmp] = ncity++;
	}
	cityb = citiestoint[stringtmp];
	//Horarios
	int h0, h1, m0, m1;
	char ctmp, ap0, ap1;
	double cost;
	r = scanf("%d%c%d%c%d%c%d%c%lf", &h0, &ctmp, &m0, &ap0, &h1, &ctmp, &m1, &ap1,
						&cost);
	cities[citya].push_back(info(timeminutes(h0, ap0, m0), timeminutes(h1, ap1,
																																		 m1),
															 cost, cityb));
	return 1;
}

int main(int argc, char **argv)
{
	int r;
	//cout << "leido" << endl;
	while (scanf("%s %d", buffer, &ntravel) != EOF)
	{
		//cout << "leido" << endl;
		citiestoint.clear();
		cities.clear();
		inttocities.clear();
		ncity = 1;
		while (readandstore())
			;
		if (cases++)
		{
			printf("\n\n");
		}
		printf("Requests and optimal routes for travel %d\n", ntravel);
		printf("------------------------------------------\n");
		//Leer todos los request
		while (1)
		{
			r = scanf("%s", buffer);
			if (buffer[0] == '#')
			{
				break;
			}
			initcap(buffer);
			stringtmp = string(buffer);
			citya = citiestoint[stringtmp];
			r = scanf("%s", buffer);
			initcap(buffer);
			stringtmp2 = string(buffer);
			cityb = citiestoint[stringtmp2];
			//modo
			r = scanf("%s", buffer);
			if (stringtmp == stringtmp2)
			{
				printf("\nYou are already in %s.\n", stringtmp.c_str());
			}
			else if (citya == 0 || cityb == 0)
			{
				printf("\nThere is no route from %s to %s.\n",
							 stringtmp.c_str(), stringtmp2.c_str());
			}
			else
			{
				mintime = 1000000;
				mincost = 1000000;
				minroute.clear();
				maxto = cityb;
				vector<bool> used(ncity, 0);
				used[citya] = 1;
				vector<info> tmproutes = cities[citya];
				for (unsigned int i = 0; i < tmproutes.size(); ++i)
				{
					minimize(tmproutes[i].endtime, tmproutes[i].to, used,
									 tmproutes[i].totaltime, tmproutes[i].cost,
									 vector<info>(1, tmproutes[i]), buffer[0] == 'T');
				}
				//Imprimir resultado
				if (!minroute.size())
				{
					printf("\nThere is no route from %s to %s.\n",
								 stringtmp.c_str(), stringtmp2.c_str());
				}
				else
				{
					printf("\nFrom: %-20s To: %-20s",
								 inttocities[citya].c_str(),
								 inttocities[cityb].c_str());
					printf(" Optimize: %s\n", (buffer[0] == 'T') ? "Time"
																											 : "Cost");
					printf(
							"==================================================================\n");
					printf(
							"From                To                     Leave   Arrive     Cost\n");
					printf(
							"==================================================================\n");
					for (unsigned int i = 0; i < minroute.size(); i++)
					{
						//Imprimir from to
						printf("%-20s%-23s", inttocities[citya].c_str(),
									 inttocities[minroute[i].to].c_str());
						sprintf(buffer, "%d:%02d%c", (minroute[i].starttime / 60) % 12, minroute[i].starttime % 60,
										((minroute[i].starttime / 60) % 24 >= 12) ? 'P' : 'A');
						printf("%-8s", buffer);
						sprintf(buffer, "%d:%02d%c", (minroute[i].endtime / 60) % 12, minroute[i].endtime % 60,
										((minroute[i].endtime / 60) % 24 >= 12) ? 'P' : 'A');
						printf("%-6s", buffer);
						sprintf(buffer, "$%.2f", minroute[i].cost);
						printf("%9s\n", buffer);
						citya = minroute[i].to;
					}
					printf(
							"                                           -----------------------\n");
					string duracion;
					if (mintime >= 2880)
					{
						sprintf(buffer, "%d days ", mintime / 1440);
						duracion += buffer;
					}
					else if (mintime >= 1440)
					{
						sprintf(buffer, "%d day ", mintime / 1440);
						duracion += buffer;
					}
					sprintf(buffer, "%d:%02d", (mintime % 1440) / 60, mintime % 60);
					duracion += buffer;
					/*}*/
					printf("%57s", duracion.c_str());
					sprintf(buffer, "$%.2f", mincost);
					printf("%9s\n", buffer);
				}
			}
		}
	}
	return 0;
}
