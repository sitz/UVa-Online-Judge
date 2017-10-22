#include <bits/stdc++.h>

using namespace std;

const char wname[6] = {"MTWRF"};
int mdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char buf[2008];
int hash_[128], schedule[13][32][18][61];

int main()
{
	int n, i, m, s, cm, cd, um, ud, sm, ss, em, es, tm, ts, tstep;
	char cw, uw;
	hash_['M'] = 0;
	hash_['T'] = 1;
	hash_['W'] = 2;
	hash_['R'] = 3;
	hash_['F'] = 4;
	gets(buf);
	sscanf(buf, "%c%d%d", &cw, &cm, &cd);
	cw = hash_[cw];
	gets(buf);
	sscanf(buf, "%d%d", &n, &tstep);
	while (gets(buf))
	{
		if (!strcmp(buf, "done"))
		{
			break;
		}
		while (gets(buf))
		{
			if (!strcmp(buf, "done"))
			{
				break;
			}
			sscanf(buf, "%c%d%d%2d%2d%2d%2d", &uw, &um, &ud, &sm, &ss, &em, &es);
			for (; sm * 100 + ss < em * 100 + es;)
			{
				schedule[um][ud][sm][ss] = 1;
				/*printf("%d %d %02d%02d\n", um, ud, sm, ss);*/
				ss += 15;
				if (ss == 60)
				{
					ss = 0;
					sm++;
				}
			}
		}
	}
	sm = tstep / 60;
	ss = tstep % 60;
	for (i = 0; i < 365 && n; i++, cw++)
	{
		/*printf("%d %d\n", cm, cd);*/
		if (cw == 7)
		{
			cw = 0;
		}
		if (cw < 5)
		{
			for (m = 9, s = 0; m * 100 + s < 1700;)
			{
				/*printf("%02d%02d\n", m, s);*/
				em = m + sm;
				es = s + ss;
				if (es >= 60)
				{
					em += es / 60;
					es %= 60;
				}
				if (em * 100 + es > 1700)
				{
					break;
				}
				for (tm = m, ts = s; tm * 100 + ts < em * 100 + es;)
				{
					/*printf("\t%02d%02d\n", tm, ts);*/
					if (schedule[cm][cd][tm][ts])
					{
						break;
					}
					ts += 15;
					if (ts == 60)
					{
						ts = 0;
						tm++;
					}
				}
				if (tm * 100 + ts < em * 100 + es)
				{
					s += 15;
					if (s == 60)
					{
						s = 0;
						m++;
					}
				}
				else
				{
					printf("%c %d %d %02d%02d\n", wname[cw], cm, cd, m, s);
					n--;
					if (!n)
					{
						break;
					}
					m = tm;
					s = ts;
				}
			}
		}
		cd++;
		if (cd > mdays[cm])
		{
			cd = 1;
			cm++;
			if (cm == 13)
			{
				cm = 1;
			}
		}
	}
	if (n)
	{
		printf("No more times available\n");
	}
	scanf(" ");
	return 0;
}
