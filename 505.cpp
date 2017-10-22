#include <bits/stdc++.h>

using namespace std;

/*   @JUDGE_ID:   2905EH   505   C++  "long long int" */
//2002/4/16 a_q505.cpp ???????? terrible..
//2002/4/29 using long long int... <ACCEPTED>

/*
INPUT:
WED, 28 FEB 35 23:59:00 -2359
WED, 1 JAN 0004 00:00:00 +2359
WED, 1 JAN 0000 00:00:00 +0000

OUTPUT:
FRI, 02 MAR 1935 02:58:00 +0300
TUE, 31 DEC 0003 03:01:00 +0300
WED, 01 JAN 0000 03:00:00 +0300
*/

#define BIG_Type long long

char *weekStr[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
char *monStr[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL",
									"AUG", "SEP", "OCT", "NOV", "DEC"};
int NUM_DAYS[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};			// 0-based, for day-in-year
int LEAP_NUM_DAYS[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};// 0-based, for day-in-year

bool isLeap(int y)
{
	return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

BIG_Type yearTime(int yy)
{
	yy += 3;
	return (BIG_Type)yy * (BIG_Type)365 + yy / 4 - yy / 100 + yy / 400;
}

char line[1000];

int main()
{
	while (gets(line))
	{
		char *p = strtok(line, " \t:,");
		//      if (p==NULL) while(1); //debug..no
		int week;
		for (week = 0; strcmp(p, weekStr[week]) != 0; week++)
			;
		p = strtok(NULL, " \t:,");
		int day = atoi(p) - 1;
		p = strtok(NULL, " \t:,");
		int mon;
		for (mon = 0; strcmp(p, monStr[mon]) != 0; mon++)
			;
		p = strtok(NULL, " \t:,");
		int year = atoi(p);
		if (strlen(p) == 2)
		{
			year += 1900;
		}
		p = strtok(NULL, " \t:,");
		int hh = atoi(p);
		p = strtok(NULL, " \t:,");
		int mm = atoi(p);
		p = strtok(NULL, " \t:,");
		int ss = atoi(p);
		p = strtok(NULL, " \t:,");
		//compute nowTime, field=>time
		BIG_Type nowTime = yearTime(year);
		if (isLeap(year))
		{
			nowTime += LEAP_NUM_DAYS[mon] + day;
		}
		else
		{
			nowTime += NUM_DAYS[mon] + day;
		}
		BIG_Type tomorrowTime = (nowTime + 2) * 24 * 60;
		nowTime *= 24;
		nowTime += hh;
		nowTime *= 60;
		nowTime += mm;
		int zone;
		if (strcmp(p, "UT") == 0)
		{
			zone = 0;
		}
		else if (strcmp(p, "GMT") == 0)
		{
			zone = 0;
		}
		else if (strcmp(p, "EDT") == 0)
		{
			zone = -4 * 60;
		}
		else if (strcmp(p, "CDT") == 0)
		{
			zone = -5 * 60;
		}
		else if (strcmp(p, "MDT") == 0)
		{
			zone = -6 * 60;
		}
		else if (strcmp(p, "PDT") == 0)
		{
			zone = -7 * 60;
		}
		else
		{
			zone = atoi(p + 1);
			zone = (zone / 100) * 60 + zone % 100;
			if (*p == '-')
			{
				zone = -zone;
			}
		}
		zone = 3 * 60 - zone;//Moscow
		nowTime += zone;
		BIG_Type nowTime2 = nowTime;
		//compute field, time=>field
		int nowMM = nowTime % 60;
		nowTime /= 60;
		int nowHH = nowTime % 24;
		nowTime /= 24;
		int yyy = year - 1;
		BIG_Type yyyBegin = yearTime(yyy);
		BIG_Type yyyEnd = yyyBegin + 365 + isLeap(yyy);
		int nowYear = -1;
		//      printf("nowTime=%d\n",nowTime);
		//      printf("yyyBegin=%d\n",yyyBegin);
		//      printf("yyyEnd=%d\n",yyyEnd);
		if (yyyBegin <= nowTime && nowTime < yyyEnd)
		{
			nowYear = yyy;
		}
		else
		{
			yyy++;
			yyyBegin = yearTime(yyy);
			yyyEnd = yyyBegin + 365 + isLeap(yyy);
			//          printf("yyyBegin=%d\n",yyyBegin);
			//          printf("yyyEnd=%d\n",yyyEnd);
			if (yyyBegin <= nowTime && nowTime < yyyEnd)
			{
				nowYear = yyy;
			}
			else
			{
				yyy++;
				yyyBegin = yearTime(yyy);
				yyyEnd = yyyBegin + 365 + isLeap(yyy);
				//              printf("yyyBegin=%d\n",yyyBegin);
				if (yyyBegin <= nowTime && nowTime < yyyEnd)
				{
					nowYear = yyy;
				}
				//              else
				//              {
				//                  printf("!!\n");
				//                  while(1); //debug..impossible
				//              }
			}
		}
		int diff = nowTime - yyyBegin;
		int nowMon, nowDay;
		if (isLeap(nowYear))
		{
			for (nowMon = 11; nowMon >= 0; nowMon--)
				if (diff >= LEAP_NUM_DAYS[nowMon])
				{
					break;
				}
			nowDay = diff - LEAP_NUM_DAYS[nowMon];
		}
		else
		{
			for (nowMon = 11; nowMon >= 0; nowMon--)
				if (diff >= NUM_DAYS[nowMon])
				{
					break;
				}
			nowDay = diff - NUM_DAYS[nowMon];
		}
		//      printf("nowMon=%d,mon=%d\n",nowMon,mon);
		//      printf("week=%d,nowDay=%d,day=%d\n",week,nowDay,day);
		if (nowDay != day)
		{
			if (zone < 0)
			{
				if (--week < 0)
				{
					week += 7;
				}
			}
			else
			{
				if (nowTime2 >= tomorrowTime)
				{
					week++;
				}
				if (++week > 6)
				{
					week -= 7;
				}
			}
		}
		/*
		        if (zone<0 && nowDay!=day)
		        {
		            if (--week<0) week+=7;
		        }
		        else if (zone>0 && nowDay!=day)
		        {
		            if (++week>6) week-=7;
		        }
		*/
		//print..
		//      SUN, 03 DEC 1996 12:10:35 +0300
		printf("%s, %02d %s %04d %02d:%02d:%02d +0300\n",
					 weekStr[week], nowDay + 1, monStr[nowMon], nowYear,
					 nowHH, nowMM, ss);
	}
}
/*@END_OF_SOURCE_CODE*/
