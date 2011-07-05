#include <iostream>

using namespace std;

int main()
{
    int i;
    unsigned long int fe[100], ma[100];
    fe[0] = 1, ma[0] = 0;
    
    for(i = 1; i < 100; i++)
    {
        fe[i] = ma[i-1]+1;
        ma[i] = fe[i-1]+ma[i-1];
    }
    
    for(;;)
    {
           cin>>i;
           if(i==-1)
                    break;
                    
            else
            cout << ma[i] << " " << fe[i]+ma[i] << endl;
    }
    
    return 0;
}
