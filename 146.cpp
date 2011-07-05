#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    for(;;){
            string str;
            cin>>str;
            char ch[50];
            for(int i=0;i<str.length();i++){
                    ch[i]=str[i];
            }

            if(str=="#")
                        break;

           if(next_permutation(ch,ch+str.length())){
                        for(int i=0;i<str.length();i++){
                                cout<<ch[i];
                        }
                        cout<<endl;
           }
           else
                        cout<<"No Successor"<<endl;
   }
   return 0;
}
