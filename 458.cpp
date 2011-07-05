#include<iostream>
#include<string.h>
#include<string>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str, '\n'))
    {
                      for(int i=0;i<str.length();i++)
                      str[i]-=7;
                      
                      cout<<str<<endl;
                      
    }
    return 0;
}
