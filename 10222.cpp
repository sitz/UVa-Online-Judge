#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    string master="`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    int max=master.length();
    string str;
    while(getline(cin,str,'\n')){
                                      int len=str.length(),i,j;
                                      for(i=0;i<len;i++){
                                             str[i]=tolower(str[i]);
                                             for(j=0;j<max;j++){
                                                     if(str[i]==master[j])
                                                                          str[i]=master[j-2];
                                             }
                                      }
                                      cout<<str<<endl;
    }
    return 0;
}
