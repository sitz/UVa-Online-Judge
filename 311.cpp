#include <bits/stdc++.h>

using namespace std;

/*

int main()
{
    int n1,n2,n3,n4,n5,n6,sum;
    while (cin>>n1>>n2>>n3>>n4>>n5>>n6)
    {
        if (n1==0&&n2==0&&n3==0&&n4==0&&n5==0&&n6==0) break;
        sum=n6;
        sum+=n5;
        n1-=11*n5;
        sum+=n4;
        if (n2>=5*n4) n2-=5*n4;
        else if (n2<5*n4)
        {
            n1-=20*n4-4*n2;
            n2=0;
        }
        sum+=n3/4;
        if (n3%4==1)
        {
            sum++;
            if (n2>=5)
            {
                n2-=5;
                n1-=7;
            }
            else if (n2<5&&n2>0)
            {
                n1-=27-4*n2;
                n2=0;
            }
            else if (n2<=0)
            {
                n1-=27;
                n2=0;
            }
        }
        else if (n3%4==2)
        {
            sum++;
            if (n2>=3)
            {
                n2-=3;
                n1-=6;
            }
            else if (n2<3&&n2>0)
            {
                n1-=18-4*n2;
                n2=0;
            }
            else if (n2<=0)
            {
                n1-=18;
                n2=0;
            }
        }
        else if (n3%4==3)
        {
            sum++;
            if (n2>=1)
            {
                n2-=1;
                n1-=5;
            }
            else if (n2<1)
            {
                n1-=9;
                n2=0;
            }
        }
        if (n2>0)
        {
            if (n2>9)
            {
                sum+=(n2+8)/9;
                n1-=36-4*(n2%9);
            }
            else if (n2==9) sum++;
            else if (n2<9)
            {
                sum++;
                n1-=36-4*(n2%9);
            }
        }
        if (n1>0)
        {
            if (n1>36) sum+=(n1+35)/36;
            else if (n1<=36) sum++;
        }
        cout<<sum<<endl;
    }
return 0;
}
*/

int t[4] = {0, 7, 6, 5};
int u[4] = {0, 5, 3, 1};
int main()
{
	int a, b, c, d, e, f, i, x, y, z;
	for (;;)
	{
		scanf("%d %d %d %d %d %d\n", &a, &b, &c, &d, &e, &f);
		x = 11 * e + t[c % 4];
		y = 5 * d + u[c % 4];
		z = f + d + e + (c + 3) / 4;
		if (y < b)
		{
			i = (b - y + 8) / 9;
			z += i;
			x += 4 * (9 * i - (b - y));
		}
		else
		{
			x += 4 * (y - b);
		}
		if (x < a)
		{
			z += (a - x + 35) / 36;
		}
		if (!z)
		{
			break;
		}
		printf("%d\n", z);
	}
	return 0;
}
