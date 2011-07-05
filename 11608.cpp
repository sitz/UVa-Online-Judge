#include<iostream>
using namespace std;

int main(){
    for(int j=1;;j++){
            int n;
            cin>>n;
            if(n<0)
                   break;
            int made[12]={0},comp[12]={0};
            for(int i=0;i<12;i++)
                    cin>>made[i];
            for(int i=0;i<12;i++)
                    cin>>comp[i];
            int temp=n;
            for(int i=0;i<12;i++){
                    int ttemp=made[i];
                    made[i]=temp;
                    temp=ttemp;
            }
            cout<<"Case "<<j<<":"<<endl;
            for(int i=0;i<12;i++){
                    if(made[i]>=comp[i]){
                                         cout<<"No problem! :D"<<endl;
                                         made[i+1]+=(made[i]-comp[i]);
                    }
                    else{
                         cout<<"No problem. :("<<endl;
                         made[i+1]+=made[i];
                    }
            }
    }
    return 0;
}
