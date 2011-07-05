#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            int n=0,cnt=0;
            int dis[5000]={0};
            cin>>n;
            for(int j=0;j<n;j++){
                    int y1,y2;
                    cin>>y1>>y2;
                    dis[j]=(y1-y2);
            }
            for(int j=0;j<n-1;j++)
                    if(dis[j]==dis[j+1])
                                        cnt++;
            if(cnt==(n-1))
                          cout<<"yes";
            else
                cout<<"no";
            if(i<(t-1))
                       cout<<endl<<endl;
    }
    return 0;
}
