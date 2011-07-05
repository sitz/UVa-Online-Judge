#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    while(getline(cin,str,'\n')){
                                 if(str==""){
                                            cout<<endl;
                                            continue;
                                 }
                                 int len=str.length(),cnt=0,i=0,j=0;
                                 for(i=0;i<len;i++){
                                                    if(str[i]=='!'){
                                                                   cout<<endl;
                                                                   continue;
                                                    }
                                                    else if(isdigit(str[i])){
                                                                        cnt+=(str[i]-'0');
                                                                        continue;
                                                    }
                                                    else{
                                                                        for(j=0;j<cnt;j++){
                                                                                           if(str[i]=='b')
                                                                                                          cout<<" ";
                                                                                           else
                                                                                                          cout<<str[i];
                                                                        }
                                                                        cnt=0;
                                                    }
                                 }
                                 cout<<endl;
    }
    return 0;
}
