#include <bits/stdc++.h>

using namespace std;

char data[8][102][66], disk[8][6401], data2[32001], pdata[6402];
const char *hex_[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

int main()
{
	int d, s, b, kase = 0;
	char parity[2];
	for (;;)
	{
		kase++;
		scanf("%d", &d);
		if (!d)
		{
			break;
		}
		scanf("%d%d%s", &s, &b, parity);
		memset(disk, 0, sizeof(disk));
		memset(data2, 0, sizeof(data2));
		memset(pdata, 0, sizeof(pdata));
		for (int i = 1; i <= d; i++)
		{
			scanf("%s", disk[i]);
		}
		int byte = 0, pbyte = 0;
		for (int i = 1; i <= b; i++)
		{
			for (int j = 1; j <= d; j++)
			{
				if (i % d == j || (i % d == 0 && j == d))
				{
					for (int k = 0; k < s; k++)
					{
						pdata[pbyte] = disk[j][s * i - s + k];
						pbyte++;
					}
				}
				else
				{
					for (int k = 0; k < s; k++)
					{
						data2[byte] = disk[j][s * i - s + k];
						byte++;
					}
				}
			}
		}
		bool valid = true;
		int check;
		if (parity[0] == 'E')
		{
			check = 0;
		}
		else
		{
			check = 1;
		}
		int datas = d - 1;
		for (int i = 1; i <= b; i++)
		{
			for (int j = 0; j < s; j++)
			{
				int xn = 0, pxn = 0, presult = -1, xind = -1;
				if (pdata[i * s - s + j] == 'x')
				{
					pxn++;
				}
				for (int k = 0; k <= datas - 1; k++)
				{
					if (data2[i * s * datas - datas * s + j + k * s] == 'x')
					{
						xn++;
						if (pxn || xn >= 2)
						{
							valid = false;
						}
						else
						{
							xind = k;
						}
						if (!valid)
						{
							break;
						}
					}
					else if (presult < 0)
					{
						presult = data2[i * s * datas - datas * s + j + k * s] - '0';
					}
					else
					{
						presult ^= data2[i * s * datas - datas * s + j + k * s] - '0';
					}
				}
				if (!valid)
				{
					break;
				}
				if ((pxn + xn == 0) && presult ^ check != pdata[i * s - s + j] - '0')
				{
					valid = false;
					break;
				}
				else if (xn && !pxn)
				{
					if (presult >= 0)
					{
						data2[i * s * datas - datas * s + j + xind * s] = (presult ^ check) ^ (pdata[i * s - s + j] - '0') + '0';
					}
					else
					{
						data2[i * s * datas - datas * s + j + xind * s] = check ^ (pdata[i * s - s + j] - '0') + '0';
					}
				}
			}
			if (!valid)
			{
				break;
			}
		}
		while (strlen(data2) % 4)
		{
			data2[strlen(data2)] = '0';
		}
		if (!valid)
		{
			printf("Disk set %d is invalid.\n", kase);
		}
		else
		{
			printf("Disk set %d is valid, contents are: ", kase);
			for (int i = 0; i <= strlen(data2); i += 4)
			{
				int res = 0;
				for (int k = 0; k < 4; k++)
				{
					res = res * 2 + data2[i + k] - '0';
				}
				if (0 <= res && res < 16)
				{
					printf("%s", hex_[res]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
