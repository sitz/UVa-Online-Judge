#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    double Vt,V0,i=0,n=0,len=0,maxlen=0,k=0,j=0;
    for(;;)
    {
           cin>>Vt>>V0;
           if(Vt==0 && V0==0)
                    break;
           if(Vt<=V0)
                     goto X;
           
           maxlen=0.3*sqrt(Vt-V0);
           n=1;
           for(i=1;i<=(Vt/V0);i++)
           {

                         len=0.3*i*sqrt(Vt/i-V0);
                         if(len>maxlen)
                         {
                                       maxlen=len;
                                       n=i;
                         }
           }
           for(j=1;j<=(Vt/V0);j++)
           {
                                 len=0.3*j*sqrt(Vt/j-V0);
                                 
                                 if(len==maxlen)
                                 k++;
           }
           if(k>=2)
           n=0;
           
X:         cout<<n<<endl;
    }
    return 0;
}
