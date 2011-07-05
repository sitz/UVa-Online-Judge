#include<iostream>

using namespace std;

int main()
{
    int n,f,f_det[20][3],sum,i,j;
    cin>>n;
    for(int z=0;z<n;z++)
    {
            sum=0;
            cin>>f;
            for(int i=0;i<f;i++)
                    for(int j=0;j<3;j++)
                            cin>>f_det[i][j];
                            
            for(int i=0;i<f;i++)
                    sum+=f_det[i][0]*f_det[i][2];
            
            cout<<sum<<endl;
    }
    return 0;
}
