#include <bits/stdc++.h>

using namespace std;

#define maxn 10002

struct ss
{
	int no;
	int time;
};
vector<ss> Left, Right;
int lind, rind, ftime, fside, T, N, M, Cross[maxn];

void Move()
{
	int i, k;

	if (lind == Left.size())
	{
		if (ftime < Right[rind].time)
			ftime += (Right[rind].time - ftime);
		if (fside == 0)
			ftime += T;
		else
			fside = 1;
		if (ftime < Right[rind].time)
			ftime += (Right[rind].time - ftime);
		k = 0;
		for (i = rind; i < Right.size(); i++)
		{
			if (k == N || Right[i].time > ftime)
				break;
			Cross[Right[i].no] = ftime + T;
			k++;
		}
		rind = i;
		ftime += T;
		return;
	}

	if (rind == Right.size())
	{
		if (ftime < Left[lind].time)
			ftime += (Left[lind].time - ftime);
		if (fside == 1)
			ftime += T;
		else
		{
			fside++;
			fside %= 2;
		}
		if (ftime < Left[lind].time)
			ftime += (Left[lind].time - ftime);
		k = 0;
		for (i = lind; i < Left.size(); i++)
		{
			if (k == N || Left[i].time > ftime)
				break;
			Cross[Left[i].no] = ftime + T;
			k++;
		}
		lind = i;
		ftime += T;
		return;
	}

	if (Left[lind].time < Right[rind].time)
	{
		if (ftime < Left[lind].time)
			ftime += (Left[lind].time - ftime);
		if (fside == 0)
			fside = 1;
		else
		{
			k = 0;
			for (i = rind; i < Right.size(); i++)
			{
				if (Right[i].time > ftime || k == N)
					break;
				Cross[Right[i].no] = ftime + T;
				k++;
			}
			rind = i;
			ftime += T;
		}
		if (ftime < Left[lind].time)
			ftime += (Left[lind].time - ftime);
		k = 0;
		for (i = lind; i < Left.size(); i++)
		{
			if (k == N || Left[i].time > ftime)
				break;
			Cross[Left[i].no] = ftime + T;
			k++;
		}
		lind = i;
		ftime += T;
		return;
	}

	if (Left[lind].time > Right[rind].time)
	{
		if (ftime < Right[rind].time)
			ftime += (Right[rind].time - ftime);
		if (fside == 0)
		{
			k = 0;
			for (i = lind; i < Left.size(); i++)
			{
				if (Left[i].time > ftime || k == N)
					break;
				Cross[Left[i].no] = ftime + T;
				k++;
			}
			lind = i;
			ftime += T;
		}
		else
			fside = 0;
		if (ftime < Right[rind].time)
			ftime += (Right[rind].time - ftime);
		k = 0;
		for (i = rind; i < Right.size(); i++)
		{
			if (k == N || Right[i].time > ftime)
				break;
			Cross[Right[i].no] = ftime + T;
			k++;
		}
		rind = i;
		ftime += T;
		return;
	}

	if (Left[lind].time == Right[rind].time)
	{
		if (fside == 0)
		{
			fside = 1;
			if (ftime < Left[lind].time)
			{
				ftime += Left[lind].time - ftime;
				k = 0;
				for (i = lind; i < Left.size(); i++)
				{
					if (k == N || Left[i].time > ftime)
						break;
					Cross[Left[i].no] = ftime + T;
					k++;
				}
				lind = i;
				ftime += T;
				return;
			}
		}
		else
		{
			fside = 0;
			if (ftime < Right[rind].time)
				ftime += (Right[rind].time - ftime);
			k = 0;
			for (i = rind; i < Right.size(); i++)
			{
				if (k == N || Right[i].time > ftime)
					break;
				Cross[Right[i].no] = ftime + T;
				k++;
			}
			rind = i;
			ftime += T;
			return;
		}
	}
}

void Cal()
{
	int i, k;
	lind = rind = 0;
	ftime = 0;
	fside = 0;
	while (lind + rind < M)
		Move();
	for (i = 0; i < M; i++)
		cout << Cross[i] << endl;
}

int main()
{
	int c, i, t, k = 0;
	ss d;
	string side;
	cin >> c;
	while (c--)
	{
		cin >> N >> T >> M;
		for (i = 0; i < M; i++)
		{
			cin >> t >> side;
			d.no = i;
			d.time = t;
			if (side == "left")
				Left.push_back(d);
			else
				Right.push_back(d);
		}
		if (k++)
			cout << endl;
		Cal();
		Left.clear();
		Right.clear();
	}
	return 0;
}
