#include <bits/stdc++.h>

using namespace std;

#define conv 0.01745329251994329914588889
#define EPS 1e-2
#define ABS(a) ((a < 0) ? (-a) : (a))

char arg_[100], cmd[1024][3], mov_type;
double ang, posX, posY;
int ans, c, doubt, i, n, qtty[1024];

void exe(char c, int q)
{
	switch (c)
	{
	case 'f':
		posX += (q * cos(ang * conv));
		posY -= (q * sin(ang * conv));
		break;
	case 'l':
		ang += q;
		break;
	case 'r':
		ang -= q;
		break;
	case 'b':
		posX -= (q * cos(ang * conv));
		posY += (q * sin(ang * conv));
		break;
	}
}
void exeAll()
{
	posX = posY = ang = 0;
	for (i = 0; i < n; i++)
	{
		exe(cmd[i][0], qtty[i]);
	}
}

int main()
{
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%s %s", &cmd[i], &arg_);
			if (arg_[0] == '?')
			{
				mov_type = cmd[i][0], doubt = i;
				continue;
			}
			qtty[i] = atoi(arg_);
		}
		if (mov_type < 'g')
		{
			qtty[doubt] = 0;
			exeAll();
			double dist = sqrt(posX * posX + posY * posY);
			if (ceil(dist) - dist < dist - floor(dist))
			{
				dist = ceil(dist);
			}
			else
			{
				dist = floor(dist);
			}
			ans = (int)dist;
			qtty[doubt] = ans;
			exeAll();
			double distA = sqrt(posX * posX + posY * posY);
			qtty[doubt] = -ans;
			double distB = sqrt(posX * posX + posY * posY);
			if (distB < distA)
			{
				ans = -ans;
			}
		}
		else
		{
			for (ans = 0; ans < 360; ans++)
			{
				qtty[doubt] = ans;
				exeAll();
				if (ABS(posX) < EPS && ABS(posY) < EPS)
				{
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
