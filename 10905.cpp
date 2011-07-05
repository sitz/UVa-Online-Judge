#include<iostream>
using namespace std;

int main(){
    for(;;){
            int n;
            cin>>n;
            if(n==0)
                    break;
            string str[50];
            for(int i=0;i<n;i++)
                    cin>>str[i];
            for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                            if(str[i]<str[j]){
                                              string temp=str[i];
                                              str[i]=str[j];
                                              str[j]=temp;
                            }
                    }
            }
            string s="";
            for(int i=0;i<n;i++)
                    s+=str[i];
            cout<<s<<endl;
    }
    return 0;
}
