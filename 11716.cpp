#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int t=0;
    scanf("%d\n",&t);
    for(int i=1;i<=t;i++){
            string str="\0";
            getline(cin,str);
            int len=str.length();
            if(len==0){
                      cout<<endl;
                      continue;
            }
            double sqr=sqrt(len);
            if(sqr!=(int)sqr){
                              cout<<"INVALID";
                              if(i!=t && i!=0)
                                      cout<<"\n";
                              continue;
            }
            int x=0;
            char s[1000][1000];
            string res;
            for(int j=0;j<sqr;j++){
                    for(int k=0;k<sqr;k++){
                            s[j][k]=str[x];
                            x++;
                    }
            }
            x=0;
            for(int j=0;j<sqr;j++){
                    for(int k=0;k<sqr;k++){
                            res+=s[k][j];
                            x++;
                    }
            }
            cout<<res;
                    cout<<"\n";
    }
    return 0;
}
