#include <bits/stdc++.h>

using namespace std;

struct Pallet {int w, h;} pallet[6];

int main()
{
	int w, h;
	while (scanf("%d%d", &w, &h) != EOF)
	{
		pallet[0].w = min(w,h);
		pallet[0].h = max(w,h);
		for (int i = 1; i < 6; i++)
		{
			scanf("%d%d", &w, &h);
			pallet[i].w = min(w,h);
			pallet[i].h = max(w,h);
		}

		sort(pallet, pallet + 6, [](Pallet &a, Pallet &b) -> bool
				 {
					 return a.w < b.w || ((a.w == b.w) && (a.h < b.h));
				 });

		bool ok = true;
		for (int i = 0; i < 6; i += 2)
		{
			if (pallet[i].w != pallet[i + 1].w
				|| pallet[i].h != pallet[i + 1].h)
			{
				ok = false;
			}
		}

		if (ok)
		{
			ok = false;
			if (pallet[0].w == pallet[2].w
				&& pallet[0].h == pallet[4].w
				&& pallet[2].h == pallet[4].h)
			{
				ok = true;
			}
		}

		printf(ok ? "POSSIBLE\n" : "IMPOSSIBLE\n");
	}

	return 0;
}
