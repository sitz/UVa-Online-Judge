#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int a[100], k;
	int b[] = {1, 2, 3, 4, 5, 6, 20, 60};
	int t = 0;
	int c[8];
	int tmp, W;
	while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] && (a[1] + a[2] + a[3] + a[4] + a[5] + a[6]))
	{
		cout << "Collection #" << ++t << ":\n";
		W = 0;
		for (int i = 1; i < 7; i += 1)
		{
			W += i * a[i];
		}
		if ((W & 1))
		{
			cout << "Can't be divided.\n\n";
			continue;
		}
		W >>= 1;
		a[20] = 0;
		a[60] = 0;
		if (a[1])
		{
			k = (a[1] - 1) >> 1;
			a[2] += k;
			a[1] -= (k << 1);
		}
		if (a[2])
		{
			k = (a[2] - 1) >> 1;
			a[4] += k;
			a[2] -= (k << 1);
		}
		if (a[3])
		{
			k = (a[3] - 1) >> 1;
			a[6] += k;
			a[3] -= (k << 1);
		}
		if (a[4] > 4)
		{
			k = (a[4] - 4) / 5;
			a[20] += k;
			a[4] -= k * 5;
		}
		if (a[5] > 3)
		{
			k = (a[5] - 3) / 4;
			a[20] += k;
			a[5] -= k * 4;
		}
		if (a[6] > 9)
		{
			k = (a[6] - 9) / 10;
			a[60] += k;
			a[6] -= 10 * k;
		}
		if (a[20] > 2)
		{
			k = (a[20] - 2) / 3;
			a[60] += k;
			a[20] -= 3 * k;
		}
		tmp = 0;
		for (c[0] = 0; c[0] <= a[b[0]]; c[0] += 1)
		{
			tmp += c[0] * b[0];
			if (tmp > W)
			{
				tmp -= c[0] * b[0];
				break;
			}
			for (c[1] = 0; c[1] <= a[b[1]]; c[1] += 1)
			{
				tmp += c[1] * b[1];
				if (tmp > W)
				{
					tmp -= c[1] * b[1];
					break;
				}
				for (c[2] = 0; c[2] <= a[b[2]]; c[2] += 1)
				{
					tmp += c[2] * b[2];
					if (tmp > W)
					{
						tmp -= c[2] * b[2];
						break;
					}
					for (c[3] = 0; c[3] <= a[b[3]]; c[3] += 1)
					{
						tmp += c[3] * b[3];
						if (tmp > W)
						{
							tmp -= c[3] * b[3];
							break;
						}
						for (c[4] = 0; c[4] <= a[b[4]]; c[4] += 1)
						{
							tmp += c[4] * b[4];
							if (tmp > W)
							{
								tmp -= c[4] * b[4];
								break;
							}
							for (c[5] = 0; c[5] <= a[b[5]]; c[5] += 1)
							{
								tmp += c[5] * b[5];
								if (tmp > W)
								{
									tmp -= c[5] * b[5];
									break;
								}
								for (c[6] = 0; c[6] <= a[b[6]]; c[6] += 1)
								{
									tmp += c[6] * b[6];
									if (tmp > W)
									{
										tmp -= c[6] * b[6];
										break;
									}
									for (c[7] = 0; c[7] <= a[b[7]]; c[7] += 1)
									{
										tmp += c[7] * b[7];
										if (tmp > W)
										{
											tmp -= c[7] * b[7];
											break;
										}
										if (tmp == W)
										{
											cout << "Can be divided.\n\n";
											goto HELL;
										}
										tmp -= c[7] * b[7];
									}
									tmp -= c[6] * b[6];
								}
								tmp -= c[5] * b[5];
							}
							tmp -= c[4] * b[4];
						}
						tmp -= c[3] * b[3];
					}
					tmp -= c[2] * b[2];
				}
				tmp -= c[1] * b[1];
			}
			tmp -= c[0] * b[0];
		}
		cout << "Can't be divided.\n\n";
	HELL:
		continue;
	}
	return 0;
}
