#include <bits/stdc++.h>

using namespace std;

int K, Q, M, kr, kc, qr, qc, mr, mc;
int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, -1, 1};

int illegal()
{
	return K == Q;
}
int illegal_mv()
{
	int i, max_, min_;
	if (M == Q)
	{
		return 1;
	}
	if (qr != mr && qc != mc)
	{
		return 1;
	}
	if (qr != kr && qc != kc)
	{
		return 0;
	}
	max_ = max(Q, M);
	min_ = Q + M - max_;
	if (qr == mr)
	{
		for (i = min_; i <= max_; i++)
		{
			if (i == K)
			{
				return 1;
			}
		}
	}
	else if (qc == mc)
	{
		for (i = min_; i <= max_; i += 8)
		{
			if (i == K)
			{
				return 1;
			}
		}
	}
	return 0;
}
int Not_allowed()
{
	int i, j, r, c;
	char F[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			F[i][j] = 0;
		}
	}
	for (i = qr - 1; i >= 0 && (kc != qc || i != kr); i--)
	{
		F[i][qc]++;
	}
	for (i = qr + 1; i < 8 && (kc != qc || i != kr); i++)
	{
		F[i][qc]++;
	}
	for (i = qc - 1; i >= 0 && (kr != qr || i != kc); i--)
	{
		F[qr][i]++;
	}
	for (i = qc + 1; i < 8 && (kr != qr || i != kc); i++)
	{
		F[qr][i]++;
	}
	for (i = 0; i < 4; i++)
	{
		r = X[i] + kr;
		c = Y[i] + kc;
		if (r >= 8 || r < 0 || c >= 8 || c < 0)
		{
			continue;
		}
		F[r][c]++;
	}
	return F[mr][mc] > 1;
}
int Continue()
{
	int i, j, r, c;
	char F[8][8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			F[i][j] = 0;
		}
	}
	for (i = mr - 1; i >= 0 && (kc != mc || i != kr); i--)
	{
		F[i][mc]++;
	}
	for (i = mr + 1; i < 8 && (kc != mc || i != kr); i++)
	{
		F[i][mc]++;
	}
	for (i = mc - 1; i >= 0 && (kr != mr || i != kc); i--)
	{
		F[mr][i]++;
	}
	for (i = mc + 1; i < 8 && (kr != mr || i != kc); i++)
	{
		F[mr][i]++;
	}
	for (i = 0; i < 4; i++)
	{
		r = X[i] + kr;
		c = Y[i] + kc;
		if (r >= 8 || r < 0 || c >= 8 || c < 0)
		{
			continue;
		}
		F[r][c]++;
		if (F[r][c] < 2)
		{
			return 1;
		}
	}
	return 0;
}
void Cal()
{
	if (illegal())
	{
		printf("Illegal state\n");
		return;
	}
	else if (illegal_mv())
	{
		printf("Illegal move\n");
		return;
	}
	else if (Not_allowed())
	{
		printf("Move not allowed\n");
		return;
	}
	else if (Continue())
	{
		printf("Continue\n");
	}
	else
	{
		printf("Stop\n");
	}
}
void Ini()
{
	kr = K / 8;
	kc = K % 8;
	qr = Q / 8;
	qc = Q % 8;
	mr = M / 8;
	mc = M % 8;
}

int main()
{
	while (scanf("%d%d%d", &K, &Q, &M) == 3)
	{
		Ini();
		Cal();
	}
	return 0;
}
