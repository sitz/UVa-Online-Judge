#include <bits/stdc++.h>

using namespace std;

#define MAXI(a, b) (a > b ? a : b)
#define MINI(a, b) (a > b ? b : a)

int N, M, N_row, M_row, N_left, M_left, N_right, M_right, MAX;
int Find_R(int n)
{
	int k;
	k = sqrt((double)n);
	if (k * k < n)
	{
		return k + 1;
	}
	return k;
}
int Find_L_R(int n, int row)
{
	int m, d, k;
	m = (row - 1) * (row - 1) + 1;
	d = n - m + 1;
	k = ceil((double)d / 2);
	return k;
}
int Find_R_R(int n, int row)
{
	int m, d, k;
	m = row * row;
	d = m - n + 1;
	k = ceil((double)d / 2);
	return k;
}
int Dis()
{
	if (M_left >= N_left && M_right >= N_right)
	{
		return 1;
	}
	return 0;
}
int Distance(int m, int m_r, int n, int n_r)
{
	int d = 0, k, dis;
	if ((m % 2 && m_r % 2) || (!(m % 2) && !(m_r % 2)))
	{
		d++;
	}
	if ((n % 2 && n_r % 2 == 0) || (n % 2 == 0 && n_r % 2 != 0))
	{
		d++;
	}
	k = m_r - n_r - 1;
	dis = k * 2 + d + 1;
	return dis;
}
int LEFT_inside()
{
	int d, val, dis, meet_row;
	int meet_point;
	d = M_left - N_left - 1;
	meet_row = M_row - d;
	dis = d * 2 + 1;
	if ((M_row % 2 == 0 && M % 2 != 0) || (M_row % 2 != 0 && M % 2 == 0))
	{
		dis++;
		meet_row--;
	}
	meet_point = (meet_row - 1) * (meet_row - 1) + N_left * 2;
	val = dis + Distance(meet_point, meet_row, N, N_row);
	return val;
}
void Out_side()
{
	int meet_point, val;
	int d = (M_row - 1) * (M_row - 1);
	meet_point = d + N_left * 2;
	val = Distance(meet_point, M_row, N, N_row);
	val += abs(M - meet_point);
	if (val < MAX)
	{
		MAX = val;
	}
	d = (M_row) * (M_row);
	meet_point = d - N_right * 2 + 1;
	val = Distance(meet_point, M_row, N, N_row);
	val += abs(M - meet_point);
	if (val < MAX)
	{
		MAX = val;
	}
}
void Cal()
{
	int temp;
	N_row = Find_R(N);
	M_row = Find_R(M);
	if (N_row == M_row)
	{
		printf("%d\n", abs(M - N));
		return;
	}
	N_left = Find_L_R(N, N_row);
	M_left = Find_L_R(M, M_row);
	if (N_left == M_left)
	{
		printf("%d\n", Distance(M, M_row, N, N_row));
		return;
	}
	N_right = Find_R_R(N, N_row);
	M_right = Find_R_R(M, M_row);
	if (N_right == M_right)
	{
		printf("%d\n", Distance(M, M_row, N, N_row));
		return;
	}
	if (Dis() == 1)
	{
		temp = LEFT_inside();
		if (temp < MAX)
		{
			MAX = temp;
		}
	}
	else
	{
		Out_side();
	}
	printf("%d\n", MAX);
}

int main()
{
	int a, b;
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%d%d", &a, &b);
		MAX = 2147483647;
		N = MINI(a, b);
		M = MAXI(a, b);
		Cal();
		if (kase)
		{
			printf("\n");
		}
	}
	return 0;
}
