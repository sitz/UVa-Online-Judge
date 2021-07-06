#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	while (N)
	{
		int max = 0, m_index = 0;
		int w, h;
		for (int i = 0; i < N; i++)
		{
			scanf(" %d %d", &w, &h);
			if (h > w)
			{
				int t;
				t = h;
				h = w;
				w = t;
			}
			int l = h * 6;
			if (l > max)
			{
				m_index = i;
				max = l;
			}
			l = (w * 3) > (h * 12) ? h * 12 : w * 3;
			if (l > max)
			{
				m_index = i;
				max = l;
			}
		}
		printf("%d\n", m_index + 1);
		scanf("%d", &N);
	}
	return 0;
}
