#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    char code[] = { '0','1','2','3','0','1','2','0','0','2','2','4','5','5','0','1','2','6','2','3','0','1','0','2','0','2' };
    string str;
    while(cin>>str){
                                int len=str.length(),i;
                                string out,finalStr;
                                for(i=0;i<len;i++){
                                                   char ch=code[str[i]-'A'];
                                                   out+=ch;
                                }
                                len=out.length();
                                for(i=0;i<len;i++){
                                       if(out[i]!=out[i+1] && out[i]!='0')
                                                 finalStr+=out[i];
                                }
                                cout<<finalStr<<endl;
    }
    return 0;
}
