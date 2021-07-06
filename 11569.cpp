#include <bits/stdc++.h>

using namespace std;

const int MAXALPHA = 26;
const int MAXSIZE = 256;

char S[MAXSIZE];
int len[MAXALPHA + 1], cnt[MAXALPHA + 1];

int main()
{
	int numOfCase;
	cin >> numOfCase;
	cin.getline(S, MAXSIZE);
	while (numOfCase--)
	{
		cin.getline(S, MAXSIZE);
		int alpha[MAXALPHA + 5], i, j, size;
		memset(alpha, 0, sizeof(alpha));
		alpha[0] = 1;
		for (i = 0; S[i]; i++)
			if (isupper(S[i]))
			{
				alpha[S[i] - 'A' + 1] = 1;
			}
		memset(len, 0, sizeof(len));
		memset(cnt, 0, sizeof(cnt));
		int v1, v2;
		len[0] = cnt[0] = 1;
		v1 = v2 = 0;
		for (i = 1; i <= MAXALPHA; i++)
			if (alpha[i])
			{
				v2 = i;
				for (j = 0; j < i; j++)
					if (alpha[j])
					{
						v1 = j;
						if (5 * v1 <= 4 * v2)
						{
							if (len[v1] + 1 > len[v2])
							{
								len[v2] = len[v1] + 1;
								cnt[v2] = 0;
							}
							if (len[v1] + 1 == len[v2])
							{
								cnt[v2] += cnt[v1];
							}
						}
					}
			}
		if (!v2)
		{
			cout << "0 0" << endl;
		}
		else
		{
			int maxlen = len[v2], ans = 0;
			for (i = 1; i <= MAXALPHA; i++)
				if (len[i] == maxlen)
				{
					ans += cnt[i];
				}
			cout << maxlen - 1 << " " << ans << endl;
		}
	}
	return 0;
}
