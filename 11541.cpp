#include<iostream>
#include<cmath>
#include<cctype>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            string str;
            cin>>str;
            char alph[150]={'\0'};
            int freq[150]={0};
            int len =str.length();
            int j=0,k=0,l=0,num=0,ctr=0;
            for(j=0,k=0,l=0;j<len;j++){
                    if(isalpha(str[j])){
                               alph[k]=str[j];
                               k++;
                               l++;
                               freq[l]=num;
                               num=0;
                               ctr=0;
                    }
                    if(isdigit(str[j])){
                                        int temp=str[j]-'0';
                                        num+=temp;
                                        ctr++;
                    }
            }
            cout<<"Case "<<i<<": ";
            for(j=0;j<k;k++){
                    for(int c=0;c<=freq[j];){
                                         cout<<alph[j];
                    }
            }
            cout<<endl;
    }
    return 0;
}
