#include<iostream>
#include<cmath>
using namespace std;
int main(){
    for(;;){
            long long n,i,j;
            cin>>n;
            if(n==0)
                    break;
            double cood[n][2];
            for(i=0;i<n;i++)
                            cin>>cood[i][0]>>cood[i][1];
            if(n==1){
                    cout<<"INFINITY\n";
                    continue;
            }
            double min=sqrt(pow((cood[0][0]-cood[1][0]),2)+pow((cood[0][1]-cood[1][1]),2));
            for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                               double dis=sqrt(pow((cood[i][0]-cood[j][0]),2)+pow((cood[i][1]-cood[j][1]),2));
                               if(dis<min)
                                          min=dis;
            }
            }
            if(min>=10000)
                          cout<<"INFINITY\n";
            else
                          printf("%.4lf\n",min);
    }
    return 0;
}
