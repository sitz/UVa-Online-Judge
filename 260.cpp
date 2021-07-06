#include <bits/stdc++.h>

using namespace std;

/**************
IL GIOCO DELL'X
     260
***************/
#define MAXN 205
#define MAX 1000
/*10000*/
int R[] = {-1, -1, 0, 0, 1, 1};
int C[] = {-1, 0, -1, 1, 0, 1};
char Game[MAXN][MAXN];
int QR[MAX], QC[MAX];
int QHR, QTR, QHC, QTC, N, Kase;
void PushR(int r)
{
	QR[QHR++] = r;
	QHR %= MAX;
}
int PopR()
{
	int r = QR[QTR++];
	QTR %= MAX;
	return r;
}
void PushC(int r)
{
	QC[QHC++] = r;
	QHC %= MAX;
}
int PopC()
{
	int r = QC[QTC++];
	QTC %= MAX;
	return r;
}
int IsEmpty()
{
	return QHR == QTR;
}
int BFS(int r, int c)
{
	int i, p, q, nr, nc;
	QHR = QTR = QHC = QTC = 0;
	PushR(r);
	PushC(c);
	Game[r][c] = 'A';
	while (!IsEmpty())
	{
		p = PopR();
		q = PopC();
		for (i = 0; i < 6; i++)
		{
			nr = p + R[i];
			nc = q + C[i];
			if (nr >= N || nc >= N || nr < 0 || nc < 0)
			{
				continue;
			}
			if (Game[nr][nc] != 'w')
			{
				continue;
			}
			if (nc == N - 1 && Game[nr][nc] == 'w')
			{
				return 1;
			}
			Game[nr][nc] = 'A';
			PushR(nr);
			PushC(nc);
		}
	}
	return 0;
}
void Com()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		if (Game[i][0] == 'w')
			if (BFS(i, 0))
			{
				printf("%d W\n", Kase++);
				return;
			}
	}
	printf("%d B\n", Kase++);
}
int main()
{
	int i;
	char input[50];
	Kase = 1;
	while (1)
	{
		gets(input);
		sscanf(input, "%d", &N);
		if (!N)
		{
			break;
		}
		for (i = 0; i < N; i++)
		{
			gets(Game[i]);
		}
		Com();
	}
	return 0;
}
