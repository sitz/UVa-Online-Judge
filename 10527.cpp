#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 10010;

char num[MAXSIZE];
int numLen;

bool Input()
{
	cin.getline(num, MAXSIZE);
	numLen = strlen(num);
	if (num[0] == '-')
	{
		return false;
	}
	else
	{
		return true;
	}
}

int divisible(int fact)
{
	char temp[MAXSIZE];
	int tempLen = 0, carry = 0, i;
	for (i = 0; i < numLen; i++)
	{
		temp[tempLen++] = (carry * 10 + num[i] - '0') / fact + '0';
		carry = (carry * 10 + num[i] - '0') % fact;
	}
	if (!carry)//divisible
	{
		i = numLen = 0;
		while (temp[i] == '0')
		{
			i++;
		}
		for (; i < tempLen; i++)
		{
			num[numLen++] = temp[i];
		}
		//        cout<<"it is divisible"<<endl;
		//        for ( i=0;i<numLen;i++ )
		//            cout<<num[i];
		//        cout<<endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

bool IsZero()
{
	bool flg = true;
	for (int i = 0; i < numLen; i++)
		if (num[i] != '0')
		{
			flg = false;
			break;
		}
	return flg;
}

void solve()
{
	if (IsZero())
	{
		cout << "10" << endl;
		return;
	}
	if (numLen == 1)
	{
		cout << "1" << num[0] << endl;
		return;
	}
	int result[MAXSIZE];
	int resLen = 0;
	bool loop = true;
	while (loop && numLen > 1)
	{
		int fact;
		bool flg = false;
		for (fact = 9; fact > 1; fact--)
		{
			if (divisible(fact))
			{
				result[resLen++] = fact;
				flg = true;
				break;
			}
		}
		if (!flg)
		{
			loop = false;
		}
	}
	if (numLen > 1)
	{
		cout << "There is no such number." << endl;
	}
	else
	{
		int i;
		cout << num[0];
		for (i = resLen - 1; i >= 0; i--)
		{
			cout << result[i];
		}
		cout << endl;
	}
}

int main()
{
	while (Input())
	{
		solve();
	}
	return 0;
}
