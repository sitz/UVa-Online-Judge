#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 105;

int nRooms, initCat, initMouse;
bool CatMove[MAXSIZE][MAXSIZE], MouseMove[MAXSIZE][MAXSIZE];
bool cond1, cond2;
int catVisted[MAXSIZE], mouseVisted[MAXSIZE];

void input()
{
	memset(CatMove, 0, sizeof(CatMove));
	memset(MouseMove, 0, sizeof(MouseMove));
	cond1 = cond2 = false;
	cin >> nRooms >> initCat >> initMouse;
	int a, b;
	// input cat road
	while (cin >> a >> b && a >= 0)
	{
		CatMove[a][b] = true;
	}
	cin.get();
	// input mouse road
	char str[100];
	while (cin.getline(str, 100) && strcmp(str, "\0"))
	{
		sscanf(str, "%d%d", &a, &b);
		MouseMove[a][b] = true;
	}
}

void dfs(int *vis, int room, int cm, bool end)
{
	if (vis[room] || end)
	{
		return;
	}
	if (cm == 2 && catVisted[room])
	{
		end = true;
		cond1 = true;
		return;
	}
	vis[room] = cm;
	for (int i = 1; i <= nRooms; i++)
	{
		if (cm == 1 && CatMove[room][i])// cat
		{
			dfs(vis, i, cm, end);
		}
		else if (cm == 2 && MouseMove[room][i])//mouse
		{
			dfs(vis, i, cm, end);
		}
	}
}

void solve()
{
	memset(catVisted, 0, sizeof(catVisted));
	memset(mouseVisted, 0, sizeof(mouseVisted));
	dfs(catVisted, initCat, 1, false);
	dfs(mouseVisted, initMouse, 2, false);
	for (int i = 1; i <= nRooms; i++)
		if (MouseMove[initMouse][i] && !catVisted[i])
		{
			cond2 = true;
			break;
		}
	if (cond1)
	{
		cout << "Y ";
	}
	else
	{
		cout << "N ";
	}
	if (cond2)
	{
		cout << "Y" << endl;
	}
	else
	{
		cout << "N" << endl;
	}
}

int main()
{
	int numOfCase;
	cin >> numOfCase;
	for (int kase = 1; kase <= numOfCase; kase++)
	{
		input();
		solve();
		if (kase != numOfCase)
		{
			cout << endl;
		}
	}
	//  system( "pause" );
	return 0;
}
