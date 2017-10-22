#include <bits/stdc++.h>

using namespace std;

#define KKL 10048
#define WWL 100048

const char *ans[2] = {"N", "S"};
char map_[256], note[64], K[KKL], W[WWL];
int F[KKL];

void kmp_table(char *K, int KL)
{
	F[0] = F[1] = 0;
	int i, j;
	for (i = 2; i < KL; ++i)
	{
		j = F[i - 1];
		while (1)
		{
			if (K[j] == K[i - 1])
			{
				F[i] = j + 1;
				break;
			}
			if (j == 0)
			{
				F[i] = 0;
				break;
			}
			j = F[j];
		}
	}
}
int kmp(char *W, int WL, char *K, int KL)
{
	kmp_table(K, KL);
	for (int i = 0, j = 0; j < WL;)
	{
		if (W[j] == K[i])
		{
			i++;
			j++;
			if (i == KL)
			{
				return j;
			}
		}
		else if (i > 0)
		{
			i = F[i];
		}
		else
		{
			j++;
		}
	}
	return -1;
}
void read_music(char *x, int L)
{
	char p, v;
	for (int i = 0; i < L; ++i)
	{
		scanf("%s", note);
		p = v;
		v = map_[note[0]] + (note[1] == '#') - (note[1] == 'b');
		v = (v + 12) % 12;
		if (i)
		{
			x[i - 1] = (v - p + 12) % 12;
		}
	}
}

int main()
{
	map_['A'] = 0;
	map_['B'] = 2;
	map_['C'] = 3;
	map_['D'] = 5;
	map_['E'] = 7;
	map_['F'] = 8;
	map_['G'] = 10;
	int z, KL, WL;
	while (scanf("%d %d", &WL, &KL) && WL)
	{
		read_music(W, WL);
		read_music(K, KL);
		--WL, --KL;
		z = kmp(W, WL, K, KL);
		puts(ans[z != -1]);
	}
	return 0;
}
