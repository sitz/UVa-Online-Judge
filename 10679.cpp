#include<iostream>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    for(int i=1;i<=t;i++){
            char str[100000]={'\0'};
            cin>>str;
            int n=0;
            cin>>n;
            for(int j=1;j<=n;j++){
                    char s[1000]={'\0'};
                    cin>>s;
                    char *index=strstr(str,s);
                    cout<<index;
                    if(index=='\0')
                                   cout<<"n";
                    else
                                   cout<<"y";
                    if(!(i==t && j==n))
                              cout<<endl;
            }
    }
    return 0;
}
