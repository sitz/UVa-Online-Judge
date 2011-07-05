#include <iostream>

using namespace std;

unsigned long long combination(int n, int m)
{
    unsigned long long combo = 1;
    if(m<(n-m))  
         m=n-m;
    
    for(int i = n, j = 1; i > m; i--)
    {
        combo *= i;
        
        while((combo%j)==0 && (j<=n-m))
        {
            combo/=j;
            j++;
        }
    }   
    return combo;
}

int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        if((n==0)&&(m==0))
            break;
        else
            cout << combination(n, m) << endl;
    }
    return 0;
}
