#include<iostream>

using namespace std;

int main()
{
    int N,div_sum=1;
    cout<<"PERFECTION OUTPUT"<<endl;
    while((cin>>N))
    {
                      div_sum=1;
                      for(int i=2;i<N;i++)
                      {
                              if(N%i==0)
                                        div_sum+=i;
                      }
                      printf("%-10 d",div_sum);
                      if(div_sum<N)
                                   cout<<"DEFICIENT"<<endl;
                      if(div_sum==N)
                                   cout<<"PERFECT"<<endl;
                      if(div_sum>N)
                                   cout<<"ABUNDANT"<<endl;
    }
    cout<<"END OF OUTPUT";
    return 0;
}
