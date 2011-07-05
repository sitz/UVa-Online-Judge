#include<iostream>
using namespace std;

int main(){
    string master="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int max=master.length();
    string str;
    while(getline(cin,str)){
                    int len=str.length(),i,ind=-1,ctr=0;
                    char out='0';
                    for(i=0;i<len;i++){
                                       if(str[i]>out)
                                                     out=str[i];
                                       if((str[i]<'0'||str[i]>'9') && (str[i]<'A' || str[i]>'Z') && (str[i]<'a'|| str[i]>'z'))
                                                                   ctr=-1;
                    }
                    for(i=0;i<max;i++){
                                      if(out==master[i]){
                                                        ind=i+1;
                                                        break;
                                      }
                    }
                    if(ind<0 || ctr<0){
                              cout<<"such number is impossible!\n";
                              continue;
                    }
                    else
                              cout<<ind<<endl;
    }
  return 0;
}
