#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int C,N,i=0,j=0;
    float marks[100],avg=0,sum=0,count=0,res=0;
    cin>>C;
    for(i=0;i<C;i++)
    {
                    count=0,N=0,avg=0,sum=0,res=0;
                    
                    cin>>N;
                    for(j=0;j<N;j++)
                    {
                                    cin>>marks[j];
                                    sum+=marks[j];
                    }
                    avg=sum/N;
                    for(j=0;j<N;j++)
                    {
                                    if(marks[j]>avg)
                                                    count++;
                    }
                    res=(count/N)*100;
                    printf("%.3f",res);
                    cout<<"%"<<endl;

    }
    return 0;
}
