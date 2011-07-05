#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
    int x=0;
    while(cin>>x){
                  string str,s;
                  int coef[100]={0},j=0;
                  getline(cin,str);
                  for(int i=0;i<str.length();i++){
                          if(str[i]==' '){
                                       //coef[j]=strtol(s,' ',10);
                                       //coef[j]=atoi(s.c_str());
                                       j++;
                                       s="";
                                       continue;
                          }
                          s+=str[i];
                  }
                  for(int k=0;k<=j;k++)
                          cout<<coef[j]<<"\t";
    }
    return 0;
}
