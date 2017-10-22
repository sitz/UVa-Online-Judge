#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int menu, cake, drink, t, tmp, *up, *down;
	scanf("%lld", &t);

	for (long long int i = 1; i <= t; ++i)
	{
		scanf("%lld %lld %lld", &menu, &cake, &drink);
		long long int Cake[cake], Drink[drink], total = 0;
		double ave;
		for (long long int i = 0; i < cake; ++i)
		{
			scanf("%lld", Cake + i);
			total += Cake[i];
		}
		for (long long int i = cake; i < drink + cake; ++i)
		{
			scanf("%lld", Drink + i - cake);
			total += Drink[i - cake];
		}
		for (long long int i = drink + cake; i < menu; ++i)
		{
			scanf("%lld", &tmp);
			total += tmp;
		}
		ave = total / (double)menu;
		printf("Case #%lld: ", i);
		sort(Cake, Cake + cake);
		up = upper_bound(Cake, Cake + cake, ave);
		down = lower_bound(Cake, Cake + cake, ave);
		if (up == Cake + cake)
			--up;
		if (*down != ave && down != Cake || down == Cake + cake)
			--down;
		printf("%lld ", ave - *down > *up - ave ? *up : *down);
		sort(Drink, Drink + drink);
		up = upper_bound(Drink, Drink + drink, ave);
		down = lower_bound(Drink, Drink + drink, ave);
		if (up == Drink + drink)
			--up;
		if (*down != ave && down != Drink || down == Drink + drink)
			--down;
		printf("%lld\n", ave - *down > *up - ave ? *up : *down);
	}

	return 0;
}
