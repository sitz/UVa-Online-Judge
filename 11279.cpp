#include <bits/stdc++.h>

using namespace std;

const char *DV[] = {"`123qjlmfp/[]", "456.orsuyb;=\\", "789aehtdck-", "0zx,inwvg'"},
					 *qwerty[] = {"`1234567890-=", "qwertyuiop[]\\", "asdfghjkl;'", "zxcvbnm,./"},
					 *shift = "~!@#$%^&*()_+{}|:\"<>?", *unshift = "`1234567890-=[]\\;',./";
const int DVdist[] = {5, 4, 4, 4}, ONEdist[] = {4, 3, 3, 3}, TWOdist[] = {1, 0, 0, 0};

double one(char c)
{
	int r, p;

	for (r = 0; !strchr(qwerty[r], c); ++r)
		;
	p = strchr(qwerty[r], c) - qwerty[r];
	return hypot(r - 2, p < ONEdist[r] ? ONEdist[r] - p : p >= ONEdist[r] + 4 ? p - ONEdist[r] - 3 : 0);
}

double dvo(char c)
{
	int r, p;

	for (r = 0; !strchr(DV[r], c); ++r)
		;
	p = strchr(DV[r], c) - DV[r];
	return hypot(r - 2, p < DVdist[r] ? DVdist[r] - p : p >= DVdist[r] + 4 ? p - DVdist[r] - 3 : 0);
}

double two(char c)
{
	int r, p;

	for (r = 0; !strchr(qwerty[r], c); ++r)
		;
	p = strchr(qwerty[r], c) - qwerty[r];
	if (p < TWOdist[r])
		p = TWOdist[r] - p;
	else if (p < TWOdist[r] + 4)
		p = 0;
	else if (p < TWOdist[r] + 6)
		p = 1;
	else if (p < TWOdist[r] + 10)
		p = 0;
	else
		p -= 9 + TWOdist[r];
	return hypot(r - 2, p);
}

int main()
{
	char s[1001];

	while (gets(s))
	{
		double O = 0, T = 0, D = 0;

		for (int i = 0; s[i]; ++i)
		{
			if (isspace(s[i]))
				continue;
			if (isupper(s[i]))
				s[i] = tolower(s[i]);
			else if (strchr(shift, s[i]))
				s[i] = unshift[strchr(shift, s[i]) - shift];

			O += one(s[i]);
			T += two(s[i]);
			D += dvo(s[i]);
		}
		printf("%.2f %.2f %.2f\n", T * 2, O * 2, D * 2);
	}
}
