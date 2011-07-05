#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
            char ch[10]={'\0'};
            cin>>ch;
            int len=strlen(ch);
            for(int j=0;j<len;j++){
                    for(int k=j+1;k<len;k++){
                            if(ch[j]>ch[k]){
                                            char temp=ch[j];
                                            ch[j]=ch[k];
                                            ch[k]=temp;
                            }
                    }
            }
            do{
                    for(int j=0;j<len;j++)
                            cout<<ch[j];
                    cout<<endl;
            }while(next_permutation(ch,ch+len));
            cout<<endl;
    }
    return 0;
}
