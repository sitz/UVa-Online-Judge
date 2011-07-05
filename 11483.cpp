#include<iostream>
using namespace std;

int main(){
    int i=0;
    for(i=1;;i++){
            int n;
            cin>>n;
            if(n==0)
                    break;
            for(int j=0;j<n;j++){
                    string str;
                    getline(cin,str);
                    cout<<"Case "<<i<<": "<<endl;
                    cout<<"#include<string.h>"<<endl;
                    cout<<"#include<stdio.h>"<<endl;
                    cout<<"int main()"<<endl;
                    cout<<"{"<<endl;
                    for(int j=0;j<=n;j++){
                            int len=str.length();
                            int c1=0,c2=0;
                            cout<<"printf(\"";
                            for(int k=0;k<len;k++){
                                    cout<<str[k];
                            }
                    }
                    cout<<"\");"<<endl;
            }
            cout<<"printf(\"\\n\");"<<endl;
            cout<<"return 0;"<<endl;
            cout<<"}"<<endl;
    }
    return 0;
}
            
