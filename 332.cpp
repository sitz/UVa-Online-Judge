#include <bits/stdc++.h>

using namespace std;

int kase = 1;
int j, k;
char buffer[50];

long long gcd(long long a, long long b)
{
	long long temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	while (cin >> j && j >= 0)
	{
		cin >> buffer;
		k = strlen(buffer) - 2 - j;
		double X;
		long long p, q;
		if (j == 0)
		{
			sscanf(buffer, "%lf", &X);
			p = 0;
			for (int i = 2; buffer[i]; i++)
			{
				p = p * 10 + (long long)(buffer[i] - '0');
			}
			//  p = (long long)ceil( (X-0.000000005) * pow( 10.0,strlen(buffer)*1.0-2.0 ));
			q = (long long)ceil(pow(10.0, strlen(buffer) * 1.0 - 2.0));
		}
		else
		{
			char temp[50] = {'\0'};
			int t = 0;
			for (int i = strlen(buffer) - j; buffer[i]; i++)
			{
				temp[t++] = buffer[i];
			}
			temp[t] = '\0';
			strcat(buffer, temp);
			sscanf(buffer, "%lf", &X);
			p = (long long)ceil((pow(10.0, 1.0 * (k + j)) - pow(10.0, 1.0 * k)) * X);
			q = (long long)ceil((pow(10.0, j * 1.0) * pow(10.0, k * 1.0) - pow(10.0, k * 1.0)));
		}
		long long g = gcd(p, q);
		p /= g;
		q /= g;
		cout << "Case " << kase++ << ": " << p << "/" << q << endl;
	}
	return 0;
}
