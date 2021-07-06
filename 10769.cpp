#include <bits/stdc++.h>

using namespace std;

char str[5000], *p;
int w[100], nw;
int b[100], nb;
int H;
int main()
{
	int cases = 0;
	while (true)
	{
		if (gets(str) == NULL)
		{
			break;
		}
		if (strcmp(str, "") == 0)
		{
			continue;
		}
		sscanf(str, "%d", &H);
		gets(str);
		for (p = strtok(str, " "), nb = 0; p; p = strtok(NULL, " "))
		{
			b[nb++] = atoi(p);
		}
		gets(str);
		for (p = strtok(str, " "), nw = 0; p; p = strtok(NULL, " "))
		{
			w[nw++] = atoi(p);
		}
		for (int i = 0; i < nb; i++)
			for (int j = i + 1; j < nb; j++)
				if (b[i] < b[j])
				{
					int t = b[i];
					b[i] = b[j];
					b[j] = t;
				}
		for (int i = 0; i < nw; i++)
			for (int j = i + 1; j < nw; j++)
				if (w[i] < w[j])
				{
					int t = w[i];
					w[i] = w[j];
					w[j] = t;
				}
		bool flag = false;
		if (b[0] + b[1] + w[0] + w[1] >= H)
		{
			for (int i = 0; i < nb && !flag; i++)
				for (int j = 0; j < nw && !flag; j++)
					for (int k = i + 1; k < nb && !flag; k++)
						for (int l = j + 1; l < nw && !flag; l++)
							if (b[i] + w[j] + b[k] + w[l] == H)
							{
								printf("%d %d %d %d\n", b[i], w[j], b[k], w[l]);
								flag = true;
							}
		}
		if (!flag)
		{
			puts("no solution");
		}
	}
}
