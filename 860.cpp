#include <bits/stdc++.h>

using namespace std;

const char *Delim(" ,.:;!?\"()\n\t"), *EndText("****END_OF_TEXT****"), *EndInput("****END_OF_INPUT****");
char buf[25], *p;

int main()
{
	double Et, Emax, Erel, log10c;
	int c;
	map<string, int> m;
	while (cin >> buf, strcmp(buf, EndInput))
	{
		c = 0;
		m.clear();
		do
		{
			for (int i = 0; buf[i] != '\0'; i++)
			{
				buf[i] = tolower(buf[i]);
			}
			p = strtok(buf, Delim);
			while (p != NULL)
			{
				m[string(p)]++;
				c++;
				p = strtok(NULL, Delim);
			}
		} while (cin >> buf, strcmp(buf, EndText));
		Et = Emax = Erel = 0;
		log10c = log10(c);
		for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			Et += (it->second * (log10c - log10(it->second)));
		}
		Et /= c;
		printf("%d %.1lf %.0lf\n", c, Et, 100. * Et / log10c);
	}
	return 0;
}
