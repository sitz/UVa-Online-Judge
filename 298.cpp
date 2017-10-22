#include <bits/stdc++.h>

using namespace std;

vector<int> nowposx, nowposy, nowvx, nowvy, reposx, reposy, revx, revy;
int main()
{
	int times;
	scanf("%d", &times);
	for (int i = 0; i < times; i++)
	{
		nowposx.clear();
		nowposy.clear();
		nowvx.clear();
		nowvy.clear();
		reposx.clear();
		reposy.clear();
		revx.clear();
		revy.clear();
		int x, y;
		scanf("%d%d", &x, &y);
		bool pos[x][y][7][7];
		memset(pos, 0, sizeof(pos));
		int stx, sty, edx, edy;
		scanf("%d%d%d%d", &stx, &sty, &edx, &edy);
		bool finish = false;
		int nofob;
		scanf("%d", &nofob);
		bool oc[x][y];
		memset(oc, 0, sizeof(oc));
		for (int j = 0; j < nofob; j++)
		{
			int obx1, obx2, oby1, oby2;
			scanf("%d%d%d%d", &obx1, &obx2, &oby1, &oby2);
			for (int k = obx1; k <= obx2; k++)
				for (int l = oby1; l <= oby2; l++)
				{
					oc[k][l] = true;
				}
		}
		if (stx == edx && sty == edy)
		{
			printf("Optimal solution takes 0 hops.\n");
			finish = true;
		}
		pos[stx][sty][3][3] = true;
		nowposx.push_back(stx);
		nowposy.push_back(sty);
		nowvx.push_back(0);
		nowvy.push_back(0);
		int count = 0;
		while (!finish)
		{
			reposx.clear();
			reposy.clear();
			revx.clear();
			revy.clear();
			count++;
			for (int j = 0; !finish && j < nowposx.size(); j++)
			{
				int tempvx, tempvy;
				for (int k = -1; !finish && k <= 1; k++)
					for (int l = -1; !finish && l <= 1; l++)
					{
						tempvx = nowvx[j] + k;
						tempvy = nowvy[j] + l;
						if (tempvx < -3 || tempvx > 3 || tempvy < -3 || tempvy > 3)
						{
							continue;
						}
						if (tempvx + nowposx[j] < 0 || tempvx + nowposx[j] >= x || tempvy + nowposy[j] < 0 || tempvy + nowposy[j] >= y)
						{
							continue;
						}
						if (oc[tempvx + nowposx[j]][tempvy + nowposy[j]])
						{
							continue;
						}
						if (tempvx + nowposx[j] == edx && tempvy + nowposy[j] == edy)
						{
							finish = true;
							printf("Optimal solution takes %d hops.\n", count);
						}
						if (pos[tempvx + nowposx[j]][tempvy + nowposy[j]][tempvx + 3][tempvy + 3])
						{
							continue;
						}
						else
						{
							pos[tempvx + nowposx[j]][tempvy + nowposy[j]][tempvx + 3][tempvy + 3] = true;
							reposx.push_back(tempvx + nowposx[j]);
							reposy.push_back(tempvy + nowposy[j]);
							revx.push_back(tempvx);
							revy.push_back(tempvy);
						}
					}
			}
			if (int(reposx.size()) == 0)
			{
				printf("No solution.\n");
				finish = true;
			}
			else
			{
				nowposx = reposx;
				nowposy = reposy;
				nowvx = revx;
				nowvy = revy;
			}
		}
	}
}
