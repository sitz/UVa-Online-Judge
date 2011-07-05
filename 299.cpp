#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int no,n,l[50],s;
    cin>>no;
    for(int z=0;z<no;z++)
    {
            s=0;
            cin>>n;
            for(int i=0;i<n;i++)
                    cin>>l[i];
            for(int j=0;j<n;j++)
                    for(int k=j+1;k<n;k++)
                            if(l[j]>l[k])
                            {
                                         int temp=l[j];
                                         l[j]=l[k];
                                         l[k]=temp;
                                         
                                         s++;
                            }
            cout<<"Optimal train swapping takes "<<s<<" swaps."<<endl;
    }
    return 0;
}
