#include <bits/stdc++.h>

using namespace std;

using std::sort;
const int max_song = (1 << 16) + 10;
int number_songs, quire;
double freq_count;

struct song
{
	int id, len;
	double freq;
	bool operator<(const song &T) const
	{
		return len * (freq + T.freq) + T.len * T.freq < T.len * (freq + T.freq) + len * freq;
	}
} songs[max_song];
int main()
{
	//    freopen("in.txt","r",stdin);
	while (scanf("%d", &number_songs) != EOF)
	{
		freq_count = 0.0;
		for (int i(0); i < number_songs; ++i)
		{
			scanf("%d%d%lf", &songs[i].id, &songs[i].len, &songs[i].freq);
			freq_count += songs[i].freq;
		}
		scanf("%d", &quire);
		sort(songs, songs + number_songs);
		printf("%d\n", songs[quire - 1].id);
	}
	return 0;
}
